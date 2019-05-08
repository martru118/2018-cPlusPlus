//Lecture 14
#include <iostream>

using namespace std;

//void myfunc(int i);

int main()
{
/*
    int myInteger = 5;
    int mySecond = 2;
    int *mypointer;
    cout << myInteger << endl;

    mypointer = &myInteger;
    //*mypointer = *mypointer + 1;
    (*mypointer)++; 
    
    //myfunc(mySecond);

    int *p2;
    int x;
    x = 0;
    p2 = &x;
    *p2 = 12;
    cout << *p2 << " " << x;

    int i = 12; //initialize integer
    int *p1;    //initialize pointer
    p1 = &i;    //set p1 to point to i
    *p1 = 24;  //use *p1 to change to value of i to 24
    cout << i << endl;
*/
    double *p1;
    double mydouble = 2.2;
    double **p2;  //pointer to a pointer
    double myint = 7;
    p1 = &mydouble;
    //p2 = &myint;
    p2 = &p1;
    cout << **p2 << endl;

    //make p2 point the same thing as p1
    //by having the same datatype

    return 0;
}

/*
void myfunc(int i) 
{
    i += 1;
    cout << i;
}
*/



//NOTES
/*
There has to be enough memory allocated for the code to run
The memory prepares the compiler
Pointers are declared using an asterisk (*)
Pointers cannot point to an element with a different data type
Pointers are the only way for C++ to change memory needed

* means go to the address of mypointer
follow the arrow to myInteger
pointer points to the value of myInteger
retreive myInteger = 5
leave the prenthesis and apply ++
change the value of the integer
*/
