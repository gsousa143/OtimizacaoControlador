clc, clear, close all;
hold on;
% ------------------------------------------------
% MODELO
% ------------------------------------------------
path = "../DADOS/MODELO/"
d0 = readmatrix(path+"dados.csv");

dopt = readmatrix(path+"dados_opt.csv");
d0 = [zeros(1,2);d0];
dopt = [zeros(1,2);dopt];

load(path+"saix.mat");
load(path+"saiy.mat");
plot(d0(:,1),d0(:,2),dopt(:,1),dopt(:,2),saix(:,2),saiy(:,2),"LineWidth",1);
legend(["Estimated","Optimum","Qbot"],'Location','best','Box','off');
xlabel("x Position [$m$]","Interpreter","latex");
ylabel("y Position [$m$]","Interpreter","latex");
set(gca(),"fontsize",14,'FontName', 'Times New Roman')
drawnow;

estimado = sqrt(mean((saix(:,2)-d0(:,1)).^2 + (saiy(:,2)-d0(:,2)).^2));
otimo = sqrt(mean((saix(:,2)-dopt(:,1)).^2 + (saiy(:,2)-dopt(:,2)).^2));
figure;


% -----------------------------------------------
% CONTROLADOR
% -----------------------------------------------
path = "../CONTROLADORES/";
fis = readfis(path+"fbm.fis");

subplot(2,2,1);
[xOut,yOut] = plotmf(fis,'input',1);
plot(xOut,yOut,"LineWidth",1)

xlabel('Angular error [$rad$]',"Interpreter","latex")
ylabel('Membership',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')

subplot(2,2,2);
[xOut,yOut] = plotmf(fis,'input',2);
plot(xOut(1:30,:),yOut(1:30,:),"LineWidth",1)


xlabel('Euclidian Distance [$m$]',"Interpreter","latex")
ylabel('Membership',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')

subplot(2,2,3);
[xOut,yOut] = plotmf(fis,'output',1);
plot(xOut,yOut,"LineWidth",1);



xlabel('Linear Velocity [$m/s$]',"Interpreter","latex")
ylabel('Membership',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')


subplot(2,2,4);
[xOut,yOut] = plotmf(fis,'output',2);
plot(xOut,yOut,"LineWidth",1);
set(gca(),"fontsize",14,'FontName', 'Times New Roman')


xlabel('Angular Velocity [$rad/s$]',"Interpreter","latex")
ylabel('Membership',"Interpreter","latex")
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')
drawnow;
figure;

% ------------------------------------------------
% TRAJETORIA
% ------------------------------------------------
path = "../DADOS/"
d0 = readmatrix(path+"FBM/dados1.csv");
dopt = readmatrix(path+"FBMO/dados1.csv");
zzx = readmatrix("../SETPOINTS/zzx.csv");

plot(d0(:,1),d0(:,2),"r",dopt(:,1),dopt(:,2),"m",zzx(:,1),zzx(:,2),"--xb","LineWidth",1);
legend(["FBM","FBMO","Reference"],'Location','best','Box','off');
xlabel("x Position [$m$]","Interpreter","latex");
ylabel("y Position [$m$]","Interpreter","latex");
set(gca(),"fontsize",14,'FontName', 'Times New Roman')
drawnow;
figure;

%------------------------------------------------
% %ERROS
[fCusto0,er0,etraj0,eu0,ev0,tempo0,w] = CalculaErros(d0);
[fCustoopt,eropt,etrajopt,euopt,evopt,tempoopt] = CalculaErros(dopt);
subplot(4,1,1)
plot(tempo0,er0,tempoopt,eropt,"LineWidth",1);
title("Er")
ylabel('Euclidian Error [$m$]',"Interpreter","latex")
axis padded
legend(["FBM","FBMO"],Box="off")
set(gca(),"fontsize",14,'FontName', 'Times New Roman')

subplot(4,1,2)
plot(tempo0,etraj0,tempoopt,etrajopt,"LineWidth",1);
title("Etraj")
ylabel('Trajectory Error [$m$]',"Interpreter","latex")
axis padded
legend(["FBM","FBMO"],Box="off")
set(gca(),"fontsize",14,'FontName', 'Times New Roman')

subplot(4,1,3)
plot(tempo0,eu0,tempoopt,euopt,"LineWidth",1);
title("Eu")
ylabel('Control Effort [$V$]',"Interpreter","latex")
axis padded
legend(["FBM","FBMO"],Box="off")
set(gca(),"fontsize",14,'FontName', 'Times New Roman')

subplot(4,1,4)
plot(tempo0,ev0,tempoopt,evopt,"LineWidth",1);
title("Ev")
ylabel('Linear Velocity [$m/s$]',"Interpreter","latex")
xlabel("Time [$s$]","Interpreter","latex");
axis padded
legend(["FBM","FBMO"],Box="off")
set(gca(),"fontsize",14,'FontName', 'Times New Roman')

drawnow;





