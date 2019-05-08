//Lecture 15
#include <cstdlib>
#include <iostream>
typedef int* IntPtr;

using namespace std;

void printPointer(int *pointer, string name);
void myFunction(IntPtr some_pointer);
void example1();
void example2();
void example3();

void printPointer(int *pointer, string name) {
    cout << name << " = " << pointer << " ⇒ " << *pointer << endl;
}

void myFunction(IntPtr some_pointer) {
    *some_pointer = 100;
    //change the value at the address
}

void example1() {
    cout << "--ex1--" << endl;
    int x = 0;
    int *pointer = &x;

    //go to pointer and go to the value at this address
    *pointer = 12;
    printPointer(pointer, "pointer");
    cout << "X = " << x << " [address of X = " << &x << "]" << endl;
}

void example2() {
    cout << "--ex2--" << endl;
    int x = 0;
    IntPtr pointer = &x;

    myFunction(pointer);
    printPointer(pointer, "pointer");
    cout << "X = " << x << " [address of X = " << &x << "]" << endl;
}

void example3() {
    cout << "--ex3--" << endl;
    //takes blocks of four bites in memory
    int some_array[] = {10, 11, 12, 13};
    int *pointer = some_array;

    /*
    printPointer(some_array, "*some_array[0]");
    *some_array = 100;  //changes the first index of the array
    printPointer(some_array, "*some_array[0]");
    printPointer(some_array + 1, "some_array[1]");   //point to the next index
    //increment by whatever datatype that is held
    //from the pointer jump by 4 bytes
    *(some_array + 1) = 101;    //some_array[1] = 101
    printPointer(some_array + 1, "some_array[1]");
    */

    //print the whole array
    cout << "Array before:" << endl;
    for(int &element: some_array) {
        cout << &element << " ⇒ " << element << endl;
    }

    //apply modifications
    printPointer(pointer++, "pointer[0]");
    printPointer(pointer++, "pointer[1]");
    printPointer(pointer++, "pointer[2]");
    *pointer = 99;
    printPointer(pointer++, "pointer[3]");
    printPointer(pointer, "?");

    cout << "\nArray after:" << endl;
    for(int &element: some_array) {
        cout << &element << " ⇒ " << element << endl;
    }    

}

int main(int argc, char const *argv[])
{
    cout << "--------------LECTURE 14--------------" << endl;
    //example1();
    //example2();
    example3();

    return 0;
}

/*
     int x = 45; //x is an automatic/ordinary variable
     IntPtr p1;  //same as int *p1

     //p1 = &x;
     p1 = new int;   //create a dynamic variable

     *p1 = 50;

     cout << "p1 value: " << *p1 << "\t" << "*p1 address: " << &p1  << endl;

     delete p1; //delete dynamic variable

     IntPtr p2 = new int;
     IntPtr p3 = new int;

     const int a_size = 30;
     IntPtr p1;

     p1 = new int[a_size];

     for(int i = 0; i < a_size; i++) {
          p1[i] = i;
          //*(p1+i) = i;   //same as previous line

          cout << "p1[" << i << "] value = " << p1[i] << ",  "
               << "p1[" << i << "] address = " << (p1+i) << endl;
     }
*/

/*
int main() {
    int *p1; //pointer to an integer (called a pointer variable)
    int t = 20; //an automatic variable (also called an ordinary variable)

    //point p1 to t's address
    p1 = &t;

    //display value and address of pointer variable
    cout << "value: *p1 = " << *p1 << "\t" << "address: p1 = " << p1 << endl;

    //display value and address of ordinary variable
    cout << "value: t = " << t << "\t" << "address: &t = " << &t << endl;


    delete[] p1;

    return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

//define our own type!
typedef int* IntPtr;

void myFunction(IntPtr p2);

int main() {
  IntPtr p1; //same as int *p1;
             //pointer to an integer
             // (called a pointer variable)
  int t = 20; //an automatic variable
              //(also called an ordinary variable)

  //point p1 to t's address
  p1 = &t;

  myFunction(p1);

  //display value and address of pointer variable
  cout << "value: *p1 = " << *p1 << "\t"
       << "address: p1 = " << p1 << endl;

  //display value and address of ordinary variable
  cout << "value: t = " << t << "\t"
       << "address: &t = " << &t << endl;

  return 0;
}

void myFunction(IntPtr p2) {
  *p2 = 10;

  int x = 5;
  p2 = &x;
  cout << "value: *p2 = " << *p2 << "\t"
       << "address: p2 = " << p2 << endl;
  cout << "value: x = " << x << "\t"
      << "address: &x = " << &x << endl;

}
*/


//NOTES
/*
Pointers are a datatype hold the address of a value
Go to that variables address, make changes

WHat datatype is the pointer is pointing to?
Be very conscious when passing parameters by pointer
Passing pointers cause permanent changes to a value
*/
