% -------------------------------------------------------------------
%  File name: MontePiPlots.m
%  Author: Eshan Shakrani
%  Date: 09/17/2023
% -------------------------------------------------------------------
    
% for varying values of n:
% 1. plot execution time with respect to n 
% 2. plot approximate values of pi with respect to n
% for a fixed value of n
% 3. plot the points in real-time with points inside the circle having
%    a different color than points outside the circle; print the estimated
%    value of pi on the plot

% close all figures currently open
close all  

% values of n to test
n_vals = [1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000];

% list to hold the execution times for various values of n
exec_times = zeros(length(n_vals), 1);

% list to hold the pi approximations for various values of n
pi_est_list = zeros(length(n_vals), 1);


% run the following code for each value of n being tested
for ind = 1 : length(n_vals)

    start_time = tic();

    n = n_vals(ind);

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
   
    % build the lists of approximate pi values and executions times
    pi_est_list(ind) = pi_est;

    duration = toc(start_time);

    exec_times(ind) = duration;

    fprintf("Completed n = %d\n", n);
    
end

set(gcf, 'Position', [300, 100, 1300, 1000])

% first plot: Execution time vs. n
fprintf("Generating Plot 1...\n")
subplot(3, 1, 1)
semilogx(n_vals, exec_times, '-o', 'MarkerSize', 8, 'LineWidth', 5)
xlabel("n", 'FontSize', 16, 'Interpreter', 'tex')
ylabel("Execution Time (sec)", 'FontSize', 16, 'Interpreter', 'tex');
ylim([-1, max(exec_times) + 1])
title("Program Execution Time vs. Number of Points Plotted, n", ...
    'FontSize', 16, 'Interpreter', 'tex')
text(n_vals, exec_times - 0.65, string(exec_times), 'FontSize', 12) 

% second plot: Approx. pi vs. n
fprintf("Generating Plot 2...\n")
subplot(3, 1, 2)
semilogx(n_vals, pi_est_list, 'r-o', 'MarkerSize', 8, 'LineWidth', 5)
xlabel("n", 'FontSize', 16, 'Interpreter', 'tex')
ylabel("Approximate value of \pi", 'FontSize', 16, ...
    'Interpreter', 'tex')
ylim([0, max(pi_est_list) + 1])
title("\pi Approximation vs. Number of Points Plotted, n", ...
    "FontSize", 16, 'Interpreter', 'tex')
text(n_vals, pi_est_list + 0.65, string(pi_est_list), 'FontSize', 12)


% third plot: real-time generation and plotting of points
fprintf("Generating Plot 3...\n")
subplot(3, 1, 3)
set(gca, 'color', '#adadad')

axis([0, 1, 0, 1])

% fixed value of n: 
n = 200;

% points to plot the quarter circle
circ_x = 0 : 0.01 : 1;
circ_y = (1 - (circ_x.^2)).^(1/2);
plot(circ_x, circ_y, 'Color', 'black', 'LineWidth', 6);

% label the quarter circle with its equation
text(0, 1.1, '$y = \sqrt{1 - x^2}; x\epsilon[0, 1]$', ...
    'Interpreter', 'latex', 'FontSize', 16, 'Color', 'black', ...
    'FontWeight', 'bold')

title_text = ['Plotting ', num2str(n), ' Points on x\epsilon[0,1], ' ...
    'y\epsilon[0,1] in Relation to the Unit Circle'];
title(title_text, 'FontSize', 16, 'Interpreter', 'tex')

xlabel("x", 'FontSize', 16, 'Interpreter', 'tex')
ylabel('y', 'FontSize', 16, 'Interpreter', 'tex')


hold('on')




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
        % points inside the circle are red
        scatter(x1, y1, 'r', 'filled')
        drawnow;
    else
        % points outside the circle are blue
        scatter(x1, y1, 'b', 'filled')
        drawnow;
    end

    % keep user updated on current progress
    if mod(i, 10) == 0
        fprintf("Iteration %d/%d...\n", i, n);
    end
end


hold('off')




% approximated value for pi
pi_est = round((count / n) * 4, 6);

% show the approx. pi value on the plot
pi_text = ['\pi \approx ', num2str(pi_est, 4)];
text(0.5, 0.5, pi_text, 'Interpreter', 'tex', 'FontSize', 24, ...
    'color', 'black')

% print approx. pi value to the console
fprintf('Pi approximation: %f\n', pi_est);

saveas(gcf, 'hw1_plots.png', 'png')
   
% helper function to find distance between two points
function d = dist(x1, y1, x2, y2)
    d = ((x1 - x2)^2 + (y1 - y2)^2)^(1/2);
end