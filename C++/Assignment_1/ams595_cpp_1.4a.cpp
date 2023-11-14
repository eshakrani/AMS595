#include <iostream>
using namespace std; 

/** @brief Determines if an integer is prime or not
 * 
 *  Special case: 1 is neither prime nor composite - treated as false
 *
 *  @param n The integer to test for primality
 *  @return true if the integer is prime, false otherwise
 */
bool isprime(int n) {
    // any number less than 2 (including 1) is not prime
    if (n < 2) {
        return false;
    }

    /* use a for loop to check whether n is evenly divisible 
       by every number from 2 to (n/2)

       only need to check from 2 to halfway to n because any 
       number past (n/2) would need a value >1.0 and <2.0
       to multiply to n, which means it is not evenly divisible

       2 is prime, but even though the code inside the loop would
       result in 2 being marked false, the correct result of true
       still gets marked for 2 because the loop will not activate
       due to n=2 not fulfilling the loop's condition
    */
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    // if this code was reached, then n was not evenly divisible by 
    // any numbers from 2 to (n/2) --> can conclude that n is prime
    return true;
}

/** @brief Test cases for the isprime() function
 *  @return Void
 */
void test_isprime() {
    // array used to convert from 1/0 values to "true"/"false"
    const char* words[2] = {"false", "true"};
    cout << "isprime(2) = " << words[isprime(2)] << '\n';
    cout << "isprime(10) = " << words[isprime(10)] << '\n';
    cout << "isprime(17) = " << words[isprime(17)] << '\n';
}

int main() {
    cout << endl;

    test_isprime();
    
    cout << endl;
}