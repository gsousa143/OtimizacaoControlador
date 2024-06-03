clc, clear;

U = ones(100,2);
X = zeros(7,1);
tempo = 0;
load("..\CONSTANTES\const_estimado.mat");


T = 0.01;
for i = 1:100
    u = U(i,:)';
    [tempo,X] = integracaoNumerica(X,u,tempo,T,constantes);
end



