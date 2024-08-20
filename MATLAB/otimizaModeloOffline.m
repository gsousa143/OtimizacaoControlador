clc,clear,close all;
hold on;
warning("off")
load("../CONSTANTES/const_inicial.mat");
% 

load("../DADOS/MODELO/dados_qbot_fbm_zzx.mat");
T = 0.01;
tempo = (0:0.01:(size(dados,1)-1)*T)';
posicao = dados(:,1:2);
velocidade = dados(:,8:9);


solucaoInicial = constantes(1:14);

limites(1,:) = [constantes(1:4)*1.1, 0.07, constantes(6:14)*1.5];
limites(2,:) = [constantes(1:4)*0.9, 0.00, constantes(6:14)*0.5];
X0 = zeros(7,1);

limites

tic

[fopt, xopt] = de(@(x) otmModelo(x,posicao,velocidade,tempo,X0,constantes,false), ...
    limites, solucaoInicial, 50, Inf, 3600, true);

toc
% constantes = attConstantes(constantes,xopt);
% save("../CONSTANTES/const_otimo.mat","constantes");
