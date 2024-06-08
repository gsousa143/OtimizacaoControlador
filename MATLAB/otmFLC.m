function fCusto = otmFLC(x,fis,Xinicial,T,tempoInicial,tempoMax,constantes,setpoints,isp,On)
dados = [];
[A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p] = calculaMatrizesModelo(constantes);
% bloco para verificar se ocorre algum erro no processo de otimização, tanto
%na integração numerica quando no controlador
try
    fis = attFLC(fis,x);
    dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,setpoints,isp,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);
    
    fCusto = calculaErros(dados); %calcula o funcional custo

    if On

    else
        clf;
        fprintf("\n x = ");
        fprintf("%2.5f, ", x);
        plotDadosTrajetoria(dados,true);
        %verifica se a trajetoria ultrapassou o tempo maximo proposto para
        %a otimização offline
        if dados(end,end)>=tempoMax
            %aplica penalidade
            fCusto = fCusto + 1000;
        end
    end
catch
    fCusto = 1e6;
    fprintf("\n f(x) = %2.5f", fCusto);
end




end



