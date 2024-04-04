function y = otimizaModelo(x,saidas,U,tempos,X0,C)

C = attConstantes(C,x,1:12);


X = X0;
i=1;
T = tempos(2)-tempos(1);
try
while(i<size(tempos,1))
u = U(i,:)';

[~,X] = integracaoNumericaMex(X,u,tempos(i),T,C);
dados(i,:) = X(1:2);
% drawnow;
% plot(X(1),X(2),'.b',saix(i+1,2),saiy(i+1,2),'.r');
i = i+1;
end


eR = ( saidas(2:end,:)-dados ).^2;


y = sqrt( sum(eR, 'all')/i );

% writematrix(dados,'DADOS/MODELO/dados_opt.csv','WriteMode','append');
clf;
plot(saidas(:,1),saidas(:,2),dados(:,1),dados(:,2));
title("funcional custo: "+string(y));
drawnow;
catch
    y = 1e10;
end
end

