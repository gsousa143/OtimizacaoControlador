classdef ddmr_flc < matlab.System %#codegen
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object.

    % Public, tunable properties
    properties
        R = 0; L = 0; alpha_s= 0 ; alpha_k=0; f_s=0; f_k=0; V=zeros(2,2); A_tau=zeros(2,2); B_tau=zeros(2,2); M_i=zeros(2,2); k_i=0; k_p=0; T = 0.01;
        fis_params = zeros(1,5);
    end

    % Pre-computed constants or internal states
    properties (Access = private)
        state;
    end

    methods (Access = protected)
        function setupImpl(obj)
            obj.state = zeros(7,1);
        end


        function [x_a, y_a, theta, phi_d, phi_e,u_d,u_e] = stepImpl(obj,x_sp,y_sp)
            % Recebe um setpoint de posição e atualiza o estado do ddmr em
            % relação ao sinal de controle provido pelo controlador de
            % trajetoria fuzzy.
            setpoint = [x_sp, y_sp];
            error = setpoint - obj.state(1:2)';
            l = norm(error);

            PHIr = (atan2( error(2), error(1) )-obj.state(3))/2;
            phi = 2*atan2( tan(PHIr) ,1 );

            speeds = flc_ddmr(phi,l,obj.fis_params);


            u = 1/0.034*[
                speeds(1)+speeds(2)*0.1175;
                speeds(1)-speeds(2)*0.1175];

            [~, states] = ode45(@(t,X) ...
                unifiedModel(t, X, u, obj.R, obj.L, obj.alpha_s, obj.alpha_k, obj.f_s, obj.f_k, obj.V, obj.A_tau, obj.B_tau, obj.M_i, obj.k_i, obj.k_p), ...
                [0,obj.T] , obj.state);

            obj.state = states(end,:)';

            x_a = obj.state(1);
            y_a = obj.state(2);
            theta = obj.state(3);
            phi_d = obj.state(4);
            phi_e = obj.state(5);
            u_d = u(1);
            u_e = u(2);

        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end

        function [o1, o2, o3, o4, o5, o6, o7] = getOutputSizeImpl(obj)
            % Return size for output port to be same as input port
            inSize = [1 1];
            o1 = inSize;
            o2 = inSize;
            o3 = inSize;
            o4 = inSize;
            o5 = inSize;
            o6 = inSize;
            o7 = inSize;
        end

        function [o1, o2, o3, o4, o5, o6, o7] = getOutputDataTypeImpl(obj)
            % Return data type for output port to be same as input port
            out = "double";
            o1 = out;
            o2 = out;
            o3 = out;
            o4 = out;
            o5 = out;
            o6 = out;
            o7 = out;
        end

        function [o1, o2, o3, o4, o5, o6, o7] = isOutputComplexImpl(~)
            % Return output port complexity to be real
            o1 = false;
            o2 = false;
            o3 = false;
            o4 = false;
            o5 = false;
            o6 = false;
            o7 = false;
        end

        function [o1, o2, o3, o4, o5, o6, o7] = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            o1 = true;
            o2 = true;
            o3 = true;
            o4 = true;
            o5 = true;
            o6 = true;
            o7 = true;
        end
    end

    methods(Access = public)
        function state = getState(obj)
            state = obj.state;
        end

        function setState(obj,state)
            obj.state = state;
        end

        function setFlc(obj,fis_params)
            obj.fis_params = fis_params;
        end

        function setConstants(obj, constants)
            obj.R = constants(1); % Raio das rodas do robô (m)
            obj.L = constants(2); % Comprimento do semieixo das rodas do robô (m)
            m_c = constants(3); % Massa da plataforma do robô
            m_w = constants(4); % Massa da roda do robô
            d = constants(5);

            N = constants(6); %Relacao de engrenagens do motor CC
            b = constants(7); % Coeficiente de atrito viscoso do motor CC
            K_ce = constants(8); % Constante de força contra-eletromotriz do motor CC
            K_t = constants(9); % Constante de torque do motor CC
            R_a = constants(10); % Resistencia de armadura totau do robô

            f_s = constants(11); % Coeficiente de atrito estático
            f_k = constants(12); % Coeficiente de atrito cinético

            obj.alpha_s = constants(13); % Constante de saturação do atrito estático
            obj.alpha_k = constants(14); % constants de saturação do atrito cinético

            obj.k_i = constants(15); % Ganho Ki
            obj.k_p = constants(16); % Ganho Kp


            g = 9.81; %Aceleracao da gravidade

            m = m_c + 2*m_w;
            I_c = m_c*obj.L^2/2;
            I_w = m_w*obj.R^2/2;
            I_t = I_c + 2*m_w*obj.L^2 + 2*I_w + m_c*d^2;

            obj.f_s = f_s*m*g;
            obj.f_k = f_k*m*g;

            obj.V = obj.R^2*d*m_c/(4*obj.L^2)*[
                0, 1;
                -1,0];

            obj.A_tau = (b - (K_ce*K_t)/R_a)/N*eye(2,2);

            obj.B_tau = K_t/R_a*eye(2,2);

            obj.M_i = -inv([
                I_w + obj.R^2*(m*obj.L^2 + I_t)/(4*obj.L^2), obj.R^2*(m*obj.L^2 - I_t)/(4*obj.L^2);
                obj.R^2*(m*obj.L^2 - I_t)/(4*obj.L^2), I_w + obj.R^2*(m*obj.L^2 + I_t)/(4*obj.L^2)]);
        end

    end
end

%Helper Functions
function dstate_dt = unifiedModel(~, state, u, R, L, alpha_s, alpha_k, f_s, f_k, V, A_tau, B_tau, M_i, k_i, k_p)
A_cin = R/2*[
    cos(state(3)), cos(state(3));
    sin(state(3)), sin(state(3))];


