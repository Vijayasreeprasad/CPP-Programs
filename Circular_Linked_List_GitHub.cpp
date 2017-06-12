#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct node
{
    int value;
    node* next;
};




//inserting a node at the very beginning of the circular linked list.
node* circularinsertBegin(node *head,int num)
{
	node *newNode=new node; // creating a new node	
	newNode->value=num; // assigning num to the value of new node created 
	if(head==NULL)   //if empty list make the new node as head
	{
		head=newNode;
		newNode->next=head;
	}
	else
	{
		node *t=head;    //else find the tail(t) and  make the tail->next point to newNode 
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=newNode;
		newNode->next=head;
		head=newNode; // make the newNode the head of the circular linked list
	}
	return head;
}


//inserting the node at the end of the circular linked list 
node* circularinsertEnd(node *head, int num)
{
	node *newNode=new node;  //creating a new Node
	newNode->value=num; // assinging num to the value of the new node created 
	if(head==NULL)   // if empty list make the new node as head
	{
		head=newNode;
		newNode->next=head;
	}
	else
	{
	node *t=head;  //else find the tail(t) and  make the tail->next point to newNode 
	while(t->next!=head)
	{
			t=t->next;
	}
		t->next=newNode;
	 	newNode->next=head;      //make the new node->next point to head
	 	t=newNode;            // make the new node as tail
	}
	return head;
}




///////////Sorted Insert By Value///////

/*Inserting a node based on the value passed. That is, inserting at a appropriate place.
For example if current list 2->3->5->6->2 , which is already in ascending order.
If you wanna insert number 4 the following code exactly places number 4 after 3 and maintains the
ascedning order. */

node *sortedinsert(node *head, int num)
{
       node *newnode = new node; //creating a new Node
       newnode->value = num;     // assinging num to the value of the new node created 
    if(head==NULL)               //if the list is empty
    {
       	head=newnode;
       	newnode->next=head;
	}
	   
	else if(head->next==head)       // If only one node in the list
	{
	   	if(num<head->value)        // num passed is less than the value of head.
		{
	   		newnode->next=head;   //make the newnode->next point to head.
	   		head->next=newnode;   
	   		head=newnode;         //make the new node as head.
		}
		else                     //else if num is greater than the value of head
		{
			head->next=newnode;   //make the head->next point newnode and newnode->next point to head. 
			newnode->next=head;
		}
	}
	else                           //else find the tail(t)
	{
		node *tail=head;   // finding the tail(t)
		while(tail->next!=head)
		{
			tail=tail->next;
		}
		
	//Creating two pointers one pointing to head and another pointing to tail.
	//Here *nptr is pointing to head. Whereas, *prev is pointing to tail.
		node *nptr=head;         
		node *prev=tail;
		while(nptr->next!=head && nptr->value<num)  //traversing the list 
		{
			prev=nptr;
			nptr=nptr->next;
		}
		
	//if its fisrt position in the list insert it and make the new node as head.
		if(nptr==head && prev==tail)  
		{
			newnode->next=nptr;
			prev->next=newnode;
			head=newnode;
		}
		
	//nptr is at tail 	
	else if(nptr==tail && nptr->value<num)
		{
			nptr->next=newnode;
			newnode->next=head;
		}
		else
		{
			prev->next=newnode;
			newnode->next=nptr;
		}
	}
	return head;	
}


///////////////////////SORTED DELETE////////////////////////

//Deleting based on the value.
node *sorteddelete(node *head,int num)
{
	if(!head)    //if the list is empty return NULL
	return NULL;
	
	node *t=head;  //finiding tail(t)
	while(t->next!=head)
		{
			t=t->next;
		}
	
	if(head->value==num)   //if the number you passed natches with the value of head
	{
		if(head==t)       //if only one node in the list, then head and tail will pint to same node. Delete node abnd return NULL
		{
			delete head;
			return NULL;
		}
		/*if there are more than one node in the list and the value of num matches with the value of the head
		create a new pointer *curr which is pointing to head, move the head pointer, then make the tail->next point to
		head and delete the curr. */
		else
		{
			node *curr=head;      
			head=head->next;
			t->next=head;
			delete curr;
		}
	}
	//Create two pointers(*np and *pn) to traverse the list. 
	else
	{
		node *np=head; node *pn=NULL;
		while((np!=t)&&(np->value!=num))
		{
			pn=np;
			np=np->next;
		}
		
		if(np==t && num!=np->value)
		{
			cout<<"not found"<<endl;
			
		}
	else if((np->value==num))
		{
			pn->next=np->next;
			delete np;
		}
	}
	return head;
}

