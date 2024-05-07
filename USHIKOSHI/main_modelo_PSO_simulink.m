global ornitorrinco jaguatirica
ornitorrinco = cell(4,100);
jaguatirica = 1;

for babuino=1:10
    pso_modelo_simulink
    save(['resultado',num2str(babuino)],'x');
    clear
end