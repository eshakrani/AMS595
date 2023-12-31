function [x] = GaussElim(A, b)
% GAUSSELIM function
%   x = GaussElim(A, b)
%   
%   INPUTS:
%   A: matrix of size (n x n) consisting of real numbers 
%   b: vector of size n consisting of real numbers
%
%   OUTPUTS:
%   x: vector of size n consisting of real numbers
%   x is the result of Gaussian elimination on A and b
%   Alternatively, Ax = b
    
    % if the user didn't correctly enter both inputs
    if nargin ~= 2
        fprintf('Inputs were not properly entered.\n');
        return

    else
        % check if A only has 2 dimensions
        if all(size(size(A)) == [1, 2]) == 0
            error(['Input A is not a 2-dimensional (n x n) ' ...
                'matrix.'])

        % check if A is a square matrix
        elseif size(A,1) ~= size(A,2)
            error('Input is not (n x n). Dimensions don''t match.')

        % check if b has the right number of elements
        elseif size(b,1) * size(b,2) ~= size(A,1)
            error('Input b does not have the correct dimensions.')
        elseif (size(b,1) == 1 && size(b,2) ~= size(A,1)) || (size(b,2) ...
                    == 1 && size(b,1) ~= size(A,1))
            error(['Input b must have the same length as the number ' ...
                'of rows in A'])
        end
    end

    % in case b is a horizontal vector, transpose it to make it vertical
    if size(b,1) == 1
        b = transpose(b);
    end

    % start Gaussian elimination process:

    % create the augmented matrix by combining A and b
    C = [A b];
    
    rows = size(A,1);

    % run the loop for each row in the matrix - 1
    % because in a matrix with n rows, only (n - 1) get reduced
    for i = 1 : rows - 1

        %disp(C(i, :))
        
        % for each subsequent row, figure out the multipler to eliminate 
        % the element under the current row's pivot element
        for j = i + 1 : rows

            % ex. reduce row 2 with the following multipler
            % m = C(2,1) / C(1,1)
            % for all x: C(2,x) = C(2,x) - m * C(1,x)
            mult = C(j, i) / C(i, i);

            % reduce the current row
            C(j, :) = C(j, :) - mult * C(i, :);
        end
    end

    %disp(C);

    % C is the reduced matrix 
    % now use backward substitution to solve for each element in x
    n = rows;
    x = zeros(n, 1);

    for i = n : -1 : 1
        % starting value is the reduced value of b in the ith position
        total = C(i, n + 1);

        % isolate x(i) by subtracting all other values of x from the total
        % and then dividing by the coefficient of x(i)
        %
        % initializing all x(i) values to 0 ensures that the same formula
        % can be used for each x(i) regardless of the number zero terms
        for j = n : -1 : 1
            total = total - C(i, j) * x(j);
        end

        % set the ith element in x to the calculated value
        % this new x(i) value will be used to calculate x(i-1) onwards
        x(i) = total / C(i, i);

    end
    
end

