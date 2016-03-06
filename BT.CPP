#include<bits/stdc++.h>
using namespace std ;
class node;
class stackk
{
	node* s[100];
	int top;
public:
	stackk()
	{
		top=-1;
	}
	void push(node* symbol)
	{
		if(top==99)
		{
			cout<<"Stack is full\n";
			return;
		}
		s[++top]=symbol;
	}
	node* pop()
	{
		if(top==-1)
			return NULL;
		else
			return (s[top--]);
	}
	friend class node;
};

class node
{
	node *lft,*rit;
public:
	int nfo;
	friend class stackk;
	node* create(node* r)
	{
		node* tmp=new node,*pre,*cur;
		char d[10];
		int i;
		cout<<"\nEnter the element: ";
		cin>>tmp->nfo;
		tmp->lft=tmp->rit=NULL;
		if(r==NULL)
			return tmp;
		cout<<"Enter direction: ";
		cin>>d;
		pre=NULL;
		cur=r;
		for(i=0;i<strlen(d);i++)
		{
			if(cur==NULL)
				break;
			pre=cur;
			if(d[i]=='L')
				cur=cur->lft;
			else
				cur=cur->rit;
		}
		if(cur!=NULL || i!=strlen(d))
		{
			cout<<"Invalid entry";
			delete(tmp);
			return r;
		}
		if(d[i-1]=='L')
			pre->lft=tmp;
		else
			pre->rit=tmp;
		return r;
	}

	void disp(node* r,int lvl)
	{
		int i;
		if(r==NULL)
			return;
		disp(r->rit,lvl+1);
		for(i=0;i<lvl;i++)
			cout<<"	";
		cout<<r->nfo<<endl;
		disp(r->lft,lvl+1);
	}

	void inord(node* root)
	{
		node* r=root;
		stackk s1;
		for(;;)
		{
			for(;r;r=r->lft)
				s1.push(r);
			r=s1.pop();
			if(!r)
				break;
			cout<<r->nfo<<" ";
			r=r->rit;
		}
	}
	void preord(node* root)
	{
		node* r=root;
		stackk s1;
		for(;;)
		{
			for(;r;r=r->lft)
			{
				cout<<r->nfo<<" ";
				s1.push(r);
			}
			r=s1.pop();
			if(!r)
				break;
			r=r->rit;
		}
	}
	void postord(node* root)
	{
		node* r=root,*r1=root->rit;
		stackk s1;
		while(r1)
		{
			for(;r;r=r->lft)
			{
				if(r->rit)
					s1.push(r->rit);
				s1.push(r);
			}
			r=s1.pop();
			r1=s1.pop();
			if(r->rit && r1==r->rit)
			{
				s1.push(r);
				r=r->rit;
			}
			else
			{
				s1.push(r1);
				cout<<r->nfo<<" ";
				r=NULL;
			}
		}
	}
	node* parent(node* r,int ele)
	{
		node* r1;
		if(r==NULL)
			return NULL;
		else if((r->lft && ele==r->lft->nfo)||(r->rit && ele==r->rit->nfo))
			return r;
		r1=parent(r->lft,ele);
		if(r1)
			return r1;
		else
			return parent(r->rit,ele);
	}
	int depth(node* r)
	{
		if(!r)
			return 0;
		int ld=depth(r->lft);
		int rd=depth(r->rit);
		return (ld>rd)?(ld+1):(rd+1);
	}
	int ancestors(node* r,int key)
	{
		if(r==NULL)
			return 0;
		if(r->nfo==key)
			return 1;
		if(ancestors(r->lft,key) || ancestors(r->rit,key))
		{
			cout<<r->nfo<<"	";
			return 1;
		}
		else
			return 0;
	}
	int leafcnt(node* r)
	{
		if(r==NULL)
			return 0;
		if(r->lft==NULL && r->rit==NULL)
			return 1;
		else
			return leafcnt(r->lft) + leafcnt(r->rit);
	}
	node* recIns(node* root,node* n,node* ele)
	{
		if(root==NULL)
			return ele;
		char d;
		cin>>d;
		if(d=='L')
		{
				if(n->lft==NULL)
				{
					n->lft=ele;
					return root;
				}
				else
					return recIns(root,n->lft,ele);
		}
		else
		{
			if(n->rit==NULL)
			{
				n->rit=ele;
				return root;
			}
			else
				return recIns(root,n->rit,ele);
		}
	}
};



int main()
{
	//clrscr();
	node t,*bt=NULL,*tmp;
	int exit=0,opt,ele;
	while(exit==0)
	{
		//clrscr();
		cout<<"1.Insert\n11.Insert recursively\n2.Display\n3.Inorder traversal\n4.Postorder traversal\n5.Preorder traversal\n6.Find parent\n7.Find depth\n8.Print ancestors\n9.Leaf count\n0.Exit\n";
		cin>>opt;
		switch(opt)
		{
        case 0:
			exit=1;
			break;
		case 1:
			bt=t.create(bt);
			break;
        case 2:
			t.disp(bt,0);
			break;
		case 3:
			t.inord(bt);
			break;
		case 4:
			t.postord(bt);
			break;
		case 5:
			t.preord(bt);
			break;
		case 6:
			cout<<"Enter the element: ";
			cin>>ele;
			tmp=t.parent(bt,ele);
			if(tmp==NULL)
				cout<<"Not found or root";
			else
				cout<<"Parent: "<<tmp->nfo;
			break;
		case 7:
			cout<<"Depth: "<<t.depth(bt);
			break;
		case 8:
			cout<<"Enter the element: ";
			cin>>ele;
			cout<<"Ancestors:\n";
			t.ancestors(bt,ele);
			break;
		case 9:
			cout<<"No. of leaf nodes: "<<t.leafcnt(bt);
			break;
        case 11:
			cout<<"Enter the element: ";
			node* tmp=new node;
			cin>>tmp->nfo;
			bt=t.recIns(bt,bt,tmp);
			break;
		default:
			cout<<"Invalid choice";
		}
		return -1;
		//getch();
	}
}
