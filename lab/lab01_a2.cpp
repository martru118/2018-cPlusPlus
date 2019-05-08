#include <iostream>
#include <string>

using namespace std;

int main() {
    //67 83 67 73 32 49 48 54 48 85 
    
    string courseCode = "CSCI 1060U";
    //cycle through every character of courseCode
    for (int i=0; i<courseCode.length();i++) { 
        //convert each character to integer
        cout << int(courseCode[i]) << endl;
    }
    
    
    return 0;
}