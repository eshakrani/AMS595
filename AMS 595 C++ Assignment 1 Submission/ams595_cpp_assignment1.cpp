// import statements for basic i/o operations and other standard C++ functionality
#include <iostream>
#include <vector>
using namespace std;


// ******* Q2 ************** //
/** @brief Prints out every element in a vector
 *  @param v the vector to print
 *  @return Void
 */
void print_vector(vector<int> v) {
    // use a for-each loop to iterate 
    // through the vector and print each element
    for (auto i : v) {
        cout << i << "  ";
    }
    cout << endl;
}
// ******* Q2 END ************** //


// ******* Q4a ************** //
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
// ******* Q4a END ************** //

// ******* Q4b ************** //
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
// ******* Q4b END ************** //

// ******* Q4c ************** //
/** @brief Gets the prime factorization of an integer n
 *  @param n the integer to prime factorize
 *  @return a vector containing the elements of the prime factorization of n
 */
vector<int> prime_factorize(int n) {
    // vector to hold the prime factors of n
    vector<int> prime_factors;

    // if n itself is prime, then n is its only prime factor
    if (isprime(n)) {
        prime_factors.push_back(n);
        return prime_factors;
    }

    int limit = sqrt(n);

    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            while (n != 1 && n % i == 0) {
                prime_factors.push_back(i);
                n = n / i;
            }
        }
    }

    return prime_factors;
}

/** @brief Test cases for prime_factorize() function
 *  @return Void
 */
void test_prime_factorize() {
    vector<int> v1 = prime_factorize(2),
                v2 = prime_factorize(72),
                v3 = prime_factorize(196);
    cout << "Prime factors of 2:" << endl;             
    print_vector(v1);

    cout << endl << "Prime factors of 72:" << endl;
    print_vector(v2);

    cout << endl << "Prime factors of 196:" << endl;
    print_vector(v3);
}
// ******* Q4c END ************** //


// ******* Q5 ************** //
/** @brief Displays the first n rows of Pascal's triangle
 *  @param n the number of rows to display from the triangle
 *  @return Void
 */
void pascal_n_rows(int n) {
    // set up a vector of vectors to represent the n rows of the triangle
    // the inner vectors will be each row 
    vector<vector<int>> triangle;

    // starting from row 1, the ith row of the triangle has i elements
    // since each row starts and ends with 1, 
    // prefill each row with the i elements - all 1s
    for (int i = 1; i <= n; i++) {
        vector<int> row_i(i, 1);
        triangle.push_back(row_i);
    }

    /* 
    rows 1 and 2 are composed of only 1s
    for each row starting from row 3:
        to get element i, add elements at indices i and (i - 1)
        from the previous row
    */
    vector<int> current_row, prev_row; 
    for (int i = 2; i < triangle.size(); i++) {
        current_row = triangle[i];
        prev_row = triangle[i - 1];
        for (int j = 1; j < current_row.size() - 1; j++) {
            current_row[j] = prev_row[j - 1] + prev_row[j];
        }
        triangle[i] = current_row;
    }

    while(!current_row.empty()) {
        current_row.erase(current_row.begin());
    }
    while(!prev_row.empty()) {
        prev_row.erase(prev_row.begin());
    }

    for (auto v : triangle) {
        print_vector(v);
    }
}



int main() {

    char line[] = "__________________________________";

    // ******* Q1 ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 1:" << endl << endl;

    /* 
    MATLAB code to convert:
    n = input('Enter a number: ');

    switch n
        case -1
            disp('negative one')
        case 1
            disp('positive one')
        otherwise
            disp('other value')
    end
    */

    // C++ equivalent:

    // declare the variable that will be used to hold 'n'
    int n;

    // propt the user and read in the given value 
    cout << endl << "Enter a number: ";
    cin >> n;
    cout << endl;

    // switch statement with cases for each value of n
    switch(n) {
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl; 
            break;
        default:
            cout << "other value" << endl;
    }

    cout << endl;
    cout << "QUESTION 1 END" << endl;
    cout << line << line << line << endl;
    // ******* Q1 END ************** //

    cout << endl << endl;
    system("read -p 'Press Enter to continue to Q2...' ");

    // ******* Q2 ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 2:" << endl << endl;

    cout << "(Wrote the print_vector() function to print the contents of a vector object)" << endl;

    cout << endl;

    cout << "QUESTION 2 END" << endl;
    cout << line << line << line << endl;
    // ******* Q2 END ************** //

    cout << endl << endl;
    system("read -p 'Press Enter to continue to Q3...' ");


    // ******* Q3 ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 3:" << endl << endl;
    
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

    cout << "QUESTION 3 END" << endl;
    cout << line << line << line << endl;
    // ******* Q3 END ************** //

    cout << endl << endl;
    system("read -p 'Press Enter to continue to Q4a...' ");

    // ******* Q4a ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 4a:" << endl << endl;

    test_isprime();

    cout << endl;

    cout << "QUESTION 4a END" << endl;
    cout << line << line << line << endl;
    // ******* Q4a END ************** //

    cout << endl << endl;
    system("read -p 'Press Enter to continue to Q4b...' ");
    
    // ******* Q4b ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 4b:" << endl << endl;

    test_factorize();

    cout << endl;

    cout << "QUESTION 4b END" << endl;
    cout << line << line << line << endl;
    // ******* Q4b END ************** //

    cout << endl << endl;
    system("read -p 'Press Enter to continue to Q4c...' ");
    
    // ******* Q4c ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 4c:" << endl << endl;

    test_prime_factorize();

    cout << endl;

    cout << "QUESTION 4c END" << endl;
    cout << line << line << line << endl;
    // ******* Q4c END ************** //
    
    cout << endl << endl;
    system("read -p 'Press Enter to continue to Q5...' ");

    // ******* Q5 ************** //
    cout << endl;
    cout << line << line << line << endl;
    cout << "QUESTION 5:" << endl << endl;

    cout << "Display the first n rows of Pascal's Triangle" << endl;
    cout << "Enter n: ";
    cin >> n;
    cout << endl << endl;

    pascal_n_rows(n);

    cout << endl;

    cout << "QUESTION 5 END" << endl;
    cout << line << line << line << endl;
    // ******* Q5 END ************** //




    return 0;
}