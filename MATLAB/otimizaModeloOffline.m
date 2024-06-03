clc,clear,close all;
hold on;

load("../CONSTANTES/const_estimado.mat");
load("../DADOS/MODELO/dadosQbot.mat");

X0 = zeros(7,1);

solucaoInicial = constantes(1:12); %dos valores estimados seleciono os quais serão variaveis de decisão

limites(1,:) = [constantes(1:2)*1.5, constantes(3:12)*10];
limites(2,:) = [constantes(1:2)*0.5, constantes(3:12)*0.1];


[fopt, xopt] = pso(@(x) otmModelo(x,posicao,velocidade,tempo,X0,constantes,false), ...
    limites, solucaoInicial,[], 60, 100, Inf, true);

constantes = attConstantes(constantes,xopt,1:12);
save("../CONSTANTES/const_otimo.mat","constantes");
