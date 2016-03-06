#include<iostream.h>
#include<conio.h>
void radixs(int a[],int a1[],int n)
{
	int k,i,min,t,temp;
	for(k=0;k<3;k++)
	 {
	  for(i=0;i<n;i++)
	   {
	    min=a[i]%10;
		t=i;
		for(int j=1+i;j<n;j++)
		 {
           if(min>(a[j]%10))
		    {
			 min=a[j]%10;
			 t=j;
			}
		 }
         temp=a1[t];
		 a1[t]=a1[i];
		 a1[i]=temp;
		 temp=a[t];
		 a[t]=a[i];
		 a[i]=temp;
		}
	   for(int j=0;j<n;j++)
			a[j]=a[j]%10;
	 }
     cout<<"Sorted array: \n";
	 for(i=0;i<n;i++)
		cout<<a1[i]<<"\n";
}
void main()
{
	clrscr();
	int n1,b[100],c[100];
	cout<<"Enter number of terms: ";
	cin>>n1;
	cout<<"Enter the terms: \n";
	for(int i=0;i<n1;i++)
	 {
	  cin>>b[i];
	  c[i]=b[i];
	 }
	radixs(b,c,n1);
	getch();
}