////////////////////////////END SORTED DELETE///////////////////

// Deleting at the begining of the list
node* circulardeleteBegin(node *head)
{
	if(head==NULL)  //if the list is empty return NULL
{
		return NULL;
}
// else find tail
else
{
	node *t=head;
	while(t->next!=head)
	{
		t=t->next;
	}
		
	if(head==t)  //if only one node in the list , head and tail will point to same node. delete head and return NULL
	{
		delete head;
		return NULL;
	}
	//create a *curr pointer pointing to head, move head, make the tail->next point to new head and delete curr.
	else 
	{
		node *curr=head;
		head=head->next;
		t->next=head;
		delete curr;
		return head;
	}
 }
}



//Deleting at the end of the list
node *circulardeleteEnd(node *head)
{
	if(!head)   //if no nodes on the list return NULL.
	return NULL;
	
	// else find the tail(t)
		node *t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		
	//if only one node in the list, head and tail will point to same node. delete head and return NULL
	if(head==t)
		{
			delete head;
			//cout<<"deleted"<<endl;
			return NULL;
		}
		
	//create two pointers *np pointing to head and *pn pointing to NULL, to traverse the list.	
	else
		{
		
			node *np=head; node *pn=NULL;
			while(np->next!=head)
			{
				pn=np;
				np=np->next;
			}
			
			//after reaching the last node. 
				pn->next=np->next;
				delete np;
				return head;
		}

}




// Printing all the elements of the Circular Linked list
void print(node *head){
	node *temp=head;
	do{
    cout<<temp->value<<" ";
    temp=temp->next;
	}while(temp!=head);
}


int main()
{
struct node *head = NULL;

cout<<"1. Testing Sorted insert "<<endl;
cout<<endl;
cout<<"Inserting 41"<<endl;
head=sortedinsert(head,41);
print(head); cout<<endl;
cout<<"Inserting 5, 32, 49, 10"<<endl;
head=sortedinsert(head,5);
head=sortedinsert(head,32);
head=sortedinsert(head,49);
head=sortedinsert(head,10);
print(head);
cout<<endl;
cout<<"----------------------------"<<endl;
cout<<"2. Testing CircularInsertBegin"<<endl;
head=circularinsertBegin(head,2);

print(head);
cout<<endl;
cout<<"----------------------------"<<endl;
cout<<"3. Testing CircularInsertEnd"<<endl;
head=circularinsertEnd(head,100);

print(head);
cout<<endl;
cout<<"------------------------------"<<endl;
///////////

cout<<endl;
cout<<"4. Testing Delete At End"<<endl;
head=circulardeleteEnd(head);
print(head);
cout<<endl;
cout<<"--------------------------"<<endl;

cout<<endl;
cout<<"5. Again deleting At End"<<endl;
head=circulardeleteEnd(head);
print(head);
cout<<endl;
cout<<"--------------------------"<<endl;

cout<<endl;
cout<<"6. Deleting At Begin"<<endl;
head=circulardeleteBegin(head);
print(head);
cout<<endl;
cout<<"--------------------------"<<endl;

cout<<endl;
cout<<"7. Inserting 23 using Sorted Insert by value "<<endl;
head=sortedinsert(head,23);
print(head);
cout<<endl;
cout<<"--------------------------"<<endl;
cout<<endl;

cout<<"8. Deleting number 23 using Sorted Delete by value"<<endl;
head = sorteddelete(head,23);
print(head);
cout<<endl;	
return 0; 
}
