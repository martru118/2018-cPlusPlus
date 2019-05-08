//Lecture 15: Pointers (Youtube video)
#include <cstdlib>
#include <iostream>

using namespace std;
typedef int* intptr;

void myfunction(intptr &p2);

int main() {
    intptr p1;  //pointer to an integer
    int t = 20;

    //point p1 to t's address
    p1 = &t;

    //copy of the address is passed
    myfunction(p1);

    //display value and address of pointer
     cout << "value: *p1 = " << *p1 << "\t"
         << "address: p1 = " << p1 << endl;
        
     cout << "value: t = " << t << "\t"
         << "Address: &t = " << &t << endl;

     return 0;
}

void myfunction(intptr &p2) {
    int x = 5;
    p2 = &x;

    cout << "value: x = " << x << "\t"
         << "Address: &x = " << &x << endl;

    cout << "value: *p2 = " << *p2 << "\t"
         << "address: p2 = " << p2 << endl;
}