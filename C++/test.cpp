#include <iostream>
using namespace std;

int main() {
    int a = 25;
    int *b = &a;
    cout << *(b+1) << endl << *(b++) << endl;
}