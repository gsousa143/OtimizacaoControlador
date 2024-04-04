function [fCusto,er,etraj,eu,ev,tempo,w] = calculaErros(dados)


%constantes
R = 0.0336044872242929;
Ki = 1*eye(2,2);
Kp = 2.5*eye(2,2);

%pesos para o calculo do funcional custo
w = [3.22434168942421,4*17.7005313308371,0.889478037302839,4*9.11454514018721];
n = size(dados,1);

etraj = zeros(n,1);
eu = zeros(n,1);

%determinando vetor de tempos
tempo = dados(:,12);


%erro real
er = sqrt((dados(:,10)-dados(:,1)).^2 + (dados(:,11)-dados(:,2)).^2);


%esforco de controle
Ypi = abs(Ki*dados(:,6:7)' + Kp*(dados(:,8:9) - dados(:,4:5))');



%velocidade linear
ev = abs(dados(:,4)+dados(:,5))*R/2;


for i = 1:n
    %erro de trajetoria
    setpoint = dados(i,10:11);
    try
        if setpoint ~= dados(i-1,10:11)
            setpointAnterior = dados(i-1,10:11);
        end
    catch
        setpointAnterior = dados(i,10:11);
    end

    AeT = setpoint(2)-setpointAnterior(2);
    BeT = setpointAnterior(1)-setpoint(1);
    CeT = setpoint(1)*setpointAnterior(2) - setpointAnterior(1)*setpoint(2);
    etraj(i) = abs(AeT*dados(i,1) + BeT*dados(i,2) + CeT)/sqrt(AeT^2+BeT^2);


    %esforco de controle
    eu(i) = norm(Ypi(:,i),1);
end

etraj(isnan(etraj))=0;


fCusto = w(1)*sqrt(mean(er.^2)) + w(2)*sqrt(mean(etraj.^2)) + w(3)*mean(eu)  + w(4)*sqrt((mean(0.15-ev).^2));

 %como é calculado o vetor de pesos
% writematrix([1/sqrt(mean(er.^2)), 1/sqrt(mean(etraj.^2)), 1/mean(eu), 1/sqrt((mean(0.15-ev).^2))],"w.csv");


end

