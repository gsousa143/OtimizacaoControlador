function [Fbest, gbest, it,x] = ga(costf, limites, x0, NP, itMax, tempoMax, info)
fM = 0.01;
mr = 0.3;
etta = 10;

it = 1;
tempoInicial = tic;
D = size(limites,2);
xMax = limites(1,:);
xMin = limites(2,:);
x = zeros(NP,D);

x = inicializaPopulacao(xMin,xMax,x0,NP,D);

for n=1:NP
    F(n) = costf(x(n,:));
end

tempoIt = toc(tempoInicial);

while(1)
    % determina Fbest e gbest
    [C, I] = min(F);
    Fbest = C;
    gbest = x(I, :);

    %verifica criterios de parada
    if ( it >= itMax )||( toc(tempoInicial)+tempoIt > tempoMax )
        infoOtm(it,Fbest,gbest);
        fprintf('\t Tempo %9.4g',(toc(tempoInicial)));
        break;
    end

    if info
        infoOtm(it,Fbest,gbest);
    end

    pais = selecaoRoleta(x,F,NP);

    filhos = cruzamentoSBX(pais,NP,D,etta);

    filhos = multacao(filhos,NP,D,fM,mr);

    filhos = min(filhos,xMax);
    filhos = max(filhos,xMin);

    [x,F] = elitismo(x,filhos,F,NP,costf);
    

    it = it+1;
end

end



function infoOtm(it,Fbest,gbest)
fprintf("\n\n==============================================================================================================")
fprintf('\niter %3.0f; \t fbest  %9.5g; \t gbest ',it,Fbest);
fprintf('%9.5g,   ', gbest);
writematrix([it, Fbest, gbest],"savega.csv","WriteMode","append");
end

function x = inicializaPopulacao(xMin,xMax,x0,NP,D)
for d = 1:D
    x(1:NP,d) = xMin(d) + rand(NP,1)*( xMax(d) - xMin(d) );
end
if ~isempty(x0)
    x(1:size(x0,1),:) = max(min(x0,xMax),xMin);
end
end

function pais = selecaoRoleta(x,F,NP)
Fbest = min(F);
Fworst = max(F);

Fap = 0.01 + (0.99)*(Fworst-F)/(Fworst-Fbest);
roleta = cumsum(Fap');
for n = 1:NP
    indice = find(roleta>=roleta(end)*rand(),1);
    if isempty(indice)
        indice = 1;
    end
    pais(n,:) = x(indice,:);
end
end

function filhos = cruzamentoSBX(pais,NP,D,etta)
u = rand(1, NP/2);
Betta = (2*u).^(u>0.5)/(etta+1) + (2*(1-u)).^(u<=0.5)*(-1/(etta+1));
Betta = repmat(Betta,1,D);
pais = reshape(pais',[],2)';
filhos = (sum(pais,1) + Betta.*[diff(pais,1,1);-diff(pais,1,1)])/2;
filhos = reshape(filhos',[],NP)';
end


function filhos = multacao(filhos,NP,D,fM,mr)
filhos = filhos +  fM*(rand(NP, D)<=mr) .* (2 * rand(NP, D) - 1) .* filhos;
end


function [x,F] = elitismo(x,filhos,F,NP,costf)
for n = 1:NP
    Ffilhos(n) = costf(filhos(n,:));
end
Fe = [F, Ffilhos];
xe = [x; filhos];
[~,I] = sort(Fe);

x = xe(I(1:NP),:);
F = Fe(I(1:NP));
end

function [x,F] = elitismo1to1(x,filhos,F,NP,costf)
for n = 1:NP
    Ffilhos(n) = costf(filhos(n,:));
end
indices = F>Ffilhos;
F(indices) = Ffilhos(indices);
x(indices,:) = filhos(indices,:);
end
