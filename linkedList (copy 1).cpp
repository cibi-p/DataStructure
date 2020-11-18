#include<iostream>
#include<stdlib.h>
using namespace std;

void printnode();
int menulinkedlist();
void displayqueue(int*);
//-------------------likedlist-----------------------------
struct node
{
	char name[40];
	node *next;
}*head,*tail;

int createlist(int a)
{
        node *temp;
        if(head!=NULL)
	{
		cout<<"\n________________________________"<<endl;
		cout<<"| already the list is existed |"<<endl;
		cout<<"________________________________"<<endl<<endl;
		return 0;
	}
	else{
	for(int i=0;i<a;i++)
	{      
		node *newnode=new node();
		char c[40];
		cout<<"Enter the "<<i+1<<"th name: \t"<<endl;
               cin>>newnode->name;
               newnode->next=NULL;
              if(head==NULL)
		{
               	head=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
                      temp=newnode;
                      tail=temp;
               }
	}
	cout<<"List created successfully ^_^ "<<endl;
	printnode();
	return 0;}
}
void printnode()
{
	node *temp=new node();
       cout<<"\n\n\n";
       cout<<"********************************************************"<<endl;
       cout<<"                  You Entered Data                                      "<<endl;
	cout<<"********************************************************"<<endl<<endl;
       for(temp=head; temp != NULL; temp=temp->next)
	{
		cout<<temp->name<<endl;
        }
	cout<<"\n\n";
	cout<<"********************************************************"<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"\n\n";
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
}
void insertnode(int position, int *a)
{
	if(position>*a+1||position<=0)
	{
		cout<<"Enter the input between 1 to "<<*a+1<<endl;
               cout<<"Enter the position:"<<endl;
		cin>>position;
		insertnode(position, a);
	}
	else{
       node *temp;
	if(position==1)
	{
		node *newnode=new node();
              cout<<"Enter the name for 1st position";
              cin>>newnode->name;
              newnode->next=head;
              head=newnode;
	}
	if(position==(*a)+1)
	{
               node *newnode=new node();
               cout<<"Enter the name for "<<(*a)+1<<"th postion";
		cin>>newnode->name;
               newnode->next=NULL;
               tail->next=newnode;
	}
	else
	{
		node *newnode=new node();
               node *prev, *curr;
               cout<<"Enter the name for "<<position<<"th position";
               cin>>newnode->name;
               curr=head;
               for(int i=0;i<position-1;i++)
		{
                      prev=curr;
			curr=curr->next;
		}
              prev->next=newnode;
              newnode->next=curr;
	}
	*a=*a+1;}
}  
void deletenode(int position, int *a)
{
	if(position<=0||position>*a)
	{
		cout<<"Enter the number between 1 to "<<*a<<endl;
		cin>>position;
		deletenode(position,a);
	}
	else{
	node *temp, *curr, *prev;
	if(position==1)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	if(position==*a)
	{
              curr=head;
		temp=tail;
               for(int i=0;i<*a-2;i++)
		{
			curr=curr->next;
		}
		curr->next=NULL;
              curr=tail;
		free(temp);
	}
	else
	{
		temp=head;
		curr=head;
		prev=head;
		for(int i=0;i<position-1;i++)
		{
				prev=curr;
				curr=curr->next;
		}
		prev->next=curr->next;
              free(curr);
	}
       *a=*a-1;}
} 
void searchinlinkedlist(int* a)
{
	node* temp;
	temp=head;
	int find=0;
	cout<<"Enter the string to search:\t"<<endl;
	string searchh;
	cin>>searchh;
	cout<<searchh<<endl;
	for(int i=0; i<*a;i++)
	{
		if(searchh==temp->name)
		{
			find++;
		}
		else{
			temp=temp->next;
		}
	}
	if(find!=0)
	{
		cout<<"The entered string is found in the linked list:"<<endl;
	}
	else{
		cout<<"The entered string is not found in the linked list:"<<endl;
	}
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
}

//-----------------end of linked list----------------

//--------------stack------------------------------------

struct  stack
{
	char name[40];
	stack *next;
}*top;

int stacksize=0;

void push()
{
	cout<<"Enter the string to push:\t";
	stack *newnode;
	newnode= new stack();
	cin>>newnode->name;	
	newnode->next=top;
	top=newnode;
	stacksize++;
	cout<<"\nThe given element is pushed successfully <=(o_o)=>\n"<<endl;
}

