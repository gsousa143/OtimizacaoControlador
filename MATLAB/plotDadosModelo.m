function plotDadosModelo(dados,saidas,tempos)
subplot(1,2,1)
hold on;
plot(saidas(:,1), saidas(:, 2), "LineWidth", 2);
cor = plot(dados(:,1), dados(:, 2), "LineWidth", 2);
cor = get(cor,"Color");
hold off;
axis equal;
xlabel('X Position [$m$]', "Interpreter", "latex");
ylabel('Y Position [$m$]', "Interpreter", "latex");
legend(["QBOT", "Dinamic Model"]);
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(1,2,2)
hold on;
er = sqrt((saidas(:,1)-dados(:,1)).^2 + (saidas(:,2)-dados(:,2)).^2);
plot(tempos,er,"Color", cor, "LineWidth", 2)
axis padded;
xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('Error [$m$]', "Interpreter", "latex");
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
hold off;


set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
drawnow;


end

