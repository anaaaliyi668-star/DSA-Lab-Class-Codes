#include<iostream>

using namespace std;

class stackType{
	private:
		int maxsize;
		int top;
		int *stacklist;
	public:
	bool isemptystack();
	bool isfullstack();
	void push(int);
	int pop();
	int topelement();
	stackType(int);
	~stackType();	
};
stackType::stackType(int SIZE){
	if(SIZE<=-1){
	cout<<"\n size of stack must be piositive";
	maxsize=10;
	}else{
		maxsize=SIZE;
	}
	top=-1;
	stacklist=new int[maxsize];
	}
stackType::~stackType(){
		delete stacklist;
	}
bool stackType::isemptystack(){
		return (top==-1);
    }
bool stackType::isfullstack(){
	return (top>=maxsize-1);
}
void stackType::push(int item){
	if (isfullstack()){
		cout<<"\n stack overflow";
	}else{
		top=top+1;
		stacklist[top]=item;
		cout<<"\n data is successfully stored";
	}
}
int stackType::pop(){
	int del_val;
	if(isemptystack()){
		cout<<"\n stack is underflow";
	}else{
		del_val=stacklist[top];
		top=top-1;
		return del_val;
		cout<<"data is successfully removed ";
	}
}
int stackType::topelement(){
	return stacklist[top];
}
int main(){
	stackType stackobj(5);
	stackType otherobj(5);
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
	    	cout<<"\n enter the number ";
	    	cin>>item;
	    	stackobj.push(item);
	    	break;
	    	 case '2':
	    	 	cout<<"\n element to be removed is"<<stackobj.pop();
	    	break;
	    	 case '3':
	    	 	cout<<"\n top element is"<<stackobj.topelement();
	    	break;
	    	 case '4':
	    	 	cout<<"data in the stack is ";
	    	 	otherobj=stackobj;
	    	 	while(!otherobj.isemptystack()){
	    	 		cout<<"\t "<<otherobj.pop();
				 }
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
