/*  Assignment 12:
					Pizza parlor accepting maximum M orders.Orders are served in first come first served based.Order once placed cannot be cancelled.
					Write C++ program to simulate the system using circular queue using array.
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 2/10/2019
														Last updated on: 2/10/2019
*/

#include<iostream>
#define MAX 5
using namespace std;

class pizza
{
	int front,rear;
	string orders[MAX];

	public:
			pizza()
			{
				front=rear=-1;
			}
			void add_order();
			void delete_order();
			void display();
			int isEmpty();
			int isFull();
};

void pizza::add_order()
{
	if(isFull())
		cout<<"Queue Overflow";
	else
	{
		cout<<"Enter Order : ";
		string str;
		cin>>str;

		if(front==-1)
			front=0;
		else if(rear == MAX-1 && front != 0)
			rear=-1;
		orders[++rear]=str;
	}
}

void pizza::delete_order()
{
	if(isEmpty())
		cout<<"Queue Underflow";
	else
	{
		cout<<"Your Order is : "<<orders[front];
		if(front == rear)
			front = rear = -1;
		else if(front == MAX-1)
			front = 0;
		else
			front++;
	}
}

void pizza::display()
{
	if(front==-1)
		cout<<"Queue is Empty";
	else if(rear >= front)
        for (int i = front;i <= rear; i++)
            cout<<orders[i];
    else
    {
        for (int i = front; i < MAX; i++)
            cout<<orders[i]<<endl;
        for (int i = 0; i <= rear; i++)
            cout<<orders[i]<<endl;
    }
}

int pizza::isFull()
{
	if((front==0 && rear==MAX-1) || (front==rear+1))
		return 1;
	return 0;
}

int pizza::isEmpty()
{
	if(front==-1)
		return 1;
	return 0;
}

int main()
{
	pizza obj;

	int choice;
	while(1)
	{
		cout<<"1. Add Order"<<endl;
		cout<<"2. Delete Order"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"Enter choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1: obj.add_order(); break;
			case 2: obj.delete_order(); break;
			case 3: obj.display(); break;
			default : cout<<"Invalid choice";
		}
	}
}
