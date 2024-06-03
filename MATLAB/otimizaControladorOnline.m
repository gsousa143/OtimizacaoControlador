clc, clear;



T = 1e-2;

for controlador = ["fbgo"]
    for metodo = ["pso"]
        for trajetoria = ["spr"]



            %parametros para a otimizacao
            Totm = 6  %perido de tempo no qual a otimização em tempo real ocorerá
            itMax = Inf; %maximo de iteracoes
            NP = 8 %numero de particulas


            setpoins = readmatrix("..\SETPOINTS\"+upper(trajetoria)+".csv"); %referencias constantes
            load("..\CONSTANTES\const_otimo.mat"); % constantes do modelo unificado



            %definindo os limites para as variaveis de decisão
            limitesMax = ([.3,.3,.3,.5,.5])*pi;
            limitesMin = ([0.001, 0.001, 0.001, 0, 0])*pi;
            limites = [limitesMax;limitesMin];

            var = (limitesMax-limitesMin)*0.01



            path = "..\DADOS\CONTROLADOR\"+upper(trajetoria)+"\"+upper(controlador)+"_"+upper(metodo)+"\"
            mkdir(path);

            for teste = 1:5
                %inicia variaveis
                tempoInicial = 0; %tempo inicial = 0s
                fis = readfis("..\CONTROLADORES\"+upper(controlador)+".fis"); %Importa controlador
                xopt(1) = fis.input(1).mf(1).params(1);
                xopt(2) = fis.input(1).mf(2).params(1);
                xopt(3) = fis.input(1).mf(3).params(1);
                xopt(4) = fis.input(1).mf(7).params(2);
                xopt(5) = fis.input(1).mf(8).params(2);
                solucaoInicial = xopt % a solucao otima da "iteração 0" é o controlador original
                limites = [min(xopt+var,limitesMax);max(xopt-var,limitesMin)];
                % limites = [limitesMax;limitesMin];
                tempo = tempoInicial;

                v = [];

                voltaInicial = 1
                voltaFinal = 50

                % condição continuar o codigo apos pausa
                if voltaInicial > 1
                    load(path+"save.mat")
                    load(path+"dados"+string(teste)+"_"+string(voltaInicial-1)+".mat")
                    tempo = dados(end,end)

                end



                for volta = voltaInicial:voltaFinal

                    XInicial = zeros(7,1); %Estado Inicial
                    X = XInicial;
                    dados = []; %matriz de dados
                    isp = 1;
                    iotm = isp; %setpoint da otimizacao


                    setpoint = setpoins(isp,:);

                    while(1)
                        %estudos de caso
                        %constantes = estudosDeCaso(C,isp,"massa");

                        %controlador fuzzy
                        u = flc(X',setpoint,fis);

                        dados = [dados; [X', u', setpoint, tempo] ];


                        %atualização do setpoint e verificação das condições de parada
                        distancia = norm(setpoint-X(1:2)');
                        if  distancia < 0.035
                            isp = isp+1;
                            if (isp > size(setpoins, 1))
                                save(path+"save",'fis','xopt','solucaoInicial','limites')
                                break;
                            end
                            setpoint = setpoins(isp,:);
                        end



                        if mod(tempo,Totm) < T
                            %Ciclo de Otimização em tempo real
                            tic
                            limites = [min(xopt+var,limitesMax);max(xopt-var,limitesMin)];

                            
                            if metodo == "ga"
                                [fopt, xopt,iter,solucaoInicial] = ga(@(x) otmFLC(x,fis,XInicial,T,tempoInicial,Totm,constantes,setpoins,iotm,true), ... %OTIMIZAÇÃO
                                    limites, solucaoInicial,NP,itMax,Totm,false);
                            elseif metodo == "pso"
                                [fopt, xopt,iter,solucaoInicial] = pso(@(x) otmFLC(x,fis,XInicial,T,tempoInicial,Totm,constantes,setpoins,iotm,true), ... %OTIMIZAÇÃO
                                    limites, solucaoInicial,v,NP,itMax,Totm,false);
                            elseif metodo == "de"
                                [fopt, xopt,iter,solucaoInicial] = de(@(x) otmFLC(x,fis,XInicial,T,tempoInicial,Totm,constantes,setpoins,iotm,true), ... %OTIMIZAÇÃO
                                    limites, solucaoInicial,NP,itMax,Totm,false);
                            end
                            writematrix([iter,toc,fopt,xopt,volta],path+"otm"+string(teste)+".csv",'WriteMode','append');
                            clf;
                            plotDadosTrajetoria(dados);

                            t0 = tempo;
                            fis = attFLC(fis,xopt);
                            iotm = isp;
                            XInicial = X;

                            %reinicilização do enxame/populacao realimentando somente a
                            %solucao otima do ciclo anterior

                            if abs(xopt-solucaoInicial) < var*1e-1
                                solucaoInicial = xopt
                                v = [];
                            end

                        end


                        %Atualização do estado
                        [tempo,X] = integracaoNumerica_mex(X,u,tempo,T,constantes);

                    end




                    fCusto = calculaErros(dados);
                    plotDadosTrajetoria(dados,true);

                    custos = [volta,fCusto];
                    writematrix(custos,path+"custos"+string(teste)+".csv",'WriteMode','append'); %salva os custos em um arquivo de texto
                    save(path+"dados"+string(teste)+"_"+string(volta),'dados','custos'); %salva os dados da volta em um arquivo
                    
                end
            end
        end
    end
end %controlador
