clc,clear,close all;
hold on;


C = readmatrix("../CONSTANTES/constantesEst.csv");
load("../DADOS/MODELO/saix.mat");
load("../DADOS/MODELO/saiy.mat");
load("../DADOS/MODELO/vL.mat");
load("../DADOS/MODELO/vR.mat");


saidas = [saix(:,2),saiy(:,2)];


U = [ud(:,2),ue(:,2)]/0.034; %tranforma em velocidade angular

tempos = saix(:,1);

X0 = zeros(7,1);


solucaoInicial = C(1:12); %dos valores estimados seleciono os quais serão variaveis de decisão

limites(1,:) = [C(1:2)*1.1, C(3:12)*10];
limites(2,:) = [C(1:2)*0.9, C(3:12)*0.1];




[fopt, xopt] = de(@(x) otmModelo(x,saidas,U,tempos,X0,C,false), ...
    limites, solucaoInicial, 50, 100, Inf, true);

C = attConstantes(C,xopt,1:12);
writematrix(C,"../CONSTANTES/constantesOpt2.csv");
