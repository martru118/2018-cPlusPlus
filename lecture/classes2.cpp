//Lecture 18: Classes in C++
#include <cstdlib>
#include <iostream>

using namespace std;

//composite structure for a person
struct Person {
    public:
        Person();   //default constructor
        Person(string f, string l, int age, bool e);
        ~Person();  //default destructor
        string toString();

        //create getters and setters
        string getFirstname() {return firstName;};
        void setFirstname(string f) {firstName = f;};
        string getLastname() {return lastName;};
        void setLastname(string l) {lastName = l;};
        bool setAge(int a); //mutator function
        int getAge() {return age;};
        bool isEmployed() {return employed;};
        void setEmployed(bool e) {employed = e;};

    //private variables as retrieved by getters and setters
    private:
        string firstName;
        string lastName;
        int age;
        bool employed;
};

Person::Person() {
    firstName = "FNU";
    lastName = "LNU";
    age = -1;
    employed = false;
}

Person::Person(string f, string l, int a, bool e) {
    firstName = f;
    lastName = l;
    if(!setAge(a)) {
        a = -1;
    }
    employed = e;
}

Person::~Person() {
    cout << "Destroying one person object!" << endl;
}

string Person::toString() {
    string pstring = "";
    pstring += firstName + " " + lastName + " is a " + to_string(age) + " year old who is ";
    if (employed) {
        pstring += "employed.\n";
    } else {
        pstring += "unemployed.\n";
    }

    return pstring;
}

bool Person::setAge(int a) {
    if (age < -1) {
        return false;
    } else {
        age = a;
        return true;
    }
}

int main() {
    Person *p1 = new Person;
    cout << p1->toString() << endl;
    p1->setFirstname("BIG");
    p1->setLastname("BIRD");
    p1->setAge(46);
    p1->setEmployed(false);
    delete p1;

    Person *p2 = new Person("Big", "Bird", 81, false);
    cout << p2->toString() << endl;
    delete p2;
}
