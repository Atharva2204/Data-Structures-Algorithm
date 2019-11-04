 /*  Assignment 3:
	Write a menu driven program in C to evaluate the polynomial at a given value , add of two polynomials and multiply
	two polynomials
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 9/7/2019
														Last updated on: 14/7/2019
*/

#include<stdio.h>
#include<math.h>

struct poly
{
  int coeff,exp;
};

void evaluate();
void add();
void multiply();

int n1,n2;
struct poly p1[100];
struct poly p2[100];

void main()
{
	printf("ENTER THE NO. OF TERMS IN THE FIRST POLYNOMIAL \n");					// Input no. of terms in 1st poly
	scanf("%d",&n1);

	for(int i=0;i<n1;i++)															// Input poly 1
	{
		printf("ENTER THE COEFFICIENT OF TERM %d IN POLYNOMIAL 1 \n",i+1);
		scanf("%d",&p1[i].coeff);

		printf("ENTER THE POWER OF 'x' IN TERM %d OF POLYNOMIAL 1 \n",i+1);
		scanf("%d",&p1[i].exp);
	}

	printf("The polynomial u entered is :");
	for(int i=0;i<n1-1;i++)
		printf("%dx^%d + ",p1[i].coeff,p1[i].exp);
	printf("%dx^%d \n",p1[n1-1].coeff,p1[n1-1].exp);

	int choice=1;
	while(choice!=0)
	{
		printf("\n0.Press 0 to EXIT \n");
		printf("1.EVALUATE THE VALUE OF POLYNOMIAL \n");
		printf("2.ADD TWO POLYNOMIALS \n");
		printf("3.MULTIPLY TWO POLYNOMIALS \n");
		printf("ENTER YOUR CHOICE \n");
		scanf("%d",&choice);

		if(choice==2 || choice==3)
		{
			printf("ENTER THE NO. OF TERMS IN SECOND POLYNOMIAL \n");				// Input no. of terms in 2nd poly
			scanf("%d",&n2);

			for(int i=0;i<n2;i++)													// Input poly 2
			{
				printf("ENTER THE COEFFICIENT OF TERM %d IN POLYNOMIAL 2 \n",i+1);
				scanf("%d",&p2[i].coeff);

				printf("ENTER THE POWER OF 'x' IN TERM %d OF POLYNOMIAL 2 \n",i+1);
				scanf("%d",&p2[i].exp);
			}

			printf("The polynomial u entered is :");
			for(int i=0;i<n2-1;i++)
				printf("%dx^%d + ",p2[i].coeff,p2[i].exp);
			printf("%dx^%d \n",p2[n2-1].coeff,p2[n2-1].exp);
		}

		switch(choice)
		{
			case 0:  break;
			case 1:  evaluate(); break;
			case 2:  add(); break;
			case 3:  multiply(); break;
			default: printf("Invalid Choice");
		}
	}
}

void evaluate()																		// EVALUATE function
{
      float x=0,value=0;
      printf("ENTER THE VALUE OF X TO EVALUATE THE POLYNOMIAL\n");
      scanf("%f",&x);

      for(int i=0;i<n1;i++)
         value+=p1[i].coeff*(pow(x,p1[i].exp));
      printf("THE VALUE OF THE POLYNOMIAL IS %f \n",value);
}

void add()																			// ADDITION function
{
	  struct poly add[n1+n2];

	  int i=0,j=0,k=0;
	  while(i<n1 && j<n2)
	  {
			if(p1[i].exp==p2[j].exp)
			{
				add[k].coeff=p1[i].coeff+p2[j].coeff;
				add[k].exp=p1[i].exp;
				i++;
				j++;
				k++;
			}
			else if(p1[i].exp>p2[j].exp)
			{
				add[k].coeff=p1[i].coeff;
				add[k].exp=p1[i].exp;
				i++;
				k++;
			}
			else
			{
				add[k].coeff=p2[j].coeff;
				add[k].exp=p2[j].exp;
				j++;
				k++;
			}
	   }

	   while(i<n1)
	   {
		   add[k].coeff=p1[i].coeff;
		   add[k].exp=p1[i].exp;
		   k++;
		   i++;
	   }
	   while(j<n2)
	   {
		   add[k].coeff=p2[j].coeff;
		   add[k].exp=p2[j].exp;
		   k++;
		   j++;
	   }

		for(int i=0;i<k-1;i++)
			printf("%dx^%d + ",add[i].coeff,add[i].exp);
		printf("%dx^%d \n",add[k-1].coeff,add[k-1].exp);
}

void multiply()																 		 // MULTIPLY function
{
	struct poly mult[n1*n2];
	struct poly finalmult[n1*n2];

	int n=0;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			mult[n].coeff = p1[i].coeff*p2[j].coeff;
			mult[n].exp = p1[i].exp+p2[j].exp;
			n++;
		}
	}

	for(int i=0;i<n1*n2-1;i++)
	{
		for(int j=0;j<n1*n2-1;j++)
		{
			if(mult[j].exp<mult[j+1].exp)
			{
				int temp1=mult[j].coeff;
				mult[j].coeff=mult[j+1].coeff;
				mult[j+1].coeff=temp1;

				int temp2=mult[j].exp;
				mult[j].exp=mult[j+1].exp;
				mult[j+1].exp=temp2;
			}
		}
	}

	int ctr=0,a=0,sum=0;
	for(int i=0;i<n1*n2;i++)
	{
		for(int j=0;j<n1*n2;j++)
		{
			if(mult[i].exp==mult[j+1].exp)
			{
				sum+=mult[i].coeff+mult[j+1].coeff;

				ctr++;
			}
		}
		finalmult[a].coeff=sum;
		a++;
	}

	for(int i=0;i<n1*n2-ctr;i++)
	{
		printf("%dx^%d",mult[i].coeff,mult[i].exp);
		if(i!=(n1*n2-ctr-1))
			printf(" + ");
	}
}
