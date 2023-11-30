#include "approximations.h"

/** @brief computes approximations for pi using the trapezoidal rule
 *         with various numbers of intervals
 *  @param n_list a vector containing values, each representing a number of intervals
 *  @return a pointer to an array containing the pi approximations for each value in n_list
 */
double* approximations(std::vector<int> n_list) {
    // use the size of the input vector to determine the length of the result array
    int num = n_list.size();
    double* results = new double[num];

    // iterate through the vector, use each element as an input to the pi_approx function
    // since the output of pi_approx() is a PiResults struct, extract the 'approx' attribute
    // store this value in its corresponding spot in the results array
    double appr;
    for(int i = 0; i < num; i++) {
        appr = pi_approx(n_list[i]).approx;
        results[i] = appr;
    }

    return results;
}