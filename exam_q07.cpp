#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
    public:
        Stack();
        ~Stack();
        void push(int d);
        int pop();
        bool isEmpty() {return (top == NULL);};
        friend ostream& operator<<(ostream& os, Stack &s);
    private:
        Node *top;
};

Stack::Stack() {
    top = NULL;
}

Stack::~Stack() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        exit(1);
    } else {
        //pop all remaining Nodes
        while (!isEmpty()) {
            pop();
        }
    }
}

void Stack::push(int d) {
    Node *newtop = new Node;
    newtop->data = d;
    newtop->next = top;
    top = newtop;
}

int Stack::pop() {
    //make the top null, set next as the top
    if (!isEmpty()) {
        Node* oldtop = new Node;
        top = NULL;
        oldtop->next = top;
    } else {
        cout << "ERROR: Stack is empty!\n";
        exit(1);
    }
}

ostream& operator<<(ostream& os, Stack &s) {
    if (!s.isEmpty()) {
        os << s.top << " -> ";
    } else {
        os << "<empty_stack>" << endl;
    }
}


int main() {
    Stack *s = new Stack();
    cout << *s << endl;
    s->push(5);
    cout << *s << endl;
    s->push(3);
    cout << *s << endl;

    while (!s->isEmpty()) {
        cout << "Stack content popped: " << s->pop() << endl;
    }

    cout << *s << endl;
    delete s;
    return 0;
}
