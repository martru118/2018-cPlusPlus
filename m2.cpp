#include <iostream>
#include <cstdlib>

using namespace std;

//items enter on a First In Last Out basis
struct Node {
    string data;
    Node* next;
};

class Stack {
    public:
        Stack();
        ~Stack();
        void push(string d);
        string pop();
        string toString();
        bool isEmpty();

    private:
        Node* top;
};

Stack::Stack() {
    top = NULL;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(string d) {
    //need a new node to store data d in
    Node* temp = new Node;
    temp->data = d;
    temp->next = top;

    top = temp;
}

string Stack::pop() {
    if (!isEmpty()) {
        string value = top->data;
        Node* oldtop = top;
        top = oldtop->next;
        
        delete oldtop;
        return value;
    } else {
        cout << "You can't pop from an empty stack" << endl;
        exit(1);
    }
}

string Stack::toString() {
    string result = "---TOP---\t";
    if (isEmpty()) {
        result += "NULL";
        return result;
    } else {
        Node* current = top;

        while (current != NULL) {
            result += current->data + " -> ";
            current = current->next;
        } 
        result += "\t---BOTTOM---";
        return result;
    }
}

bool Stack::isEmpty() {
    return (top == NULL);
}

int main() {
    Stack* s = new Stack();
    s->push("Cheeseburger");
    s->push("Pizza");
    s->push("Large Coffee");
    cout << s->toString() << endl;

    delete s;
    return 0;
}
