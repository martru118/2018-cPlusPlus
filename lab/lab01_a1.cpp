#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string name;
    int birthYear;
    double hourlyWage;

    // prompt user for name
    cout << "Name: ";
    getline (cin, name);    // allows input for first and last name

    // prompt user for birth year
    cout << "Birth year: ";
    cin >> birthYear;
    int age = 2018 - birthYear; // calculate age from birthYear

    // prompt user for hourly wage
    cout << "Hourly wage ($): ";
    cin >> hourlyWage;  // allows input for integers and decimals
    cout << fixed << setprecision(2);   // set hourlyWage to 2 decimal places
    
    // output statement
    cout << name << " is " << age << " years old and requests an hourly wage of $" << hourlyWage << "." << endl;
    
    
    return 0;
}