clear, clc;
close all;
hold on;
load("../CONSTANTES/const_estimado.mat")
load("../DADOS/MODELO/dadosQbot.mat");
X0 = zeros(7,1);
dados = trajetoriaModelo(constantes,velocidade,tempo,X0);
plot(posicao(:,1),posicao(:,2),"DisplayName","Qbot","LineWidth",2)
plot(dados(:,1),dados(:,2),"DisplayName","Modelo","LineWidth",2)
hold off;
legend
drawnow

save("../DADOS/MODELO/dados_estimado.mat","dados");