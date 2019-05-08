//Lecture 18: Classes in C++
#include <cstdlib>
#include <iostream>

using namespace std;

//composite structure for a person
struct Person {
    string firstName;
    string lastName;
    int age;
    bool isEmployed;
};

Person *createPerson(string f, string l, int age, bool e);

int main() {
    //create an automatic variable of type Person
    Person p;
    p.firstName = "Cookie";
    p.lastName = "Monster";
    p.age = 42;
    p.isEmployed = true;

    cout << p.firstName << " " << p.lastName << " is a " << p.age << " year old puppet. " << endl;

    //create dynamic Person variable
    Person *p2 = new Person;
    (*p2).firstName = "Big";
    p2->lastName = "Bird";
    p2->age = 81;
    p2->isEmployed = false;

    cout << p2->firstName << " " << p2->lastName << endl;
    delete p2;

    Person *p3 = createPerson("Ernie", "LNU", 36, true);
    cout << p3->firstName << endl;
    delete p3;
}

Person *createPerson(string f, string l, int a, bool e) {
    Person *temp = new Person;

    temp->firstName = f;
    temp->lastName = l;
    temp->age = a;
    temp->isEmployed = e;

    return temp;
}
