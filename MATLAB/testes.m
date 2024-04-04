X = zeros(7,1);
u = [0.15;0.15];
tempo = 0;

T  = 1e-2;
for i = 1:100
c = readmatrix("..\CONSTANTES\constantesEst.csv");
[tempo,X] = IntegracaoNumerica(X,u,tempo,T,c)
end