function [x] = GaussElim(A, b)
% GAUSSELIM function
%   x = GaussElim(A, b)
%
%   A: matrix of size (n x n) consisting of real numbers 
%   b: vector of size n consisting of real numbers
%
%   x: vector of size n consisting of real numbers
%   x is the result of Gaussian elimination on A and b
%   Alternatively, Ax = b
    
    % if the user didn't correctly enter both inputs
    if nargin ~= 2
        fprintf('Inputs were not properly entered.\n');
        return

    else
        x = [1, 2, 3];
    end

    
end

