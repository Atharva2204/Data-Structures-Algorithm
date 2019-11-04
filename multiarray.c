/*  Assignment 2:
	Write a menu driven program in C to input a two dimensional array from user & find whether it is upper triangular
	or not,find its transpose, addition subtraction & multiplication of 2 matrix and addition of diagonal elements
*/

/*	Developed by ATHARVA KULKARNI(32)                   Date: 26/6/2019
														Last updated on: 27/6/2019
*/

#include<stdio.h>
void uppertria();
void adddiagonal();
void addmat();
void submat();
void mulmat();
void transpose();

int rows,sum;
int mat1[10][10];
int mat2[10][10];
int count1=0,count2=0;

void main()
{
	printf("Enter no. of rows or columns(square matrix)\n");               // Input no. of rows or columns
	scanf("%d",&rows);

	printf("Enter matrix \n");
	for(int i=0;i<rows;i++)
	{
 		for(int j=0;j<rows;j++)
		{
				printf("Enter the element (%d,%d)\n",i,j);
				scanf("%d",&mat1[i][j]);                                    // Input matrix,


				if(i==j)
						sum+=mat1[i][j];                                    // diagonal elements sum,
		}
	}

	int choice=1;
	while(choice!=0)                                                         // For displaying menu again & again on screen
	{
		printf("\n\n====ENTER YOUR CHOICE=======\n");                         // Choice menu
		printf("0.Press 0 to exit \n");
		printf("1.To display whether UPPER TRIANGULAR or not \n");
		printf("2.To display ADDITION of DIAGONAL elements\n");
		printf("3.To display ADDITION of two matrix \n");
		printf("4.To display SUBTRACTION of two matrix \n");
		printf("5.To display MULTIPLICATION of two matrix \n");
		printf("6.To find TRANSPOSE of a matrix \n");
		scanf("%d",&choice);

		if(choice==3 || choice==4 || choice==5)                           // Input matrix 2 for particular choices
		{
			printf("Enter matrix 2 \n");
			for(int i=0;i<rows;i++)
				for(int j=0;j<rows;j++)
					scanf("%d",&mat2[i][j]);
		}
		switch(choice)
		{
			case 0: break;
			case 1:	uppertria();  break;
			case 2: adddiagonal(); break;
			case 3: addmat();     break;
			case 4: submat();     break;
			case 5: mulmat();	  break;
			case 6: transpose();  break;
			default : printf("Invalid Input \n");
		}
	}
}

void uppertria()                                               			 // Upper triangular function
{
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<rows;j++)
            {
                if(i>j)
				{
					count1++;         // For counting i>j elements             // & Upper Triangular in one loop
					if(mat1[i][j]==0)
						count2++;     // Counting no. of 0's in i>j elements
				}
            }
        }
			if(count1==count2)
				printf("Upper Triangular \n");
			else
				printf("Not Upper Triangular \n");


        /*  2nd LOGIC

       int flag=1;

        for(int i=0;i<rows;i++)
            for(int j=0;j<rows;j++)
                if(i>j && mat1[i][j]!=0)     // If elements below the main diagonal (col<row)is not equal to zero then it is not upper triangular matrix
                    flag=0;

        if(flag==1)
               printf("Upper Triangular \n");
        else
				printf("Not Upper Triangular \n");  */
}

void adddiagonal()                                         		// Addition of diagonal elements function
{
			printf("Addition of diagonal elements is %d \n",sum);
}

void addmat()                                                   	// Addition of 2 matrix function
{
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<rows;j++)
					printf("%d ",mat1[i][j]+mat2[i][j]);
				printf("\n");
			}
}

void submat()                                                   	// Subtraction of 2 matrix function
{
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<rows;j++)
					printf("%d",mat1[i][j]-mat2[i][j]);
				printf("\n");
			}
}

void mulmat()                                                     	// Multiplication of 2 matrix function
{
			int sum=0;
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<rows;j++)
				{
					for(int k=0;k<rows;k++)
							sum+=mat1[i][k]*mat2[k][j];
					printf("%d  ",sum);
					sum=0;
				}
				printf("\n");
			}

			/*  2nd LOGIC

			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<rows;j++)
				{
                    res[i][j] = 0;
                    for (int k = 0; k < rows; k++)
                        res[i][j] += mat1[i][k] * mat2[k][j];
				}
			} */
}

void transpose()                                                  	 // Transpose function
{
		printf("The TRANSPOSE of matrix \n");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<rows;j++)
				printf("%d  ",mat1[i][j]);
			printf("\n");
		}
		printf("is: \n");
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<rows;j++)
				printf("%d ",mat1[j][i]);
			printf("\n");
		}
}
