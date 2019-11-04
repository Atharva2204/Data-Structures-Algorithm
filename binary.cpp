 /*  Assignment 8 (Method 1):
				Write a C++ program for storing binary number using doubly linked list. Write functions
				a) to compute 1's and 2's compliment
				b) add two binary numbers
*/

/*	Developed by ATHARVA KULKARNI(32)               Date: 13/8/2019
													Last updated on: 20/8/2019
*/


#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int bit;
	node *next;
	node *back;
};

class binary
{
	node *head,*tail;
	public:
			binary()
			{
				head = NULL;
				tail = NULL;
			}
			void create();
			void one();
			void two();
			void add(binary obj1,binary obj2);
			void display();
};

void binary::create()
{
	node *curr,*prev;
	curr = new node;

	cout<<"Enter bit : ";
	cin>>curr->bit;
	curr->back=NULL;
	curr->next=NULL;

	if(head==NULL)
		head=curr;
	else
	{
		curr->back=prev;
		prev->next=curr;
	}
	prev=curr;
	tail=curr;
}

void binary::one()
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->bit==1)
			cout<<"0";
		else
			cout<<"1";
		temp=temp->next;
	}
}

void binary::two()
{
	node *temp;
	temp=tail;

	/*while(temp->bit!=1)					// using 2 loops
		temp=temp->back;

	temp=temp->back;
	while(temp!=NULL)
	{
		if(temp->bit==1)
			temp->bit=0;
		else
			temp->bit=1;
		temp=temp->back;
	}*/

	int flag=0;
	while(temp->back!=NULL)                 // using 1 loop
	{
		if(temp->bit==1)
			flag=1;

		temp = temp->back;
		if(flag==1)
		{
			if(temp->bit==1)
				temp->bit=0;
			else
				temp->bit=1;
		}
	}
}

void binary::add(binary obj1,binary obj2)
{
	node *curr,*prev,*temp1,*temp2;

	temp1 = obj1.tail;
	temp2 = obj2.tail;

	int sum=0,carry=0;
	while(temp1!=NULL || temp2!=NULL)
	{
		curr = new node;
		curr->next = NULL;
		curr->back = NULL;

		sum = carry + (temp1?temp1->bit:0) + (temp2?temp2->bit:0);
		carry = sum/2;
		sum %= 2;

		curr->bit = sum;

		if(tail==NULL)
			tail = curr;
		else
		{
			prev->back = curr;
			curr->next = prev;
		}
		prev=curr;
		head=curr;

		temp1 = temp1->back;
		temp2 = temp2->back;
	}
	if(carry>0)
	{
		curr = new node;
		curr->next=head;
		head->back=curr;
		curr->bit=carry;
		head=curr;
	}
}

void binary::display()
{
	node *temp;
	temp=head;

	while(temp!=NULL)
	{
		cout<<temp->bit;
		temp=temp->next;
	}
}

int main()
{
	binary obj1,obj2,obj3;

	//char ch = 'y';
	int i=0;
	while(i++ < 5)
	{
		obj1.create();
		//cout<<"Add more ? : ";
		//cin>>ch;
	}

	cout<<"Your binary number is : ";
	obj1.display();

	int choice = 1;
	while(1)
	{
		cout<<"\n\n**********************************************\n\n";
		cout<<"\n1. One's Compliment"<<endl;
		cout<<"2. Two's Compliment"<<endl;
		cout<<"3. Add"<<endl;
		cout<<"4. Enter Your Choice"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1: obj1.one(); break;
			case 2: obj1.two();
					obj1.display();
					break;
			case 3:
					i=0;
					while(i++ < 5)
						obj2.create();

					obj3.add(obj1,obj2);
					obj3.display();
					break;
			case 4: exit(0);
			default: cout<<"Invalid choice !!!"<<endl;
		}
	}
}
