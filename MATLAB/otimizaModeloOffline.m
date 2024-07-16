clc,clear,close all;
hold on;
warning("off")
load("../CONSTANTES/const_estimado.mat");
load("../DADOS/MODELO/dadosQbot.mat");



solucaoInicial = constantes(5:14);

limites(1,:) = [0.07, constantes(6:14)*10];
limites(2,:) = [0, constantes(6:14)*0.1];
X0 = zeros(7,1);
limites

[fopt, xopt] = de(@(x) otmModelo(x,posicao,velocidade,tempo,X0,constantes,false), ...
    limites, solucaoInicial, 70, 50, Inf, true);

constantes = attConstantes(constantes,xopt);
save("../CONSTANTES/const_otimo_joao.mat","constantes");
