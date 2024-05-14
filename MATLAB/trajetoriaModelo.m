function dados = trajetoriaModelo(C,U,tempos,X0)
%TRAJETORIAMODELO Summary of this function goes here
%   Detailed explanation goes here
X = X0;
i=2;
T = tempos(2)-tempos(1);
dados = zeros(size(tempos,1),7);
warning("");
dados(i,:) = X;

while(i<size(tempos,1)+1)
    u = U(i,:)';
    [~,X] = integracaoNumericaMex(X,u,tempos(i),T,C);
    dados(i,:) = X;
    i = i+1;

    if lastwarn~="" % verifica se o ultimo warning foi o warning vazio gerado no inicio do codigo(gambiara para captar warnings)
        print(lastwarn);
        error("erro na execução da trajetoria");
    end
end
dados = [dados,tempos];
end

