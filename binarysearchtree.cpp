#include <iostream>
using namespace std;


struct BSTNode{
	int data;
  BSTNode *leftchild;	
  BSTNode *rightchild;
};

class BinarySearchTree{
	private :
    	BSTNode *root;
    public :
	   void insertBST(int);
	   bool searchBST(int);	
	   void deleteBST(int);
	   void inorderTraversal();
	   void inorder(BSTNode *);
	   void preorderTraversal();
	   void preorder(BSTNode * );
	    void postorderTraversal();
	   void postorder(BSTNode * );
	   BSTNode * findMin(BSTNode * );
	   BSTNode * findMax(BSTNode * );
	   int findHeight();
	   int totalNode();
	   int totalLeaves();
	   BinarySearchTree();
	   ~BinarySearchTree();
	   void destroyNode(BSTNode *);
	   bool isTreeEmpty();
};
  
 BinarySearchTree::BinarySearchTree(){
  	root=NULL;
  }
 BinarySearchTree::~BinarySearchTree(){
  	destroyNode(root);
  }
  void BinarySearchTree::destroyNode(BSTNode * temp){
  	if(temp==NULL){
  		return;
	  }else{
	  	destroyNode(temp->leftchild);
	  	destroyNode(temp->rightchild);
	  	delete temp;
	  }
  }
  void BinarySearchTree::insertBST(int newData){
  	BSTNode *temp=new BSTNode;
  	temp->data=newData;
  	temp->leftchild=NULL;
  	temp->rightchild=NULL;
  	if(root==NULL){
  		root=temp;
	  }else{
	  	BSTNode *current,*prevCurrent;
	  	current=root;
	  	while(current!=NULL){
	  		prevCurrent=current;
	  		if(current->data==newData){
	  			cout<<"\nDupilicate Data is not allowed in BST";
	  			return;
			  }else if(current->data>newData){
			  	current=current->leftchild;
			  }else{
			  	current=current->rightchild;
			  }
		  }
		  if(prevCurrent->data>newData){
		  	prevCurrent->leftchild=temp;
		  }else{
		  	prevCurrent->rightchild=temp;
		  }
	  }
	  	cout<<"\nData is successfully stored";
  } 
 /*  int BinarySearchTree::findHeight(){
  	
  }
  BinarySearchTree::findMax(){
  	
  }   
  void BinarySearchTree::findMin(){
  	
  } */
  void BinarySearchTree::inorderTraversal(){
  	inorder(root);
  } 
  void BinarySearchTree::inorder(BSTNode * temp){
  	if(temp!=NULL){
  		inorder(temp->leftchild);
  		cout<<"\t "<<temp->data;
  		inorder(temp->rightchild);
	  }
  }
   void BinarySearchTree::postorderTraversal(){
  	postorder(root);
  }  
  void BinarySearchTree::postorder(BSTNode * temp){
  	if(temp!=NULL){
  		postorder(temp->leftchild);
  		postorder(temp->rightchild);
  		cout<<"\t "<<temp->data;
	  }
  } 

 void BinarySearchTree::preorderTraversal(){
  	preorder(root);
  } 
  void BinarySearchTree::preorder(BSTNode * temp){
  	if(temp!=NULL){
  		cout<<"\t "<<temp->data;
  		preorder(temp->leftchild);
  		preorder(temp->rightchild);
	  } 
  }

  bool BinarySearchTree::searchBST(int searchkey){
  	bool found=false;
  	if(root==NULL){
  		cout<<"\n tree is empty";
	  }else{
	  	BSTNode *current=root;
	  	while(current!=NULL && !found){
	  		if(current->data==searchkey){
	  			found=true;
	  			break;
			  }else if(current->data>searchkey){
			  	current=current->leftchild;
			  }else{
			  	current=current->rightchild;
			  }
		  }
	  }
	  return found;
  }
  /* 
  void BinarySearchTree::totalLeaves(){
  	
  } 
  void BinarySearchTree::totalNode(){
  	
  }   */  
  
  void BinarySearchTree::deleteBST(int deletekey){
  	BSTNode *current, *prevCurrent,*temp;
  	bool found=false;
  	if(root==NULL){
  		cout<<"\n Tree is Empty";
	  }else{
	  	current=root;
	  	while(current!=NULL){
	  	prevCurrent=current;
		  if(current->data==deletekey){
		  	found=true;
		  	break;
		  }else if(current->data>deletekey){
		  	current=current->leftchild;
		  }else{
		  	current=current->rightchild;
		  }
		  }
		  if(!found){
		  	cout<<"\n item  is not found";
		  }else{
		  	if(prevCurrent->data<deletekey){
		  		if(current->leftchild==NULL && current->rightchild==NULL){
		  			prevCurrent->rightchild=current->rightchild;
		  			delete current;
				  }else if(current->rightchild==NULL){
				  	prevCurrent->rightchild=current->leftchild;
		  			delete current;
				  }else if(current->leftchild!=NULL && current->rightchild!=NULL){
			          temp=current->leftchild;
					  while(temp->rightchild!=NULL){
					  	temp=temp->rightchild;
					  }	
					  current->data=temp->data;	
					  delete temp;
				  }
			  }else{
			  	if(current->leftchild==NULL){
			  			prevCurrent->leftchild=current->rightchild;
			  			delete current;
				  }else if(current->rightchild==NULL){
				  		prevCurrent->leftchild=current->leftchild;
			  			delete current;
				  }else if(current->leftchild!=NULL && current->rightchild!=NULL){
				  	  temp=current->leftchild;
					  while(temp->rightchild!=NULL){
					  	temp=temp->rightchild;
					  }	
					  current->data=temp->data;	
					  delete temp;
				  }
			  }
		  }
	  }
	  cout<<"\n data is successfully deleted";
  }                                         
int main(){
	
	BinarySearchTree bst;
	char op;
	int item;
	int searchitem;
	int deleteitem;
	menu:
		cout<<"\n press 1 to insert new item into the tree";
		cout<<"\n press 2 to search item in the tree";
		cout<<"\n press 3 to delete item from the tree";
		cout<<"\n press 4 for preorder traversal in the tree";
		cout<<"\n press 5 for inorder traversal in the tree";
		cout<<"\n press 6 for postorder traversal in the tree";
		
		cout<<"\n select operation";
		cin>>op;
		switch(op){
			case '1':
		     	cout<<"\n enter new item";
		    	cin>>item;
		    	bst.insertBST(item);
			break;
			case '2':
			cout<<"\n enter item to be searched";
			cin>>searchitem;
			if(bst.searchBST(searchitem)){
			 cout<<"\n item is found in the tree";
			}else{
				cout<<"\n item is not found in the tree";
			}
			break;
			case '3':
				cout<<"\n enter item to be deleted";
				cin>>deleteitem;
				bst.deleteBST(deleteitem);
				break;
			case '4':
				cout<<"\n preorder";
				bst.preorderTraversal();
				break;
			case '5':
				cout<<"\n inorder";
				bst.inorderTraversal();
				break;
			case '6':
				cout<<"\n postorder";
				bst.postorderTraversal();
				break;
				default:
					cout<<"\n incorrect, Try again";
					break;
		}
	goto menu;
	return 0;
}
