 /*  Assignment 8 (Method 2):
				Write a C++ program for storing binary number using doubly linked list. Write functions
				a) to compute 1's and 2's compliment
				b) add two binary numbers
*/

/*	Developed by ATHARVA KULKARNI(32)               Date: 13/8/2019
													Last updated on: 24/8/2019
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int bit;
	node *next,*back;
};

class binary2
{
	node *head,*tail;
	public:
			binary2()
			{
				head = NULL;
				tail = NULL;
			}
			void create(int);
			void one(binary2);
			void two(binary2);
			void add(binary2,binary2);
			void display();
};

void binary2::create(int last)
{
	node *curr,*prev;
	curr = new node;

	curr->bit=last;
	curr->back=NULL;
	curr->next=NULL;

	if(tail==NULL)
		tail=curr;
	else
	{
		curr->next=prev;
		prev->back=curr;
	}
	prev=curr;
	head=curr;
}

void binary2::one(binary2 llnum)
{
	node *temp,*curr,*prev;
	temp=llnum.head;
	while(temp!=NULL)
	{
		curr = new node;
		curr->next = NULL;
		curr->back = NULL;

		if(temp->bit==1)
			curr->bit=0;
		else
			curr->bit=1;

		if(head==NULL)
			head=curr;
		else
		{
			curr->back=prev;
			prev->next=curr;
		}
		prev=curr;
		temp=temp->next;
	}
}

void binary2::two(binary2 llnum)
{
	node *temp,*curr,*prev;
	temp=llnum.tail;

	int flag=0;
	while(temp!=NULL)
	{
		curr = new node;
		curr->next=NULL;
		curr->back=NULL;

		if(tail==NULL)
			tail=curr;
		else
		{
			curr->next=prev;
			prev->back=curr;
		}
		prev=curr;

		if(flag==0)
		{
			if(temp->bit==1)
			{
					flag=1;
					curr->bit=1;
			}
			else
				curr->bit=0;
		}
		else
		{
			if(temp->bit==1)
				curr->bit=0;
			else
				curr->bit=1;
		}
		temp=temp->back;
	}
	head=curr;
}

void binary2::add(binary2 llnum1,binary2 llnum2)
{
	node *curr,*prev,*temp1,*temp2;

	temp1 = llnum1.tail;
	temp2 = llnum2.tail;

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

void binary2::display()
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
	binary2 llnum1,llnum2,llone,lltwo,lladd;

	int num1;
	cout<<"Enter Binary Number : ";
	cin>>num1;

	while(num1!=0)
	{
		int last = num1%10;
		llnum1.create(last);
		num1 /=10;
	}

	int choice;
		cout<<"\n\n**********************************************\n\n";
		cout<<"\n1. One's Compliment"<<endl;
		cout<<"2. Two's Compliment"<<endl;
		cout<<"3. Add"<<endl;
		cout<<"4. Enter Your Choice"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1: llone.one(llnum1);
					llone.display();
					break;
			case 2: lltwo.two(llnum1);
					lltwo.display();
					break;
			case 3:
					int num2;
					cout<<"Enter binary number : ";
					cin>>num2;

					while(num2!=0)
					{
						int last = num2%10;
						llnum2.create(last);
						num2 /=10;
					}

					lladd.add(llnum1,llnum2);
					lladd.display();
					break;
			case 4: exit(0);
			default: cout<<"Invalid choice !!!"<<endl;
		}
}
