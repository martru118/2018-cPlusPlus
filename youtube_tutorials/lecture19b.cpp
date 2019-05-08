//Lecture 19b: Overloading operators in C++ classes
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

        //overloading operators
        bool isEqual(Person p);
        bool operator==(Person p);  //naming an operator
        bool operator<(Person p);
    
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

bool Person::isEqual(Person p) {
    return (firstName == p.getFirstname())
        && (lastName == p.getLastname())
        && (age == p.getAge());
}

//there is already a definition for the operator "=="
//function is overloaded so when a Person object is passed, 
//it will be compared to the current Person object
bool Person::operator==(Person p) {
    return (firstName == p.getFirstname())
        && (lastName == p.getLastname())
        && (age == p.getAge());
}

//overload "<" operator to compare 
//compare one Person with another Person on the basis of age
bool Person::operator<(Person p) {
    //check the current object's age 
    //is less than the parameter's getAge()
    if (age < p.getAge()) {
        return true;

    } /* else if (age == p.getAge()) {
        if (getName() < p.getName()) {
            return true;
        } else {
            return false;
        }

    } */ else {
        return false;
    }
}

int main() {
    Person* p = new Person();
    p->setFirstname("Oscar");
    p->setLastname("A. Grouch");
    p->setAge(20);
    p->setStudent(false);
    p->setEmployed(true);
    p->print();

    Person* pp = new Person("Oscar", "the Grouch", 108, false, false);
    pp->print();

    if (pp->isEmployed()) {
        cout << pp->getName() << " has a job!" << endl;
    } else {
        cout << pp->getName() << " does not have a job (yet)." << endl;
    }

    if (p->operator==(*pp)) {
        cout << "They are the same!" << endl;
    }

    if (pp->operator==(*pp)) {
        cout << "Variable pp is the same as itself!" << endl;
    }

    //calling p is less than pp (passed as parameter)
    //call the "<" operator for p
    //pass pp as a parameter to compare it with
    if (*p < *pp) {     //p->operator<(*p2)
        cout << p->getName() << " is younger!" << endl;
    }

    delete p;
    delete pp;
    return 0;
}
