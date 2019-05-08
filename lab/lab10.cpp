#include <string>
#include <iostream>

using namespace std;

struct Node {
    string element_name;
    Node* next;
};

class Queue {
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void Enqueue(string dataNode);
        string Dequeue();
        string toString();

    private:
        Node* front;    //a pointer to the front of the Queue
        Node* back;     //a pointer to the back of the Queue
};

//creates an empty queue
Queue::Queue() {
    front = NULL;
    back = NULL;
}

//deletes the queue
Queue::~Queue() {
    while(!isEmpty()) {
        Dequeue();
    }
}

//check if the queue is empty
bool Queue::isEmpty() {
    return (front == NULL && back == NULL);
}

//adds a new Node to the back of the Queue
void Queue::Enqueue(string dataNode) {
    Node *nq = new Node;
    nq->element_name = dataNode;
    nq->next = front;   //connect new node to the front
    front = nq;     //declare front equal to a new node
}

//delete a Node from the front of the Queue
string Queue::Dequeue() {
    if (!isEmpty()) {
        string dq = front->element_name;
        Node *current = new Node;
        Node *previous = new Node;
        current = front;
        
        //move pointers through queue
        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }
        //point previous node to the second-last node
        back = previous;
        previous->next = NULL;

        //current node points to last node before being deleted
        delete current;
        return dq;

    } else {
        cout << "Nothing in queue." << endl;
        exit(1);
    }
}

//returns a string containing the contents of the queue from both Nodes
string Queue::toString() {
    string qq = "";
    Node* display = front;

    while(display != NULL) {
        //display the node at the address
        qq += "[" + display->element_name + "] -> ";
        display = display->next;
    }

    return qq;
}

int main() {
    Queue* q = new Queue();

    q->Enqueue("Turtle");   //front
    q->Enqueue("Fish");
    q->Enqueue("Dog");
    q->Enqueue("Cat");      //back

    cout << q->toString() << endl;

    q->Dequeue();

    cout << q->toString() << endl;

    return 0;
}
