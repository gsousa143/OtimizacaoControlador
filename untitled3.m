clear
clc
close all;
% hold on;
trajetoria = "zzx";
load("CONSTANTES/const_inicial")
load('DADOS\MODELO\dados_qbot_fbg_zzx.mat')


ddmr = DDMR;
ddmr.setup();
ddmr.setState(zeros(7,1));
ddmr.setConstants(constantes);


optM = OptModel;
optM.setup();
optM.setParams(constantes);

n_data = optM.T_otm/ddmr.T;
for nLaps = 1:20
    data = [];

    figure
    drawnow;
    ddmr.setState(zeros(7,1));

    for i=1:n_data:size(dados,1)-n_data

        initial_state = ddmr.getState();

        u = dados(i:i+n_data,8:9);
        qbot_data = dados(i:i+n_data,1:2);
        initial_state(1:2,1) = qbot_data(1,:)';

        for j = 1:n_data
            X = ddmr.step(u(j,:)');
            data = [data;X];

        end
        
        constantes = optM.step(u,qbot_data,constantes,initial_state)
        ddmr.setConstants(constantes);
    end
    plot(data(:,1),data(:,2),dados(:,1),dados(:,2))
    title("volta "+string(nLaps))
    legend(["MODELO","QBOT"])
    xlabel("$x_a$ [m]", Interpreter="latex")
    ylabel("$y_a$ [m]", Interpreter="latex")
    set(gca, 'fontsize', 12, 'FontName', 'Times New Roman')
    drawnow;
    saveas(gcf, string(nLaps)+'.jpeg');


end


