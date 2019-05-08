//Lecture 7: Parameters in C++ (Youtube video)
#include <iostream>
#include <cstdlib>

using namespace std;

//declaring call-by-value function
int valueSquared(int a);

//declaring call-by-reference function
int refSquared(int& a);

int main() {
    int num = 8;
    int squarenum = 0;

    cout << "Memory address of num is: " << &num << endl;

    cout << "CALL-BY-VALUE PARAMETER EXAMPLE" << endl;
    squarenum = valueSquared(num);
    cout << "The square of " << num << " is " << squarenum << endl;

    cout << "CALL-BY-REFERENCE PARAMETER EXAMPLE" << endl;
    squarenum = refSquared(num);
    cout << "The square of " << num << " is " << squarenum << endl;

    return 0;
}

int valueSquared(int a) {
    /*
    the value of the variable is passed as a parameter
    the value is taken and gets copied 
    to a different location in memory where it gets stored
    */
    
    cout << "Memory address of a is " << &a << endl;
    a *= a;
    return a;
}

int refSquared(int& a) {
    /*
    passes the memory location (reference) of the parameter value
    instead of a copy of the parameter value
    take the variable and refer it to the same address
    variable and parameter are now referred to the same address
    changes made to paramter also effects the variable that is being passed
    */

    cout << "Memory address of a is " << &a << endl;
    a *= a;
    return a;
}
