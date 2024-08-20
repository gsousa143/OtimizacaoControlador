function fCusto = otmModelo(x,saidas,U,tempos,X0,constantes,on)

constantes = attConstantes(constantes,x);

try
    dados = trajetoriaModelo(constantes,U,tempos,X0);
    eR = ( saidas-dados(:,1:2) ).^2;
    fCusto = sqrt( sum(eR, 'all')/size(tempos,1) );
catch
    fCusto = Inf;
end


if ~on
    clf
    if ~isinf(fCusto)
        try
            plotDadosModelo(dados,saidas,tempos)
        catch

        end
    end
    fprintf('\nf(x)  %9.5g; \t x ',fCusto);
    fprintf('%9.5g,   ', x);
end

