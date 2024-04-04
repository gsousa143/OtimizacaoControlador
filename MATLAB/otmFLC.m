function fCusto = otmFLC(x,fis,Xinicial,T,tempoInicial,tempoMax,C,matrizSetpoints,isp,On)
dados = [];
fis = attFLC(fis,x);
try
dados = ddmr(fis,Xinicial,T,tempoInicial,tempoMax,C,matrizSetpoints,isp);
catch
end


if (size(dados,1) == 0)
    fCusto = Inf;
else
    
    if On
        fCusto = calculaErros(dados);
    else
        [fCusto,er,etraj,eu,ev,~,w] = calculaErros(dados);
        if dados(end,end)>=tempoMax
            fCusto = fCusto + 1000;
        end
        plotDDMR(dados,T,fis);
        fprintf('\nf(x) = %9.5g;' ,fCusto);
        fprintf('\tx = ');
        fprintf('%9.5g, ', x);
        fprintf('\nw1*Er = %9.5g, \t w2*Etraj = %9.5g, \t w3*Eu = %9.5g, \t w4*Ev = %9.5g, \t tempo = %9.5g\n' ...
            ,w(1)*sqrt(mean(er.^2)),w(2)*sqrt(mean(etraj.^2)),w(3)*mean(eu),w(4)*sqrt((mean(0.15-ev).^2)),dados(end,end));
    end
end



end

