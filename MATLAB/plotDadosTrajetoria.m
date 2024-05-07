function plotDadosTrajetoria(dados, print)
if nargin < 2
    print = false;
end
% Verifica se estou passando uma string com o caminho pros dados ou uma matriz de dados
if isa(dados, "string")
    dados = readmatrix(dados);
end

[fCusto, er, etraj, eu, ev, tempo, w] = calculaErros(dados);

tempo = tempo - tempo(1, end);

subplot(2, 4, 1);
hold on;
plot(tempo, er, "LineWidth", 2);

hold off;
title("E_r");
ylabel('Euclidian Error [$m$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(2, 4, 2);
hold on;

    plot(tempo, etraj, "LineWidth", 2);

hold off;
title("E_{traj}");
ylabel('Trajectory Error [$m$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(2, 4, 5);
hold on;
plot(tempo, sum(eu,1), "LineWidth", 2);
hold off;
title("E_u");
xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('Control Effort [$V$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(2, 4, 6);
hold on;
plot(tempo, ev, "LineWidth", 2);
hold off;
title("E_v");
xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('Linear Velocity [$m/s$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');


subplot(2,4,[3,4,7,8])
hold on;
plot(dados(:,1), dados(:, 2), "LineWidth", 2);
hold off;
axis equal;
xlabel('X Position [$m$]', "Interpreter", "latex");
ylabel('Y Position [$m$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

drawnow;
if print
    fprintf("\n f(x) = %2.5f, w1*er = %2.5f, w2*etraj = %2.5f, w3*eu = %2.5f, w4*ev = %2.5f, tempo = %3.3f \n", ...
        fCusto, w(1)*mean(er), w(2)*mean(etraj), w(3)*mean(eu,"all"), w(4)*mean(0.15-ev), tempo(end));
end

end
