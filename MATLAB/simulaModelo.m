clear, clc;
close all;
figure;
hold on;
controlador = "ofbg";
trajetoria = "cir";
tipo = "inicial";
load("../CONSTANTES/const_"+tipo+".mat");

load("../DADOS/MODELO/dados_qbot_"+controlador+"_"+trajetoria+".mat");
T = 0.01;
tempo = (0:0.01:(size(dados,1)-1)*T)';
posicao = dados(:,1:2);
velocidade = dados(:,8:9);

% load("dadosQbot.mat")

X0 = zeros(7,1);
dados = trajetoriaModelo(constantes,velocidade,tempo,X0);
plot(posicao(:,1),posicao(:,2),"DisplayName","Qbot","LineWidth",2)
plot(dados(:,1),dados(:,2),"DisplayName","Modelo","LineWidth",2)
hold off;

legend
figure;
eR = sqrt(sum(( posicao-dados(:,1:2) ).^2,2));
max(eR)
plot(tempo,eR,"LineWidth",2);
fCusto = sqrt( sum(eR.^2, 'all')/size(tempo,1) );
save("../DADOS/MODELO/dados_modelo_"+tipo+"_"+controlador+"_"+trajetoria+".mat", 'dados');
fCusto
