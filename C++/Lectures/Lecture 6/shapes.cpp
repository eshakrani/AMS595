#include "shapes.h"
#include <iostream>
using namespace std;

int main(){
    double side, base, height;
    cout << "Enter the side length of the square: ";
    cin >> side;
    cout << "The area of the square is: " << square(side) << endl;
    cout << "Enter the base length of the triangle: ";
    cin >> base;
    cout << "Enter the height of the triangle: ";
    cin >> height; 
    cout << "Your triangle has area: " << triangle(base, height) << endl;
}