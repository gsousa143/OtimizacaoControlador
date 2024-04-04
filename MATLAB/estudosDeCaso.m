function constantes = estudosDeCaso(constantes,arg,tipo)
if tipo=="atrito"
    constantes = atrito(constantes,arg);
elseif tipo=="bateria"
    constantes = bateria(constantes,arg);
elseif tipo=="massa"
    constantes = massa(constantes,arg);
end
end


function constantes = atrito(constantes,xa)
if xa>0.4
    constantes(9) = constantes(9)*3;
    constantes(10) = constantes(10)*3;
end
end


function constantes = bateria(constantes,tempo)
constantes(5) = constantes(5)*( 1.6./(1+exp(0.003*tempo)) + 0.2 );
end


function constantes = massa(constantes,isp)
if isp>5
    constantes(7) = constantes(7)+10;
end
end