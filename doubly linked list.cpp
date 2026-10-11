#include <iostream>
#include <string>
using namespace std;

struct bookType {
    string bookAuthor;
    string bookTitle;
    string bookISBN;
    string bookEdition;
    float bookPrice;
    bookType* next;
    bookType* prev;  
};
bookType *head=NULL;
bookType *tail=NULL;  

void addBookAtStart() {
    bookType* temp=new bookType;
    cout<<"\n enter the book Author :";
    getline(cin,temp->bookAuthor);
    cout<<"\n enter the book title :";
    getline(cin,temp->bookTitle);
    cout<<"\n enter the book ISBN :";
    getline(cin,temp->bookISBN);
    cout<<"\n enter the book Edition :";
    getline(cin,temp->bookEdition);
    cout<<"\n enter the book price :";
    cin>>temp->bookPrice;
    
    temp->prev = NULL;  
    temp->next = NULL; 
    
    if(head==NULL) {
        head=temp;
        tail=temp;  
    } else {
        temp->next=head;
        head->prev=temp;  
        head=temp;
    }
    cout<<"\n data is successfully stored at the beginning";
}

void addBookAtEnd() {
    bookType *temp=new bookType;
    cout<<"\n enter the book Author :";
    getline(cin,temp->bookAuthor);
    cout<<"\n enter the book title :";
    getline(cin,temp->bookTitle);
    cout<<"\n enter the book ISBN :";
    getline(cin,temp->bookISBN);
    cout<<"\n enter the book Edition :";
    getline(cin,temp->bookEdition);
    cout<<"\n enter the book price :";
    cin>>temp->bookPrice;
    
    temp->next = NULL;
    temp->prev = NULL;
    
    if(head==NULL) {
        head=temp;
        tail=temp;
    } else {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    cout<<"\n data is successfully stored at the end";
}

void addBookAtSpecificPosition(int position) {
    if(position < 1) {
        cout<<"\n invalid position";
        return;
    }
    
    bookType* temp=new bookType;
    cin.ignore();  // Clear newline
    cout<<"\n enter the book Author :";
    getline(cin,temp->bookAuthor);
    cout<<"\n enter the book title :";
    getline(cin,temp->bookTitle);
    cout<<"\n enter the book ISBN :";
    getline(cin,temp->bookISBN);
    cout<<"\n enter the book Edition :";
    getline(cin,temp->bookEdition);
    cout<<"\n enter the book price :";
    cin>>temp->bookPrice;
    
    temp->next = NULL;
    temp->prev = NULL;
    
    if(head==NULL) {
        head=temp;
        tail=temp;
    } else if(position == 1) {
        temp->next = head;
        head->prev = temp;
        head = temp;
    } else {
        bookType* curr = head;
        int i = 1;
        while(i < position-1 && curr != NULL) {
            curr = curr->next;
            i++;
        }
        if(curr == NULL) {
            cout<<"\n position out of range";
            delete temp;
            return;
        }
        temp->next = curr->next;
        temp->prev = curr;
        if(curr->next != NULL) {
            curr->next->prev = temp;
        } else {
            tail = temp;  // Inserting at the end
        }
        curr->next = temp;
    }
    cout<<"\n data is successfully stored at the specified position";
}

void removeBookFromStart() {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        bookType* temp=head;
        head=head->next;
        if(head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;  // List becomes empty
        }
        delete temp;
        cout<<"\n data is successfully removed from the beginning";
    }
}

void removeBookFromEnd() {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else if(head->next==NULL) {
        delete head;
        head=NULL;
        tail=NULL;
        cout<<"\n data is successfully removed from end ";
    } else {
        bookType* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        cout<<"\n data is successfully removed from the end";
    }
}

