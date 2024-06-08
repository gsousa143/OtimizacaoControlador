function dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,setpoints,ispInicial,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p)
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
%setpoints = Matriz com os pontos de referencia (setpoints) [nx2 float]
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
%       dados[i,1] Posição no Eixo X em metros
%       dados[i,2] Posição no Eixo Y em metros
%       dados[i,3] Angulo em relação ao Eixo X em radianos
%       dados[i,4] Velocidade da roda Direita em metros/segundo
%       dados[i,5] Velocidade da roda Esquerda em metros/segundo
%       dados[i,6] Integral do Erro de Velocidade da Roda Direita
%       dados[i,1] Integral do Erro de Velocidade da Roda Esquerda
%   dados[i,8:9] Sinal de Controle (velocidade das rodas desejada) na amostra i
%       dados[i,8] Setpoint de velocidade da roda Direita em metros/segundo
%       dados[i,9] Setpoint de velocidade da roda Esquerda em metros/segundo
%   dados[i,10:11] Setpoint na amostra i
%       dados[i,10] Setpoint de posição no Eixo X em metros
%       dados[i,11] Setpoint de posição no Eixo Y em metros
%   dados[i,12] Tempo em segundos da amostra i


%inicização de valores
dados = [];
tempo = tempoInicial;
X = Xinicial;
isp = ispInicial;
setpoint = setpoints(isp,:);

%gera um warning com string vazia (gambiara para captar warnings)
warning("");


while(1)    
        %controlador fuzzy
        u = flc(X',setpoint,fis);
    
        %incrementa a matriz de dados
        dados = [dados; [X', u', setpoint, tempo] ];
    
        %atualização do setpoint 
        distancia = norm(setpoint-X(1:2)');
        if  distancia < 0.035
            isp = isp+1;
            % verifica se o robô chegou na ultima referencia
            if isp>size(setpoints,1)
                break
            end
            setpoint = setpoints(isp,:);
        end
        
        %verificação das condições de parada
        if tempo>=tempoInicial+tempoMax
            break;
        end

        

        %Atualização do estado
            [tempo,X] = integracaoNumerica_mex(X,u,tempo,T,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);
        
        if lastwarn~="" % verifica se o ultimo warning foi o warning vazio gerado no inicio do codigo(gambiara para captar warnings)
            print(lastwarn);
            error("erro na execução da trajetoria");
        end
end
end

