#include<iostream>
using namespace std;
#define MAX 60
#define MIN 10

struct node
{
	char name[20];
	int starthour;
	int startmin;
	int endhour;
	int endmin;
	
	node *next;
};

class appointment
{
	node *head;
	public:
			appointment()
			{
				head=NULL;
			}
			void create();
			void freeslot();
			void appoint();
			void cancelappoint();
			void sorttime();
			void display();
};

void appointment::create()
{
	node *curr,*prev;
	curr = new node;
	curr->next=NULL;
	
	cout<<"Enter Name : ";
	cin>>curr->name;
	cout<<"Enter Starthour : ";
	cin>>curr->starthour;
	cout<<"Enter Startmin : ";
	cin>>curr->startmin;
	cout<<"Enter Endhour : ";
	cin>>curr->endhour;
	cout<<"Enter Endmin : ";
	cin>>curr->endmin;
	
	if(head==NULL)
		head=curr;
	else
		prev->next=curr;
	prev=curr;
}

void appointment::display()
{
	node *temp;
	temp=head;
	
	while(temp!=NULL)
	{
		cout<<temp->name<<"  "<<temp->starthour<<":"<<temp->startmin<<" -- "<<temp->endhour<<":"<<temp->endmin<<endl;
		temp=temp->next;
	}
}

void appointment::freeslot()
{
	node *temp;
	temp=head;

	while(temp->next->next!=NULL)
	{
		if(temp->endmin+1 != temp->next->startmin)
		{
			cout<<"Free Slot : "<<temp->endhour<<":"<<temp->endmin<<"--"<<temp->next->starthour<<":"<<temp->next->startmin<<endl;
		}
	}
}

int main()
{
	appointment obj;
	
	for(int i=0;i<3;i++)
		obj.create();
	obj.freeslot();
	obj.display();
}