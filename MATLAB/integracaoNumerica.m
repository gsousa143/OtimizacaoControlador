function [tempoFinal,X] = integracaoNumerica(X,u,tempoInicial,periodo,constantes)  %#codegen
[tempos, Xs] = ode23(@(t,X) modeloUnificado(t,X,u,constantes), [tempoInicial,tempoInicial+periodo] , X);
X = Xs(end,:)';
tempoFinal = tempos(end);
end



function Xponto = modeloUnificado(~,X,u,constantes)
R = constantes(1); % Raio das rodas do robô (m)
L = constantes(2); % Comprimento do semieixo das rodas do robô (m)

b = constantes(3); % Coeficiente de atrito viscoso do motor CC
Kce = constantes(4); % Constante de força contra-eletromotriz do motor CC 
Kt = constantes(5); % Constante de torque do motor CC 
Ra = constantes(6); % Resistencia de armadura totau do robô

mc = constantes(7); % Massa da plataforma do robô
mw = constantes(8); % Massa da roda do robô

Fs = constantes(9); % Coeficiente de atrito estático e cinético
Fk = constantes(10); % Coeficiente de atrito estático e cinético

alpha_s = constantes(11); % Constante de saturação do atrito com o solo 
alpha_k = constantes(12); % Constantes de saturação do atrito com o solo 

ki = constantes(13); % Ganho Ki
kp = constantes(14); % Ganho Kp

g = 9.81; %Aceleracao da gravidade

N = 1;

m = mc + 2*mw; %Massa do robô
Ic = mc*L^2/2;
Iw = mw*R^2/2;
It = Ic + 2*mw*L^2 + 2*Iw;

A_taum = (b - (Kce*Kt)/Ra)/N;

B_taum = Kt/Ra;

A_cin = R/2*[
    cos(X(3)), cos(X(3));
    sin(X(3)), sin(X(3));
    1/L, -1/L];



M_TRACO = [
    Iw + R^2*(m*L^2 + It)/(4*L^2), R^2*(m*L^2 - It)/(4*L^2);
    R^2*(m*L^2 - It)/(4*L^2), Iw + R^2*(m*L^2 + It)/(4*L^2)];

tau_F = g*m*[
    Fk*tanh(alpha_k*X(4)) - Fs*tanh(alpha_s*X(4));
    Fk*tanh(alpha_k*X(5)) - Fs*tanh(alpha_s*X(5))];


eta = [
    X(4);
    X(5)];

epi = [
    X(6);
    X(7)];

Ypi = min(12, max( ki*epi + kp*(u-eta), -12) );


Xponto = [
    A_cin*eta; 
    M_TRACO\(B_taum*Ypi - A_taum*eta - tau_F);
    u-eta];
end


