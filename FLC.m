classdef FLC < matlab.System
    % untitled Add summary here
    %
    % Estrutura Geral para o controlador de trajetoria de DDMRs, recebe
    % como entradas o erro angular e 

    % Public, tunable properties
    properties
        n_points = 101;
        angular_error_params = [pi/11, pi/11, pi/11, pi/11, 2*pi/11];
        R = 0.034;
        L = 0.1175;
    end

    % Pre-computed constants or internal states
    properties (Access = private)
        
    end

    methods (Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function u = stepImpl(obj,phi,l)
            % Implement algorithm. Calculate y as a function of input u and
            % internal states.
            

            %input Angular Error
            angular_error = [
                gauss_mf(phi,obj.angular_error_params(1),-pi);
                gauss_mf(phi,obj.angular_error_params(2),obj.angular_error_params(4)-pi);
                gauss_mf(phi,obj.angular_error_params(3),obj.angular_error_params(5)-pi);
                gauss_mf(phi,obj.angular_error_params(3),-obj.angular_error_params(5));
                gauss_mf(phi,obj.angular_error_params(2),-obj.angular_error_params(4));
                gauss_mf(phi,obj.angular_error_params(1),0);
                gauss_mf(phi,obj.angular_error_params(2),obj.angular_error_params(4));
                gauss_mf(phi,obj.angular_error_params(3),obj.angular_error_params(5));
                gauss_mf(phi,obj.angular_error_params(3),pi-obj.angular_error_params(5));
                gauss_mf(phi,obj.angular_error_params(2),pi-obj.angular_error_params(4));
                gauss_mf(phi,obj.angular_error_params(1),pi)];

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

            x_linear_speed = linspace(-0.15,0.15,obj.n_points);
            x_angular_speed = linspace(-0.5,0.5,obj.n_points);

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

            u = 1/obj.R*[
                speeds(1)+speeds(2)*obj.L;
                speeds(1)-speeds(2)*obj.L];

            %plot fuzzy agg output
            % plot(linspace(-1,1,obj.n_points), [fuzzy_agg_linear_speed;fuzzy_agg_angular_speed]);
            % legend(["Velocidade Linear","Velocidade Angular"],Location="northoutside",Orientation="horizontal",Box="off");
            % ylim([-0.1, 1.1] );
            % drawnow;
        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end


        function [o1] = getOutputSizeImpl(obj)
            % Return size for output port to be same as input port
            o1 = [2 1];

        end

        function [o1] = getOutputDataTypeImpl(obj)
            % Return data type for output port to be same as input port
            o1 = "double";
 
        end

        function [o1] = isOutputComplexImpl(~)
            % Return output port complexity to be real
            o1 = false;

        end

        function [o1] = isOutputFixedSizeImpl(~)
            % Return true for each output port with fixed size
            o1 = true;
        end
    end
    methods (Access=public)
        function setFLC(obj,angular_error_params)
            obj.angular_error_params = angular_error_params;
        end

    end
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
