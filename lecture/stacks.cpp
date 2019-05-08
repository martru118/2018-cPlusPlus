//Lecture 20: Stacks & Queues
#include <cstdlib>
#include <iostream>

using namespace std;

//create a node to store one item of data in the stack
struct Node {
    string data;
    Node* next; //points to the next Node in the stack
};

//Queues go First In, First Out
//Stacks go First In, Last Out
class Stack {
    public:
        Stack();    //constructor
        ~Stack();   //deconstructor

        bool isEmpty() {return (top == NULL);}
        void push(string d);    //pushes a node containing d onto the top of the stack
        string pop();   //pop the top node of the stack
                        //return the string stored in that node
        
        string toString();      //save the stack to a string
    
    private:
        Node *top;  //points to the top item in the stack
};

Stack::Stack() {
    //initialize the stack by pointing top to NULL (ie nothing)
    top = NULL;
}

Stack::~Stack() {
    //has to free up memory allocated to Nodes in the stack
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(string d) {
    Node* newtop = new Node;
    newtop->data = d;
    newtop->next = top;     //point new node's next to old top of stack

    top = newtop;   //make new node the top of the stack
}

string Stack::pop() {
    //pop the top of the stack is the stack is not empty
    if (!isEmpty()) {
        string value = top->data;   //set aside current value
        Node* oldtop = top;     //create oldtop to point to top
        top = top->next;    //reassign top of stack to be second-top node
        
        delete oldtop;      //delete the node being popped
        return value;
        
    } else{
        cout << "ERROR: You cannot pop from an empty stack.\n";
        exit(1);
    }
}

string Stack::toString() {
    string result = "<TOP>\n";
    Node* current = top;

    while (current != NULL) {
        result += current->data + "\n";
        current = current->next;
    }

    result += "<BOTTOM>\n";
    return result;
}

int main() {
    Stack* dogs = new Stack();
    cout << dogs->toString() << endl;
    dogs->push("Hudson");
    dogs->push("Mabel");
    dogs->push("Nica");
    dogs->push("Charlie");
    cout << dogs->toString() << endl;

    while (!dogs->isEmpty()) {
        cout << "Stack content pooped:\n"
             << dogs->pop() << endl;
    }
    
    delete dogs;
    return 0;
}
