clear
clc
close all;

trajetoria = "zzx";
load("CONSTANTES/const_otimo")
load('SETPOINTS/'+trajetoria+'.mat')
ddmr = ddmr_flc;
ddmr.setConstants(constantes);
% ddmr.setFlc([0.1571, 0.1571, 0.1571, 2*pi/11, 3*pi/11]); %FBG
ddmr.setFlc([0.066218, 0.079945, 0.4796, 0.06798, 0.84621]) %OFBG


data = [];
i_sp = 1;

x_sp = setpoints(i_sp,1);
y_sp = setpoints(i_sp,2);

N_sp = size(setpoints,1);
for t = 0:ddmr.T:t_final
    [x_a,y_a] = ddmr.step(x_sp,y_sp);

    if  (norm([x_sp,y_sp]-[x_a,y_a]) < 0.035) & (i_sp<N_sp)
        i_sp = i_sp+1;
        x_sp = setpoints(i_sp,1);
        y_sp = setpoints(i_sp,2);
    end
    
end




