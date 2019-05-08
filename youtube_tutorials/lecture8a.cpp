#include <iostream>
#include <fstream>  //file i/o library
#include <string>

using namespace std;

int main() {
    const int lines = 5;
    string input[lines];
    string a_out;

    cout << "Enter output filename: " << endl;
    cin >> a_out;
    ofstream readTXT(a_out, ios::app);   //create an output file stream
    //ios::app appends to the file rather than overwriting it
    /*
    ofstream txt;
    txt.open(a_out);
    */

    cout << "Enter in 5 lines of text to store in a file:" << endl;
    for (int i = 0; i < lines; i++) {
        cin >> input[i];
    }

    //output odd lines to file
    for (int i = 0; i < lines; i += 2) {
        cout << ".";
        readTXT << input[i] << endl;    //outputs input[i] to the file
    }
    cout << "\nFile writing complete." << endl;

    readTXT.close();    //close the file


    //overwrite the file contents
    cout << "Reading in " << a_out << endl;
    ifstream writeTXT(a_out);   //create an inout file stream

    string str;

    //read from the file
    do {
       writeTXT >> str;
       cout << str << endl; 
    } while (!writeTXT.eof());
    
    
    writeTXT.close();   //close the file

    return 0;
}