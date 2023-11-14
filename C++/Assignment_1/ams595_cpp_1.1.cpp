// import statements for basic i/o operations and other standard C++ functionality
#include <iostream>
using namespace std; 

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
int main() {

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
    
    return 0;
}