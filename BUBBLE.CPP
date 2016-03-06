#include<bits/stdc++.h>

using namespace std ;
int main()
    {
    //clrscr();
    cout<<"This is bubble sort \n";
    int n,a[10],temp;
    cout<<"Enter the number of elements you wish to sort : ";
    cin>>n;
    int i ;
    for(i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<":  ";
        cin>>a[i];
    }

    for (i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if( a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"The sorted elements are :  "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\n";
    }
    return -1 ;
    //getch();
}
