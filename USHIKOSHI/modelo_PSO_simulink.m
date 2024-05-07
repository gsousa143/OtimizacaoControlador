%Função que simula o sistema dada uma referência e alguns parâmetros do
%controlador. A saída é o erro RMSE.

%Recebe vetor linha e retorna escalar

%Usar dois parâmetros para otimizar uma MF triangular
%centro e largura

%Usar três parâmetros para otimizar uma MF trapezoidal
%centro, base menor e base maior

%Elaborar modelo do sistema em MA com jacobiana
%Inserir expoente de Lyapunov como entrada no fuzzy
%(descobrir como atuar contra a instabilidade para inserir no fuzzy)


function custo = fuzzy_PSO_simulink(x)

tic

global ornitorrinco jaguatirica x_real y_real m R D L dl ind K b Res M1 M2 Ic Im I k1 k2 k3 k4 k5 k6 k7

% in = Simulink.SimulationInput('Fuzzy_Manobra');
% in = in.setBlockParameter('Fuzzy_Manobra/Fuzzy Logic Controller','FIS','FB');

% R, m, dl, L, D, K, b, Res, ind, I
R = x(1);
m = x(2);
dl = x(3);
L = x(4);
D = x(5);
K = x(6);
b = x(7);
Res = x(8);
ind = x(9);
I = x(10);

set_param('Fuzzy_Manobra/Controlador fuzzy', 'FIS', 'FB')

k1 = 1/R;
k2 = L/R;
k3 = K/Res;
k4 = ((K^2)/Res)+b;
k5 = 1/m;
k6 = m*dl;
k7 = 1/I;

set_param('Fuzzy_Manobra/S1/Gain1', 'Gain', '1/R')
set_param('Fuzzy_Manobra/S1/Gain', 'Gain', 'L/R')
set_param('Fuzzy_Manobra/S5/Md1', 'Gain', 'K/Res')
set_param('Fuzzy_Manobra/S5/Md2', 'Gain', '((K^2)/Res)+b')
set_param('Fuzzy_Manobra/S6/Gain', 'Gain', 'K/Res')
set_param('Fuzzy_Manobra/S6/Gain1', 'Gain', '((K^2)/Res)+b')
set_param('Fuzzy_Manobra/Dinamico/gain1', 'Gain', '1/R')
set_param('Fuzzy_Manobra/Dinamico/gain5', 'Gain', '1/R')
set_param('Fuzzy_Manobra/Dinamico/gain6', 'Gain', '1/m')
set_param('Fuzzy_Manobra/Dinamico/gain2', 'Gain', 'L')
set_param('Fuzzy_Manobra/Dinamico/gain4', 'Gain', 'dl')
set_param('Fuzzy_Manobra/Dinamico/gain10', 'Gain', 'm*dl')
% Ic = (1/8)*mc*L^2;
% Im=0;
% I=Ic+mc*dl^2+2*mw*L^2+2*Im;
set_param('Fuzzy_Manobra/Dinamico/gain3', 'Gain', '1/I')
set_param('Fuzzy_Manobra/Dinamico/gain7', 'Gain', 'L')
set_param('Fuzzy_Manobra/Dinamico/gain8', 'Gain', '1/R')
set_param('Fuzzy_Manobra/Dinamico/gain9', 'Gain', '1/R')
% set_param('Fuzzy_Manobra/S1/Gain1', 'Gain', 'k1')
% set_param('Fuzzy_Manobra/S1/Gain', 'Gain', 'k2')
% set_param('Fuzzy_Manobra/S5/Md1', 'Gain', 'k3')
% set_param('Fuzzy_Manobra/S5/Md2', 'Gain', 'k4')
% set_param('Fuzzy_Manobra/S6/Gain', 'Gain', 'k3')
% set_param('Fuzzy_Manobra/S6/Gain1', 'Gain', 'k4')
% set_param('Fuzzy_Manobra/Dinamico/gain1', 'Gain', 'k1')
% set_param('Fuzzy_Manobra/Dinamico/gain5', 'Gain', 'k1')
% set_param('Fuzzy_Manobra/Dinamico/gain6', 'Gain', '1/m')
% set_param('Fuzzy_Manobra/Dinamico/gain2', 'Gain', 'L')
% set_param('Fuzzy_Manobra/Dinamico/gain4', 'Gain', 'dl')
% set_param('Fuzzy_Manobra/Dinamico/gain10', 'Gain', 'k6')
% % Ic = (1/8)*mc*L^2;
% % Im=0;
% % I=Ic+mc*dl^2+2*mw*L^2+2*Im;
% set_param('Fuzzy_Manobra/Dinamico/gain3', 'Gain', 'k7')
% set_param('Fuzzy_Manobra/Dinamico/gain7', 'Gain', 'L')
% set_param('Fuzzy_Manobra/Dinamico/gain8', 'Gain', 'k1')
% set_param('Fuzzy_Manobra/Dinamico/gain9', 'Gain', 'k1')

res = sim('Fuzzy_Manobra','ReturnWorkspaceOutputs','on');

%% Custo

erro_x = x_real - res.saix(:,2);
erro_y = y_real - res.saiy(:,2);

%Calcular o erro RMSE
erro_total=sqrt((abs(erro_x(:,1)).^2)+(abs(erro_y(:,1)).^2));
erro_rmse=sum(erro_total.^2)/length(erro_total)

x

%Calcular custo
custo = erro_rmse;

ornitorrinco{1,jaguatirica} = x;
ornitorrinco{2,jaguatirica} = custo;
ornitorrinco{3,jaguatirica} = NaN;
ornitorrinco{4,jaguatirica} = NaN;

jaguatirica = jaguatirica + 1;

save('ornitorrinco.mat','ornitorrinco');

toc

end

