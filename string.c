/*  Assignment 4:
	Write a menu driven program in C to find length ,copy one string to other, reverse a string,check for equality of string,
	print substring of a string and concat two strings
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 2/7/2019
														Last updated on: 10/7/2019
*/

#include<stdio.h>
#include<string.h>

void length();
void copy();
void reverse();
void equal();
void substring();
void concat();

char str1[20]={""};
char str2[20]={""};
char str3[20]={""};

int len=0;

void main()
{		
	printf("Enter a string \n");						// Input a string
	gets(str1);
	
	int choice=1;
	while(choice!=0)
	{
		printf("ENTER YOUR CHOICE \n");
		printf("0. Press 0 to exit \n");
		printf("1. Length of string \n");
		printf("2. Copy string \n");
		printf("3. Reverse string \n");
		printf("4. Equality of string \n");
		printf("5. Substring of string \n");
		printf("6. Concat string \n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: length();  break;
			case 2: copy();	   break;
			case 3: reverse();  break;
			case 4: equal(); break;
			case 5: substring(); break;
			case 6: concat(); break;
		}
	}
}

void length()															// Length
{
	for(int i=0;str1[i]!='\0';i++)						 	
		len++;
	printf("The length of string is %d \n",len);
}

void copy()																// Copy
{
	for(int i=0;str1[i]!='\0';i++)							
		str2[i]=str1[i];
	printf("String on copying str1 to str2 is %s \n",str2);
}

void reverse()															// Reverse
{
	for(int i=0;str1[i]!='\0';i++)							
		str3[i]=str1[len-i-1];
	printf("Reverse of string is %s \n",str3);
}

void equal()															// Equal
{
	int flag=1;
	int len2 = strlen(str3);
	int min = (len>len2)?len2:len;
	for(int i=0;i<min;i++)									
		if(str1[i]!=str3[i])
			flag=0;
	
	if(flag==0)
		printf("Not Equal \n");
	else
		printf("Equal \n");
}

void substring()														// Substring
{	
	int a,b;                                        
	printf("Enter a(lower limit) & b(upper limit)   LIMIT STARTS FROM 0 \n");		
	scanf("%d %d",&a,&b);
	
	printf("Substring is ");
	for(int i=a;i<=b;i++)
		printf("%c",str1[i]);
}

void concat()															// Concat
{	
	for(int i=0;str2[i]!='\0';i++)													
		str1[len++]=str2[i];
	printf(" \n Concatnation of str2 to str1 is %s \n",str1);	
}
