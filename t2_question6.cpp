//Lecture 20: Stacks and Data Structures
#include <iostream>
#include <cstdlib>

using namespace std;

//items enter on a First In Last Out basis
struct Node {   //create a node struct
    string data;
    Node* next;
};

class Stack {
    public:
        Stack();    //constructor
        ~Stack();   //deconstructor cleans up dynamic memory (all the pointers created)
        void push(string d);    //pushes a node onto top of stack
        string pop();   //pop top node off of the stack
        string toString();    //display the stack's contents as a string (top->bottom)
        bool isEmpty();

    private:
        Node* top;      //points to the very top of the stack
};

//constructor resolves back to the Stack class
Stack::Stack() {
    //initialize stack to be empty
    top = NULL;
}

Stack::~Stack() {
    //deconstructor to delete all dynamic variables
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(string d) {
    //need a new node to store data d in
    Node* temp = new Node;
    temp->data = d;
    temp->next = top;   //point the new node to the old top of the stack

    top = temp; //point top to the new top of the stack
}

string Stack::pop() {
    if (!isEmpty()) {
        string value = top->data;
        Node* oldtop = top;
        top = oldtop->next;
        
        delete oldtop;
        //data is not deleted 
        //but rather a copy is made 
        //and added to string value
        return value;
    } else {
        cout << "You can't pop from an empty stack" << endl;
        exit(1);
    }
}

string Stack::toString() {
    string result = " ---TOP--- ";
    if (isEmpty()) {
        result += "NULL";
        return result;
    } else {
        Node* current = top;

        while (current != NULL) {
            result += current->data + " -> ";
            current = current->next;
        } 
        result += " ---BOTTOM--- ";
        return result;
    }
}

bool Stack::isEmpty() {
    return (top == NULL);
}

int main() {
    Stack* s = new Stack();
    cout << "Output when empty: " << s->toString() << endl;
    s->push("Cheeseburger");
    s->push("Pizza");
    s->push("Large Coffee");
    cout << "Output when *not* empty: " << s->toString() << endl;

    delete s;
    return 0;
}