char pop()
{
	char* data;
	if(top==NULL)
	{
		cout<<"The stack is empty  -_- "<<endl;
		string entter;
	       cout<<"press any letter and enter to continue:";
       	do{
			getline(cin, entter);
		     }while(entter.length()==0);
		return 0;
	}
	else{
	stack *temp;
        cout<<"The name get pop out in stack is "<<top->name<<endl;
	data=top->name;
	temp=top;
	top=top->next;
	stacksize--;
	}
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
	return *data;
}
int isstackempty()
{
	if(top==NULL)
	{
		cout<<"The stack is empty -_-"<<endl;
	       cout<<"press any letter and enter to continue:";
		string entter;
              do{
		       getline(cin, entter);
	            }while(entter.length()==0);
		return 1;
	}
	else
	{
		cout<<"The stack is not empyt it contain "<<stacksize<<" elements."<<endl;
	       string entter;
	       cout<<"press any letter and enter to continue:";
              do{
		       getline(cin, entter);
	            }while(entter.length()==0);
		return 0;
	}
}

char peek()
{
	if(top==NULL)
	{
		cout<<"The given stack is empty  [ -_-] "<<endl;
		string entter;
		cout<<"press any letter and enter to continue:";
       	do{
			getline(cin, entter);
		    }while(entter.length()==0);
		return 0;
	}
	else
	{
	cout<<"The peek name in the stack is "<<top->name<<endl;
	char* ttemp=top->name;
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
	return *ttemp;
	}
}

void displaythestack()
{
	stack *temp=top;
	cout<<"\n\n--------------------------  --------------------------------"<<endl;
	cout<<"The element in the stack are:"<<endl;
	for(int i=0;i<stacksize;i++)
	{
		cout<<temp->name;
		if(i<stacksize-1)
		{ cout<<"->";}
		temp=temp->next;
	}
	cout<<"\n--------------------------  --------------------------------\n\n"<<endl;
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
}
int menulinkedlist()
{
	int a, position;
	cout<<"How much name you want to add:\t";
       cin>>a;
       createlist(a);
	int exit1=0;
	while(exit1!=15){
	system("clear");
	cout<<"Linked list operations:\n"<<endl;
	cout<<"\t11--> Insert node:(enter 11) "<<endl;
	cout<<"\t12--> Delete node: (enter 12) "<<endl;
	cout<<"\t13--> Print the data in node: (enter 13)"<<endl;
	cout<<"\t14--> Search in the linked list: (enter 14):"<<endl;	
	cout<<"\t15--> Back to main menu: (enter 15)"<<endl;
	cout<<"Enter your Choice:"<<endl;
	cin>>exit1;
	if(exit1==11){
       cout<<"Which position do you want to enter the data:\t";
       cin>>position;
       insertnode(position, &a);
       printnode();
	}
	if(exit1==12){
	cout<<"Enter the position of the node to delete:\t"<<endl;
	cin>>position;
	deletenode(position,&a);
	printnode();
	}
	if(exit1==13){
	printnode();
	}
	if(exit1==14)
	{
		searchinlinkedlist(&a);
	}
	if(exit1==15)
	{ return 0; }
	}
	return 0;
}
int menustack()
{	
	int exit1=0;
	while(exit1!=26){
       int a,position;
	system("clear");
	cout<<"Stack Operations:\n"<<endl;
	cout<<"\t21-->push into stack: (enter 21)"<<endl;
	cout<<"\t22-->pop from stack: (enter 22)"<<endl;
	cout<<"\t23-->Is stack empty: (enter 23)"<<endl;
	cout<<"\t24--> Display peek: (enter 24)"<<endl;
	cout<<"\t25--> Display all the element: (enter 25)"<<endl;
	cout<<"\t26-->Back to main menu: (enter 26)"<<endl;
	cout<<"Enter your Choice:"<<endl;
	cin>>exit1;
       if(exit1==21)
	{
		push();
		displaythestack();
	}
	if(exit1==22)
	{
		pop();
		cout<<"Now the stack is:"<<endl;
		displaythestack();
	}
	if(exit1==23)
	{
		isstackempty();
	}
	if(exit1==24)
	{
		peek();
	}
	if(exit1==25)
	{
		displaythestack();
	}
	if(exit1==26)
	{ return 0; }
	}
	return 0;
}
//------------------End of Stack---------------

//-----------------Queue---------------------

