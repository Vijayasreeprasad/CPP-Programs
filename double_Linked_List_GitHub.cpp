#include<iostream>
using namespace std;

struct node
{
	int value;
	node *next;
	node *prev;
};

//Inserting a node at the BEGINING of the Node
node *insertBegin(node *head,int num)
{
	node *newnode=new node;  //creating node
	newnode->value=num;			//assigning num to the value of newnode
	
	if(head==NULL) //empty list; the, make the newnode as head.
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else //inserting at the begining
	{
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=NULL;
		head=newnode;
	}
	return head;
}

//Inserting a node at the END
node *insertEnd(node *head, int num)
{
	node *newnode=new  node;
	newnode->value=num;
	
	if(head==NULL)			//empty list
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else					//traverse to the end of the list and attach the newnode.
	{
		node *nptr=head;				//creating a pointer to traverse the list
		while(nptr->next!=NULL)			//traversing till end of the list
		{
			nptr=nptr->next;
		}
		
		nptr->next=newnode;
		newnode->prev=nptr;
		newnode->next=NULL;
	}
	return head;
	
}


//Sorted Insert By value

/*Inserting a node based on the value passed. That is, inserting at a appropriate place.
For example if current list 2->3->5->6-, which is already in ascending order.
If you wanna insert number 4 the following code exactly places number 4 after 3 and maintains the
ascedning order. */

node *sortedInsert(node *head,int num)
{
	node *newnode=new node;
	newnode->value=num;
	
	if(head==NULL) //empty list insert at begin// extreme case:1
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	
	else if(num<head->value) //num is less than the value of head //extreme case:2
	{
		newnode->next=head;
		head->prev=newnode;
		newnode->prev=NULL;
		head=newnode;
	}
	
	else			//creating two pointers *nptr and *pn to traverse the list
	{
	node *nptr=head;
	node *pn=NULL;
	
	while((nptr!=NULL) && (nptr->value<num))    //traversing the list
	{
		pn=nptr;
		nptr=nptr->next;	
	}

	pn->next=newnode;
	newnode->prev=pn;
	newnode->next=nptr;
	if(nptr!=NULL)     /// extreme case:3
	nptr->prev=newnode;
	
	}
	return head;
}


//DELETE OPERATIONS//
//Deleting a node at the BEGINING of the list.
node *deleteBegin(node*head)
{
	if(head==NULL)  //if list is empty return Null
		return NULL;
	
	else              //create a temp pointer make it point to head. Move the head by one position and delete the temp.
	{
		node *temp=head;
		head=head->next;
		if(head!=NULL)
		head->prev=NULL;
		delete temp;
		return  head;
	}	
}



//Deleting a node at the END of the list
node *deleteEnd(node *head)
{
	if(head==NULL)        //if the list is empty return NULL
	return NULL;
	
	else if(head->next==NULL) //only one node in the list, delete that node and return NULL.
	{
		delete head;
		return NULL;
	}
	
	//create two pointers *nptr and *pn to traverse the list till end and delete the last node
	else
	{
		node *nptr=head;
		node *pn=NULL;
		
		while((nptr->next!=NULL)) //traverse till end and delete the last node
		{
			pn=nptr;
			nptr=nptr->next;
		}
		pn->next=nptr->next;
		delete nptr;
		return head;
	}
}



//Sorted Delete By Value. Deleting a node based on the value. list should be in Ascending order
node *sortedDel(node *head,int num)
{
	if(head==NULL)			//if the list is empty return NULL
	return NULL;
	
	else if(head->value==num) //num macthed with value of head
	{
		node *temp=head;
		head=head->next;
		if(head!=NULL)
		head->prev=NULL;
		delete temp;
		return  head;
	}	
	
	//create two pointers to traverse the list to find the value.
else
	{
		node *nptr=head;
		node *pn=NULL;
		
		while((nptr!=NULL)&&(nptr->value!=num))
		{
			pn=nptr;
			nptr=nptr->next;
		}
		
		if(nptr==NULL) //num not found in the list
		{
			cout<<"not found"<<endl;
			
		}
		
		else
		{
			node *temp= nptr->next;
			pn->next=temp;
			if(temp!=NULL)
			temp->prev=pn;
			delete nptr;
			return head;
		}
	}
}


//Searching a particular node in the list
bool search(node*head,int num)
{
	if(head==NULL)
	return false;
	else
	{
		node *nptr=head;
		while(nptr!=head && nptr->value!=num)
		{
			nptr=nptr->next;
		}
		if(nptr==NULL)
		{
			cout<<"not found"<<endl;
			return false;
		}
		else if(nptr->value==num)
		{
			return true;
		}
	}
}


//Printing the elements of the list
void print(node *head)
{
	node *temp=head;
do
	{
		cout<<temp->value<<" ";
		temp=temp->next;
	}	
	while(temp!=NULL);
}



int main()
{
	struct node* head=NULL;
	cout<<"1. Checking InsertAtBegin"<<endl;
	cout<<"Inserting 6 "<<endl;
	head = insertBegin(head,6);
	print(head);
	cout<<endl;
	cout<<"InsertingAtBegin, Inserting 4 and 14"<<endl;
	head = insertBegin(head,4);
	head = insertBegin(head,14);
	print(head); cout<<endl;
cout<<"-----------------------------"<<endl;
cout<<"2. Checking Sorted Insert By Value"<<endl;
cout<<"Inserting 2, 20, 100"<<endl;
head = sortedInsert(head,2);
head = sortedInsert(head,20);
head = sortedInsert(head,100);
print(head);
cout<<endl;
	
	cout<<"------------------"<<endl;
	cout<<"3. Checking DeleteAtEnd"<<endl;
	head = deleteEnd(head);
	print(head);
	cout<<endl;
	
	cout<<"---------------------"<<endl;
	cout<<"4. Checking Sorted Delete By Value.."<<endl;
	cout<<"Deleting 4"<<endl;
		head=sortedDel(head,4);
		print(head);
		cout<<endl;


	return 0;
}

































