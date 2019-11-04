 /*  Assignment 5:
	Write a C++ program for sparse matrix realization and operations on it - transpose,fast transpose and
	addition of two matrices
*/

/*	Developed by ATHARVA KULKARNI(32)               Date: 13/7/2019
													Last updated on: 23/7/2019
*/

#include<iostream>
using namespace std;

class sparsematrix
{
	public:	int r1,r2;
			int mat1[100][3];
			int mat2[100][3];
			int add[200][3];
			int trans[100][3];
			int fasttrans[100][3];
			void inputmatrix();
			void transpose();
			void fasttranspose();
			void addition();
};

void sparsematrix::inputmatrix()										// Input matrix 1 function
{
	cout<<"Enter rows of matrix 1 = ";
	cin>>r1;

	cout<<"Enter matrix 1 \n";
	for(int i=0;i<r1;i++)
		for(int j=0;j<3;j++)
			cin>>mat1[i][j];
}

void sparsematrix::transpose()											// Transpose function
{
	int min,max=0,a=1,index;

	for(int i=0;i<r1;i++)
		for(int j=0;j<3;j++)
			if(max<mat1[i][j])
				max=mat1[i][j];
	min=max;

	trans[0][0]=mat1[0][1];
	trans[0][1]=mat1[0][0];
	trans[0][2]=mat1[0][2];

	for(int i=0;i<r1;i++)
	{
		for(int j=1;j<r1;j++)
		{
			if(min>mat1[j][1])
			{
				min=mat1[j][1];
				index=j;
			}
		}

		trans[a][0]=mat1[index][1];
		trans[a][1]=mat1[index][0];
		trans[a][2]=mat1[index][2];
		a++;
		mat1[index][1]=max;			// Making min element as max so that it does not come in the next iteration
		min=max;
	}

	cout<<"\n ----------TRANSPOSE IS--------------\n";
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<3;j++)
			cout<<trans[i][j];
		cout<<"\n";
	}
}

void sparsematrix::fasttranspose()										// Fast Transpose function
{
	int max=0;
	for(int i=1;i<r1;i++)
		if(max<mat1[i][1])
			max=mat1[i][1];

	int freq[max+1];
	int rsp[max+1];
	int pos=0,x=1,ctr=0;

	rsp[0]=1;
	for(int i=1;i<r1;i++)
	{
		for(int j=1;j<r1;j++)			// Calculating freq of each
			if(mat1[j][1]==pos)
				ctr++;
		freq[pos]=ctr;
		ctr=0;

		rsp[i]=freq[i-1]+rsp[i-1];
		pos++;
	}
	for(int i=1;i<r1;i++)
	{
		int loc=rsp[mat1[i][1]];
		fasttrans[loc][0]=mat1[i][1];
		fasttrans[loc][1]=mat1[i][0];
		fasttrans[loc][2]=mat1[i][2];
		rsp[mat1[i][1]]++;				// For row to increase ; if same column value comes then problem so
	}
	fasttrans[0][0]=mat1[0][1];
	fasttrans[0][1]=mat1[0][0];
	fasttrans[0][2]=mat1[0][2];

	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<3;j++)
			cout<<fasttrans[i][j];
		cout<<"\n";
	}
}

void sparsematrix::addition()												// Addition function
{
		cout<<"Enter rows of matrix 2 = ";
		cin>>r2;

		cout<<"Enter matrix 2 \n";
		for(int i=0;i<r2;i++)
			for(int j=0;j<3;j++)
				cin>>mat2[i][j];

		int i=1,k=1,a=0;
		while(i<r1 && k<r2)
		{
			if(mat1[i][0]==mat2[k][0] && mat1[i][1]==mat2[k][1])
			{
				add[a][0]=mat1[i][0];
				add[a][1]=mat1[i][1];
				add[a][2]=mat1[i][2]+mat2[k][2];
			}
			else if((mat1[i][0]==mat2[k][0] && mat1[i][1]>mat2[k][1]) || mat1[i][0]>mat2[k][0])
			{
				add[a][0]=mat2[k][0];
				add[a][1]=mat2[k][1];
				add[a][2]=mat2[k][2];
				i--;
			}
			else if((mat1[i][0]==mat2[k][0] && mat1[i][1]<mat2[k][1]) || mat1[i][0]<mat2[k][0])
			{
				add[a][0]=mat1[i][0];
				add[a][1]=mat1[i][1];
				add[a][2]=mat1[i][2];
				k--;
			}
			i++;
			k++;
			a++;
		}
		while(k<r2)
		{
			add[a][0]=mat2[k][0];
			add[a][1]=mat2[k][1];
			add[a][2]=mat2[k][2];
			k++;
			a++;
		}
		while(i<r1)
		{
			add[a][0]=mat1[i][0];
			add[a][1]=mat1[i][1];
			add[a][2]=mat1[i][2];
			i++;
			a++;
		}

		cout<<"\n ----------SUM IS--------------\n";
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<3;j++)
			cout<<add[i][j];
			cout<<"\n";
		}
}

int main()
{
	sparsematrix obj;

	obj.inputmatrix();

	int choice=1;
	while(choice!=0)
	{
		cout<<"\n----------MENU------------\n";
		cout<<"0. EXIT \n";
		cout<<"1. TRANSPOSE \n";
		cout<<"2. FAST TRANSPOSE \n";
		cout<<"3. ADDITION \n";
		cout<<"Enter ur choice \n";
		cin>>choice;

		switch(choice)
		{
			case 0:break;
			case 1:obj.transpose();  break;
			case 2:obj.fasttranspose();  break;
			case 3:obj.addition();  break;
			default:cout<<"Invalid Choice \n";
		}
	}
}
