//Lecture 2
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
  
  /*hello_string.cpp*/
  string msg = "this is the end of class!";
  string name;
  cout << "Enter name: ";
  cin >> name;

  cout << name << ", " << msg << endl;


  /*hello_double.cpp*/
  double x = 2.3;

  cout << fixed << setprecision(2);
  cout << "x = $" << x << endl;

  double y = 4/3;
  cout << "y = " << y << endl;
  
}
