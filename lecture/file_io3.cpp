//Lecture 8
//example of handling file access issues/errors during reading and writing
#include <iostream> //library for terminal input/output
#include <string> //library for strings
#include <fstream> //library for file input/output
#include <cstdlib>

using namespace std;

int main() {
    string filename;
    const int SIZE = 5; //size of data array
    string data[SIZE];

    //FILE OUTPUT
    cout << "Enter output filename: ";
    cin >> filename;
    //ofstream myOutput;
    //myOutput.open(filename);
    //the above two lines are the same as...
    ofstream myOutput(filename, ios::app);

    //check if the fstream encountered an error
    //when opening
    if(myOutput.fail()) {
        cout << "ERROR: no permissions to write to file"
            << filename << endl;
        exit(1);
    }

    cout << "Enter " << SIZE
         << " words to store in a file in reverse order: ";
    for (int i=0; i < SIZE; i++) {
        cin >> data[i];
    }

    //write to file
    for (int i = SIZE-1; i >= 0; i--) {
        myOutput << data[i] << endl;
    }

    //Always close the file when finished
    myOutput.close();

    //FILE INPUT
    cout << "Reading in " << filename << "..." << endl;
    ifstream myInput(filename);

    if(myInput.fail()) {
        cout << "ERROR: no permissions to read from file"
            << filename << endl;
        exit(1);
    }

    //Read from the filename
    while(!myInput.eof()) {
        string line;
        myInput >> line;
        cout << line << endl;
    }

    //Close the file
    myInput.close();

    return 0;
}