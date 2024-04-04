function dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,Constantes,Setpoints,ispInicial)
%SIMULA TRAJETORIA EXECUTADA PELO DDMR
% 
% 
% 
%**Parametros de Entrada**
%
%fis = controlador de trajetoria fuzzy [mamfis]
% 
%Xinicial = Estado Inicial [1x7]
% 
%T = Periodo de amostragem [1x1]
%
%tempoInicial = inicialização do tempo em segundos [1x1 float]
% 
%tempoMax = Tempo maximo em segundos onde a trajetoria é executada [1x1 float]
%   serve tambem como criterio de paradas para trajetorias que não 
%   atingem o ultimo setpoint. Obs o tempoMax para a execução da
%   trajetoria é computado como tempoInicial+tempoMax
%
%Constantes = Vetor com os parametros utlizados no modelo matematico [1x10 float]
%   em espaço de estados. Mais informações sobre o a representação de cada
%   constante consultar "help ModeloUnificado"
%
%Setpoints = Matriz com os pontos de referencia (setpoints) [nx2 float]
%   Onde cada linha representa um ponto no espaco no formato x_sp, y_sp
%   n o numero de setpoints
% 
%ispInicial = Indice que indica qual será o setpoint inicial [1x1 inteiro]
% 
% 
% 
% **Saidas**
% 
% dados = Matriz com os dados da execução da trajetoria. [nx17 float]
%   n = numero de amostras
%   dados[i,1:7] Estado na amostra i
%   dados[i,8:9] Sinal de Controle (velocidade das rodas desejada) na amostra i
%   dados[i,10:11] Setpoint na amostra i
%   dados[i,12] Tempo em segundos da amostra i


%inicização de valores

dados = [];
constantes = Constantes;
tempo = tempoInicial;
X = Xinicial;
isp = ispInicial;
setpoint = Setpoints(isp,:);


while(1)
        %constantes = estudosDeCaso(Constantes,isp,"massa");
    
        %controlador fuzzy
        u = flc(X',setpoint,fis,constantes(1),constantes(2));
    
        dados = [dados; [X', u', setpoint, tempo] ];
    
    
        %atualização do setpoint 
        distancia = norm(setpoint-X(1:2)');
        if  distancia < 0.035 && isp
            isp = isp+1;
            if isp>size(Setpoints,1)
                break
            end
            setpoint = Setpoints(isp,:);
        end
        
        %verificação das condições de parada
        if tempo>=tempoInicial+tempoMax
            break;
        end

        %plot da trajetoria em "tempo real"
        % if mod(tempo,5) < T
        %     X(1:2)
        %     clf;
        %     plot(dados(:,10),dados(:,11),"gx--",dados(:,1),dados(:,2),"b-");
        %     drawnow;
        % end
    
        %Atualização do estado
        [tempo,X] = integracaoNumericaMex(X,u,tempo,T,constantes);
end
    
end

