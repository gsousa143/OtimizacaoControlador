function dados = trajetoriaModelo(constantes,U,tempos,X0)
[A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p] = calculaMatrizesModelo(constantes);
X = X0;
i=2;
periodo = tempos(2)-tempos(1);
dados = zeros(size(tempos,1),7);
warning("");
dados(i,:) = X;

while(i<size(tempos,1)+1)
    u = U(i,:)';
    [~,X] = integracaoNumerica_mex(X,u,tempos(i),periodo,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p);
    dados(i,:) = X;
    i = i+1;

    if lastwarn~="" % verifica se o ultimo warning foi o warning vazio gerado no inicio do codigo(gambiara para captar warnings)
        print(lastwarn);
        error("erro na execução da trajetoria");
    end
end
dados = [dados,tempos];
end

