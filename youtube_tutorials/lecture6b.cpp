//Lecture 6: Functions in C++ (Youtube Video)
#include <iostream>
#include <cstdlib>

using namespace std;

//declaration of functions
//ensures the compiler knows the name of the function
void hello(string name);

//overloading functions
void hello(string fname, string lname);

int main() {
    //function calls
    hello("Spencer");
    hello("Micheal");
    hello("John", "Doe");
    hello("Rebecca");

    return 0;
}

//definition of functions
void hello(string name) {
    cout << "Hello " << name << endl;
}

void hello(string fname, string lname) {
    cout << "Hello " << fname << " " << lname << endl;
}
