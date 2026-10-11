#include<iostream>
using namespace std;

struct studentType{
    string name;
    string id;
    double gpa;
    studentType* next;
};

studentType* top = NULL;


bool isemptystack(){
    return (top == NULL);
}

// Push operation
void push(){
    studentType* newNode = new studentType;

    cout << "Enter Name: ";
    cin >> newNode->name;
    cout << "Enter ID: ";
    cin >> newNode->id;
    cout << "Enter GPA: ";
    cin >> newNode->gpa;

    newNode->next = top;
    top = newNode;

    cout << "Student pushed successfully.\n";
}


void pop(){
    if(isemptystack()){
        cout << "Stack is empty. Cannot pop.\n";
        return;
    }

    studentType* temp = top;
    cout << "Popped Student: " << temp->name << endl;

    top = top->next;
    delete temp;
}

// Display top elemen
void topelement(){
    if(isemptystack()){
        cout << "Stack is empty.\n";
        return;
    }

    cout << "Top Student:\n";
    cout << "Name: " << top->name << endl;
    cout << "ID: " << top->id << endl;
    cout << "GPA: " << top->gpa << endl;
}

int main(){
    int choice;

    do{
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Top Element\n4. Check Empty\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: topelement(); break;
            case 4:
                if(isemptystack())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    }while(choice != 5);

    return 0;
}
