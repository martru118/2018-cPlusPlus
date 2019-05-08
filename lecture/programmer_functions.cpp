//Lecture 6
#include <iostream>
#include <string>

using namespace std;

/*programmer_function_ex2.cpp*/
void hello(string name);
//we can overload a function (ie have two functions)
//with the same name but different parameters
void hello(string fname, string lname);
void hello(int number);

int valueSquared(int value);
int refSquared(const int& value); //references value

int main() {    //the compilier needs to check if function is legitimate
    hello("Caleb");
    hello("Malaviya");
    hello("Gabriel");
    hello("Simon");
    hello("Vashist");
    hello("Jon", "Z");
    hello(42);
    hello('c');

    int n = 1;
    int nsquared = 1;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Memory address of n is: " << &n << endl;   //reference of n

    cout << "\nCALL-BY-VALUE Example:" << endl;
    //square n by calling valueSquared function
    nsquared = valueSquared(n);
    cout << "The square of " << n << " is: " << nsquared << endl;

    cout << "\nCALL-BY-REFERENCE Example:" << endl;
    //square n by calling valueSquared function
    nsquared = refSquared(n);
    cout << "The square of " << n << " is: " << nsquared << endl;

    return 0;
}

//definition of functions
void hello(string name) {
    cout << "Hello " << name << "!" << endl;
}

void hello(string fname, string lname) {
    cout << "Hello " << fname << " " << lname << "!" << endl;
}

void hello(int number) {
    cout << "Hello Robot #" << number << "!" << endl;
}


/*programmer_function_ex2b.cpp*/
int valueSquared(int value) {
    cout << "The memory address of value is: " << &value << endl;
    value *= value;
    return value;
}

int refSquared(const int &num) {
  cout << "memory address of num in refSquared is "
       << &num << endl;

  int num2 = num * num;
  return num2;
}