global m R D L dl ind K b Res M1 M2

m=3.79; % Manual qbot2
R=0.034; % Estimado
D=0.35; % Manual qbot2
L=D/2;
dl=0;   % Estimado
ind=1.51e-3; % Manual Kobuki
K=10.913e-3; % Manual Kobuki
b=0.015;    % Estimado
Res=1.5506; %Manual Kobuki

%Considerando m=mc+2*mw
mc=(10/11)*m;   % Estimado
mw=(1/22)*m;    % Estimado

Iw=(1/2)*mw*R^2;    % Estimado geometricamente
Ic=(1/8)*mc*L^2;    % Estimado geometricamente
%Im=?
Im=0;               % Estimado
I=Ic+mc*dl^2+2*mw*L^2+2*Im;

M=[Iw+((R^2)/(4*L^2))*(m*(L^2)+I) ((R^2)/(4*L^2))*(m*(L^2)-I);((R^2)/(4*L^2))*(m*(L^2)-I) Iw+((R^2)/(4*L^2))*(m*(L^2)+I)];
V=[1 0;0 1];
B=V/M;

M1=(1/44)*m*R^2+(R^2/(4*L^2))*(m*L^2+(1/8.8)*m*D^2+(1/11)*m*L^2);
M2=(R^2/(4*L^2))*(m*L^2-(1/8.8)*m*D^2-(1/11)*m*L^2);

clc