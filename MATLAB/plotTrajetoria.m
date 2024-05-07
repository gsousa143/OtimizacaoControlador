function plotTrajetoria(dados)
n = 50;
for i = 1:size(dados,1)/n
    plotDDMR(dados(1:i*n,:))
end
plotDDMR(dados)
end


function plotDDMR(dados)
    clf;

    R = 0.35/2;
    x = dados(end,1);
    y  = dados(end,2);
    theta = dados(end,3);


    ang = linspace(0,2*pi,15);
    xDDMR = x + R*cos(ang);
    yDDMR = y + R*sin(ang);
    

    
    plot(dados(:,1),dados(:,2),"r--", ...
        x, y,"bo", ...
        xDDMR,yDDMR,"b", ...
        [x,x+R*cos(theta)], [y,y+R*sin(theta)], "g", ...
        dados(end,10),dados(end,11),"rx",LineWidth=1)
    



xlabel("x Position [$m$]","Interpreter","latex");
ylabel("y Position [$m$]","Interpreter","latex");
axis equal
axis padded
set(gca(),"fontsize",14,'FontName', 'Times New Roman')


drawnow;
    

end
