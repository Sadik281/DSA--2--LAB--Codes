/*Power Function Implementation
Last Updated : 4 Apr, 2026
Given two numbers b(base) and e(exponent), calculate the value of be.

Examples: 

Input: b = 3.00000, e = 5
Output: 243.00000

Input: b = 0.55000, e = 3
Output: 0.16638

Input: b = -0.67000, e = -7
Output: -16.49971?*/
#include<iostream>
#include<cmath>
using namespace std;
int powercalc(double b, int e) {
    if (e == 0) {
        return 1; // Any number raised to the power of 0 is 1
    }
    double result = 1.0;
    int absExponent = abs(e);
    
    for (int i = 0; i < absExponent; ++i) {
        result *= b;
    }
    
    if (e < 0) {
        result = 1.0 / result; // If exponent is negative, take reciprocal
    }
    
    return result;
}
int main() {
    double base;
    int exponent;
    
    cout << "Enter base (b): ";
    cin >> base;
    cout << "Enter exponent (e): ";
    cin >> exponent;
    
    double result = powercalc(base, exponent);
    
    cout << "Result: " << result << endl;
    
    return 0;
}