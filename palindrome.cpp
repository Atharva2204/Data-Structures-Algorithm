 /*  Assignment 9:
                Write a C++ program to check for palindrome string using stack.
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 2/10/2019
														Last updated on: 2/10/2019
*/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class palindrome
{
	int top;
	char num[100];
	public:
			palindrome()
			{
				top=-1;
			}
			void push(char x);
			char pop();
			int isEmpty();
			int isFull();
};

void palindrome::push(char x)
{
	if(isFull())
		cout<<"Stack Overflow"<<endl;
	else
		num[++top]=x;
}

char palindrome::pop()
{
	char x;
	if(isEmpty())
		cout<<"Empty Stack"<<endl;
	else
		x = num[top--];

	return x;
}

int palindrome::isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int palindrome::isFull()
{
	if(top==9)
		return 1;
	else
		return 0;
}

int main()
{
	palindrome obj;

	char str[100];
	cout<<"Enter a String : ";
	cin>>str;

	strlwr(str);

	cout<<str;

	for(int i=0;i<strlen(str);i++)
		if(isalpha(str[i]))
			obj.push(str[i]);

	int count=0;
	for(int i=0;i<strlen(str);i++)
		if(str[i]==obj.pop())
			count++;

	if(count==strlen(str))
		cout<<"Palindrome";
	else
		cout<<"Not Palindrome";
}
