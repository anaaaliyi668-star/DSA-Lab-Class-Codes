#include <iostream>
using namespace std;

class stackType {
private:
    struct node {
        int data;
        node* next;
    };

    node* top;

public:
    stackType();
    ~stackType();

    bool isEmptyStack();
    void push(int item);
    int pop();
    int topElement();
    void display();
};

stackType::stackType() {
    top = NULL;
}

stackType::~stackType() {
    node* temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        delete temp;
    }
}

bool stackType::isEmptyStack() {
    return (top == NULL);
}


void stackType::push(int item) {
    node* newNode = new node;
    newNode->data = item;
    newNode->next = top;
    top = newNode;

    cout << "\nData is successfully stored";
}


int stackType::pop() {
    if (isEmptyStack()) {
        cout << "\nStack Underflow";
        return -1;
    }

    node* temp = top;
    int del_val = top->data;
    top = top->next;
    delete temp;

    return del_val;
}


int stackType::topElement() {
    if (isEmptyStack()) {
        cout << "\nStack is empty";
        return -1;
    }
    return top->data;
}


void stackType::display() {
    if (isEmptyStack()) {
        cout << "\nStack is empty";
        return;
    }

    node* temp = top;
    cout << "\nStack elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    stackType stackobj;
    char op;
    int item;

menu:
    cout << "\nPress 1 to push element into the stack";
    cout << "\nPress 2 to pop element from the stack";
    cout << "\nPress 3 to return top element";
    cout << "\nPress 4 to print stack elements";
    cout << "\nPress 0 to exit";
    cout << "\nSelect operation: ";
    cin >> op;

    switch (op) {
        case '1':
            cout << "\nEnter the number: ";
            cin >> item;
            stackobj.push(item);
            break;

        case '2':
            cout << "\nElement removed is: " << stackobj.pop();
            break;

        case '3':
            cout << "\nTop element is: " << stackobj.topElement();
            break;

        case '4':
            stackobj.display();
            break;

        case '0':
            exit(0);

        default:
            cout << "\nIncorrect, try again";
    }

    goto menu;
    return 0;
}
