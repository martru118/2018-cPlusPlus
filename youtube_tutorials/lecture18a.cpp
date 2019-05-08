#include <string>
#include <iostream>

using namespace std;

//composite structure for a person
struct Person {
/*
A struct is a composite data type (only contains data)
Used as a way of storing multiple related variables into one structure
*/
    //data contained in struct
    string firstName;
    string lastName;
    int age;
    bool isEmployed;
    bool isStudent;
};

//seperate from struct
Person* createPerson(string f, string l, int a, bool e, bool s);

int main() {
    /*
    Ordinary/Automatic variables:
    Not created dynamically
    Created at the start of the function and deleted at the end
    Not stored in the heap, but in standard memory
    */
    Person p;

    //access variables by using dot operator
    //cannot access variable in the composite function
    //they only exist as a part of the person variable
    p.firstName = "Cookie";
    p.lastName = "Monster";
    p.age = 42;
    p.isEmployed = true;
    p.isStudent = false;

    cout << p.firstName << " " << p.lastName 
         << " is a " << p.age << " year old person." << endl;

    //a dynamic variable
    Person *pp = new Person;
    pp->firstName = "Big";      //(*pp).firstName = "Big";
    pp->lastName = "Bird";
    pp->age = 81;
    pp->isEmployed = true;
    pp->isStudent = false;

    if (pp->isEmployed) {
        cout << pp->firstName << " " << pp->lastName 
             << " has a job!" << endl;
    } else {
        cout << pp->firstName << " " << pp->lastName 
             << " is currently between employment opportunities." << endl;
    }

    delete pp;

    Person* ppp = createPerson("Ernie", "LNU", 36, true, true);
    cout << ppp->firstName << " is " << ppp->age << " years old." << endl;
    delete ppp;     //deletes pointers made in createPerson class

    return 0;
}

Person* createPerson(string f, string l, int a, bool e, bool s) {
    Person* temp = new Person;  //cannot be deleted because it is being returned

    temp->firstName = f;
    temp->lastName = l;
    temp->age = a;
    temp->isEmployed = e;
    temp->isStudent = s;

    return temp;
}
