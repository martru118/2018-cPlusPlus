//Lecture 7
#include <iostream>
#include <string>

using namespace std;

//declaration of functions
void hello(string name);

//you can overload a function by declaring it with a different
//number or type of parameter(s)
void hello(string fname, string lname);
void hello(int num);

int main() {
    //cout << "Hello Caleb!" << endl;
    hello("Caleb"); //this is a function call
    hello("Alexa");
    hello("Frede");
    hello("Dennis", "C");
    hello(123);
    char initial = 'C';
    hello(initial);
    bool alive = true;
    hello(alive);
    return 0;
    }

//Defintion of functions
void hello(string name) {
    cout << "Hello " << name << "!" << endl;
}

void hello(string fname, string lname) {
    cout << "Hi " << fname << " " << lname << "!" << endl;
}

void hello(int num) {
    cout << "Hello robot #" << num << "!" << endl;
}