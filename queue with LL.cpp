#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class queueType {
private:
    node* front;
    node* rear;

public:
    queueType();
    ~queueType();

    bool isqueueempty();
    void enqueue(int);
    int dequeue();
    int frontelement();
    int rearelement();
    void printqueue();
};

queueType::queueType() {
    front = NULL;
    rear = NULL;
}

queueType::~queueType() {
    while (!isqueueempty()) {
        dequeue();
    }
}

bool queueType::isqueueempty() {
    return (front == NULL);
}

void queueType::enqueue(int item) {
    node* newnode = new node;
    newnode->data = item;
    newnode->next = NULL;

    if (isqueueempty()) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int queueType::dequeue() {
    if (isqueueempty()) {
        cout << "\nQueue underflow";
        return -1;
    }

    node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
    return value;
}

int queueType::frontelement() {
    if (isqueueempty()) {
        cout << "\nQueue is empty";
        return -1;
    }
    return front->data;
}

int queueType::rearelement() {
    if (isqueueempty()) {
        cout << "\nQueue is empty";
        return -1;
    }
    return rear->data;
}

void queueType::printqueue() {
    if (isqueueempty()) {
        cout << "\nQueue is empty";
        return;
    }

    node* temp = front;
    cout << "\nElements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    queueType queueobj;
    char op;
    int item;

menu:
    cout << "\n press 1 to enqueue element into the queue";
    cout << "\n press 2 to dequeue element from the queue";
    cout << "\n press 3 to return front element";
    cout << "\n press 4 to return rear element";
    cout << "\n press 5 to print queue elements";
    cout << "\n press 0 to exit";
    cout << "\n\n select operation ";
    cin >> op;

    switch (op) {
    case '1':
        cout << "\n enter the element ";
        cin >> item;
        queueobj.enqueue(item);
        break;

    case '2':
        cout << "\n element removed is " << queueobj.dequeue();
        break;

    case '3':
        cout << "\n front element is " << queueobj.frontelement();
        break;

    case '4':
        cout << "\n rear element is " << queueobj.rearelement();
        break;

    case '5':
        queueobj.printqueue();
        break;

    case '0':
        exit(0);

    default:
        cout << "\n incorrect, try again";
    }

    goto menu;
    return 0;
}
