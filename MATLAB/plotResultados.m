clc
clear
close all


% plotSomenteTrajetorias(["FBg","OFBg","FBm"], ["zzx","dia","cir","inf"])

% plotControlador(["FBm","FBg","OFBg"])

% plotTrajetorias(["FBg","OFBg","FBm"],"zzx")

 plotTrajetoriamodelo("fbm_zzx")


% plotSomenteTrajetoriamodelo("ofbg",["zzx","dia","cir","inf"])

function plotTrajetorias(controladores, trajetoria)
t = tiledlayout(1,5,'TileSpacing','Compact','Padding','Compact');
ax1 = nexttile();
ax2 = nexttile();
ax3 = nexttile();
ax4 = nexttile();
ax5 = nexttile();

% path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/";
path = "../DADOS/MODELO/dados_qbot_";
load("../SETPOINTS/"+lower(trajetoria)+".mat")



for controlador = controladores
    % load(path+controlador+"/dados1_1.mat")
    load(path+lower(controlador)+"_"+lower(trajetoria))
    hold(ax1, "on");
    plot(ax1,dados(:,1), dados(:, 2),LineWidth=1);
    hold(ax1, "off");
    dados = [dados, (0:0.01:t_final)'];
    [fCusto, er, etraj, eu, ea, tempo, w] = calculaErros(dados);
    tempo = tempo - tempo(1, end);
    hold(ax2,"on")
    plot(ax2, tempo, er,LineWidth=1)
    hold(ax2,"off")
    hold(ax3,"on")
    plot(ax3, tempo, etraj,LineWidth=1)
    hold(ax3,"off")
    hold(ax4,"on")
    plot(ax4, tempo, abs(eu(:,1))+abs(eu(:,2)),LineWidth=1)
    hold(ax4,"off")
    hold(ax5,"on")
    plot(ax5, tempo, ea,LineWidth=1)
    hold(ax5,"off")

end

hold(ax1, "on");
plot(ax1,setpoints(:,1),setpoints(:,2),"x--",LineWidth=1);
hold(ax1, "off");

title(ax1, 'a)')
xlabel(ax1, '$x_a$ [m]', 'Interpreter', 'latex');
ylabel(ax1, '$y_a$ [m]', 'Interpreter', 'latex');
set(ax1, 'fontsize', 12, 'FontName', 'Times New Roman');


title(ax2, 'b)')
xlabel(ax2, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax2, '$E_r$ [m]', 'Interpreter', 'latex');
set(ax2, 'fontsize', 12, 'FontName', 'Times New Roman');

title(ax3, 'c)')
xlabel(ax3, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax3, '$E_{traj}$ [m]', 'Interpreter', 'latex');
set(ax3, 'fontsize', 12, 'FontName', 'Times New Roman');

title(ax4, 'd)')
xlabel(ax4, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax4, '$||\bar{\eta}||$ [m/s]', 'Interpreter', 'latex');
set(ax4, 'fontsize', 12, 'FontName', 'Times New Roman');

title(ax5, 'e)')
xlabel(ax5, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax5, '$a$ [m/s$^2$]', 'Interpreter', 'latex');
set(ax5, 'fontsize', 12, 'FontName', 'Times New Roman');

lgd = legend(ax1,[controladores, "Trajetória de Referência"], box="off", Orientation="horizontal",FontSize=12,FontName="Times New Roman");
lgd.Layout.Tile = 'south';

% legend("Location","best")
% saveas(gcf, '../IMAGENS/CONTROLADOR/'+tipo+'_'+trajetoria+'.eps', 'epsc');
end

function plotTrajetoriamodelo(trajetoria)
t = tiledlayout(1,4,'TileSpacing','Compact','Padding','Compact');

% First Tile
ax1 = nexttile();
% Second Tile
ax2 = nexttile();

ax3 = nexttile();
% Fourth Tile
ax4 = nexttile();


load("../DADOS/MODELO/dados_qbot_" + trajetoria)
tempo = 0:0.01:(size(dados,1)-1)*0.01;
qbot = dados;



for tipo = ["inicial", "otimo"]
    % Update First Tile
    hold(ax1, 'on');
    load("../DADOS/MODELO/dados_modelo_" + tipo + "_" + trajetoria);
    grafico = plot(ax1, dados(:,1), dados(:,2),LineWidth=1);
    cor = get(grafico, 'Color');
    er = sqrt((qbot(:,1) - dados(:,1)).^2 + (qbot(:,2) - dados(:,2)).^2);
    hold(ax1, 'off');


    hold(ax2, 'on');
    plot(ax2, tempo, er, 'DisplayName', upper(tipo), 'Color', cor,LineWidth=1);
    hold(ax2, 'off');

    % Second Tile update
    hold(ax3, 'on');
    plot(ax3, tempo, dados(:,4),LineWidth=1);
    hold(ax3, 'off');

    % Third Tile update
    hold(ax4, 'on');
    plot(ax4, tempo, dados(:,5),LineWidth=1);
    hold(ax4, 'off');
end


hold(ax1, 'on');
plot(ax1, qbot(:,1), qbot(:,2),"--",LineWidth=1)
hold(ax1, 'off');


hold(ax3, 'on');
plot(ax3, tempo, qbot(:,4),"--");
hold(ax3, 'off');


hold(ax4, 'on');
plot(ax4, tempo, qbot(:,5),"--");
hold(ax4, 'off');

% Customize Titles and Labels
title(ax1, 'a)')
xlabel(ax1, '$x_a$ [m]', 'Interpreter', 'latex');
ylabel(ax1, '$y_a$ [m]', 'Interpreter', 'latex');
set(ax1, 'fontsize', 12, 'FontName', 'Times New Roman');


title(ax2, 'b)')
xlabel(ax2, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax2, 'Erro [m]', 'Interpreter', 'latex');
set(ax2, 'fontsize', 12, 'FontName', 'Times New Roman');

title(ax3, 'c)')
xlabel(ax3, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax3, '$\varphi_r$ [m/s]', 'Interpreter', 'latex');
set(ax3, 'fontsize', 12, 'FontName', 'Times New Roman');

title(ax4, 'd)')
xlabel(ax4, 'Tempo [s]', 'Interpreter', 'latex');
ylabel(ax4, '$\varphi_l$ [m/s]', 'Interpreter', 'latex');
set(ax4, 'fontsize', 12, 'FontName', 'Times New Roman');

lgd = legend(["Inicial","Ótimo","Qbot2"], box="off", Orientation="horizontal",FontSize=12,FontName="Times New Roman");
lgd.Layout.Tile = 'south';
drawnow;
end


function plotControlador(controladores)

hold on;
n = size(controladores,2);
i=1;
for controlador = controladores
    fis = readfis("../CONTROLADORES/"+controlador+".fis")
    subplot(n,1,i)
    plotmf(fis,"input",1,1000);
    i = i+1;
end
end




function plotSomenteTrajetorias(controladores, trajetorias)
t = tiledlayout(2,4,'TileSpacing','Compact','Padding','Compact');

for trajetoria = trajetorias
% path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/";
path = "../DADOS/MODELO/dados_qbot_";
load("../SETPOINTS/"+lower(trajetoria)+".mat")
nexttile()
hold on;
for controlador = controladores
    % load(path+controlador+"/dados1_1.mat")
    load(path+lower(controlador)+"_"+lower(trajetoria))
    % hold(ax1, "on");
    plot(dados(:,1), dados(:, 2),LineWidth=1);
    % hold(ax1, "off");
    dados = [dados, (0:0.01:t_final)'];
    trajetoria+controlador
    plotDadosTrajetoria(dados,true);

end

plot(setpoints(:,1),setpoints(:,2),"x--",LineWidth=1);
title(upper(trajetoria))
xlabel("$x_a$ [m]", Interpreter="latex")
ylabel("$y_a$ [m]", Interpreter="latex")
set(gca, 'fontsize', 12, 'FontName', 'Times New Roman')
axis padded
hold off;
end

lgd = legend([controladores, "Trajetória de Referência"], box="off", Orientation="horizontal",FontSize=12,FontName="Times New Roman");
lgd.Layout.Tile = 'south';
for trajetoria = trajetorias
% path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/";
path = "../DADOS/MODELO/dados_qbot_";
load("../SETPOINTS/"+lower(trajetoria)+".mat")
nexttile()
hold on;
for controlador = controladores
    % load(path+controlador+"/dados1_1.mat")
    load(path+lower(controlador)+"_"+lower(trajetoria))
    % hold(ax1, "on");
    plot((0:0.01:t_final)',abs(dados(:,8))+abs(dados(:,9)),LineWidth=1)
    % hold(ax1, "off");

end
% title(upper(trajetoria))
xlabel("Tempo (s)", Interpreter="latex")
ylabel("$||\bar{\eta}||$ [m/s]", Interpreter="latex")
set(gca, 'fontsize', 12, 'FontName', 'Times New Roman')
axis padded
hold off;
end
end


    


function plotSomenteTrajetoriamodelo(controlador,trajetorias)
t = tiledlayout(1,4,'TileSpacing','Compact','Padding','Compact');


for trajetoria = trajetorias
nexttile()


hold on
load("../DADOS/MODELO/dados_qbot_" + controlador + "_" + trajetoria)
tempo = 0:0.01:(size(dados,1)-1)*0.01;
qbot = dados;
plot(qbot(:,1), qbot(:,2),LineWidth=1)
hold off


for tipo = ["inicial", "otimo"]
    % Update First Tile
    hold on
    load("../DADOS/MODELO/dados_modelo_" + tipo + "_" + controlador + "_" + trajetoria);
    plot(dados(:,1), dados(:,2),LineWidth=1);
    % cor = get(grafico, 'Color');
    % er = sqrt((qbot(:,1) - dados(:,1)).^2 + (qbot(:,2) - dados(:,2)).^2);
    hold off

end

% Customize Titles and Labels
title(upper(trajetoria),'fontsize', 12, 'FontName', 'Times New Roman')
xlabel('$x_a$ [m]', 'Interpreter', 'latex','fontsize', 12, 'FontName', 'Times New Roman');
ylabel('$y_a$ [m]', 'Interpreter', 'latex','fontsize', 12, 'FontName', 'Times New Roman');

end
lgd = legend(["Qbot2","Inicial","Ótimo"], box="off", Orientation="horizontal",FontSize=12,FontName="Times New Roman");
lgd.Layout.Tile = 'south';
drawnow;
end