void removeBookFromSpecificPosition(int position) {
    if(head==NULL) {
        cout<<"\n list is empty";
        return;
    }
    if(position < 1) {
        cout<<"\n invalid position";
        return;
    }
    
    if(position == 1) {
        removeBookFromStart();
        return;
    }
    
    bookType* curr = head;
    int i = 1;
    while(i < position && curr != NULL) {
        curr = curr->next;
        i++;
    }
    
    if(curr == NULL) {
        cout<<"\n position out of range";
        return;
    }
    
    if(curr->next == NULL) {
        // Removing from end
        tail = curr->prev;
        tail->next = NULL;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    delete curr;
    cout<<"\n data is successfully removed from the specified position";
}

void printBookInformation() {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        int count=1;
        bookType* current=head;
        cout<<"\n ========== BOOK INFORMATION (Forward) ==========\n";
        while(current!=NULL) {
            cout<<"\nBook #"<<count<<":\n";
            cout<<" Author : "<<current->bookAuthor<<"\n";
            cout<<" Title : "<<current->bookTitle<<"\n";
            cout<<" ISBN : "<<current->bookISBN<<"\n";
            cout<<" Edition : "<<current->bookEdition<<"\n";
            cout<<" Price : "<<current->bookPrice<<"\n";
            current=current->next;
            count++;
        }
        cout<<"\nTotal Books: "<<count-1<<"\n";
        cout<<"\n book information is successfully printed ";
    }
}
void printBookInformationReverse() {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        int count=1;
        bookType* current=tail;
        cout<<"\n ========== BOOK INFORMATION (Reverse) ==========\n";
        while(current!=NULL) {
            cout<<"\nBook #"<<count<<":\n";
            cout<<" Author : "<<current->bookAuthor<<"\n";
            cout<<" Title : "<<current->bookTitle<<"\n";
            cout<<" ISBN : "<<current->bookISBN<<"\n";
            cout<<" Edition : "<<current->bookEdition<<"\n";
            cout<<" Price : "<<current->bookPrice<<"\n";
            current=current->prev;
            count++;
        }
        cout<<"\nTotal Books: "<<count-1<<"\n";
    }
}

void searchBookByName(string Title) {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        bookType* temp=head;
        int position=1;
        bool found=false;
        while (temp!=NULL) {
            if(temp->bookTitle==Title) {
                cout<<"\nBook found at position "<<position<<":\n";
                cout<<" Author : "<<temp->bookAuthor<<"\n";
                cout<<" Title : "<<temp->bookTitle<<"\n";
                cout<<" ISBN : "<<temp->bookISBN<<"\n";
                cout<<" Edition : "<<temp->bookEdition<<"\n";
                cout<<" Price : "<<temp->bookPrice<<"\n";
                found=true;
            }
            temp=temp->next;
            position++;
        }
        if(!found) {
            cout<<"\n book with title \""<<Title<<"\" not found";
        }
    }
}

int main() {
    cout<<"\n name : Anwar Aliyi Id:Ru0270/17 section 1 Doubly Linked List\n";
    string op;
    int position;
    float price;
    string title;
    
menu:
    cout<<"\npress 1 to add book at the beginning";
    cout<<"\npress 2 to add book at the end";
    cout<<"\npress 3 to add book at the specific position";
    cout<<"\npress 4 to remove book from the beginning";
    cout<<"\npress 5 to remove book from the end";
    cout<<"\npress 6 to remove book from the specific position";
    cout<<"\npress 7 to print list of data";
    cout<<"\npress 8 to search book by name";
    cout<<"\npress 9 to print in reverse ";
    cout<<"\npress 0 to exit";
    cout<<"\n \n select operation: ";
    
    getline(cin, op);
    
    switch(op[0]) {
    case '1':
        addBookAtStart();
        break;
    case '2':
        addBookAtEnd();
        break;
    case '3':
        cout<<"\n enter position: ";
        cin>>position;
        addBookAtSpecificPosition(position);
        break;
    case '4':
        removeBookFromStart();
        break;
    case '5':
        removeBookFromEnd();
        break;
    case '6':
        cout<<"\n enter the position: ";
        cin>>position;
        removeBookFromSpecificPosition(position);
        break;
    case '7':
        printBookInformation();
        break;
    case '8':
        cin.ignore();
        cout<<"\n enter book title: ";
        getline(cin,title);
        searchBookByName(title);
        break;
    case '9':
        printBookInformationReverse();
        break;
    case '0':
        return 0;
    default:
        cout<<"\n invalid choice, please try again";
    }
    goto menu;
    return 0;
}
