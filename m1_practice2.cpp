//Create a program (save it as test1_q4.cpp) 
//that reads in course codes (e.g., CSCI1060U) 
//until the user enters “DONE”. 
//Each course code that is read in should be stored in an array of strings.
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
    string courseCode;
    int codesNum = 100;  //assume array has a size of 100
    string codeArray[codesNum] = {};

    for (int i = 0; i < codesNum; i++) {
        cout << "Enter the course code: ";
        cin >> courseCode;

        //when user enters done, break out of loop
        if (courseCode == "done" || courseCode == "DONE") {
            codesNum = i;
        }

        //add course code into an array
        codeArray[i] = courseCode;
    }

    //display list of course codes
    cout << "\nList of course codes: " << endl;
    for (int j = 0; j < codesNum; j++) {
        cout << codeArray[j] << endl;
    }
}
