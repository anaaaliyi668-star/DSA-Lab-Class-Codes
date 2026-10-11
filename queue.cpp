#include<iostream>

using namespace std;
class queueType{
	private:
		int *queuelist;
		int maxsize;
		int frontindex;
		int rearindex;
		public:
			bool isqueueempty();
			bool isqueuefull();
			void enqueue(int);
			int dequeue();
			int frontelement();
			int rearelement();
			queueType(int);
			~queueType();
};
queueType::queueType(int SIZE){
	if(SIZE<=-1){
		cout<<"\n queue size must be positive ";
		maxsize=10;
	}else{
		maxsize=SIZE;
	}
	frontindex=-1;
	rearindex=-1;
	queuelist=new int[maxsize];
}
queueType::~queueType(){
	delete queuelist;
}
bool queueType::isqueueempty(){
	return (rearindex==-1&&frontindex>rearindex);
}
bool queueType::isqueuefull(){
	return (rearindex>=maxsize-1 && rearindex>=maxsize-1);
}
void queueType::enqueue(int item){
	if(isqueuefull()){``
		cout<<"\n queue overflow";
	}else{
		if(frontindex==-1)
		frontindex=0;
		rearindex=rearindex+1;
		queuelist[rearindex]=item;
	}
}
int queueType::dequeue(){
	int delval;
	if(isqueueempty()){
		cout<<"\n queue underflow";
		delval=-1;
		return delval;
	}else{
		delval=queuelist[frontindex];
		frontindex++;
		return delval;
			
	}
}
int queueType::frontelement(){
	if(isqueueempty()){
		cout<<"\n queue underflow";
		return -1;
	}else{
		return queuelist[frontindex];
	}
}
int queueType::rearelement(){
	if(isqueueempty()){
		cout<<"\n queue underflow";
		return -1;
	}else{
		return queuelist[rearindex];
	}
}
int main(){
	queueType queueobj(5);
	queueType otherobj(5);
	char op;
	int item;
	menu:
		cout<<"\n press 1 to enque element into the queue";
		cout<<"\n press 2 to deque element from the queue";
		cout<<"\n press 3 to return front element";
		cout<<"\n press 4 to return rear element  ";
		cout<<"\n press 5 to print queue element";
		cout<<"\n press 0 to exit";
	    cout<<"\n\n select operation ";
	    cin>>op;
	    switch(op){
	    case '1':
	    	cout<<"\n enter the element ";
	    	cin>>item;
	    	queueobj.enqueue(item);
	    	break;
	    	 case '2':
	    	 	cout<<"\n element to be removed is"<<queueobj.dequeue();
	    	break;
	    	 case '3':
	    	 	cout<<"\n front element is"<<queueobj.frontelement();
	    	break;
	    	case '4':
	    		cout<<"\n rear element is"<<queueobj.rearelement();
	    		break;
	    	 case '5':
	    	 	cout<<"\n elemrent : ";
	    	 	otherobj=queueobj;
	    	 	while(!otherobj.isqueueempty()){
	    	 		cout<<"\t "<<otherobj.dequeue();
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
