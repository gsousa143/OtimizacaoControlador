clc, clear;






Setpoints = readmatrix("..\SETPOINTS\zzx.csv"); %referencias constantes
C = readmatrix("..\CONSTANTES\constantesOpt.csv");
constantes = C;
T = 1e-2;


%pesos para o calculo do funcional custo


%parametros para a otimizacao
Totm = 3 %perido de tempo no qual a otimização em tempo real ocorerá
parametros.itMax = Inf;
parametros.tempoMax = Totm;
parametros.NP =  5;
parametros.info = 0; 
parametros.cP = 1.49; %PSO
parametros.cS = 1.49; %PSO
parametros.Fp = 1.8; %DE
parametros.cr = 0.3; %DE/GA
parametros.betta = 0.3; %GA
parametros.fM = 0.9; %GA
parametros.path = "";





%definindo os limites para as variaveis de decisão
delta = 0.01;
limitesMax = [0.06,0.06,0.3, 0.25+delta, 0.5-delta]*pi;
limitesMin = [0.003,0.003,0.03, 0+delta, 0.25-delta]*pi;
limites = [limitesMax;limitesMin]

var = (limitesMax-limitesMin)/100;



path = "..\DADOS\FBMO\DE\"
for teste = 1:10
    tempoInicial = 0;
    fis = readfis("../CONTROLADORES\fbmo.fis"); %CONTROLADOR
    xopt(1) = fis.input(1).mf(1).params(1);
    xopt(2) = fis.input(1).mf(2).params(1);
    xopt(3) = fis.input(1).mf(3).params(1);
    xopt(4) = fis.input(1).mf(7).params(2);
    xopt(5) = fis.input(1).mf(8).params(2);
    solucaoInicial = xopt
  

    tempo = tempoInicial;

    for laps = 1:50

        XInicial = zeros(7,1);
        X = XInicial;
        dados = [];
        isp = 1;
        iotm = isp;


        setpoint = Setpoints(isp,:);

        while(1)
            %estudos de caso
            % constantes = atrito(C,X(1));
            % constantes = massa(C,isp);
            % constantes = bateria(C,tempo);

            %controlador fuzzy
            u = FLC(X',setpoint,fis,constantes(1),constantes(2));

            dados = [dados; [X', u', setpoint, tempo] ];


            %atualização do setpoint e verificação das condições de parada
            distancia = norm(setpoint-X(1:2)');
            if  distancia < 0.0875
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
                 
                if max(abs(mean(solucaoInicial)./xopt-1)) < 1e-6
                    solucaoInicial = xopt;
                end

                [fopt, xopt,iter,solucaoInicial] = DE(@(x) otmFLC(x,fis,XInicial,T,tempoInicial,Totm,C,Setpoints,iotm,true), ... %OTIMIZAÇÃO
                    limites, solucaoInicial,parametros);

                writematrix([iter,toc,fopt,xopt],path+"otm"+string(teste)+"_"+string(laps)+".csv",'WriteMode','append');
                plotDDMR(dados,T,fis);
                
                if 
                t0 = tempo;
                fis = attFLC(fis,xopt);
                iotm = isp;
                XInicial = X;
                
            end


            %Atualização do estado
            [tempo,X] = IntegracaoNumerica_mex(X,u,tempo,T,constantes);

        end




        fCusto = CalculaErros(dados);
        fprintf('\n\nlap %9.4g \t custo %9.4g \t\n',laps,fCusto);

        writematrix(dados,path+"dados"+string(teste)+"_"+string(laps)+".csv");
        writematrix([laps, fCusto],path+"custo"+string(teste)+".csv",'WriteMode','append');
        writematrix([solucaoInicial;xopt],path+"saveOtm"+string(teste)+"_"+string(laps)+".csv");
    end
end


