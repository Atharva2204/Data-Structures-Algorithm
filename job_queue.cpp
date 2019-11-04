/*  Assignment 11:
					Write a C++ program for simulating job queue. Write functions to add job and delete job from queue
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 2/10/2019
														Last updated on: 2/10/2019
*/

#include<iostream>
//#define MAX 5
using namespace std;

int no;

class job_queue
{
	int front,rear;
	string *jobs;

	public:
			job_queue(int no)
			{
				front=rear=-1;
				jobs = new string[no];
			}
			void add_job();
			void delete_job();
			void display();
			int isEmpty();
			int isFull();
};

void job_queue::add_job()
{
	if(isFull())
		cout<<"Queue Overflow";
	else
	{
		cout<<"Enter Job : ";
		string str;
		cin>>str;
		if(front==-1)
			front=0;
		jobs[++rear]=str;
	}
}

void job_queue::delete_job()
{
	if(isEmpty())
		cout<<"Queue Underflow";
	else
	{
		front++;
		cout<<"Job Deleted";
	}
}

void job_queue::display()
{
	if(front==-1)
		cout<<"Queue is Empty";
	else
	{
		for(int i=front;i<=rear;i++)
			cout<<jobs[i]<<endl;
	}
}

int job_queue::isFull()
{
	if(front==0 && rear==no-1)
		return 1;
	return 0;
}

int job_queue::isEmpty()
{
	if(front==-1 || front>rear)
		return 1;
	return 0;
}

int main()
{
	cout<<"Enter no. of Elements : ";
	cin>>no;

	job_queue obj(no);

	int choice;
	while(1)
	{
		cout<<"1. Add job"<<endl;
		cout<<"2. Delete job"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"Enter choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1: obj.add_job(); break;
			case 2: obj.delete_job(); break;
			case 3: obj.display(); break;
		}
	}
}
