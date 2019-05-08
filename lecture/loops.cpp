//Lecture 5
#include <iostream>

using namespace std;

int main() {

    /*loop_ex1.cpp*/
    //for loop for adding every even number from 0 to 100
    int sum = 0;
    for (int i = 0; i <= 100; i++) {    //start; end; increments

        if (i % 2 == 0) {   //if i/2 has a remainder of 0
            cout << "i = " << i << endl;
            sum += i;
        }
    }
    cout << "sum of even numbers = " << sum << endl;

    int sum = 0;
    //For loop for adding up even number
    for (int i = 0; i <= 100; i++) {
        //if i is even add it to the sum
        if (i%2 == 0) { //means if i/2 has a remainder of 0
            cout << "i = " << i << endl;
            //sum = sum + i;
            sum += i; // same as above line
            }
    }

    //create a for loop with no if or switch that adds up
    //the even numbers
    sum = 0;
    for (int i = 0; i <= 100; i=i+2) {}
    cout << "sum of even numbers = " << sum << endl;


    /*loop_ex2.cpp*/
    //a while loop that works the same as below
    //for loop
    int sum = 0;
    int count = 0;
    while (count <= 100) {
        cout << "count = " << count << endl;
        if (count%2 == 0) {
        sum = sum+count;
        }
        count++; //count = count + 1;
    }
    cout << "sum of even numbers = " << sum << endl;

    /*
    int sum = 0;
    //For loop for adding up even number
    for (int i = 0; i <= 100; i++) {
    //if i is even add it to the sum
        if (i%2 == 0) { //means if i/2 has a remainder of 0
        cout << "i = " << i << endl;
        //sum = sum + i;
        sum += i; // same as above line
        }
    }
    cout << "sum of even numbers = " << sum << endl;
    */


    /*loop_ex3.cpp*/
    int x = 10000000;
    int y = 63;
    while (x%y != 0) {
        cout << x << " is not divisible by " << y << endl;
        x--; //x = x - 1;
    }
    cout << x << " is divisible by " << y << endl;


    /*loop_ex4.cpp*/
    //Create a variable of type character
    int x;

    //Get a character value from the user
    //and store in the variable
    cout << "Enter an integer: ";
    cin >> x;

    while(x > 0) {
        //Display the character value back to the user
        //as an integer
        cout << "The ASCII character value of the integer " << x
             << " is " << static_cast<char>(x) << endl;
        cout << "Enter an integer: ";
        cin >> x;
    }

}
