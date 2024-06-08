clc
clear
close all




plotCustosModelo("controlador")




function plotCustosOnline(metodos, trajetoria, controladores,maxTestes)
path = "../DADOS/CONTROLADOR/";
hold on;
legenda = [];

for metodo = metodos
    for controlador = controladores
        custos = [];
        for i = 1:maxTestes
            try
                if metodo == ""
                    custo = readmatrix(path+upper(trajetoria)+"/"+upper(controlador)+"/custos"+string(i)+".csv");
                else
                    custo = readmatrix(path+upper(trajetoria)+"/"+upper(controlador)+"_"+upper(metodo)+"/custos"+string(i)+".csv");
                end
                custos = [custos,custo(:,2)];

            catch

            end
        end

        if size(custos,2) > 1
            media = mean(custos,2);
            dp = std(custos,1,2);
            errorbar(media,dp,"LineWidth",1);
            legenda = [legenda, controlador+metodo];
        else
            if size(custos,1) == 1
                yline(custos,"LineWidth",1)
            else
                plot(custos,"LineWidth",1);
            end
            legenda = [legenda, controlador+metodo];
        end

    end %controlador = controladores
end %metodo = metodos
xlabel('Lap', "Interpreter", "latex");
ylabel('Lap Functional Cost', "Interpreter", "latex");
axis padded;

legend(legenda)
title(trajetoria)

set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
hold off;
drawnow;
end


function plotQbot(tipo)
load("../DADOS/MODELO/dadosQbot.mat","posicao","tempo")
load("../DADOS/MODELO/dados_estimado.mat")
estimado = dados(:,1:2);
load("../DADOS/MODELO/dados_otimo.mat")
otimo = dados(:,1:2);
hold on;

if tipo=="trajetoria"
plot(estimado(:,1),estimado(:,2),LineWidth=2,DisplayName="Modelo Estimado")
plot(otimo(:,1),otimo(:,2),LineWidth=2,DisplayName="Modelo Otimizado")
plot(posicao(:,1),posicao(:,2),LineWidth=2,DisplayName="Qbot")

xlabel('$x_a$ [$m$]', "Interpreter", "latex");
ylabel('$y_a$ [$m$]', "Interpreter", "latex");


elseif tipo=="erro"
erro_estimado = sqrt(sum((posicao-estimado).^2,2));
erro_otimo = sqrt(sum((posicao-otimo).^2,2));
plot(tempo,erro_estimado,LineWidth=2,DisplayName="Modelo Estimado")
plot(tempo,erro_otimo,LineWidth=2,DisplayName="Modelo Otimizado")

xlabel('Tempo [$s$]', "Interpreter", "latex");
ylabel('Erro [$m$]', "Interpreter", "latex");
end

hold off;
axis padded;
legend('Orientation','horizontal','location','southoutside','Box','off')
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
drawnow;

saveas(gcf, '../IMAGENS/MODELO/'+tipo+'.eps', 'epsc');
end

function plotCustosModelo(tipo)

custos = readmatrix("../DADOS/"+upper(tipo)+"/custos.csv");

plot(custos(:,1),custos(:,2),LineWidth=2)
xlabel('Iteração');
ylabel('Funcional Custo');
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
drawnow;
saveas(gcf, '../IMAGENS/'+upper(tipo)+'/custos.eps', 'epsc');

end

function plotControladores(controladores)
controladores = ["fbg"]
path = "../CONTROLADORES/";
for controlador = controladores
    fis = readfis(path+controlador+".fis")
    nE = size(fis.Inputs,2);
    nS = size(fis.Outputs,2);
    for i = 1:nE
        figure
        range = fis.Input(i).range;
        x = linspace(range(1),range(2),1000);
        for j = 1:size(fis.Input(i).mf,2)
            hold on;
            mf = fis.Input(i).mf(j);
            y = evalmf(mf,x);
            plot(x,y,DisplayName=mf.name,LineWidth=2)
        end
        xlabel(fis.Input(i).name, "Interpreter", "latex");
        ylabel("Graus de Pertinencia", "Interpreter", "latex");
        axis padded;
        legend('location','southoutside','Box','off',"NumColumns",6)
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
        drawnow 
    end
end

end
