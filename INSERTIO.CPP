#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int a[50] , ele , i , j , n ;
    cout<<"This is Insertion Sort .\nEnter the number of elements you wish to sort : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>a[i];
    }
    for(i=1;i<n;i++)
    {
        j=i;
        ele=a[j];
        while((j>0)&&(a[j-1])>ele)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=ele;
    }

    cout<<"The sorted array is :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"   ";
    }
    return -1 ;
}
