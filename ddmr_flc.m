classdef DDMR_FLC < matlab.System
    % untitled Add summary here
    %
    % This template includes the minimum set of functions required
    % to define a System object.

    % Public, tunable properties
    properties

    end

    % Pre-computed constants or internal states
    properties (Access = private)
        R = 0; L = 0; alpha_s= 0 ; alpha_k=0; f_s=0; f_k=0; V=zeros(2,2); A_tau=zeros(2,2); B_tau=zeros(2,2); M_i=zeros(2,2); k_i=0; k_p=0; T = 0.01;
        n_points = 101;
        angular_error_params = [pi/11, pi/11, pi/11, pi/11, 2*pi/11];
    end

    methods (Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function y = stepImpl(obj,u)
            % Implement algorithm. Calculate y as a function of input u and
            % internal states.
            y = u;
        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end
    end
end
