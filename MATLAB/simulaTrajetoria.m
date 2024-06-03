clear, clc;
close all;


for controlador  = ["fbg","fbgo"]
fis = readfis('../CONTROLADORES/'+controlador+'.fis');


for trajetoria = ["zzx"]


path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/"+upper(controlador)+"/";


mkdir(path);






T = 1e-2;
t0  = 0;
custos = [];
Xinicial = zeros(7,1);
tempoMax = Inf;
setpoints= readmatrix('../SETPOINTS/'+trajetoria+'.csv');
load("../CONSTANTES/const_otimo.mat");

for laps = 1:1
    dados = ddmr(fis,Xinicial,T,t0,tempoMax,constantes,setpoints,1); %realiza a trajetoria de uma volta
    t0 = dados(end,end); %atualiza o tempo inicial.
    plotDadosTrajetoria(dados,true); %plota dados de trajetoria.
    [fCusto,er,etraj,eu,ev,tempo,w] = calculaErros(dados); %calcula o custo.
    custos = [laps,fCusto]; %incrementa matriz com funcional custo da volta e numero da volta.
    save(path+"dados1_"+string(laps),'dados','custos'); %salva os dados da volta em um arquivo
    writematrix(custos,path+"custos1.csv")
end

% figure
% plotTrajetoria(dados)
end
end
