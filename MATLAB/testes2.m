clc, clear;

U = ones(100,2);
X = zeros(7,1);
tempo = 0;
load("../CONSTANTES/const_estimado.mat");
[A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p] = calculaMatrizesModelo(constantes);
T = 0.01;
% for i = 1:100
%     u = U(i,:)';
%     [tempo,X] = integracaoNumerica(X,u,tempo,T,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);
% end



