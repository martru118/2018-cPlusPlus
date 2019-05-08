//Lecture 2 (Youtube video)
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double x = 2.0;

    //output double with n decimal point 
    //(inside brackets of setprecision function)
    cout << fixed << setprecision(1);
    cout << "x = " << x << endl;    //2.0

    //floating point division with float and int
    double y = 4.0/3;
    cout << "y = " << y << "\n";    //1.3

    //integer division
    double z = 10/3;
    cout << fixed << setprecision(2);
    cout << "z = " << z << endl;
    return 0;
}