tau_F = [
    f_s*tanh(alpha_s*state(4)) - f_k*tanh(alpha_k*state(4));
    f_s*tanh(alpha_s*state(5)) - f_k*tanh(alpha_k*state(5))];

eta = [
    state(4);
    state(5)];


epi = [
    state(6);
    state(7)];

Y_pi = min(12, max( k_i*epi + k_p*(u-eta), -12) );


dtheta_dt = R*(state(4)-state(5))/(2*L);

dstate_dt = [
    A_cin*eta;
    dtheta_dt;
    M_i*((A_tau+(dtheta_dt*V))*eta - B_tau*Y_pi + tau_F);
    u-eta];
end



function speeds = flc_ddmr(phi,l,fis_params)
n_points = 101;

%input Angular Error
angular_error = [
    gauss_mf(phi,fis_params(1),-pi);
    gauss_mf(phi,fis_params(2),fis_params(4)-pi);
    gauss_mf(phi,fis_params(3),fis_params(5)-pi);
    gauss_mf(phi,fis_params(3),-fis_params(5));
    gauss_mf(phi,fis_params(2),-fis_params(4));
    gauss_mf(phi,fis_params(1),0);
    gauss_mf(phi,fis_params(2),fis_params(4));
    gauss_mf(phi,fis_params(3),fis_params(5));
    gauss_mf(phi,fis_params(3),pi-fis_params(5));
    gauss_mf(phi,fis_params(2),pi-fis_params(4));
    gauss_mf(phi,fis_params(1),pi)];

%input Distance
distance = [
    linz_mf(l,0.01,0.02);
    lins_mf(l,0.01,0.02)];



%inference process
fuzzy_linear_speed = [
    min(distance(2), max([angular_error(1), angular_error(11)]) );
    min(distance(2), max([angular_error(2), angular_error(10)]) );
    min(1, max([angular_error(3), angular_error(4), angular_error(8), angular_error(9),distance(1)]) );
    min(distance(2), max([angular_error(5), angular_error(7)]) );
    min(distance(2), max([angular_error(6)]))];

fuzzy_angular_speed = [
    min(distance(2), max([angular_error(4), angular_error(5), angular_error(9), angular_error(10)]) );
    min(1, max([angular_error(1), angular_error(11), angular_error(6),distance(1)]) );
    min(distance(2), max([angular_error(2), angular_error(3), angular_error(7), angular_error(8)]) )];

x_linear_speed = linspace(-0.15,0.15,n_points);
x_angular_speed = linspace(-0.5,0.5,n_points);

fuzzy_agg_linear_speed = max([ ...
    min(fuzzy_linear_speed(1), pi_mf(x_linear_speed,-0.16,-0.15,-0.1,-0.05));
    min(fuzzy_linear_speed(2), pi_mf(x_linear_speed,-0.1,-0.05,-0.05,0));
    min(fuzzy_linear_speed(3), pi_mf(x_linear_speed,-0.05,0,0,0.05));
    min(fuzzy_linear_speed(4), pi_mf(x_linear_speed,0,0.05,0.05,0.1));
    min(fuzzy_linear_speed(5), pi_mf(x_linear_speed,0.05,0.1,0.15,0.16))], [],1);




fuzzy_agg_angular_speed = max([ ...
    min(fuzzy_angular_speed(1), linz_mf(x_angular_speed,-0.5,0));
    min(fuzzy_angular_speed(2), tri_mf(x_angular_speed,-0.5,0,0.5));
    min(fuzzy_angular_speed(3), lins_mf(x_angular_speed,0,0.5))], [],1);


%defuzzification
speeds = [
    sum(x_linear_speed.*fuzzy_agg_linear_speed)/sum(fuzzy_agg_linear_speed);
    sum(x_angular_speed.*fuzzy_agg_angular_speed)/sum(fuzzy_agg_angular_speed)];


%plot fuzzy agg output

% plot(linspace(-1,1,n_points), [fuzzy_agg_linear_speed;fuzzy_agg_angular_speed]);
% % legend(["Velocidade Linear","Velocidade Angular"],Location="northoutside",Orientation="horizontal",Box="off");
% ylim([-0.1, 1.1]);
% drawnow;

% drawnow;

end


%membership functions
function y = lins_mf(x,a,b)
y = zeros(size(x),'like',x);
if a<b
    y(x>=b) = 1;
    id = x>=a & x<=b;
    y(id) = (x(id)-a)/(b-a);
end
end

function y = linz_mf(x,a,b)
y = zeros(size(x),'like',x);

if a<b
    y(x<a) = 1;
    id = x>=a & x<b;
    y(id) = (b-x(id))/(b-a);
end
end

function y = gauss_mf(x,a,b)
y = exp( (-(x-b).^2)/(2*a^2) );
end

function y = tri_mf(x,a,b,c)
y = zeros(size(x),'like',x);
if (a ~= b)
    id = find(a < x & x < b);
    y(id) = (x(id)-a)/(b-a);
end
if (b ~= c)
    id = find(b < x & x < c);
    y(id) = (c-x(id))/(c-b);
end
y(x == b) = 1;
end

function y = pi_mf(x,a,b,c,d)
y = zeros(size(x),'like',x);
y(x>b & x<c) = 1;
y(x>a & x<=b) = 2*((x(x>a & x<=b)-a)/(b-a)).^2;
y(x>=c & x<d) = 2*((x(x>=c & x<d)-d)/(d-c)).^2;
y(x>(a+b)/2 & x<=b) = 1-2*((x(x>(a+b)/2 & x<=b)-b)/(b-a)).^2;
y(x>=c & x<(c+d)/2) = 1-2*((x(x>=c & x<(c+d)/2)-c)/(d-c)).^2;
end
