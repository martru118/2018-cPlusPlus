#include <string>
#include <iostream>

using namespace std;

//a person class
//declaration of the class
class Person {
/*
unlike a struct, classes can group functions together with data
*/
    public:     //part of the class that can be accessed outside of the class
        Person();   //constructor
        Person(string f, string l, int a, bool e, bool s);  //constructor
        void print();
        void setAge(int a);
        int getAge() {return age;}
    
    private:    //can only be accessed within the class (by the functions of the class)
        string firstName;
        string lastName;
        int age;
        bool isEmployed;
        bool isStudent;
};

//definition of the class
Person::Person() {  //class_name::function_name     class_name(scope_resolution_operator)function_name
    //function is declared within the scope of the class
    //set default values for variables
    firstName = "FNU";
    lastName = "LNU";
    age = -1;
    isEmployed = false;
    isStudent = false;
}

Person::Person(string f, string l, int a, bool e, bool s) {
/*
Constructors are used to initialize variables and the like
*/
    firstName = f;
    lastName = l;
    if (age < 0) {
        age = -1;
    } else {
        age = a;
    }
    isEmployed = e;
    isStudent = s;
}

void Person::print() {
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    if (age == -1) {
        cout << "Age unknown" << endl;
    } else {
        cout << "Age (in years): " << age << endl;
    }
    cout << "Are they employed?: " << isEmployed << endl;
    cout << "Are they a student?: " << isStudent << endl;
}

void Person::setAge(int a) {
    if (a < 0) {
        age = -1;
    } else {
        age = a;
    }

}

int main() {
    Person* p = new Person();
    p->setAge(20);
    p->print();
    delete p;

    Person* pp = new Person("Oscar", "the Grouch", 108, false, false);
    pp->print();
    delete pp;

    return 0;
}
