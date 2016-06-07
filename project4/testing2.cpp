/*
This program snippet will be used with some degree of modification for the implementation of getRightTriangle
function in triangle class...
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    unsigned long l, h;
    cout << "Enter the lower bound: ";
    cin >> l;
    cout << "Enter the upper bound: ";
    cin >> h;

    unsigned long a, b, c;
    for (a = 3; a < h/2; a++){
        for (b = a+1; b < h/2; b++){
            for (c = b+1; c < h/2; c++){
                if ((a+b+c > l) && (a+b+c < h) && (pow(c,2) == pow(a,2) + pow(b,2))){
                    cout << h << '\t' << a << '\t' << b << '\t' << c << endl;
                }
            }
        }
    }
}
