#include <string>
#include <iostream>

using namespace std;

class Person {

    public:
        Person();
        Person(string f, string l, int a, bool e, bool s);
        void print();

        //create getters and setters to retrieve values
        void setAge(int a);
        int getAge() {return age;}
        void setFirstname(string f);
        void setLastname(string l);
        void setName(string f, string l);
        string getFirstname();
        string getLastname();
        string getName();
        void setEmployed(bool e);
        bool isEmployed();
        void setStudent(bool s);
        bool isStudent();
    
    private:
        string firstName;
        string lastName;
        int age;
        bool employed;
        bool student;
};

Person::Person() {
    firstName = "FNU";
    lastName = "LNU";
    age = -1;
    employed = false;
    student = false;
}

Person::Person(string f, string l, int a, bool e, bool s) {
    firstName = f;
    lastName = l;
    if (age < 0) {
        age = -1;
    } else {
        age = a;
    }
    employed = e;
    student = s;
}

void Person::print() {
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
    if (age == -1) {
        cout << "Age unknown" << endl;
    } else {
        cout << "Age (in years): " << age << endl;
    }
    cout << "Are they employed?: " << isEmployed() << endl;
    cout << "Are they a student?: " << isStudent() << endl;
}

void Person::setAge(int a) {
    if (a < 0) {
        age = -1;
    } else {
        age = a;
    }

}

void Person::setFirstname(string f) {
    firstName = f;
}

string Person::getFirstname() {
    return firstName;
}

void Person::setLastname(string l) {
    lastName = l;
}

string Person::getLastname() {
    return lastName;
}

void Person::setName(string f, string l) {
    firstName = f;
    lastName = l;
}

string Person::getName() {
    return (firstName + " " + lastName);
}

void Person::setEmployed(bool e) {
    employed = e;
}

bool Person::isEmployed() {
    return employed;
}

void Person::setStudent(bool s) {
    student = s;
}

bool Person::isStudent() {
    return student;
}

int main() {
    Person* p = new Person();
    p->setAge(20);
    p->print();
    delete p;

    Person* pp = new Person("Oscar", "the Grouch", 108, false, false);
    pp->print();

    if (pp->isEmployed()) {
        cout << pp->getName() << " has a job!" << endl;
    } else {
        cout << pp->getName() << " does not have a job (yet)." << endl;
    }

    delete pp;

    return 0;
}
