clc;
clear all;
global fis
trajetoria = 'inf';
controlador = 'fbm';
setpoint = ['SETPOINTS/', trajetoria, '.mat'];
load(setpoint);
fis = readfis(['CONTROLADORES/' controlador '.fis']);
N_sp = size(setpoints,1);
t_final = 150;
save(setpoint,'setpoints','t_final');
R = 0.034;
L = 0.1175;
k_i = 1;
k_p = 2.5;
modelo = 'Fuzzy_manobra_aplicado_2015b';
slbuild(modelo);



