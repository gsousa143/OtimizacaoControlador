function dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,setpoints,ispInicial,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p)
%SIMULA TRAJETORIA EXECUTADA PELO DDMR
% 

%inicização de valores
dados = [];
tempo = tempoInicial;
X = Xinicial;
i_sp = ispInicial;
setpoint = setpoints(i_sp,:);
N_sp = size(setpoints,1);

%gera um warning com string vazia (gambiara para captar warnings)
warning("");


while(1)    
        %controlador fuzzy
        u = flc(X',setpoint,fis,R,L);
    
        %incrementa a matriz de dados
        dados = [dados; [X', u', setpoint, tempo] ];
    
        %atualização do setpoint 
        distancia = norm(setpoint-X(1:2)');
        if  (distancia < 0.035) & (i_sp<N_sp)
            i_sp = i_sp+1;
            setpoint = setpoints(i_sp,:);
        end
        
        %verificação das condições de parada
        if tempo>=tempoInicial+tempoMax
            break;
        end

        % plotTrajetoria(dados)

        
        %Atualização do estado
            [tempo,X] = integracaoNumerica_mex(X,u,tempo,T,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);
end
end

