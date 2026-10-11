#include<iostream>
using namespace std;

struct studentType{
	    string name;
	    string id;
	    double gpa;
		studentType* next;
};
studentType* top=NULL;


bool isemptystack(){
    return (top == NULL);
}

void push(){
	 studentType* temp = new studentType;
    cout << "\nEnter Name: ";
    cin >> temp->name;
    cout << "\nEnter ID: ";
    cin >> temp->id;
    cout << "\nEnter GPA: ";
    cin >> temp->gpa;
    temp->next =NULL;
if(top==NULL){
	top=temp;
}else{
	temp->next=top;
	top=temp;
}
    cout << "\nStudent pushed successfully.\n";
}


void pop(){
    if(isemptystack()){
        cout << "Stack is underflow\n";
    }else{
    studentType* temp = top;
    cout << " \nStudent to be delete: " << temp->name <<"\t"<<temp->id<<"\t"<<temp->gpa;
    top = top->next;
    delete temp;
}
}
void topelement(){
	 if(isemptystack()){
        cout << "Stack is empty.\n";
        return;
    }else{
	
    cout << "Top Student:\n";
    cout << "\t Name: " << top->name << endl;
    cout << "\t ID: " << top->id << endl;
    cout << "\t GPA: " << top->gpa << endl;
}
}
void printstudenttype(){
	studentType* current;
	
	if(isemptystack()){
		cout<<"\n stack underflow";
	}else{
			current=top;
		cout<<"\n student data: ";
		while(current!=NULL){
			 cout << "\n\t Name: " << current->name << endl;
    cout << "\t ID: " << current->id << endl;
    cout << "\t GPA: " << current->gpa << endl;
			current=current->next;
		}
			cout<<"\n data is succussfully printed ";	

	}
}

int main(){
	char op;
	int item;
	menu:
		cout<<"\n press 1 to push element into the stack";
		cout<<"\n press 2 to pop element from the stack";
		cout<<"\n press 3 to return top element info at beginning";
		cout<<"\n press 4 to print stack elemnts  ";
		cout<<"\n press 0 to exit";
	    cout<<"\n select operation ";
	    cin>>op;
	    switch(op){
	    case '1':
	    	push();
	    	break;
	    	 case '2':
	    	 	pop();
	    	break;
	    	 case '3':
	    	 	topelement();
	    	break;
	    	 case '4':
	    	 	printstudenttype();
	    	break;
	    	 case '0':
	    	 	exit(0);
	    	break;
	    	default:
	    		cout<<"\n incorrect, try again";
	    		break;
	    	}
	goto menu;

	return 0;
}

