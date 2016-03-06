#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int i , j , n  , temp , a[50];
    cout<<"This is selection sort .\nEnter the number of elements you wish to sort : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        int p = i ;
        for(j=i+1;j<n;j++)
        {
            if(a[p]>a[j])
            {
                p = j;
            }
        }
        temp = a[i];
        a[i] = a[p];
        a[p] = temp ;
    }
    cout<<"The sorted array is :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"   ";
    }
    return -1;
}
