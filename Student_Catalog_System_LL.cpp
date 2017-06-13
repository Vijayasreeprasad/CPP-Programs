#include<iostream>
#include<cstdio>
#include<conio.h>
#include<fstream>
using namespace std;

struct ListNode
{
	char name[25];
	char discipline[25];
	char section[20];
	int roll_num;
	ListNode *next;
};
ListNode *head;

//Adding a Record Of the Student
//cin is a static object of the istream class, defined in the iostream header file. It is used for taking user input.
//Although you can use cin for taking string input too, the input string will be truncated at the first white-space character.
//gets is a function, defined in the stdio.h header file. gets is used for taking string input.
void insertRecord()
{
	ListNode *newNode;
	newNode = new ListNode;

	cout<<"-->Pressed 1, To Add New Record.."<<endl;
	cout<<"Enter the Details of the Student: "<<endl;
	cout<<"Student Name: ";
	gets(newNode->name);
	fflush(stdin);
	cout<<"Student Discipline: ";
	gets(newNode->discipline);
	fflush(stdin);
	cout<<"Student Section: ";
	gets(newNode->section);
	fflush(stdin);
	cout<<"Studnet Roll_Num: ";
	cin>>newNode->roll_num;
	fflush(stdin);
	newNode->next=NULL;
	
	if(head==NULL)
	{
		head=newNode;
	}
	
	else
	{
		ListNode *curr;
		curr=head;
		
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=newNode;
	}
	
	cout<<"Record Entered!!"<<endl;
	cout<<"Press Any Key To Continue!!"<<endl;
	getch();
}

//Modifying Record of the Student
//Search the student based on the Roll_Num and modify the record.
void searchModifyRecord()
{
    ListNode *newNode;
    ListNode *prev;
    ListNode *curr;
    int roll_number;
    cout<<"-->Pressed 3, To Search and Modify particlar Record.."<<endl;
    cout<<"Enter the Roll_Num to search and modify: ";
    cin>>roll_number;
    
    prev=head;
    curr=head;
    while(curr->roll_num!=roll_number)
    {
    	prev=curr;
    	curr=curr->next;
	}
	
	newNode=new ListNode;
	fflush(stdin);  // The purpose of fflush(stream) is to make the operating system flush any buffers to the underlying file.
	cout<<"Enter the Details of the Student: "<<endl;
	cout<<"Student Name: ";
	gets(newNode->name);
	fflush(stdin);
	cout<<"Student Discipline: ";
	gets(newNode->discipline);
	fflush(stdin);
	cout<<"Student Section: ";
	gets(newNode->section);
	fflush(stdin);
	cout<<"Student Roll_Num: ";
 	cin>>newNode->roll_num;
 	fflush(stdin);
	
	prev->next=newNode;
	newNode->next=curr->next;
	curr->next=NULL;
	delete curr;
	cout<<endl<<"Record Modified!!"<<endl;
	cout<<"Press Any Key To Continue!!"<<endl;
	getch();
}

//Seacrhing a record of particular student based on the Roll_Num
void searchRecord()
{
	ListNode *prev, *curr;
	int roll_number;
	cout<<"-->Pressed 2, To Search a particular record.."<<endl;
    cout<<"Enter the Roll_Num to search: ";
	cin>>roll_number;
	
	if(head==NULL)
	{
		cout<<"No Records found!!"<<endl;
		cout<<"Press Any Key To Continue!!"<<endl;
	}
	
	else
	{
		prev=NULL;
		curr=head;
		while(curr->next!=NULL && curr->roll_num!=roll_number)
		{
			prev=curr;
			curr=curr->next;
		}
		
		if(curr->roll_num!=roll_number)
		{
			cout<<"Invalid Roll_num"<<endl;
			cout<<"Press Any Key To Continue!!"<<endl;
		}
		
		else
		{
			cout<<"Student Name: ";
			puts(curr->name);
			cout<<"Student Discipline: ";
			puts(curr->discipline);
			cout<<"Student Section: ";
			puts(curr->section);
			cout<<"Student Roll_Num: ";
			cout<<curr->roll_num<<endl;
			getch();
		}
	}
}

//Deleting a Record based on the Roll_Num searched.
void deleteRecord()
{
	if(head==NULL)
	{
		cout<<"-->Pressed 4, No Records found.."<<endl;
		cout<<"Press Any Key To Continue!!"<<endl;
		return;
	}
	
	int roll_number;
	cout<<"-->Pressed 4, Enter the Roll_num to delete the Record: ";
	cin>>roll_number;
	
	
	if(head->roll_num==roll_number)
	{
		ListNode *del=head;
		head=head->next;
		delete del;
	}
	
	else
	{
		ListNode *prev, *curr;
		prev=NULL;
		curr=head;
		while(curr->next!=NULL && curr->roll_num!=roll_number)
		{
			prev=curr;
			curr=curr->next;
		}
		
		if(curr->next==NULL)
		{
			cout<<"Record Not Found!!"<<endl;
			cout<<"Press Any Key To Continue!!"<<endl;
		}
		else
		{
			prev->next=curr->next;
			delete curr;
			cout<<"Record Deleted!!"<<endl;
			cout<<"Press Any Key To Continue!!"<<endl;
			getch();
		}
	}
}

//Displaying all the records of the Student Information System
void displayRecords()
{ 
	if(head==NULL)
	{
		cout<<"-->Pressed 5, No Records to Display"<<endl;	
		cout<<"Press Any Key To Continue!!"<<endl;
	}
	
	else
	{
		
		ListNode *curr;
		curr=head;
		cout<<"-->Presses 5, Student Details:"<<endl;
		while(curr!=NULL)
		{	
			cout<<endl;
			cout<<"Student Name:";
			puts(curr->name);
			cout<<"Student Discipline:";
			puts(curr->discipline);
			cout<<"Student Section: ";
			puts(curr->section);
			cout<<"Student Roll_num: ";
			cout<<curr->roll_num<<endl;
			curr=curr->next;
			
		}	
	}	
}

int main()
{
	char num;
	cout<<"***********************************************"<<endl;
	cout<<"********** Studnet Information System *********"<<endl;
	cout<<"***********************************************"<<endl;
	cout<<"Press Any Key To Continue..."<<endl;
	getch();
	do
	{
		cout<<"a.Press '1' to Add a New record"<<endl;
  		cout<<"b.Press '2' to Search a record"<<endl;
  		cout<<"c.Press '3' to Modify a record"<<endl;
  		cout<<"d.Press '4' to Delete a record"<<endl;
  		cout<<"f.Press '5' to Display all the records"<<endl;
  		cout<<"e.Press '6' to Exit:"<<endl;
  		
		num=getch();
  		if(num=='1')
  		{
  			insertRecord();
  			cout<<"------------------------------------------"<<endl;
		}
		
		else if(num=='2')
		{
			searchRecord();
			cout<<"------------------------------------------"<<endl;
		}
		
		else if(num=='3')
		{
			searchModifyRecord();
			cout<<"------------------------------------------"<<endl;
		}
		
		else if(num=='4')
		{
			deleteRecord();
			cout<<"------------------------------------------"<<endl;
		}
		
		else if(num=='5')
		{
			displayRecords();
			cout<<"------------------------------------------"<<endl;
		}
		
		else if(num=='6')
		{
			exit(0);
			cout<<"------------------------------------------"<<endl;
		}
	}while(num!=20);
	getch();
}
