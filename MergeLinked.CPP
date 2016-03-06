#include<iostream.h>
#include<conio.h>
class node
{
	int data;
	node *next;
	public:
	node *head, *tail ;
	node()
	{
		head = NULL;

	     tail = NULL;

	    }

	    node* insert(int);

	    node* merge();

	    void disp(node *);

	  };node *head1, *head2;

node *node::insert(int a)

{head=NULL;

tail=NULL;

for(int i=0 ; i<a ; i++)

 {node *temp = new node;

  temp->next = NULL;

  cout<<"enter value"<<endl;

  cin>>temp->data;

  if(head!=NULL && tail!=NULL)

  {tail->next=temp;

   tail=temp;

  }

  else

    tail=head=temp;

 }

 return head;

}

void node::disp(node *t)

{if(t==NULL)

   cout<<"empty!"<<endl;

 while(t!=NULL)

 {cout<<t->data<<"\t";

  t=t->next;

 }

 cout<<endl;

}

node* node::merge()

{ node *list = new node;

  node *h = new node;

 if(head1==NULL && head2==NULL)

   return NULL;

 if(head1==NULL)

   return head2;

 if(head2==NULL)

   return head1;

 if(head1->data > head2->data)

 {list=h=head2;

  head2=head2->next;

 }

 else

 {list=h=head1;

  head1=head1->next;

 }

 while(head1!=NULL && head2!=NULL)

 {if(head1->data > head2->data)

  {list->next=head2;

   list=head2;

   head2=head2->next;

  }

  else

  {list->next=head1;

   list=head1;

   head1=head1->next;

  }

 }

 if(head1==NULL)

  list->next=head2;

 else

  list->next=head1;

 return h;

}

void main()

{node obj;

node *t = new node;

 int n,m;

 clrscr();

 cout<<"no. of elements in 1st : ";cin>>n;

 cout<<"no. of elements in 2nd : ";cin>>m;

 head1=obj.insert(n);

 head2=obj.insert(m);

t = obj.merge();

 obj.disp(t);

 getch();

}
