function u = flc(X,referencia,fis,R,L)
    % CONTROLADOR DE TRAJETORIA FUZZY
    %
    %
    %ENTRADAS
    %X: Vetor de estados
    %   X(1): posição do robô no eixo X em metros.
    %   X(2): posição do robô no eixo Y em metros.
    %   X(3): angulo do robô em relação ao eixo X em radianos.
    %referencia: Vetor com os setpoints de posição como um par ordenado
    %   referencia(1): posição do setpoint no eixo X em metros.
    %   referencia(2): posição do setpoint no eixo Y em metros.
    %fis: Sistema de Inferência Fuzzy
    %   Variavel do tipo mamfis que representa o controlador de trajetoria.
    %   Duas entradas: Distancia Euclidiana (metros) e Erro Angular
    %   (radianos), Duas saidas: Velocidade Linear (metros/segundo),
    %   Velocidade Angular (radianos/segundo)
    
    
    %
    %SAIDAS
    %u: vetor de velocidades das rodas desejadas
    %   u(1) velocidade da roda direita
    %   u(2) velocidade da roda esquerda
    

    % constantes
    
    
    %calculo dos erros em relação aos eixos x e y
    erro = referencia - X(1:2);
    %calculo da distancia euclidiana
    distancia = norm(erro);
    %calculo do erro angular 
    % (necessario para manter o intervalo entre [-pi, pi])
    PHIr = (atan2( erro(2), erro(1) )-X(3))/2;
    erroAngular = 2*atan2( tan(PHIr) ,1 );
    % avalia o sistema de inferencia fuzzy
    velocidades = evalfis(fis,[erroAngular,distancia]);
    % transforma as velocidades linear e angular em velocidades das rodas
    u = (1/R)*[
        velocidades(1)+velocidades(2)*L;
        velocidades(1)-velocidades(2)*L];
    
end

