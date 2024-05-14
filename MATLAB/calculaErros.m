function [fCusto,er,etraj,eu,ev,tempo,w] = calculaErros(dados)
%calculaErros:
% calcula o funcional custo de uma trajetoria


%constantes
R = 0.034; %Raio da roda, para calculo da Velocidade Linear
Ki = 1; % Constante do PI, para calcular a tensão dos motores CC
Kp = 2.5; % Constante do PI, para caluclar a tensão dos motores CC



%pesos para o calculo do funcional custo
w = [3.84325517332611,31.981474668575,1.43080872551847,16.9687608119701];


n = size(dados,1);

% como não é possivel calcular o erro de trajetoria de maneira direta, para
% o codigo ser mais eficiente é recomendando criar o vetor antes para
% alocar o espaço  na memoria
etraj = zeros(n,1);


%determinando vetor de tempos
tempo = dados(:,12);


%erro real
% distancia entre a posição atual do robo e o setpoint atual
er = sqrt((dados(:,10)-dados(:,1)).^2 + (dados(:,11)-dados(:,2)).^2);


%esforco de controle
% absoluto da tensão de entrada dos motores CC
eu = Ki*dados(:,6:7)' + Kp*(dados(:,8:9) - dados(:,4:5))';
% outras formas que ja utilizei foi o absoluto da diferença entre o
% setpoint de velocidade e a velocidade atual
% eu = abs([dados(:,8)-dados(:,4), dados(:,9)-dados(:,5)]);
% e o absoluto do setpoint de velocidade
% eu = abs(dados(:,8:9));
% Essas opções fazem sentido porque não é possivel coletar a tensão dos
% motores do QBot, então não da pra combparar os resultados entre o
% simulado e real



%velocidade linear
ev = (dados(:,4)+dados(:,5))*R/2;

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
fCusto = 1*w(1)*mean(er) + w(2)*mean(etraj) + w(3)*mean(abs(eu),"all")  + 1*w(4)*mean(0.15-abs(ev));

%como é calculado o vetor de pesos
% vetor de pesos é utilizando para normalizar os valores a partir dos testes
%realizados pela trajetoria executada pelo controlador FBM
writematrix([1/mean(er), 1/mean(etraj), 1/mean(abs(eu),"all"), 1/mean(0.15-abs(ev))],"w.csv");
end

