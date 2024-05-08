clc, clear;



T = 1e-2;

controlador = "fbmg";
trajetoria = "zzx";
metodo = "de";



%parametros para a otimizacao
Totm = 6 %perido de tempo no qual a otimização em tempo real ocorerá
itMax = Inf;
NP =  6;



Setpoints = readmatrix("..\SETPOINTS\"+upper(trajetoria)+".csv"); %referencias constantes
C = readmatrix("..\CONSTANTES\constantesOpt.csv");
constantes = C;



%definindo os limites para as variaveis de decisão
limitesMax = ([.2,.2,.2,.3,.5])*pi;
limitesMin = ([0.0001, 0.0001, 0.0001, 0, .2])*pi;
limites = [limitesMax;limitesMin]

var = (limitesMax-limitesMin)/100;



path = "..\DADOS\CONTROLADOR\"+upper(trajetoria)+"\"+upper(controlador)+upper(metodo)+"\"
mkdir(path);

for teste = 1
    tempoInicial = 0;
    fis = readfis("..\CONTROLADORES\"+upper(controlador)+".fis"); %CONTROLADOR
    xopt(1) = fis.input(1).mf(1).params(1);
    xopt(2) = fis.input(1).mf(2).params(1);
    xopt(3) = fis.input(1).mf(3).params(1);
    xopt(4) = fis.input(1).mf(7).params(2);
    xopt(5) = fis.input(1).mf(8).params(2);
    solucaoInicial = xopt

    tempo = tempoInicial;



    voltaInicial = 1;
    voltaFinal = 80;



    for volta = voltaInicial:voltaFinal
        
        XInicial = zeros(7,1);
        X = XInicial;
        dados = [];
        isp = 1;
        iotm = isp;


        setpoint = Setpoints(isp,:);

        while(1)
            %estudos de caso
            %constantes = estudosDeCaso(Constantes,isp,"massa");

            %controlador fuzzy
            u = flc(X',setpoint,fis);

            dados = [dados; [X', u', setpoint, tempo] ];


            %atualização do setpoint e verificação das condições de parada
            distancia = norm(setpoint-X(1:2)');
            if  distancia < 0.035
                isp = isp+1;
                if (isp > size(Setpoints, 1))
                    break;
                end
                setpoint = Setpoints(isp,:);
            end


            
            if mod(tempo,Totm) < T
                %%Ciclo de Otimização em tempo real
                tic
                limites(1,:) = min(xopt+var,limitesMax);
                limites(2,:) = max(xopt-var,limitesMin);
                 
                if max(abs(mean(solucaoInicial)./xopt-1)) < 1e-3
                    solucaoInicial = xopt;
                end

                [fopt, xopt,iter,solucaoInicial] = de(@(x) otmFLC(x,fis,XInicial,T,tempoInicial,Totm,C,Setpoints,iotm,true), ... %OTIMIZAÇÃO
                    limites, solucaoInicial,NP,itMax,Totm,false);

                writematrix([iter,toc,fopt,xopt],path+"otm"+string(teste)+"_"+string(volta)+".csv",'WriteMode','append');
                clf;
                plotDadosTrajetoria(dados);
                
                t0 = tempo;
                fis = attFLC(fis,xopt);
                iotm = isp;
                XInicial = X;
                
            end


            %Atualização do estado
            [tempo,X] = integracaoNumericaMex(X,u,tempo,T,constantes);

        end




        fCusto = calculaErros(dados);
        plotDadosTrajetoria(dados,true);

        writematrix(dados,path+"dados"+string(teste)+"_"+string(volta)+".csv");
        writematrix([volta, fCusto],path+"custo"+string(teste)+".csv",'WriteMode','append');
    end
end


