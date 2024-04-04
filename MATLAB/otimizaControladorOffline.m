clear;
clc;
close all;
hold on;


%OTIMIZAÇÃO
%parametros da otimização
parametros.itMax = 80;
parametros.tempoMax = Inf;
parametros.NP =  60;
parametros.info = 1;
parametros.cP = 1.49; %PSO
parametros.cS = 1.49; %PSO
parametros.Fp = 1.4; %DE
parametros.cr = 0.3; %DE/GA
parametros.betta = 0.1; %GA
parametros.fM = 0.7; %GA
parametros.path = "custosFLC.csv";


%definindo os limites para as variaveis de decisão




fis = readfis("../CONTROLADORES/fbm.fis");


solucaoInicial(1) = fis.input(1).mf(1).params(1);
solucaoInicial(2) = fis.input(1).mf(2).params(1);
solucaoInicial(3) = fis.input(1).mf(3).params(1);
solucaoInicial(4) = fis.input(1).mf(7).params(2);
solucaoInicial(5) = fis.input(1).mf(8).params(2);

solucaoInicial


limitesMax = [0.6,  0.6, 0.6,  0.35, 0.60]*pi;
limitesMin = [0.01,0.01,0.01,-0.1, 0.15]*pi;


limites = [limitesMax;limitesMin]


T = 1e-2; %periodo de amostragem



[fopt, xopt,~] = pso(@(x) otmFLC(x,fis,zeros(7,1),1e-2,0,130,readmatrix("../CONSTANTES/constantesOpt.csv"),readmatrix('../SETPOINTS/zzx.csv'),1,false), ...
    limites, solucaoInicial, parametros);

fis = attFLC(fis,xopt);

writeFIS(fis,"../CONTROLADORES/fbmo.fis");
