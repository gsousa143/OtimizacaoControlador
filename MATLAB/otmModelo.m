function fCusto = otmModelo(x,saidas,U,tempos,X0,C,on)

C = attConstantes(C,x,1:12);


dados = trajetoriaModelo(C,U,tempos,X0);


eR = ( saidas-dados(:,1:2) ).^2;

fCusto = sqrt( sum(eR, 'all')/size(tempos,1) );
if ~on
    clf
    plotDadosModelo(dados,saidas)
    fprintf('\nf(x)  %9.5g; \t x ',fCusto);
    fprintf('%9.5g,   ', x);
end

