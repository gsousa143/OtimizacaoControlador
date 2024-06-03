function [Fbest, gbest, it, x, v] = pso(costf, limites, x0,v0, NP, itMax, tempoMax, info)

cS = 1.49445;
cP = 1.49445;
W = 0.9;

if isinf(itMax)
    wRate = 0.01;
else
    wRate = 0.5/itMax;
end

it = 1;
tempoInicial = tic;

D = size(limites, 2);

xMax = limites(1, :);
xMin = limites(2, :);

vMax = (xMax - xMin)/10;

[x, v] = inicializaPopulacao(xMin, xMax, vMax, x0,v0, NP, D);

for n = 1:NP
    F(n) = costf(x(n, :));
end

pbest = x;
Fpbest = F;
[Fbest, I] = min(F);
gbest = x(I, :);


% Atualizar velocidade e posição
v = attVelocidade(x, v, pbest, I, NP, D, cS, cP, W, it, wRate);
v = min(max(v, -vMax), vMax);
x = x + v;
x = min(max(x, xMin), xMax);

it = it + 1;
tempoIt = toc(tempoInicial);

while (1)
    % Avaliar custo
    for n = 1:NP
        F(n) = costf(x(n, :));
    end

    % Atualizar Fbest e gbest
    [C, I] = min(F);
    if C <= Fbest
        Fbest = C;
        gbest = x(I, :);
    end

    % Verificar critério de parada
    if (it >= itMax) || (toc(tempoInicial) + tempoIt > tempoMax)
        infoOtm(it, Fbest, gbest);
        fprintf('\t Tempo %9.4g', toc(tempoInicial));
        break;
    end

    if info
        infoOtm(it, Fbest, gbest);
    end

    % Atualizar pbest
    i = F < Fpbest;
    pbest(i, :) = x(i, :);
    Fpbest(i) = F(i);

    % Atualizar velocidade e posição
    v = attVelocidade(x, v, pbest, I, NP, D, cS, cP, W, it, wRate);
    v = min(max(v, -vMax), vMax);
    x = x + v;
    x = min(max(x, xMin), xMax);

    it = it + 1;
end

end

function infoOtm(it, Fbest, gbest)
fprintf("\n\n==============================================================================================================");
fprintf('\niter %3.0f; \t fbest  %9.5g; \t gbest ', it, Fbest);
fprintf('%9.5g,   ', gbest);

writematrix([it, Fbest, gbest], "savepso.csv", "WriteMode", "append");

end

function [x, v] = inicializaPopulacao(xMin, xMax, vMax, x0,v0, NP, D)
x = xMin + rand(NP, D) .* (xMax - xMin);
v = 2 * rand(NP, D) .* vMax - vMax;

if ~isempty(x0)
    x(1:size(x0, 1), :) = max(min(x0, xMax), xMin);
end
if ~isempty(v0)
    v(1:size(v0, 1), :) = max(min(v0, xMax), xMin);
end
end

function v = attVelocidade(x, v, pbest, I, NP, D, cS, cP, w, it, wRate)
w = w - it * wRate;

v1 = rand(NP, D) .* (cP * (pbest - x));
v2 = rand(NP, D) .* (cS * (x(I, :) - x));
v = w * v + v1 + v2;
end
