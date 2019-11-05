#include<iostream>
using namespace std;

int main()
{
    int num[] = {2,4,2,88,34,92,23,12};
    int n=8;

    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp = num[i];
            int j;
            for(j=i ; j>=gap && num[j-gap]>temp ; j-=gap)
                num[j] = num[j-gap];

            num[j]=temp;
        }
    }
    for(int i=0;i<n;i++)
        cout<<num[i]<<endl;
}
