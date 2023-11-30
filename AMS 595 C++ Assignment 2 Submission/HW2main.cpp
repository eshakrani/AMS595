#include <iostream>
#include "pi_approx.h"
#include "approximations.h"

using namespace std;

int main() {

    cout << endl << endl;
    
    // print the pi approximation and error for N = 10000
    int N = 10000;
    PiResults r1 = pi_approx(N);
    cout << "For N = 10000:" << endl;
    cout << "Pi Approximation: " << r1.approx << endl;
    cout << "Absolute Error: " << r1.error << endl << endl;

    // create a vector with elements (10^1, 10^2, ... , 10^7)
    int tens = 10;
    vector<int> intervals;
    for(int i = 0; i < 7; i++) {
        intervals.push_back(tens);
        tens *= 10;
    }

    cout << endl << endl;

    cout << "Pi Approximations:" << endl;

    // pass this vector as an input to the approximations() function
    double* appr = approximations(intervals);
    
    // display the results
    for(int i = 0; i < 7; i++) {
        cout << "N = " << intervals[i] << ": " << endl;
        cout << appr[i] << endl << endl;
    }

    // delete the allocated memory after displaying
    delete[] appr;

}