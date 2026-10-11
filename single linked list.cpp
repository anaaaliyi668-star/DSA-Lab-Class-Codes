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
};
bookType *head=NULL;
void addBookAtStart() {
    bookType* temp=new bookType;
    cout<<"\n enter the book Author :";
    getline (cin,temp->bookAuthor);
    cout<<"\n enter the book title :";
    getline (cin,temp->bookTitle);
    cout<<"\n enter the book ISBN :";
    getline (cin,temp->bookISBN);
    cout<<"\n enter the book Edition :";
    getline (cin,temp->bookEdition);
    cout<<"\n enter the book price :";
    cin>>temp->bookPrice;
    if(head==NULL) {
        temp->next=NULL;
    } else {
        temp->next=head;
    }
    head=temp;
    cout<<"\n data is successfully stored at the beginning";
}
void addBookAtEnd() {
    bookType *temp=new bookType;
    bookType* current;
    cout<<"\n enter the book Author :";
    getline (cin,temp->bookAuthor);
    cout<<"\n enter the book title :";
    getline (cin,temp->bookTitle);
    cout<<"\n enter the book ISBN :";
    getline (cin,temp->bookISBN);
    cout<<"\n enter the book Edition :";
    getline (cin,temp->bookEdition);
    cout<<"\n enter the book price :";
    cin>>temp->bookPrice;
    if(head==NULL) {
        head=temp;
    } else {
        current=head;
        while(current->next!=NULL) {
            current=current->next;
        }
        current->next=temp;
    }
    cout<<"\n data is successfully stored at the end";
}
void addBookAtSpecificPosition(int position) {
    bookType* temp=new bookType;
    cout<<"\n enter the book Author :";
    getline (cin,temp->bookAuthor);
    cout<<"\n enter the book title :";
    getline (cin,temp->bookTitle);
    cout<<"\n enter the book ISBN :";
    getline (cin,temp->bookISBN);
    cout<<"\n enter the book Edition :";
    getline (cin,temp->bookEdition);
    cout<<"\n enter the book price :";
    cin>>temp->bookPrice;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
    } else {
        bookType* prev;
        bookType *curr;
        int i=1;
        curr=head;
        while(i<position) {
            prev=curr;
            curr=curr->next;
            i++;
        }
        temp->next=curr;
        prev->next=temp;
    }
    cout<<"\n data is successfully stored at the specified position";
}
void removeBookFromStart() {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        bookType* temp=head;
        head=head->next;
        delete temp;
        cout<<"\n data is successfully removed from the beginning";
    }
}
void removeBookFromEnd() {
    bookType* temp=head;
    if(head==NULL) {
        cout<<"\n list is empty";
    } else if(head->next==NULL) {
        temp=head;
        head=NULL;
        delete temp;
        cout<<"\n data is succussfully removed from end ";
    } else {
        bookType* prev,*curr;
        curr=head;
        while(curr->next!=NULL) {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        delete curr;
        cout<<"\n data is successfully removed from the end";
    }
}
void removeBookFromSpecificPosition(int position) {
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        bookType *prev,*curr;
        int i=1;
        curr=head;
        while(i<position) {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
        cout<<"\n data is successfully removed from the specified position";
    }
}
void printBookInformation() {
    bookType* current;
    if(head==NULL) {
        cout<<"\n list is empty";
    } else {
        int count=1;
        current=head;
        cout<<"\n book information";
        while(current!=NULL) {
            cout<<"\nBook#" <<count<< ":\n";
            cout<<" Author : " <<current->bookAuthor<<"\n";
            cout<<" Title : " <<current->bookTitle<<"\n";
            cout<<" ISBN : " <<current->bookISBN<<"\n";
            cout<<" Edition : " <<current->bookEdition<<"\n";
            cout<<" Price : " <<current->bookPrice<<"\n";
            current=current->next;
        }
        cout<<"Total Books: "<<count-1<< "\n";
        cout<<"\n bookinformation is succussfully printed ";
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
                cout<<"\nBook found at position " <<position<< ":\n";
                cout<<" Author : " <<temp->bookAuthor<<"\n";
                cout<<" Title : " <<temp->bookTitle<<"\n";
                cout<<" ISBN : " <<temp->bookISBN<<"\n";
                cout<<" Edition : " <<temp->bookEdition<<"\n";
                cout<<" Price : " <<temp->bookPrice<<"\n";
                found=true;
            }
            temp=temp->next;
            position++;
        }
        if(!found) {
            cout<<"\n book with title\""<<Title<<"\" not found";
        }
    }
}
int main() {
cout<<"\n name : Anwar Aliyi Id:Ru0270/17 section 1 single linked list\n";
    string op;
    int position;
    float price;
    string title;
menu :
    cout<<"\npress 1 to add book at the beginning";
    cout<<"\npress 2 to add book at the end";
    cout<<"\npress 3 to add book at the specific position";
    cout<<"\npress 4 to remove book from the beginning";
    cout<<"\npress 5 to remove book from the end";
    cout<<"\npress 6 to remove book from the specific position";
    cout<<"\npress 7 to print list of data  ";
    cout<<"\npress 8 to search book by name";
    cout<<"\n press 0 to exit";
    cout<<"\n \n select  operation ";
    
    getline(cin,op);
    
    switch(op[0]) {
    case '1':
        addBookAtStart();
        break;
    case '2':
        addBookAtEnd();
        break;
    case '3':
        cout<<"\n enter position ";
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
        cout<<"\n enter the position";
        cin>>position;
        removeBookFromSpecificPosition(position);
        break;
    case '7':
        printBookInformation();
        break;
    case '8':
        cout<<"\n enter book title: ";
        getline(cin,title);
        searchBookByName(title);
        break;
    case '9':
        break;
    default :
        cout<<"\n invalid choice, please try again";
        
    }
    goto menu;
    return 0;
}
