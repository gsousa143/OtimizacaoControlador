function Xponto = modeloUnificado(t,X,u,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p)


A_cin = R/2*[
    cos(X(3)), cos(X(3));
    sin(X(3)), sin(X(3));
    1/L, -1/L];




tau_F = [
    F_k*tanh(alpha_k*X(4)) - F_s*tanh(alpha_s*X(4));
    F_k*tanh(alpha_k*X(5)) - F_s*tanh(alpha_s*X(5))];


eta = [
    X(4);
    X(5)];

epi = [
    X(6);
    X(7)];

Y_pi = min(12, max( k_i*epi + k_p*(u-eta), -12) );


Xponto = [
    A_cin*eta; 
    M_TRACOi*((A_taum+(R/2*[1/L,-1/L]*eta*V_TRACO))*eta - B_taum*Y_pi - tau_F);
    u-eta];
end