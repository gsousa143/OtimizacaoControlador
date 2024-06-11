clear
clc

constante = "otimo";
controlador = "fbgo";
trajetoria = "zzx";

load("../CONSTANTES/const_"+constante+".mat")
load("../SETPOINTS/"+trajetoria+".mat")
fis = readfis("../CONTROLADORES/"+controlador+".fis");
i_sp = 1;
N_sp = size(setpoints,1);

setpoints = reshape(setpoints,[],1);
T = 0.01;

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

I_c = m_c*L^2/2;
I_w = m_w*R^2/2;
I_t = I_c + 2*m_w*L^2 + 2*I_w + m_c*d^2;
m = m_c + 2*m_w;
g = 9.81; %Aceleracao da gravidade

Mn1 = (m*L^2*R^2 + 4*I_w*L^2 + I_t*R^2)/(4*I_w^2*L^2 + 2*m*I_w*L^2*R^2 + 2*I_t*I_w*R^2 + I_t*m*R^4);
Mn2 = (R^2*(- m*L^2 + I_t));
Md = (4*I_w^2*L^2 + 2*m*I_w*L^2*R^2 + 2*I_t*I_w*R^2 + I_t*m*R^4);


sim('trajetoria')

