#include<iostream.h>
#include<math.h>
#include<conio.h>

//using namespace std;
class node
{
public:

    int data;
    node *next;
    //public:
        node(int ele=0)
        {
            data=ele;
            next=NULL;
        }

};

int a[50];
int getdigit(int ele,int j);		//getting the jth digit
node *insertrear(node *first,int ele);

int find_big(int a[],int n)
{
    int big=a[0];
    for(int i=1;i<n;i++)
        if(big<a[i])
            big=a[i];
    return big;
}
void radix_sort(int a[],int n)
{
    int i,j,k,m,big,digit;

    big=find_big(a,n);
    cout<<"\n Big: "<<big;

    m=log10(big)+1;
    cout<<"\n No of digits: "<<m;

    node *p[10],*temp;

    for(j=1;j<=m;j++)
    {
	for(i=0;i<=9;i++) p[i]=NULL;

	for(i=0;i<n;i++)
	{
	    digit=getdigit(a[i],j);
	    p[digit]=insertrear(p[digit],a[i]);
	}

	k=0;
	for(i=0;i<=9;i++)
	{
	    temp=p[i];
	    while(temp!=NULL)
	    {
		a[k++]=temp->data;
		temp=temp->next;
	    }
	}

    }
}

int getdigit(int ele,int j)
{
    int temp=(ele/(int)pow(10,j-1))%10;
    //(ele/((int)pow(10,j-1))%10));
    return temp;
}

node *insertrear(node *first,int ele)
{
    node *temp=new node(ele);
    if(first==NULL) return temp;

    node *cur=first;

    while(cur->next!=NULL)
        cur=cur->next;

    cur->next=temp;
    return first;
}

int main()
{   clrscr();
    int n,i;

    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"\nEnter the elements ";
    for(i=0;i<n;i++)
	cin>>a[i];

    radix_sort(a,n);

    cout<<"\nSorted array is: \n";
    for(i=0;i<n;i++)
	cout<<a[i]<<"  ";
getch();
    return 1;
}
