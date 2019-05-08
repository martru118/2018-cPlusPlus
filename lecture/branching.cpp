//Lecture 4
#include <iostream>

using namespace std;

int main() {
    /*
    int x = 6;
    int y = 12;
    cout << "x is " << x 
         << " and y is " << y << endl;
    
    //switch the numbers with a temp variable
    int temp = 0;
    temp = x;
    x = y;
    y = temp;

    cout << "x is " << x
         << " and y is " << y << endl;
    
    //switch the numbers without the temp variable
    x += y; // x = 18
    y = x - y;
    x -= y;
    */


    /*branching_ex1.cpp*/
    //some variables for the example
    int x = 2;
    int y = 4;
    bool temp = true;
    
    if (x < y) {
        cout << "x is less than y!" << endl;
        if (temp) {
            cout << "(also temp is true)" << endl;
        }
    } else if (x > y) {
        cout << "x is greater than y!" << endl;
    } else {
        cout << "x is equal to y :(" << endl;
    }


    /*branching_ex2.cpp*/
    char mark = 'A';
    
    cout << "Enter your lab letter grade: ";
    cin >> mark;
    
    switch (mark) {
        case 'A':
            cout << "Awesome job!" << endl;
            break;
        case 'B':
            cout << "Good work!" << endl;
            break;
        case 'C':
            cout << "Keep at it!" << endl;
            break;
        case 'D':
        case 'F':
            cout << "Please schedule an appointment with your professor." << endl;
            break;
        default:
            cout << "This is not a real grade. Try again." << endl;
    }

    
    return 0;
}