//Lecture 3
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    /*type_casting_ex1.cpp*/
    int y1 = 2;
    int y2 = 3;

    float x1 = y1/y2;
    float x2 = (float)y1/y2;
    float x3 = float(y1/y2);

    cout << "(y1/y2) = " << x1 << endl;
    cout << "(float)y1/y2 = " << x2 << endl;
    cout << "float(y1/y2) = " << x3 << endl;


    /*char_to_int.cpp*/
    //Create a variable of type character
    char c1;

    //Get a character value from the user
    //and store in the variable
    cout << "Enter a character: ";
    cin >> c1;

    //Display the character value back to the user
    //as an integer
    cout << "The integer value of the ASCII character " << c1
        << " is " << int(c1) << endl;


    /*int_to_char.cpp*/
    //Create a variable of type character
    int x;

    //Get a character value from the user
    //and store in the variable
    cout << "Enter an integer: ";
    cin >> x;

    //Display the character value back to the user
    //as an integer
    cout << "The ASCII character value of the integer " << x
        << " is " << static_cast<char>(x) << endl;

}