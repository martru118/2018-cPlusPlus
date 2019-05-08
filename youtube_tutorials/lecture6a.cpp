//Lecture 6: Functions in C++ (Youtube Video)
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //using cmath library for math operations
    /*
    cout << "sqrt(5.0) = " << sqrt(5.0) << endl;
    cout << "pow(2.0, 3.0) = " << pow(2.0, 3.0) << endl;
    */

    /*
    every instance that the program is run and time function gets called
    it actually returns a different value
    which means you use a different seed 
    which means you get a different set of numbers
    */
    cout << "Current time: " << time(NULL) << endl;
    
    /*
    set seed for random numbers
    otherwise rand will return the same value
    whenever the program runs
    */
    srand(time(NULL));
    //generate random number between 0 to 39
    cout << rand()%40 << endl;
    cout << rand()%40 << endl;
    cout << rand()%40 << endl;
    cout << rand()%40 << endl;

    return 0;
}
