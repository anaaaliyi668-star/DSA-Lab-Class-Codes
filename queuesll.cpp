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
int main(){
	return 0;
}
