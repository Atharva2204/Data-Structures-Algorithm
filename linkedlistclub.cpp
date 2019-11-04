 /*  Assignment 6:
				Write a C++ program 
*/

/*	Developed by ATHARVA KULKARNI(32)               Date: 25/7/2019
													Last updated on: 13/8/2019
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct node
{
	long int prn;
	char name[30];
	node *next;
};

class linkedlistclub
{
	public:
			node *head,*tail;
			
			linkedlistclub()
			{
				head=NULL;
			}
			void create();
			void display();
			void insert();
			void del();
			int member();
			void reverse(struct node *temp);
			void concat(linkedlistclub obj1,linkedlistclub obj2);
};

void linkedlistclub::create()
{
	node *curr,*prev;
	curr = new node;
	
	cout<<"Enter NAME : ";
	cin.ignore();
	cin.getline(curr->name,30);
	cout<<"Enter PRN : ";
	cin>>curr->prn;
	curr->next=NULL;

	if(head->next==tail)
		prev=head;
	curr->next=tail;

	prev->next=curr;
	prev=curr;
}

void linkedlistclub::insert()
{		
	node *temp,*ins;
	temp=head;
	
	int choice;
	cout<<"Where U want to insert ?"<<endl;
	cout<<"1. At start"<<endl;
	cout<<"2. In middle"<<endl;
	cout<<"3. At last"<<endl;
	cin>>choice;

	ins = new node;
	cout<<"Enter NAME to add : ";
	cin.ignore();
	cin.getline(ins->name,30);
	cout<<"Enter PRN to add : ";
	cin>>ins->prn;
	ins->next=NULL;
	
	switch(choice)
	{
		case 1:
				ins->next=head->next;
				head->next=ins;
				break;
		case 2:
				 int pos;
				 cout<<"At which position u want to add ? : ";
		   	 x:  cin>>pos;

				if(pos>=2 && pos<=(member()-3))
				{
					pos--;
					while(pos--)
						temp=temp->next;
					
					ins->next=temp->next;
					temp->next=ins;
				}
				else
				{
					cout<<"*********ERROR: Incorrect Position Entered***********"<<endl;
					cout<<"Re Enter position : ";
					goto x;
				}
				break;
		case 3:
				if(head->next==tail)
				{
					ins->next=tail;
					head->next=ins;
				}
				else
				{
					while(temp->next!=tail)
						temp=temp->next;
					ins->next=tail;
					temp->next=ins;
				}
				break;
	}
}

void linkedlistclub::del()
{	
	node *temp,*t;
	temp=head;
	
	int del;
	cout<<"Enter PRN to delete";
	cin>>del;

	if(del==head->prn)
	{
		cout<<"\n****President Deleted****\n"<<endl;
		cout<<"Enter NAME of new President : ";
		cin.ignore();
		cin.getline(head->name,30);
		cout<<"Enter PRN of new President : ";
		cin>>head->prn;
	}
	else if(del==tail->prn)
	{
		cout<<"\n****Secretary Deleted****\n"<<endl;
		cout<<"Enter NAME of new Secretary : ";
		cin.ignore();
		cin.getline(tail->name,30);
		cout<<"Enter PRN of new Secretary : ";
		cin>>tail->prn;
	}
	else
	{
		cout<<"\n****Member Deleted****\n"<<endl;
		while(del!=temp->next->prn)
			temp=temp->next;
		t=temp->next;
		temp->next=temp->next->next;
		delete(t);
	}
}

void linkedlistclub::display()
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->name<<" : "<<temp->prn<<"\n";
		temp=temp->next;
	}
}

int linkedlistclub::member()
{
	node *temp;
	temp=head;
	
	int ctr=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		ctr++;
	}
	return ctr;
}

void linkedlistclub::reverse(struct node *temp)
{
	if(temp->next!=NULL)
		reverse(temp->next);
	
	cout<<temp->name<<"  "<<temp->prn;
}

void linkedlistclub::concat(linkedlistclub obj1, linkedlistclub obj2)
{
	node *temp , *curr , *prev , *x;
	temp=obj1.head;

	while(temp!=NULL)
	{
		curr = new node;
		curr->next=NULL;
		
		if(head==NULL)
			head=curr;
		else
			prev->next=curr;
		prev=curr;
		
		strcpy(curr->name,temp->name);
		curr->prn=temp->prn;
		
		if(temp==obj1.head)
			head=curr;
		
		temp=temp->next;
		x=curr;
	}
	temp = obj2.head;
	
	while(temp!=NULL)
	{
		curr = new node;
		curr->next=NULL;

		if(temp==obj2.head)
			x->next=curr;
		prev->next=curr;
		prev=curr;

		strcpy(curr->name,temp->name);
		curr->prn=temp->prn;
		if(temp==obj2.tail)
			tail=curr;
		
		temp=temp->next;
	}
	display();
}

int main()
{
	linkedlistclub obj1,obj2,obj3;
	
	obj1.head = new node;
	obj1.tail = new node;
	obj2.head = new node;
	obj2.tail = new node;
	
	obj2.head->next=obj2.tail;
	
	cout<<"Enter NAME of President : ";
	cin.getline(obj1.head->name,30);
	cout<<"Enter PRN of President : ";
	cin>>obj1.head->prn;
	obj1.head->next=obj1.tail;
	
	cout<<"Enter NAME of Secretary : ";
	cin.ignore();
	cin.getline(obj1.tail->name,30);
	cout<<"Enter PRN of Secretary : ";
	cin>>obj1.tail->prn;
	obj1.tail->next=NULL;
	
	int choice;
	while(1)
	{
		cout<<"\n\n***************************************************************************\n\n";
		cout<<"MENU ::"<<endl;
		cout<<"1. Add member"<<endl;
		cout<<"2. Insert at a particular position"<<endl;
		cout<<"3. Delete member"<<endl;
		cout<<"4. Display Members"<<endl;
		cout<<"5. Total Members"<<endl;
		cout<<"6. Display in Reverse"<<endl;
		cout<<"7. Concat 2 lists of div A & B"<<endl;
		cout<<"8. Exit"<<endl;
		cout<<"Enter your Choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: 
					int n;
					cout<<"How many members u want to add ? : ";
					cin>>n;
					for(int i=0;i<n;i++)
						obj1.create();
					break;
			case 2: obj1.insert();  break;
			case 3: obj1.del(); break;
			case 4: obj1.display(); break;
			case 5: cout<<"Total members are : "<<obj1.member();  break;
			case 6: obj1.reverse(obj1.head);  break;
			case 7: 
					cout<<"Enter details of Division B \n"<<endl;

					cout<<"Enter NAME of President : ";
					cin.ignore();
					cin.getline(obj2.head->name,30);
					cout<<"Enter PRN of President : ";
					cin>>obj2.head->prn;

					cout<<"Enter NAME of Secretary : ";
					cin.ignore();
					cin.getline(obj2.tail->name,30);
					cout<<"Enter PRN of Secretary : ";
					cin>>obj2.tail->prn;
					obj2.tail->next=NULL;
	
					cout<<"How many members u want to add ? : ";
					cin>>n;
					for(int i=0;i<n;i++)
						obj2.create();

					obj3.concat(obj1,obj2);
					
					break;
			case 8: exit(0);
		}
	}
	return 0;
}