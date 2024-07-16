clc
clear
close all


plotControladores("fbg")


function plotCustosOnline(metodos, trajetoria, controladores,maxTestes)
path = "../DADOS/CONTROLADOR/";
hold on;

for metodo = metodos
    for controlador = controladores
        custos = [];
        controlador = upper(controlador);
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
            errorbar(media,dp,"LineWidth",1,DisplayName=controlador+metodo);

        else
            if size(custos,1) == 1
                yline(custos,"LineWidth",1,DisplayName=controlador+metodo)
            else
                plot(custos,"LineWidth",1,DisplayName=controlador+metodo);
            end

        end

    end %controlador = controladores
end %metodo = metodos
xlabel('Lap', "Interpreter", "latex");
ylabel('Lap Functional Cost', "Interpreter", "latex");
axis padded;

legend()
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
path = "../CONTROLADORES/";
for controlador = controladores
    fis = readfis(path+controlador+".fis");
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
        saveas(gcf, '../IMAGENS/CONTROLADOR/'+controlador+"_"+fis.Input(i).name+'.eps', 'epsc');
    end
    for i = 1:nS
        figure
        range = fis.Output(i).range;
        x = linspace(range(1),range(2),1000);
        for j = 1:size(fis.Output(i).mf,2)
            hold on;
            mf = fis.Output(i).mf(j);
            y = evalmf(mf,x);
            plot(x,y,DisplayName=mf.name,LineWidth=2)
        end
        xlabel(fis.Output(i).name, "Interpreter", "latex");
        ylabel("Graus de Pertinencia", "Interpreter", "latex");
        axis padded;
        legend('location','southoutside','Box','off',"NumColumns",6)
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
        drawnow
        saveas(gcf, '../IMAGENS/CONTROLADOR/'+controlador+"_"+fis.Output(i).name+'.eps', 'epsc');
    end
end

end



function plotTrajetorias(controladores, trajetoria,tipo)
path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/";
if tipo=="trajetoria"
    load("../SETPOINTS/"+lower(trajetoria)+".mat")
    plot(setpoints(:,1),setpoints(:,2),"x--", "LineWidth", 2,DisplayName="Setpoints");
    for controlador = controladores
        controlador = upper(controlador)
        load(path+controlador+"/dados1_1.mat")
        hold on;
        plot(dados(:,1), dados(:, 2), "LineWidth", 2,DisplayName=controlador);
        hold off;
        xlabel('$x_a$ [$m$]', "Interpreter", "latex");
        ylabel('$y_a$ [$m$]', "Interpreter", "latex");
        axis padded;
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
    end
    legend("Location","best")

elseif tipo == "custo"
    for controlador = controladores
        controlador = upper(controlador)
        load(path+controlador+"/dados1_1.mat")

        [~, er, etraj, eu, ev, tempo] = calculaErros(dados);
        eu = abs(eu);
        ev = abs(ev);
        tempo = tempo - tempo(1, end);

        subplot(2, 2, 1);
        hold on;
        h1 = plot(tempo, er, "LineWidth", 2);
        cor = get(h1, 'Color');
        hold off;

        ylabel('$E_r$ [$m$]', "Interpreter", "latex");
        axis padded;
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

        subplot(2, 2, 2);
        hold on;
        plot(tempo, etraj, 'Color', cor, "LineWidth", 2);
        hold off;

        ylabel('$E_{traj}$  [$m$]', "Interpreter", "latex");
        axis padded;
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');


        ylabel('$\|Y_{PI}\|$ [$V$]', "Interpreter", "latex");
        axis padded;
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
        subplot(2, 2, 3);
        hold on;
        plot(tempo, eu(1,:)+eu(2,:), "LineWidth", 2);

        hold off;
        xlabel('Tempo [$s$]', "Interpreter", "latex");
        ylabel('$Y_{PI l}$ [$V$]', "Interpreter", "latex");
        axis padded;
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');


        subplot(2, 2, 4);
        hold on;
        plot(tempo, ev, 'Color', cor, "LineWidth", 2);
        hold off;

        xlabel('Tempo [$s$]', "Interpreter", "latex");
        ylabel('$\|v_F\|$ [$m/s$]', "Interpreter", "latex");
        axis padded;
        set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

        drawnow;
    end
    lgd = legend(upper(controladores),"Orientation","horizontal","Box","off")

end

saveas(gcf, '../IMAGENS/CONTROLADOR/'+tipo+'_'+trajetoria+'.eps', 'epsc');
end
