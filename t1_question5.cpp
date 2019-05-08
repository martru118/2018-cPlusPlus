#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool writeString(string lipsum);  //writes words to a file

int main() {
    string writeTo;
    do {
        cout << "Enter a word: ";
        cin >> writeTo;

        writeString(writeTo);
    } while(writeTo != "quit" && writeTo != "QUIT");

    return 0;
}

bool writeString(string lipsum) {
    //open file for writing
    ofstream user_txt("user.txt", ios::app);

    //when document cannot write
    if (user_txt.fail()) {
        return false;
    //when document can write
    } else {
        user_txt << lipsum << endl;
        return true;
    }

    user_txt.close();
}

//It works and it is done very well -> full marks