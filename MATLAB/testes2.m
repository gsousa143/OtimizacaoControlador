clc, clear, close all;
controladores = ["fbg", "fbm", "fbmo"]
trajetorias = ["zzx", "dia", "inf", "spr"]
for trajetoria = trajetorias
    % figure
    pathDadosImagem = "../IMAGENS/CONTROLADOR/"+upper(trajetoria);
    for controlador = controladores
        pathDados = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/"+upper(controlador)+"/";
        


        plotDadosTrajetoria(pathDados+"dados1.csv");       

    end
        setpoints= readmatrix('../SETPOINTS/'+trajetoria+'.csv');
        hold on;
        plot(setpoints(:,1),setpoints(:,2), "x--", LineWidth=2)
        hold off;
        legend([upper(controladores),"Setpoints"],Location="best",Interpreter="latex");
        print(pathDadosImagem,"-dpng")
        clf;

end