/*  Assignment 1:
	Write a menu driven program in C to find Average ,Highest Marks ,Lowest Marks ,No. of students getting highest marks ,
	No. of absent students ,Marks of largest frequency
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 18/6/2019
														Last updated on: 28/6/2019
*/

#include<stdio.h>
void average();
void highest();
void lowest();
void highestnumber();
void absentnumber();
void largestfreq();

int n,min,max,count;
double sum;
int num[100];

void main()
{
	printf("Enter total no. of students \n");                     			// Input total no. of students
	scanf("%d",&n);

	printf("Enter marks (Enter a -ve value indicating absent student)\n");
	for(int i=0;i<n;i++)													// Input marks & Calculating sum of +ve elements
	{
		scanf("%d",&num[i]);
		if(num[i]>0)
			sum+=num[i];
	}

	int choice=1;
	while(choice!=0)														// For displaying menu again & again on screen
	{
		printf("\n\n\n======ENTER YOUR CHOICE======\n");                          		// Choice menu
		printf("0.Press 0 to exit\n");
		printf("1.Find average \n");
		printf("2.Find highest marks \n");
		printf("3.Find lowest marks \n");
		printf("4.Find number of students getting highest marks \n");
		printf("5.Find number of absent students \n");
		printf("6.Marks of largest frequency\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 0: break;
			case 1:	average(); break;
			case 2:	highest(); break;
			case 3: lowest();  break;
			case 4:	highestnumber();  break;
			case 5: absentnumber();	break;
			case 6:	largestfreq();	break;
			default: printf("Invalid Choice !!!");
		}
	}
}
void average()																			// Average function
{
	printf("Average marks = %f \n",sum/n);
}

void highest()																			// Highest function
{
					int index;
					for(int i=0;i<n;i++)
					{
						if(max<num[i] && num[i]>0)
						{
							max=num[i];
							index=i;
						}
					}
					printf("The highest marks scored are %d by roll no. %d\n",max,index+1);
}

void lowest()																			// Lowest function
{
					for(int i=0;i<n;i++)
						if(max<num[i] && num[i]>0)
							max=num[i];
					min=max;

					int index;
					for(int i=0;i<n;i++)
					{
						if(min>num[i] && num[i]>0)
						{
							min=num[i];
							index=i;
						}
					}
					printf("The lowest marks scored are %d by roll no. %d\n",min,index+1);
}

void highestnumber()																	// Highest number function
{
					for(int i=0;i<n;i++)
						if(max<num[i] && num[i]>0)
							max=num[i];

					for(int i=0;i<n;i++)
						if(num[i]==max)
							count++;

					printf("No. of students getting highest marks(%d) are : %d \n",max,count);
}

void absentnumber()																		// Absent number function
{
					for(int i=0;i<n;i++)
						if(num[i]<0)
							count++;
					printf("No. of Absent students = %d\n",count);
}

void largestfreq()																		// Largest freq function
{
					int prevcount=0;
					for(int i=0;i<n;i++)
					{
						count=0;
						for(int j=0;j<n;j++)
							if(num[i]==num[j])
								count++;

						if(prevcount<count)
						{
							prevcount=count;
							max=num[i];
						}
					}
					printf("%d,%d",max,prevcount);
}
