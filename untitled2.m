clear
clc
close all;
% hold on;
trajetoria = "zzx";
load("CONSTANTES/const_otimo")
load('SETPOINTS/'+trajetoria+'.mat')
ddmr = DDMR;
ddmr.setup();
ddmr.setConstants(constantes);
% ddmr.setFlc([0.1571, 0.1571, 0.1571, 2*pi/11, 3*pi/11]); %FBG
fis = FLC;
fis.setFLC([0.066218, 0.079945, 0.4796, 0.06798, 0.84621]) %OFBG


data = [];
i_sp = 1;

x_sp = setpoints(i_sp,1);
y_sp = setpoints(i_sp,2);
sp = setpoints(i_sp,:);
X = ddmr.getState();
N_sp = size(setpoints,1);
for t = 0:ddmr.T:t_final
    l = norm([x_sp,y_sp]-X(1:2));
    phi = 2*atan2( tan((atan2( y_sp-X(2), x_sp-X(1) ) - X(3))/2) ,1 );
    u = fis.step(phi,l)
    X = ddmr.step(u)
    data = [data;X];
    if  (l < 0.035) & (i_sp<N_sp)
        i_sp = i_sp+1;
        x_sp = setpoints(i_sp,1);
        y_sp = setpoints(i_sp,2);
    end
    
end
plot(data(:,1),data(:,2))



