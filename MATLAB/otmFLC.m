function fCusto = otmFLC(x,fis,Xinicial,T,tempoInicial,tempoMax,C,matrizSetpoints,isp,On)
dados = [];

% bloco para verificar se ocorre algum erro no processo de otimização, tanto
%na integração numerica quando no controlador
try
    fis = attFLC(fis,x);
    dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,C,matrizSetpoints,isp);
    
    fCusto = calculaErros(dados); %calcula o funcional custo

    if On
        % if norm(dados(1,1:2)-dados(end,1:2))<1e-4
        %     fCusto = fCusto + 1e3;
        % end
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



