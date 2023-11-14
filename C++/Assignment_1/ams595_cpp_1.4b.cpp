#include <iostream>
using namespace std;

// function to print vectors from Problem 1.2
void print_vector(vector<int>& v) {
    for (auto i : v) {
        cout << i << "  ";
    }
    cout << endl;
}

/** @brief Finds all the factors of the given integer
 *  @param n the integer to factorize
 *  @return a vector containing each multiple of n in ascending order
 */
vector<int> factorize(int n) {
    // vectors to hold the factors of n
    vector<int> factors; 

    /* use a for loop to check whether the numbers from 1 to sqrt(n) 
       go into n evenly - if m goes evenly into n, then m is a factor
       - at the same time as finding a factor m, we can also find its
         complement by dividing n by m and taking the quotient
       
       only need to check up to sqrt(n) because any number greater than
       sqrt(n) will not multiply to n with a whole number
    */
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // i is a factor
            factors.push_back(i);

            // find the other factor by dividing n by i
            factors.push_back(n/i);
        }
    }
    
    // sort the factors into ascending order
    sort(factors.begin(), factors.end());
    
    return factors;
}

/** @brief Test cases for the factorize() function
 *  @return Void
 */
void test_factorize() {
    vector<int> v1 = factorize(2),
                v2 = factorize(72),
                v3 = factorize(196);
    cout << "Factors of 2:" << endl;             
    print_vector(v1);

    cout << endl << "Factors of 72:" << endl;
    print_vector(v2);

    cout << endl << "Factors of 196:" << endl;
    print_vector(v3);
}

int main() {
    cout << endl; 

    test_factorize();

    cout << endl;
}