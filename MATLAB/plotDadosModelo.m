function plotDadosModelo(dados,saidas,tempos)
subplot(3,2,[1,3,5])
hold on;
plot(saidas(:,1), saidas(:, 2), "LineWidth", 2);
plot(dados(:,1), dados(:, 2), "LineWidth", 2);
hold off;
axis equal;
xlabel('X Position [$m$]', "Interpreter", "latex");
ylabel('Y Position [$m$]', "Interpreter", "latex");
legend(["QBOT", "Dinamic Model"]);
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(3,2,2)
hold on;
er = sqrt((saidas(:,1)-dados(:,1)).^2 + (saidas(:,2)-dados(:,2)).^2);
plot(dados(:,end),er,"LineWidth", 2)
axis padded;
xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('X Position [$m$]', "Interpreter", "latex");
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
hold off;

subplot(3,2,4)
hold on;
plot(tempos,saidas(:,1), "LineWidth", 2);
plot(tempos,dados(:,1), "LineWidth", 2);
hold off;
axis padded;
xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('Y Position [$m$]', "Interpreter", "latex");

set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(3,2,6)
hold on;
plot(tempos,saidas(:,2), "LineWidth", 2);
plot(tempos,dados(:,2), "LineWidth", 2);
hold off;
axis padded;
xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('X Position [$m$]', "Interpreter", "latex");

set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');
drawnow;


end

