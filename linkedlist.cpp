#include<iostream>

using namespace std;

struct nodeType{

int info;
nodeType* next;
};
nodeType *HEAD=NULL;
void addElementAtEnd(){
	nodeType *temp=new nodeType;
	nodeType *current;
	cout<<"\enter the number";
	cin>>temp->info;
	if(HEAD=NULL){
		
		HEAD=temp;
		
	}else{
		current=HEAD;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=temp;
	}
	cout<<"\ndata is successfully stored at the end";
}
void addElementAtStart(){
	nodeType *temp=new nodeType;
	cout<<"\nenter the number";
	cin>>temp->info;
	if(HEAD=NULL){
		temp->next=NULL;
		
}else{
	temp->next=HEAD;
}
HEAD=temp;
	cout<<"\ndata is successfully stored at the begininng";
}
void addElementAtSpecificPosition(int pos){
	nodeType *temp=new nodeType;
	cout<<"\nenter the number";
	cin>>temp->info;
		temp->next=NULL;
	if(HEAD=NULL){
	HEAD=temp;
	}else{
		nodeType *prev,*curr;
		int i=1;
		curr=HEAD;
		while(i<pos){
			prev=curr;
			curr=curr->next;
			i++;
		}
		temp->next=curr;
		prev->next=temp;
	}
	cout<<"\n data is succussfully stored at specific position";
}
void removeElementAtStart(){
	nodeType *temp;
	if(HEAD==NULL){
		cout<<"list is empty";
		}else{
			temp=HEAD;
			HEAD=HEAD->next;
			delete temp;
			cout<<"\n data is succussfully removed from beginning ";
		}
	}
	
void removeElementAtSpecificPosition(int pos){
	if(HEAD==NULL){
		cout<<"\n list is empty";
	}else{
		nodeType *prev,*curr;
		int i=1;
		while(i<pos){
			prev=curr;
			curr=curr->next;
			i++;
		}
		prev->next=curr->next;
		delete curr;
		cout<<"\n data is succussfully removed from specific position ";
	}
}
void removeElementAtEnd(){
	nodeType *temp;
	if(HEAD==NULL){
		cout<<"\nlist is empty";
		
	}else if(head->next==NULL){
		temp=head;
		head=NULL;
		delete temp;
		cout<<"\n data is succussfully removed from end ";	
	}else{
		nodeType *prev,*curr;
		curr=HEAD;
		while(curr->next!=NULL){
			prev=curr;
			curr=curr->next;
		}
		prev->next=NULL;
		delete curr;
	cout<<"\n data is succussfully removed from end ";	
	}
	
}
void printNodeType(){
nodeType* current;
if(HEAD==NULL){
	cout<<"\n list is empty";
}else{
	current=HEAD;
		cout<<"\n list of number is : ";
		while(current!=NULL){
			cout<<"\t"<<current->info;
			current=current->next;
		}
			cout<<"\n data is succussfully printed ";	
}
}
int main(){
	char op;
	int pos;
	menu:
	cout<<"\npress 1 to add element at the beginning";
	cout<<"\npress 2 to add element at the end";
	cout<<"\npress 3 to add element at the specific position";
	cout<<"\npress 4 to remove element from the beginning";
	cout<<"\npress 5 to remove element from the end";
	cout<<"\npress 6 to remove element from the specific position";
	cout<<"\npress 7 to print list of data  ";
	cout<<"\n \n select  operation ";
	cin>>op;
	switch(op){
	case '1':
		addElementAtStart();
		break;
		case '2':
			addElementAtEnd();
			break;
			case '3':
				cout<<"\n enter position ";
				cin>>pos;
				addElementAtSpecificPosition(pos);
				break;
				case '4':
					removeElementAtStart();
					break;
					case '5':
                 removeElementAtEnd();
                 break;
                 case '6':
                 	cout<<"\n enter the position";
                 	cin>>pos;
                 	removeElementAtSpecificPosition(pos);
                 	break;
                 	case '7':
                 		printNodeType();
                 		break;
	}

goto menu;	
return 0;	
	
}

