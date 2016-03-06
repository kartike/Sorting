#include<bits/stdc++.h>
using namespace std ;

int partition(int a[],int low,int high);

void quicksort(int a[],int low,int high)
{
	int j;
	if(low>=high)
        return;
    else
    {
        j=partition(a,low,high);
        quicksort(a,low,j);
        quicksort(a,j+1,high);
    }
}
int partition(int a[],int low,int high)
{
        int i,j,temp,key;
        i=low;
		j=high;
		key=a[low];
        while(1)
        {
         while(key<a[j])
          j--;
         while(i<high &&key>=a[i])
          i++;
		  if(i<j)
			{
			 temp=a[i];
			 a[i]=a[j];
			 a[j]=temp;
			}
           else
           {
             temp=a[low];
             a[low]=a[j];
             a[j]=temp;
             return j;
           }
          }
}

int main()
{
	//clrscr();
	int a[100];
	cout<<"Enter number of terms: ";
	int n1;
	cin>>n1;
    cout<<"enter terms\n";
	for(int i=0;i<n1;i++)
        cin>>a[i];
	quicksort(a,0,n1-1);
    cout<<"sorted array"<<endl;
    for(int k=0;k<n1;k++)
        cout<<a[k]<<"\t";
	//getch();
	return -1;
}
