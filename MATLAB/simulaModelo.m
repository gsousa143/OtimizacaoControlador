clear, clc;
close all;
hold on;

tipo = "otimo";
load("../CONSTANTES/const_"+tipo+".mat")
load("../DADOS/MODELO/dadosQbot.mat");

X0 = zeros(7,1);
dados = trajetoriaModelo(constantes,velocidade,tempo,X0);
plot(posicao(:,1),posicao(:,2),"DisplayName","Qbot","LineWidth",2)
plot(dados(:,1),dados(:,2),"DisplayName","Modelo","LineWidth",2)
hold off;

legend
figure;
eR = sqrt(sum(( posicao-dados(:,1:2) ).^2,2));
plot(tempo,eR,"LineWidth",2);
fCusto = sqrt( sum(eR.^2, 'all')/size(tempo,1) );

drawnow

