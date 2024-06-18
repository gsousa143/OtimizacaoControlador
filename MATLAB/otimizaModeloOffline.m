clc,clear,close all;
hold on;

load("../CONSTANTES/const_estimado.mat");
load("../DADOS/MODELO/dadosQbot.mat");

robo = readmatrix("diagonal.csv");
velocidade = robo(:,4:5);
tempo = robo(:,6);
posicao = robo(:,1:2);
X0 = zeros(7,1);

solucaoInicial = constantes(1:14);

limites(1,:) = [constantes(1:4)*1.3, 0.07, constantes(6:14)*10];
limites(2,:) = [constantes(1:4)*0.7, 0, constantes(6:14)*0.1];

limites

[fopt, xopt] = de(@(x) otmModelo(x,posicao,velocidade,tempo,X0,constantes,false), ...
    limites, solucaoInicial, 60, 100, Inf, true);

constantes = attConstantes(constantes,xopt);
save("../CONSTANTES/const_otimo_joao.mat","constantes");
