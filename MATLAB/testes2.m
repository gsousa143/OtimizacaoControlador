clc, clear, close all;
controladores = ["fbmg", "fbm", "fbmo"]
trajetorias = ["zzx", "dia", "inf", "spr"]
for trajetoria = trajetorias
    trajetoria
    figure
    for controlador = controladores
        controlador
        path = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/"+upper(controlador)+"/";
        plotDadosTrajetoria(path+"dados1.csv");
    end
    setpoints= readmatrix('../SETPOINTS/'+trajetoria+'.csv');
    hold on;
    plot(setpoints(:,1),setpoints(:,2), "x--", LineWidth=0.25)
    hold off;
    legend([controladores,"setpoints"])
end