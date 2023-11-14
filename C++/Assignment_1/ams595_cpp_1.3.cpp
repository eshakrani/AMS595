#include <iostream>
using namespace std; 

int main() {
    // print all elements of the Fibonacci sequence less than 4,000,000

    // declare and initialize the first 2 terms of the sequence:
    // f_1 = 1, f_2 = 2
    int f1 = 1, f2 = 2;

    // print these values to the console to start off the sequence
    cout << endl << "Fibonacci Sequence Under 4,000,000:" << endl;
    cout << f1 << endl << f2 << endl;

    // temporary variable to use in the loop
    int sum = 0;

    // use a while loop to continue printing out values until a number
    // greater than or equal to 4,000,000 appears
    while ((f1 + f2) < 4000000) {
        // calculate the current element by adding the previous two 
        sum = f1 + f2;

        cout << sum << endl;

        // reassign f2 -> f1 and sum -> f2 so f1 and f2 can be reused
        // in the next iteration of the loop
        f1 = f2;
        f2 = sum;
    }
    cout << endl;
}