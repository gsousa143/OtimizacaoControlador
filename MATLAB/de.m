function [Fbest, gbest, it, x] = de(costf, limites, solucaoInicial, parametros)
%EVOLUÇÃO DIFERENCIAL
%
%[fopt, xopt] = DE(costf, limitesMax, parametros.NP)
%costf: funcao custo y = costf(x) a ser otimizada, onde x um vetor 1xD é a posicao de
%uma unica particula.
%limites: matrix 4xD que gere os limites do parametros do PSO, de modo que
%cada linha representaa posicao maxima e minima e velocidades maxima e
%minima respectimante.
%parametros.NP: numero maximo de particulas.
%parametros.info: permite mostrar informacoes no console e salvar o gbest e fbest da
%ultima iteracao em um arquivo saveed.csv.
%D: dimensao, ou quantidade de variaveis de desição.

it = 1;
tempoInicial = tic;



D = size(limites,2);

xMax = limites(1,:);
xMin = limites(2,:);


% calcula posicao iniciais e inicializa vetor candidato
    for d = 1:D
        x(1:parametros.NP,d) = xMin(d) + rand(parametros.NP,1)*( xMax(d) - xMin(d) );
    end
    if ~isempty(solucaoInicial)
        x(1:size(solucaoInicial,1),:) = max(min(solucaoInicial,xMax),xMin);
    end

u = x;


% calcula o funcional custo
for n = 1:parametros.NP
    F(n) = costf(x(n, :));
end
tempoIt = toc(tempoInicial);


while(1)
    % determina Fbest e gbest
    [C, I] = min(F);
    Fbest = C;
    gbest = x(I, :);
    Fworst = max(F);
    
   %verifica criteiro de parada
    if ( it >= parametros.itMax )||( toc(tempoInicial)+tempoIt > parametros.tempoMax ) || max(abs(mean(x)./gbest-1)) < 1e-6
        infoOtm(it,Fbest,gbest,parametros.path);
        fprintf('\t Tempo %9.4g',(toc(tempoInicial)));
        break;
    end
    
    if parametros.info>0
        infoOtm(it,Fbest,gbest,parametros.path);
    end
    
    
    % determina vetor doador
    for n = 1:parametros.NP

        j = setdiff(1:parametros.NP,n);
        a = j(randi(parametros.NP-1,1,3));
        v(n,:) = gbest + parametros.Fp*( x(a(1),:) - x(a(2),:) ); %DE/best/1
        %v(n,:) = x(a(3),:) + parametros.Fp*( x(a(1),:) - x(a(2),:) ); %DE/rand/1

    end
    v = min(xMax, v);
    v = max(xMin, v);

    % cruzamento exp
    i = rand(parametros.NP,D)<=parametros.cr;
    u(i) = v(i);
    

    
    % calcula o funcional custo dos vetores canditatos
    for n = 1:parametros.NP
        Fu(n) = costf(u(n, :));
    end
    % atualiza o vetor de custos
    for n = 1:parametros.NP
        if Fu(n) < F(n)
            x(n,:) = u(n,:);
            F(n) = Fu(n);
        end
    end
    
    u = x;
    
    
    it = it+1;
end

end


function infoOtm(it,Fbest,gbest, nome)
        fprintf("\n\n==============================================================================================================")
        fprintf('\niter %3.0f; \t fbest  %9.5g; \t gbest ',it,Fbest);
        fprintf('%9.5g,   ', gbest);

        if nome ~= ""
            writematrix([it, Fbest, gbest],nome,'WriteMode','append');
        end
end

