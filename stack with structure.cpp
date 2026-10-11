#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

struct stackType {
    node* top;
};

void initStack(stackType &s) {
    s.top = NULL;
}

bool isEmpty(stackType s) {
    return (s.top == NULL);
}

void push(stackType &s, int item) {
    node* newNode = new node;
    newNode->data = item;
    newNode->next = s.top;
    s.top = newNode;
    cout << "\nData successfully pushed";
}

// Pop operation
int pop(stackType &s) {
    if (isEmpty(s)) {
        cout << "\nStack Underflow";
        return -1;
    }
    node* temp = s.top;
    int del_val = temp->data;
    s.top = temp->next;
    delete temp;
    return del_val;
}

// Top element
int topElement(stackType s) {
    if (isEmpty(s)) {
        cout << "\nStack is empty";
        return -1;
    }
    return s.top->data;
}

// Display stack
void display(stackType s) {
    if (isEmpty(s)) {
        cout << "\nStack is empty";
        return;
    }

    node* temp = s.top;
    cout << "\nStack elements: ";
    while (temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

// Main function
int main() {
    stackType s;
    initStack(s);

    char op;
    int item;

menu:
    cout << "\nPress 1 to push";
    cout << "\nPress 2 to pop";
    cout << "\nPress 3 to view top element";
    cout << "\nPress 4 to display stack";
    cout << "\nPress 0 to exit";
    cout << "\nSelect operation: ";
    cin >> op;

    switch(op) {
        case '1':
            cout << "\nEnter number: ";
            cin >> item;
            push(s, item);
            break;

        case '2':
            cout << "\nRemoved element: " << pop(s);
            break;

        case '3':
            cout << "\nTop element: " << topElement(s);
            break;

        case '4':
            display(s);
            break;

        case '0':
            exit(0);

        default:
            cout << "\nInvalid choice";
    }

    goto menu;
    return 0;
}
