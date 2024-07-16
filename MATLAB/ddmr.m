function dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,setpoints,ispInicial,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p)
%SIMULA TRAJETORIA EXECUTADA PELO DDMR
% 

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
        u = flc(X',setpoint,fis,R,L);
    
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
        % plotTrajetoria(dados)
        %Atualização do estado
            [tempo,X] = integracaoNumerica(X,u,tempo,T,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);

        if lastwarn~="" % verifica se o ultimo warning foi o warning vazio gerado no inicio do codigo(gambiara para captar warnings)
            print(lastwarn);
            error("erro na execução da trajetoria");
        end
end
end



% function dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,setpoints,ispInicial,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p)
% %SIMULA TRAJETORIA EXECUTADA PELO DDMR
% % 
% 
% %inicização de valores
% dados = [];
% tempo = tempoInicial;
% X = Xinicial;
% isp = ispInicial;
% setpoint = setpoints(isp,:);
% 
% %gera um warning com string vazia (gambiara para captar warnings)
% warning("");
% 
% 
% while(1)    
%         %controlador fuzzy
%         u = flc(X',setpoint,fis);
% 
%         %incrementa a matriz de dados
%         dados = [dados; [X', u', setpoint, tempo] ];
% 
%         %atualização do setpoint 
%         distancia = norm(setpoint-X(1:2)');
%         if  distancia < 0.035
%             isp = isp+1;
%             % verifica se o robô chegou na ultima referencia
%             if isp>size(setpoints,1)
%                 break
%             end
%             setpoint = setpoints(isp,:);
%         end
% 
%         %verificação das condições de parada
%         if tempo>=tempoInicial+tempoMax
%             break;
%         end
%         plotTrajetoria(dados)
%         %Atualização do estado
%             [tempo,X] = integracaoNumerica(X,u,tempo,T,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);
% 
%         if lastwarn~="" % verifica se o ultimo warning foi o warning vazio gerado no inicio do codigo(gambiara para captar warnings)
%             print(lastwarn);
%             error("erro na execução da trajetoria");
%         end
% end
% end


