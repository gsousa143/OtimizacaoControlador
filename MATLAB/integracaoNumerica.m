function [tempoFinal,X] = integracaoNumerica(X,u,tempoInicial,periodo,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p)  %#codegen
[tempos, Xs] = ode23(@(t,X) modeloUnificado(t,X,u,A_taum,V_TRACO,B_taum,M_TRACOi, R, L, F_s, F_k, alpha_s,alpha_k,k_i,k_p), [tempoInicial,tempoInicial+periodo] , X);
X = Xs(end,:)';
tempoFinal = tempos(end);
end



