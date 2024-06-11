function plotDadosTrajetoria(dados, print)

if nargin < 2
    print = false;
end

% Verifica se estou passando uma string com o caminho pros dados ou uma matriz de dados
if isa(dados, "string")
    dados = readmatrix(dados);
end

[fCusto, er, etraj, eu, ev, tempo, w] = calculaErros(dados);
eu = abs(eu);
ev = abs(ev);
tempo = tempo - tempo(1, end);

subplot(2, 4, 1);
hold on;
h1 = plot(tempo, er, "LineWidth", 2);
cor = get(h1, 'Color');
hold off;

ylabel('Euclidian Error [$m$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(2, 4, 2);
hold on;
plot(tempo, etraj, 'Color', cor, "LineWidth", 2);
hold off;

ylabel('Trajectory Error [$m$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(2, 4, 5);
hold on;
plot(tempo, eu(1,:), 'Color', cor, 'LineStyle', ':', "LineWidth", 2);
plot(tempo, eu(2,:), 'Color', cor, 'LineStyle', '--', "LineWidth", 2);

hold off;

xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('Control Effort [$V$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

subplot(2, 4, 6);
hold on;
plot(tempo, ev, 'Color', cor, "LineWidth", 2);
hold off;

xlabel('Time [$s$]', "Interpreter", "latex");
ylabel('Linear Velocity [$m/s$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');


subplot(2,4,[3,4,7,8])
hold on;
plot(dados(:,1), dados(:, 2), 'Color', cor, "LineWidth", 2);
hold off;
axis equal;

xlabel('X Position [$m$]', "Interpreter", "latex");
ylabel('Y Position [$m$]', "Interpreter", "latex");
axis padded;
set(gca(), "fontsize", 14, 'FontName', 'Times New Roman');

drawnow;
if print
    fprintf("\n f(x) = %2.5f, w1*er = %2.5f, w2*etraj = %2.5f, w3*eu = %2.5f, w4*ev = %2.5f, tempo = %3.0f \n", ...
        fCusto, sqrt(mean(er.^2)), sqrt(mean(etraj.^2)), sqrt(mean(abs(eu).^2,"all")), sqrt(mean((0.15-abs(ev)).^2)), tempo(end));
end
%salva em tela cheia
% set(gcf, 'Position', get(0, 'Screensize'));
end
