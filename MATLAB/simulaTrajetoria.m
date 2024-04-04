clear, clc;
hold on;
path = "../DADOS/ZZX/FBMO/"
fis = readfis('../CONTROLADORES/fbmo.fis');

T = 1e-2;
t0  = 0;
custo = [];
Xinicial = zeros(7,1);
tempoMax = Inf;
setpoints= readmatrix('../SETPOINTS/zzx.csv');
constantes = readmatrix("../CONSTANTES/constantesOpt.csv");

for laps = 1:1
    dados = ddmr(fis,Xinicial,T,t0,tempoMax,constantes,setpoints,1); %realiza a trajetoria de uma volta
    t0 = dados(end,end); %atualiza o tempo inicial.
    plotDDMR(dados,T,fis); %plota dados de trajetoria.
    fCusto = calculaErros(dados) %calcula o custo.
    custo = [custo;[laps,fCusto]]; %incrementa matriz com funcional custo da volta e numero da volta.
    % writematrix(dados,path+"dados"+string(laps)+".csv");
    % writematrix(custo,path+"custo.csv");
end
