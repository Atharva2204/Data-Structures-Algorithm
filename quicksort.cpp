#include<iostream>
using namespace std;

int Partition(float *num,int start,int end)
{
    float pivot = num[end];
    int partitionindex = start;     // set partition index as start initially

    for(int i=start;i<end;i++)
        if(num[i]<=pivot)
            swap(num[i],num[partitionindex++]);

    swap(num[partitionindex],num[end]);         //  swap pivot with element at partition index

    return partitionindex;
}

void Quicksort(float *num,int start,int end)
{
    if(start<end)
    {
        int partitionindex = Partition(num,start,end);
        Quicksort(num,start,partitionindex-1);
        Quicksort(num,partitionindex+1,end);
    }
}

int main()
{
    float num[] = {7.6,8.4,4.5,7.3,5.4,5.1,1.4,9.8};
    Quicksort(num,0,7);
    for(int i=0;i<8;i++)
        cout<<num[i]<<" ";
}
