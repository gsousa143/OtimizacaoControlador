function speeds = flc_ddmr(phi,l,fis_params)
n_points = 101;

%input Angular Error
angular_error = [
    gauss_mf(phi,fis_params(1),-pi);
    gauss_mf(phi,fis_params(2),fis_params(4)-pi);
    gauss_mf(phi,fis_params(3),fis_params(5)-pi);
    gauss_mf(phi,fis_params(3),-fis_params(5));
    gauss_mf(phi,fis_params(2),-fis_params(4));
    gauss_mf(phi,fis_params(1),0);
    gauss_mf(phi,fis_params(2),fis_params(4));
    gauss_mf(phi,fis_params(3),fis_params(5));
    gauss_mf(phi,fis_params(3),pi-fis_params(5));
    gauss_mf(phi,fis_params(2),pi-fis_params(4));
    gauss_mf(phi,fis_params(1),pi)];

%input Distance
distance = [
    linz_mf(l,0.01,0.02);
    lins_mf(l,0.01,0.02)];



%inference process
fuzzy_linear_speed = [
    min(distance(2), max([angular_error(1), angular_error(11)]) );
    min(distance(2), max([angular_error(2), angular_error(10)]) );
    min(1, max([angular_error(3), angular_error(4), angular_error(8), angular_error(9),distance(1)]) );
    min(distance(2), max([angular_error(5), angular_error(7)]) );
    min(distance(2), max([angular_error(6)]))];

fuzzy_angular_speed = [
    min(distance(2), max([angular_error(4), angular_error(5), angular_error(9), angular_error(10)]) );
    min(1, max([angular_error(1), angular_error(11), angular_error(6),distance(1)]) );
    min(distance(2), max([angular_error(2), angular_error(3), angular_error(7), angular_error(8)]) )];

x_linear_speed = linspace(-0.15,0.15,n_points);
x_angular_speed = linspace(-0.5,0.5,n_points);

fuzzy_agg_linear_speed = max([ ...
    min(fuzzy_linear_speed(1), pi_mf(x_linear_speed,-0.16,-0.15,-0.1,-0.05));
    min(fuzzy_linear_speed(2), pi_mf(x_linear_speed,-0.1,-0.05,-0.05,0));
    min(fuzzy_linear_speed(3), pi_mf(x_linear_speed,-0.05,0,0,0.05));
    min(fuzzy_linear_speed(4), pi_mf(x_linear_speed,0,0.05,0.05,0.1));
    min(fuzzy_linear_speed(5), pi_mf(x_linear_speed,0.05,0.1,0.15,0.16))], [],1);




fuzzy_agg_angular_speed = max([ ...
    min(fuzzy_angular_speed(1), linz_mf(x_angular_speed,-0.5,0));
    min(fuzzy_angular_speed(2), tri_mf(x_angular_speed,-0.5,0,0.5));
    min(fuzzy_angular_speed(3), lins_mf(x_angular_speed,0,0.5))], [],1);


%defuzzification
speeds = [
    sum(x_linear_speed.*fuzzy_agg_linear_speed)/sum(fuzzy_agg_linear_speed);
    sum(x_angular_speed.*fuzzy_agg_angular_speed)/sum(fuzzy_agg_angular_speed)];


%plot fuzzy agg output

% plot(linspace(-1,1,n_points), [fuzzy_agg_linear_speed;fuzzy_agg_angular_speed]);
% % legend(["Velocidade Linear","Velocidade Angular"],Location="northoutside",Orientation="horizontal",Box="off");
% ylim([-0.1, 1.1]);
% drawnow;

% drawnow;

end


%membership functions
function y = lins_mf(x,a,b)
y = zeros(size(x),'like',x);
if a<b
    y(x>=b) = 1;
    id = x>=a & x<=b;
    y(id) = (x(id)-a)/(b-a);
end
end

function y = linz_mf(x,a,b)
y = zeros(size(x),'like',x);

if a<b
    y(x<a) = 1;
    id = x>=a & x<b;
    y(id) = (b-x(id))/(b-a);
end
end

function y = gauss_mf(x,a,b)
y = exp( (-(x-b).^2)/(2*a^2) );
end

function y = tri_mf(x,a,b,c)
y = zeros(size(x),'like',x);
if (a ~= b)
    id = find(a < x & x < b);
    y(id) = (x(id)-a)/(b-a);
end
if (b ~= c)
    id = find(b < x & x < c);
    y(id) = (c-x(id))/(c-b);
end
y(x == b) = 1;
end

function y = pi_mf(x,a,b,c,d)
y = zeros(size(x),'like',x);
y(x>b & x<c) = 1;
y(x>a & x<=b) = 2*((x(x>a & x<=b)-a)/(b-a)).^2;
y(x>=c & x<d) = 2*((x(x>=c & x<d)-d)/(d-c)).^2;
y(x>(a+b)/2 & x<=b) = 1-2*((x(x>(a+b)/2 & x<=b)-b)/(b-a)).^2;
y(x>=c & x<(c+d)/2) = 1-2*((x(x>=c & x<(c+d)/2)-c)/(d-c)).^2;
end
