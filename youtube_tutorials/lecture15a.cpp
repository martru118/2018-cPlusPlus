//Lecture 15: Pointers I
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int* intptr;

int main() {
    int *p1;    //pointer to an integer
    int t = 20;

    //point p1 to t's address
    p1 = &t;

    //display value and address of pointer
    cout << "value: *p1 = " << *p1 << "\t"
         << "address: p1 = " << p1 << endl;

    //display address and value of ordinary variable
    cout << "value: t = " << t << "\t"
         << "address: t = " << &t << endl;
}