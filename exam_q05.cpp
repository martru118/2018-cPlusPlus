#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string courseCodes;
    const int courses = 5;
    string schedule[courses] = {};
    int inputs = 0;

    ofstream output("courses.txt", ios::app);   //open the file for reading
    
    //input course codes
    cout << "Enter " << courses << " course codes:" << endl;
    do {
        cin >> courseCodes;
        schedule[inputs] = courseCodes;

        inputs += 1;
    } while (inputs < courses);

    for (int i = 0; i < courses; i++) {
        output << schedule[i] << ", ";
    }
    
    output.close();     //close the file
}
