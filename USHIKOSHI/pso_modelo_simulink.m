clc;
close all;

Inicializar_simulink

Inicializar_trajReal

% limites inferiores
lb = [0.02; 2.5; 0; 0.1; 0.25; 8e-3; 0; 0.8; 0.8e-3; 0];
% Partículas iniciais
initial_M = [0.034, 3.79, 0, 0.175, 0.35, 10.913e-3, 0.015, 1.5506, 1.51e-3, 0.0237];
% limites superiores
ub = [0.04; 4; 0.10; 0.25; 0.45; 15e-3; 0.1; 3; 5e-3; 0.1];
% R, m, dl, L, D, K, b, Res, ind, I
% número de variáveis
nvars = 10;
% número de partículas
% np=10;
% parâmetros originais das MFs
% param_orig = [-3.141 -2.844 -1.605 -1.57 -1.606 -1.571 -0.4999 -0.01 ...
%              -0.141 0 0.141 0.01 0.4999 1.571 1.606 1.57 1.605 2.844 ...
%              3.141 -3.149 -3.141 -3 3 3.141 3.149];
% partículas iniciais
% x_inicial = param_orig.*ones(nPar,1);
% Otimização PSO

options = optimoptions('particleswarm','SwarmSize',10,'InitialSwarmMatrix',initial_M,'FunctionTolerance',1e-3,'Display','iter');
x = particleswarm(@(x) modelo_PSO_simulink(x),nvars,lb,ub,options);

% ,...
%     'SwarmSize',nPar,'InitialSwarmMatrix',x_inicial,'MaxIterations',500