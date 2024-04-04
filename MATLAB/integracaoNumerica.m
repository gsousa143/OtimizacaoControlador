function [tempo,X] = integracaoNumerica(X,u,tempo,T,c)  %#codegen
[tempos, Xs] = ode45(@(t,X) modeloUnificado(t,X,u,c), [tempo,tempo+T] , X);
X = Xs(end,:)';
tempo = tempos(end);
end




function Xponto = modeloUnificado(~,X,u,c)
R = c(1); % Raio das rodas do robô (m)
L = c(2); % Comprimento do semieixo das rodas do robô (m)
b = c(3); % Coeficiente de atrito viscoso do motor CC
Kce = c(4); % Constante de força contra-eletromotriz do motor CC 
Kt = c(5); % Constante de torque do motor CC 
Ra = c(6); % Resistencia de armadura total do robô
mc = c(7); % Massa da plataforma do robô
mw = c(8); % Massa da roda do robô
Fs = c(9); % Coistência de armadura do motor CC 
Fk = c(10); % Diferença entre coeficiente de atrito estático e cinético
alpha_s = c(11); % Constante de saturação do atrito com o solo 
alpha_k = c(12); % Constantes de saturação do atrito com o solo 

ki = c(13); % Ganho Ki
kp = c(14); % Ganho Kp


N = 1; % Relação de engrenagens do motor CC 
D = 0.35; %Diametro da plataroma do Robô
g = 9.81; %Aceleracao da gravidade
m = mc + 2*mw; %Massa do robô
Ic = mc*(D/2)^2/2;
Iw = mw*R^2/2;
It = Ic + 2*mw*L^2 + 2*Iw;
Ki = ki*eye(2,2);
Kp = kp*eye(2,2);



M_TRACO = [
    Iw+((R^2/(4*(L^2)))*(m*(L^2)+It)),      (R^2/(4*(L^2)))*(m*(L^2)-It);
    (R^2/(4*(L^2)))*(m*(L^2)-It),       Iw+((R^2/(4*(L^2)))*(m*(L^2)+It))];


B_TRACO = eye(2,2);

A_tal = (1/N)*[
    ((-Kce*Kt)/Ra)+b,           0;
    0,           ((-Kce*Kt)/Ra)+b];

B_tal = [
    Kt/Ra, 0;
    0, Kt/Ra];

A_tald = (M_TRACO\B_TRACO)*A_tal;

B_tald = (M_TRACO\B_TRACO)*B_tal;

Bx = [
    zeros(3,2);
    B_tald*Kp;
    eye(2,2)];

A_cin = (R/2)*[
    cos(X(3)),  cos(X(3));
    sin(X(3)),  sin(X(3));
    1/L,            -1/L];

Ax = [
    zeros(3,3),      A_cin,                      zeros(3,2);
    zeros(2,3),   (A_tald-B_tald*Kp),    (B_tald*Ki);
    zeros(2,3),     -eye(2,2)                   zeros(2,2)];

tal_a = [
    Fs*tanh(alpha_s*X(4))-Fk*tanh(alpha_k*X(4));
    Fs*tanh(alpha_s*X(5))-Fk*tanh(alpha_k*X(5))];


F_tald = -(M_TRACO\B_TRACO)*tal_a;

Fx = m*g*[
    zeros(3,1);
    F_tald;
    zeros(2,1)];

Xponto = Ax*X + Bx*u + Fx;
end