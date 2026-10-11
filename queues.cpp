#include<iostream>
using namespace std;

struct studentType{
	    string name;
	    string id;
	    double gpa;
		studentType* next;
};
studentType* top=NULL;

studentType *frontindex=NULL;
studentType *rearindex=NULL;
bool isqueemty)(){
	return (rearindex==NULL || frontindex==NULL)
}
void enque(){
	 studentType* temp = new studentType;
    cout << "\nEnter Name: ";
    cin >> temp->name;
    cout << "\nEnter ID: ";
    cin >> temp->id;
    cout << "\nEnter GPA: ";
    cin >> temp->gpa;

    temp->next =NULL;
    if(top==NULL){
    	rearindex=temp;
    	frontindex=temp;
	}
    temp->next=rearindex;
    rearindex=temp;
    

    cout << "\nStudent pushed successfully.\n";
}	
void dequeue(){
	if(isqueempty()){
		cout<<"stack is underflow";
	}else{
	}
}
void printstudent(){
		if(isqueempty()){
		cout<<"stack is underflow";
	}else{
		
	}
}
void pop(){
	if(top==NULL){
		cout<<"\n stuck underflow";
	}else{
		
	}
}
void frontelement(){
	 cout << "Top Student:\n";
    cout << "\t Name: " << frontindex->name << endl;
    cout << "\t ID: " << frontindex->id << endl;
    cout << "\t GPA: " << frontindex->gpa << endl;
}
void rearelement(){
   cout << "Top Student:\n";
    cout << "\t Name: " << rearindex->name << endl;
    cout << "\t ID: " << rearindex->id << endl;
    cout << "\t GPA: " << rearindex->gpa << endl;

}
