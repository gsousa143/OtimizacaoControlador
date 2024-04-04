function u = flc(X,referencia,fis,R,L)
    erro = referencia - X(1:2);
    distancia = norm(erro);
    PHIr = (atan2( erro(2), erro(1) )-X(3))/2;
    erroAngular = 2*atan2( tan(PHIr) ,1 );
    opcoes = evalfisOptions('OutOfRangeInputValueMessage',"error",'NoRuleFiredMessage',"error",'EmptyOutputFuzzySetMessage',"error");
    velocidades = evalfis(fis,[erroAngular,distancia],opcoes);
    u = (1/R)*[
        velocidades(1)+velocidades(2)*L;
        velocidades(1)-velocidades(2)*L];
end

