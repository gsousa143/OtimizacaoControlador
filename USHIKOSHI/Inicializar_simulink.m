Inicializar_Qbot2

global FB x_pos y_pos t ref_traj

[x_pos,y_pos,t]=CrossedZZ;

load('erro_ref.mat','ref_traj')

% load('CrossedZZ_3-5+2-5dasorte.mat','x_pos','y_pos','t')

FB=readfis('FB.fis');

%% Opcional para testar parametros do controlador

% x = [-3.14100000000000 0.962372637207239 2.00591351825090 -1.33864226292151 0.0128322638958821 2.34132063880785 0.301803904216927 -0.140000000000000];
% 
% if x(2) <= x(3)
%     FB.input(1).mf(1).params = [-3.141+(x(1)-x(3)/2) -2.844+(x(1)-x(2)/2) -1.605+(x(1)+x(2)/2) -1.57+(x(1)+x(3)/2)];       %GN
% end
% if x(5) <= x(6)
%     FB.input(1).mf(2).params = [-1.606+(x(4)-x(6)/2) -1.571+(x(4)-x(5)/2) -0.4999+(x(4)+x(5)/2) -0.01+(x(4)+x(6)/2)];       %PN
% end
%     FB.input(1).mf(3).params = [-0.141-x(7)/2 0 0.141+x(7)/2];          %Z
%     FB.input(1).mf(4).params = -wrev(FB.input(1).mf(2).params);         %PP
%     FB.input(1).mf(5).params = -wrev(FB.input(1).mf(1).params);         %GP
%     FB.input(1).mf(6).params = [-3.149 -3.141 -3+x(8)];                 %EN
%     FB.input(1).mf(7).params = -wrev(FB.input(1).mf(6).params);         %EP

%% Opcional para testar parametros do modelo

modelo = [0.0399777836717820,3.86952387364304,0.0212343494649605,0.250000000000000,0.419406311905019,0.0143990138605669,0.0216331108754875,0.800000000000000,0.00431344847964316,0.0656320209211811];

R = modelo(1);
m = modelo(2);
dl = modelo(3);
L = modelo(4);
D = modelo(5);
K = modelo(6);
b = modelo(7);
Res = modelo(8);
ind = modelo(9);
I = modelo(10);