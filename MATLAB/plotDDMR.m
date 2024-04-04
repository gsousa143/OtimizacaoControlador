function plotDDMR(dados,T,fis)
clf;
%verifica se estou passando uma string com o caminho pros dados ou uma matriz de dados
if isa(dados,"string")
    dados = readmatrix(dados);
end

[fCusto,er,etraj,eu,ev,tempo, w] = calculaErros(dados);
n = size(dados,1);
tempo = tempo-tempo(1,end);

subplot(3,2,1);
plot(dados(:,1),dados(:,2),"r",dados(:,10),dados(:,11),"--b","LineWidth",1);
title("Trajectory - Fcost:"+string(fCusto))
legend(["Dynamic Model","Reference"],'Location','best','Box','off');
xlabel("x Position [$m$]","Interpreter","latex");
ylabel("y Position [$m$]","Interpreter","latex");
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')




subplot(3,2,2);
% [xOut,yOut] = plotmf(fis,'input',1);
% plot(xOut,yOut,"LineWidth",1)


plotmf(fis,'input',1);
title("FLC Angular Error Input");
xlabel('Angular error [$rad$]',"Interpreter","latex")
ylabel('Membership',"Interpreter","latex")

axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')





subplot(3,2,3);
plot(tempo,er,"LineWidth",1)
title("Er: "+string( w(1)*sqrt(mean(er.^2)) ) )

ylabel('Euclidian Error [$m$]',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')



subplot(3,2,4);
plot(tempo,etraj,"LineWidth",1)
title("Etraj: "+string( w(2)*sqrt(mean(etraj.^2)) ) )

ylabel('Trajectory Error [$m$]',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')



subplot(3,2,5);
plot(tempo,eu,"LineWidth",1)
title("Eu: "+string( w(3)*mean(eu) ) )

xlabel('Time [$s$]',"Interpreter","latex")
ylabel('Control Effort [$V$]',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')


subplot(3,2,6);
plot(tempo,ev,"LineWidth",1)
title("Ev: "+string( w(4)*sqrt((mean(0.15-ev).^2)) ) )

xlabel('Time [$s$]',"Interpreter","latex")
ylabel('Linear Velocity [$m/s$]',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')





% set(gcf, 'WindowState', 'maximized'); %maximizar janela de plot
drawnow;

end

