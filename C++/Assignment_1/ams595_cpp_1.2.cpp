// **** USE WITH C++ 11 OR HIGHER **** 
#include <iostream>
using namespace std; 

void print_vector(vector<int>& v) {
    // use a for-each loop to iterate 
    // through the vector and print each element
    for (auto i : v) {
        cout << i << "  ";
    }
    cout << endl;
}

int main() {

    // Test 1:
    vector<int> v = {1, 2, 3};
    print_vector(v);

    // Test 2:
    vector<int> v2;
    for (int i = 0; i < 16; i++) {
        v2.push_back(2 * i);
    }
    print_vector(v2);

    return 0;
}