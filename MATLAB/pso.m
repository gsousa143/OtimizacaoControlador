function [Fbest, gbest, it, pbest] = pso(costf, limites, x0,NP, itMax, tempoMax, info)

cS = 1.49445;
cP = 1.49445;
it = 1;
tempoInicial = tic;


D = size(limites,2);

xMax= limites(1,:);
xMin = limites(2,:);

vMax = (xMax-xMin)/2;

[x,v] = inicializaPopulacao(xMin,xMax,vMax,x0,NP,D);

for n = 1:NP
    F(n) = costf(x(n, :));
end

pbest = x; %pbest = x pois é a 1a iteracao
Fpbest = F; %Fpbest = F pois é a 1a iteração
[Fbest, I] = min(F);
gbest = x(I,:);

tempoIt = toc(tempoInicial);

while(1)
    for n = 1:NP
        F(n) = costf(x(n, :));
    end

    % determina Fbest e gbest
    [C, I] = min(F);
    if C<=Fbest
        Fbest = C;
        gbest = x(I, :);
    end

    %verifica criteiro de parada
    if ( it >= itMax )||( toc(tempoInicial)+tempoIt > tempoMax ) 
        infoOtm(it,Fbest,gbest);
        fprintf('\t Tempo %9.4g',(toc(tempoInicial)));
        break;
    end

    if info
        infoOtm(it,Fbest,gbest);
    end


    i = F<Fpbest;
    pbest(i,:) = x(i,:);
    Fpbest(i) = F(i);

    v = attVelocidade(x,v,pbest,I,NP,D,cS,cP);
    v = min(vMax,v);
    v = max(-vMax,v);

    x = x + v;
    x = min(xMax, x);
    x = max(xMin, x);

    it = it+1;
end

end

function infoOtm(it,Fbest,gbest)
fprintf("\n\n==============================================================================================================")
fprintf('\niter %3.0f; \t fbest  %9.5g; \t gbest ',it,Fbest);
fprintf('%9.5g,   ', gbest);

writematrix([it, Fbest, gbest],"savepso.csv","WriteMode","append");

end

function [x,v] = inicializaPopulacao(xMin,xMax,vMax,x0,NP,D)
for d = 1:D
    x(1:NP,d) = xMin(d) + rand(NP,1)*( xMax(d) - xMin(d) );
    v(1:NP,d) =  2*rand(NP,1)*vMax(d) - vMax(d);
end
if ~isempty(x0)
    x(1:size(x0,1),:) = max(min(x0,xMax),xMin);
end
end


function v = attVelocidade(x,v,pbest,I,NP,D,cS,cP)
d = sum(sqrt(sum((reshape(x, [NP, 1, D]) - reshape(x, [1, NP, D])).^2, 3)),1)/(NP-1);

dMax = max(d);
dMin = min(d);

f = (d(I)-dMin)/(dMax-dMin);

w = 1/(1 + 1.5*exp(-2.6*f));

v1 = rand(NP,D).*(cP*(pbest-x));
v2 = rand(NP,D).*(cS*(x(I,:)-x));
v = w*v + v1 + v2;
end

