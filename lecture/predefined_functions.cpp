//Lecture 6
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    //using predefined functions in cmath

    float result = sqrt(5.0);
    cout << "The square root of 5 is " << result << endl;

    int base, expo;
    cout << "Enter base: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> expo;

    int power = base;
    if (expo == 0) {
        power = 1;
    } else {
        for (int i = 1; i < expo; i++) {
            power += base;
        }
    }

    cout << base << "*" << expo << " = " << power << endl;
    cout << base << "^" << expo << " = " << pow(base,expo) << endl;

    //display time
    srand(time(NULL));
    cout << "Current time: " << time(NULL) << endl;
    //display random integer
    for (int i = 0; i < 5; i++) {
        cout << "random = " << rand() << endl;
    }

    //cout << "What does time(NULL) produce as output? "
    //     << time(NULL) << endl;
    srand(time(NULL)); // set seed for random number
    int count = 1;
    cout << "How many random numbers do you need? ";
    cin >> count;

    for (int i=0; i < count; i++) {
    cout << "rand() = " << rand()%100 << endl;
    }
   

    return 0;
}
