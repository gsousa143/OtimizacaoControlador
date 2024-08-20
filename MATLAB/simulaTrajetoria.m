clear, clc;
close all;

load("../CONSTANTES/const_otimo.mat")

[A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p] = calculaMatrizesModelo(constantes);

for controlador  = ["fbg"]
fis = readfis('../CONTROLADORES/'+controlador+'.fis');


for trajetoria = ["zzx"]


path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/"+upper(controlador)+"/";


mkdir(path);



T = 1e-2;
t0  = 0;
custos = [];
Xinicial = zeros(7,1);
load('../SETPOINTS/'+trajetoria+'.mat')


for laps = 1:1
    dados = ddmr(fis,Xinicial,T,t0,t_final,setpoints,1,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p); %realiza a trajetoria de uma volta
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
