function [pi_est, err_abs, err_rel] = MontePi(n)
% MONTEPI function
%   Approximates a value for pi by plotting n points within 
%   {x: [0,1], y: [0,1]} and counting how many points lie inside the 
%   unit circle in that quadrant
% 
%   The ratio of points inside the quarter-circle to total points in the 
%   first quadrant is approximately pi/4, so we multiply this by 4 to get
%   an estimated value for pi
%  
%   pi_est = MontePi(n)
%
%   INPUTS:
%   n: integer - the total number of points being plotted
%
%   OUTPUTS:
%   pi_est: float - approximate value for pi
%   err_abs: float - absolute error between approximate pi and exact pi
%   err_rel: float - relative error between approximate pi and exact pi


    % helper function to calculate Euclidean distance between two points
    function d = dist(x1, y1, x2, y2)
        d = ((x1 - x2)^2 + (y1 - y2)^2)^(1/2);
    end

    % variable to count the number of points inside the unit circle
    count = 0;

    % generate n points
    for i = 1 : n
        x1 = rand();
        y1 = rand();

        % if the distance between this point and the origin is 
        % less than or equal to 1, then the point is inside the unit circle
        if dist(x1, y1, 0, 0) <= 1
            count = count + 1;
        end
    end

    pi_est = round((count / n) * 4, 6);

    % abs. error = | pi_exact - pi_approx. |
    err_abs = abs(pi - pi_est);

    % rel. error = | pi_exact - pi_approx. | / pi_exact
    err_rel = abs(pi - pi_est) / pi;

end