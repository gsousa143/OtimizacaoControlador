function [A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p] = calculaMatrizesModelo(constantes)
R = constantes(1); % Raio das rodas do robô (m)
L = constantes(2); % Comprimento do semieixo das rodas do robô (m)
m_c = constantes(3); % Massa da plataforma do robô
m_w = constantes(4); % Massa da roda do robô
d = constantes(5); 

N = constantes(6); %Relacao de engrenagens do motor CC
b = constantes(7); % Coeficiente de atrito viscoso do motor CC
K_ce = constantes(8); % Constante de força contra-eletromotriz do motor CC 
K_t = constantes(9); % Constante de torque do motor CC 
R_a = constantes(10); % Resistencia de armadura totau do robô

f_s = constantes(11); % Coeficiente de atrito estático 
f_k = constantes(12); % Coeficiente de atrito cinético

alpha_s = constantes(13); % Constante de saturação do atrito estático 
alpha_k = constantes(14); % Constantes de saturação do atrito cinético

k_i = constantes(15); % Ganho Ki
k_p = constantes(16); % Ganho Kp


g = 9.81; %Aceleracao da gravidade

m = m_c + 2*m_w;
I_c = m_c*L^2/2;
I_w = m_w*R^2/2;
I_t = I_c + 2*m_w*L^2 + 2*I_w;

F_s = f_s*m*g;
F_k = f_k*m*g;

V_TRACO = R^2*d*m_c/(4*L^2)*[
    0, 1;
    -1,0];

A_taum = (b - (K_ce*K_t)/R_a)/N*eye(2,2);

B_taum = K_t/R_a*eye(2,2);


M_TRACOi = -inv([
    I_w + R^2*(m*L^2 + I_t)/(4*L^2), R^2*(m*L^2 - I_t)/(4*L^2);
    R^2*(m*L^2 - I_t)/(4*L^2), I_w + R^2*(m*L^2 + I_t)/(4*L^2)]);

end