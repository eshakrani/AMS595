#include "pi_approx.h"

/** @brief written function to mimic the mathematical function used with the trapezoidal rule
 *  @param x the input to the function
 *  @return the value of the function f at x
 */
double fx(double x) {
    return sqrt(1 - pow(x, 2));
}

/** @brief approximates the value of pi using the trapezoidal rule on a quarter circle
 *  @param N the number of intervals used 
 *  @return a struct containing two values:
 *          - approx: the approximated value of pi
 *          - error:  the error between the calculated and actual values of pi
 */
PiResults pi_approx(int N) {

    // partition the interval [0, 1] into N segments
    double seg_size = 1.0 / N;

    // variables used during calculations:
    // running total during the summation process
    double total = 0;

    // the start and end points of each interval
    // x1 and x2 initialized to 0 and (0 + delta_x), then
    //   updated during each loop iteration
    double x1 = 0, x2 = seg_size;

    // temporary variable used for intermediate calculations
    double temp;

    // perform the summation for the trapezoidal rule
    for (int i = 0; i < N - 1; i++) {
        temp = fx(x1) + fx(x2);
        temp /= 2;
        temp *= seg_size;
        total += temp;

        // update x1 and x2
        x1 = x2;
        x2 = x1 + seg_size;
    }

    total += fx(x1) * seg_size / 2;

    // since the above calculation is used to approximate pi/4, 
    // get an approximation for pi itself by multiplying by 4
    double pi_approximation = total * 4;

    // calculate absolute error by subtracting the approximation from the actual value,
    // then taking the absolute value of the result
    double abs_error = abs(M_PI - pi_approximation);

    // compile the approximation and error into a struct (to be returned from the function)
    PiResults results = {.approx = pi_approximation, 
                         .error  = abs_error};

    return results;
}