clear, clc;
close all;


controlador  = "fbmg";
fis = readfis('../CONTROLADORES/'+controlador+'.fis');


for trajetoria = ["zzx", "dia", "inf", "spr"]


path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/"+upper(controlador)+"/";


mkdir(path);






T = 1e-2;
t0  = 0;
custos = [];
Xinicial = zeros(7,1);
tempoMax = Inf;
setpoints= readmatrix('../SETPOINTS/'+trajetoria+'.csv');
constantes = readmatrix("../CONSTANTES/constantesOpt.csv");

for laps = 1:1
    dados = ddmr(fis,Xinicial,T,t0,tempoMax,constantes,setpoints,1); %realiza a trajetoria de uma volta
    t0 = dados(end,end); %atualiza o tempo inicial.
    figure;
    plotDadosTrajetoria(dados); %plota dados de trajetoria.
    fCusto = calculaErros(dados); %calcula o custo.
    custos = [custos;[laps,fCusto]]; %incrementa matriz com funcional custo da volta e numero da volta.
    writematrix(dados,path+"dados"+string(laps)+".csv"); %salva os dados da volta em um arquivo csv
    writematrix(custos,path+"custo.csv"); %salva os custos de todas as voltas em um arquivo csv
end

% figure
% plotTrajetoria(dados)
end