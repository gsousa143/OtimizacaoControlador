clc,clear,close all;
hold on;


C = readmatrix("../CONSTANTES/constantesEst.csv");
load("../DADOS/MODELO/saix.mat");
load("../DADOS/MODELO/saiy.mat");
load("../DADOS/MODELO/vL.mat");
load("../DADOS/MODELO/vR.mat");


saidas = [saix(:,2),saiy(:,2)];

U = [ud(:,2),ue(:,2)]/0.034;

tempos = saix(:,1);

X0 = zeros(7,1);


solucaoInicial = C(1:12); %dos valores estimados seleciono os quais serão variaveis de decisão

limites(1,:) = solucaoInicial*1.5;
limites(2,:) = solucaoInicial*0.5;

parametros.itMax = 60;
parametros.tempoMax = Inf;
parametros.NP = 40;
parametros.info = 1;
parametros.cP = 1.49; %PSO
parametros.cS = 1.49; %PSO
parametros.path = "custosModelo.csv";


[fopt, xopt,~] = PSO(@(x) OtimizaModelo(x,saidas,U,tempos,X0,C), limites, solucaoInicial, parametros);

C = attConstantes(C,xopt,1:12);
writematrix(C,"../CONSTANTES/constantesOpt.csv");
