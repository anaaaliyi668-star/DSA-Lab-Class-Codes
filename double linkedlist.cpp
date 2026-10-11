#include<iostream>

using namespace std;
struct nodeType{
	int info;
	nodeType *next;
	nodeType *prev;
};
 nodeType *head=NULL;
 nodeType *tail=NULL;
 
 void addElementAtBeginning(){
 	nodeType *temp=new nodeType;
 	cout<<"enter number ";
 	cin>>temp->info;
 	temp->next=NULL;
 	temp->prev=NULL;
 		if (head==NULL){
 			head=temp;
 			tail=temp;
		 }else{
		 	temp->next=head;
		 	head->prev=temp;
		 }
		 cout<<"\n data is successfully stored at the beginning";
 }
 void addElementAtEnd(){
 	nodeType *temp=new nodeType;
 	cout<<"enter number ";
 	cin>>temp->info;
 	temp->next=NULL;
 	temp->prev=NULL;
 		if (head==NULL){
 			head=temp;
 			tail=temp;
		 }else{
		 	temp->next=temp;
		 	head->prev=tail;
		 	tail=tail->next;
		 }
		 cout<<"\n data is successfully stored at the end";
}
void removeElementAtBeginning(){
	nodeType *temp;
	if(head==NULL){
		cout<<"list is empty";
		
	}else{
		temp=head;
		head=head->next;
		head->prev=NULL;
			delete temp;
			cout<<"\n data is successfully removed from the beginning";
	}
}
void removeElementAtEnd(){
	nodeType *temp;
	if(head==NULL){
		cout<<"\n list is empty";
	}else{
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete temp;
		cout<<"\n data is successfully removed from the end";
	}
}
void rprintNodeType(){
if(tail==NULL){
	cout<<"\n list is empty";
}else{
	nodeType* current;
	current=tail;
		cout<<"\n list of number is : ";
		while(current->next!=NULL){
			cout<<"\t"<<current->info;
			current=current->prev;
		}
			cout<<"\n data is succussfully printed reversily ";	
}
}
void printNodeType(){
if(head==NULL){
	cout<<"\n list is empty";
}else{
	nodeType *current;
	current=head;
		cout<<"\n list of number is : ";
		while(current!=NULL){
			cout<<"\t"<<current->info;
			current=current->next;
		}
			cout<<"\n data is succussfully printed  ";	
}
}
 int main(){
 	char op;
	int pos;
	menu:
	cout<<"\npress 1 to add element at the beginning";
	cout<<"\npress 2 to add element at the end";
	cout<<"\npress 3 to remove element from the beginning";
	cout<<"\npress 4 to remove element from the end";
	cout<<"\npress 5 to print list of data  ";
	cout<<"\n press 6 to print reverse list";
    cout<<"\npress 0 to exit ";
	cout<<"\n \n select  operation ";
	cin>>op;
	switch(op){
	case '1':
		addElementAtBeginning();
		break;
		case '2':
			addElementAtEnd();
			break;
				case '3':
					removeElementAtBeginning();
					break;
					case '4':
                 removeElementAtEnd();
                 break;
                 case '5':
                       	printNodeType();
                 		break;
                 		case '6':
                       	rprintNodeType();
                 		break;
                 		case  '0':
                 			exit(0);
                 			break;
                 		default :
                 			cout<<"\n incorrect , try again  ";
                 			break;
	}

goto menu;	
return 0;
 }
