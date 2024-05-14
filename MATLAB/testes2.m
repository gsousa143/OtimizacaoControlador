clc, clear, close all;
controladores = ["fbg", "fbm", "fbgo"]
trajetorias = ["zzx", "dia", "inf", "spr"]

Custo = [];
Controlador = [];
Trajetoria = [];
Er = [];
ETraj = [];
Eu = [];
Ev = [];
Tempo = [];
for trajetoria = trajetorias
    % figure
    pathDadosImagem = "../IMAGENS/CONTROLADOR/"+upper(trajetoria);
    for controlador = controladores
        pathDados = "../DADOS/CONTROLADOR/"+upper(trajetoria)+"/"+upper(controlador)+"/";
        plotDadosTrajetoria(pathDados+"dados1.csv");
        [fCusto,er,etraj,eu,ev,tempo,w] = calculaErros(readmatrix(pathDados+"dados1.csv"));
        Custo = [Custo;fCusto];
        Controlador = [Controlador;controlador];
        Trajetoria = [Trajetoria;trajetoria];
        Er = [Er;mean(er)];
        ETraj = [ETraj; mean(etraj)];
        Eu = [Eu; mean(abs(eu),"all")];
        Ev = [Ev; mean(0.15 - abs(ev))];
        Tempo = [Tempo;tempo(end)];





    end
    setpoints= readmatrix('../SETPOINTS/'+trajetoria+'.csv');
    hold on;
    plot(setpoints(:,1),setpoints(:,2), "x--", LineWidth=2)
    hold off
    title(trajetoria)
    legend([upper(controladores),"Setpoints"],Location="best",Interpreter="latex");
    set(gcf, 'Position', get(0, 'Screensize'));
    print(pathDadosImagem,"-dpng")
    clf;

end

res = table(Trajetoria,Controlador,Custo,Er,ETraj,Eu,Ev,Tempo)
writetable(res,"res.xlsx")

