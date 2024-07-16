function [fCusto,er,etraj,eu,ea,tempo,w] = calculaErros(dados)
%calculaErros:
% calcula o funcional custo de uma trajetoria


%constantes
R = 0.034; %Raio da roda, para calculo da Velocidade Linear
L = 0.1175;
Ki = 1; % Constante do PI, para calcular a tensão dos motores CC
Kp = 2.5; % Constante do PI, para caluclar a tensão dos motores CC



%pesos para o calculo do funcional custo
w = [2.40492798773439,20.3549622976186,0.675805189069824,15.0730121331585];


n = size(dados,1);

% como não é possivel calcular o erro de trajetoria de maneira direta, para
% o codigo ser mais eficiente é recomendando criar o vetor antes para
% alocar o espaço  na memoria
etraj = zeros(n,1);


%determinando vetor de tempos
tempo = dados(:,12);
T = tempo(2)-tempo(1);


%erro real
% distancia entre a posição atual do robo e o setpoint atual
er = sqrt((dados(:,10)-dados(:,1)).^2 + (dados(:,11)-dados(:,2)).^2);


%esforco de controle
% absoluto da tensão de entrada dos motores CC
eu = min(max(Ki*dados(:,6:7)' + Kp*(dados(:,8:9) - dados(:,4:5))',-0.65),0.65);




%velocidade linear
ea = zeros(n,1);
ea(2:end) = abs( (diff( dados(:,4) + dados(:,5) ))*R/(2*T)) ;

%erro de trajetoria

% o primeiro setpoint anterior pode ser a posição inicial do robô,
% gambiara para a otimização em tempo real
setpointAnterior = dados(1,1:2);
for i = 2:n
    %determinando o setpoint atual
    setpoint = dados(i,10:11);
    try
        %condição para verificar se o setpoint é diferente
        if norm(setpoint - dados(i-1,10:11))>1e-6 
            setpointAnterior = dados(i-1,10:11);
        end
        %calculos dos coeficientes da reta entre o setpoint atual e o
        %setpoint anterior
        AeT = setpoint(2)-setpointAnterior(2);
        BeT = setpointAnterior(1)-setpoint(1);
        CeT = setpoint(1)*setpointAnterior(2) - setpointAnterior(1)*setpoint(2);
        %distancia entre o ponto e reta
        etraj(i) = abs(AeT*dados(i,1) + BeT*dados(i,2) + CeT)/sqrt(AeT^2+BeT^2);
    catch
    end
end

% caso o setpoint atual e o anterior forem o mesmo temos um problema
%de divisão por zero que resulta em um NaN a linha seguinte garante que
%todos NaN sejam substituidos por 0, para que não ocorra erros quando
%calular a media
etraj(isnan(etraj)) = 0;

%calculo da função custo
%mean(er) media do erro real
%mean(etraj) media do erro de trajetoria
%mean(eu) media dos modulos das tensão de entradas dos motores CC
%mean(ev) media do erro entre a velocidade linear e maxima velocidade
%linear possivel (de acordo com o controlador de trajetoria fuzzy)
fCusto = w(1)*sqrt(mean(er.^2)) + w(2)*sqrt(mean(etraj.^2)) + w(3)*sqrt(mean(abs(eu).^2,"all"))  + w(4)*sqrt(mean((ea).^2));

%como é calculado o vetor de pesos
% vetor de pesos é utilizando para normalizar os valores a partir dos testes
%realizados pela trajetoria executada pelo controlador FBG
writematrix([ 1/sqrt(mean(er.^2)), 1/sqrt(mean(etraj.^2)), 1/sqrt(mean(abs(eu).^2,"all")), 1/sqrt(mean((0.15-abs(ev)).^2)) ], "w.csv");
end