struct queue
{
	char name[40];
	queue* next;
}*front,*rear;

int enqueue(int *sizequeue)
{
	if(front==NULL)
	{
		queue* newnode=new queue();
		cout<<"Enter the string to add to queue:\t"<<endl;
		cin>>newnode->name;
		newnode->next=NULL;
		front=newnode;
		rear=front;
		*sizequeue=*sizequeue+1;
	}
	else{
	queue* newnode=new queue();
	cout<<"Enter the string to add to queue:\t"<<endl;
	cin>>newnode->name;
	newnode->next=rear;
	rear=newnode;
	*sizequeue=*sizequeue+1;
	}
	cout<<"The given string is enqueued successfully in a queue [ o ^_^ o ]"<<endl;
	displayqueue(sizequeue);
	return 0;
}

int dequeue(int *sizequeue)
{
	if(rear==NULL)
	{
		cout<<"The queue is empty -_-"<<endl;
	}
	else
	{
		queue* temp;
		temp=rear;
		for(int i=0;i<*sizequeue-1;i++)
		{
			temp=temp->next;
		}
		cout<<"The string get dequeue is "<<front->name<<endl;
		free(front);
		front=temp;
		*sizequeue=*sizequeue-1;	
	}	
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
	return 0;
}
void isqueueempty(int *sizequeue)
{
	if(rear==NULL)
	{
		cout<<"The queue is empty [   *_*]"<<endl;
	}
	else
	{
		cout<<"The queue is not empty it contain "<<*sizequeue<<" strings"<<endl;
	}
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
}

void displayqueue(int *sizequeue)
{
	if(rear==NULL)
	{
		cout<<"The queue is empty [  *_*]"<<endl;
	}
	else
	{	
		queue* temp;
		temp=rear;
		cout<<"---------------------- ------------------ ----------------------"<<endl;
		cout<<"The strings in the queue are:\n"<<endl;
		cout<<" Rear--->\t";
		for(int i=0;i<*sizequeue;i++)
		{
			cout<<temp->name;
			if(i<*sizequeue-1)
			{
				cout<<"<-";
			}
			temp=temp->next;
		}
		cout<<"\t<--- Front"<<endl;
		cout<<"---------------------- ------------------ ----------------------"<<endl;
	}
	string entter;
	cout<<"press any letter and enter to continue:";
       do{
		getline(cin, entter);
	}while(entter.length()==0);
}
int menuqueue()
{
	int sizequeue=0,exit1=0;
	while(exit1!=35)
	{
		system("clear");
		cout<<"Queue Operations:"<<endl;
		cout<<"\t 31--> enqueue in the queue (enter 31)"<<endl;
		cout<<"\t 32--> Dequeue from the queue (enter 32)"<<endl;
		cout<<"\t 33--> Is queue full (enter 33)"<<endl;
		cout<<"\t 34--> Display the queue (enter 34)"<<endl;
		cout<<"\t 35--> Back to the main menu (enter 35)"<<endl;
		cout<<"Enter your Choice: \n"<<endl;
		cin>>exit1;
		if(exit1==31)
		{
			enqueue(&sizequeue);
		}
		if(exit1==32)
		{
			dequeue(&sizequeue);
		}
		if(exit1==33)
		{
			isqueueempty(&sizequeue);
		}
		if(exit1==34)
		{
			displayqueue(&sizequeue);
		}
		if(exit1==35)
		{
			return 0;
		}
	}
	return 0;
}

int main()
{
       int a,position;
	int exit1=0;
	while(exit1!=4)
	{
	system("clear");
	cout<<"\n\n";
       cout<<"            ----|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|------   "<<endl;
	cout<<"                      choose your choice                              "<<endl;
	cout<<"           ----|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|------  "<<endl;
	cout<<"\n";
	cout<<" 1--> Create Linked List:(enter 1)"<<endl;
	cout<<" 2--> Create Stack: (enter 2)"<<endl;
	cout<<" 3-->  Create Queue: (enter 3) "<<endl;
	cout<<" 4-->  Exit(enter 4):"<<endl;
	cout<<"Enter your Choice:"<<endl;
	cin>>exit1;
	if(exit1==1){
	menulinkedlist();
	}
	//----------
	if(exit1==2)
	{
		menustack();
	}
	//----------------
	if(exit1==3)
	{
		menuqueue();
	}
	//------------------
	if(exit1==4){
	exit(0);
	}
	}
}
