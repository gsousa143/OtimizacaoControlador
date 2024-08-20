clc;
clear;
trajetoria = 'dia';
controlador = 'fbg';
load(['SETPOINTS/', trajetoria, '.mat']);
load("CONSTANTES/const_otimo")
N_sp = size(setpoints,1);
initialState = zeros(7,1);
[A_tau,V,B_tau,M_i, R, L, f_s, f_k, alpha_s,alpha_k,k_i,k_p] = calculaMatrizesModelo(constantes);



