function fis = attFLC(fis,x)
fis.input(1).mf(1).params = [x(1), -pi];
fis.input(1).mf(2).params = [x(2), x(4)-pi];
fis.input(1).mf(3).params = [x(3), x(5)-pi];
fis.input(1).mf(4).params = [x(3), -x(5)];
fis.input(1).mf(5).params = [x(2), -x(4)];
fis.input(1).mf(6).params = [x(1), 0];
fis.input(1).mf(7).params = [x(2), x(4)];
fis.input(1).mf(8).params = [x(3), x(5)];
fis.input(1).mf(9).params = [x(3), pi-x(5)];
fis.input(1).mf(10).params = [x(2), pi-x(4)];
fis.input(1).mf(11).params = [x(1), pi];
% fis.input(1).mf(3).params = [x(3), x(5)-pi, pi/100, -pi/2];
% fis.input(1).mf(4).params = [pi/100, -pi/2, x(3), -x(5)];
% fis.input(1).mf(8).params = [x(3), x(5), pi/100, pi/2];
% fis.input(1).mf(9).params = [pi/100, pi/2, x(3), pi-x(5)];
end