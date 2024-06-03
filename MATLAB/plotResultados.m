clc
clear
close all



figure;
plotCustosOnline(["","DE","GA","PSO"], "SPR", "FBGO",1)

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
                custos = [custos;custo(:,2)];

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







function plotTrajetoriaQbot(path)

end


function plotControladores()
path = "../CONTROLADORES/";
end
