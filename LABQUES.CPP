#include<bits/stdc++.h>
using namespace std ;

class node
{
    struct stackk
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
                cout<<"stackk is full\n";
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
    };
	node* lcl,* rcl;
	public:
	int info;
	node* create(node* r)
	{
		node* tmp=new node,*pre,*cur;
		char d[10];
		int i;
		cout<<"\nEnter the element: ";
		cin>>tmp->info;
		tmp->lcl=tmp->rcl=NULL;
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
				cur=cur->lcl;
			else
				cur=cur->rcl;
		}
		if(cur!=NULL || i!=strlen(d))
		{
			cout<<"Invalid entry";
			delete(tmp);
			return r;
		}
		if(d[i-1]=='L')
			pre->lcl=tmp;
		else
			pre->rcl=tmp;
		return r;
	}
	void disp(node* r,int lvl)
	{
		int i;
		if(r==NULL)
			return;
		disp(r->rcl,lvl+1);
		for(i=0;i<lvl;i++)
			cout<<"	";
		cout<<r->info<<endl;
		disp(r->lcl,lvl+1);
	}

	void inord(node* root)
	{
		node* r=root;
		stackk s1;
		for(;;)
		{
			for(;r;r=r->lcl)
				s1.push(r);
			r=s1.pop();
			if(!r)
				break;
			cout<<r->info<<" ";
			r=r->rcl;
		}
	}
	void preord(node* root)
	{
		node* r=root;
		stackk s1;
		for(;;)
		{
			for(;r;r=r->lcl)
			{
				cout<<r->info<<" ";
				s1.push(r);
			}
			r=s1.pop();
			if(!r)
				break;
			r=r->rcl;
		}
	}
	void postord(node* root)
	{
		node* r=root,*r1=root->rcl;
		stackk s1;
		while(r1)
		{
			for(;r;r=r->lcl)
			{
				if(r->rcl)
					s1.push(r->rcl);
				s1.push(r);
			}
			r=s1.pop();
			r1=s1.pop();
			if(r->rcl && r1==r->rcl)
			{
				s1.push(r);
				r=r->rcl;
			}
			else
			{
				s1.push(r1);
				cout<<r->info<<" ";
				r=NULL;
			}
		}
	}
	node* parent(node* r,int ele)
	{
		node* r1;
		if(r==NULL)
			return NULL;
		else if((r->lcl && ele==r->lcl->info)||(r->rcl && ele==r->rcl->info))
			return r;
		r1=parent(r->lcl,ele);
		if(r1)
			return r1;
		else
			return parent(r->rcl,ele);
	}
	int depth(node* r)
	{
		if(!r)
			return 0;
		int ld=depth(r->lcl);
		int rd=depth(r->rcl);
		return (ld>rd)?(ld+1):(rd+1);
	}
	int ancestors(node* r,int key)
	{
		if(r==NULL)
			return 0;
		if(r->info==key)
			return 1;
		if(ancestors(r->lcl,key) || ancestors(r->rcl,key))
		{
			cout<<r->info<<"	";
			return 1;
		}
		else
			return 0;
	}
	int leafcnt(node* r)
	{
		if(r==NULL)
			return 0;
		if(r->lcl==NULL && r->rcl==NULL)
			return 1;
		else
			return leafcnt(r->lcl) + leafcnt(r->rcl);
	}
};


int main()
{
	//clrscr();
	node t,*root=NULL,*tmp;
	int exit=0,opt,ele;
	while(exit==0)
	{
		//clrscr();
		cout<<"1\tInsert\n2\tDisplay\n3\tInorder traversal\n4\tPostorder traversal\n5\tPreorder traversal\n6\tFind parent\n7\tFind depth\n8\tPrint ancestors\n9\tLeaf count\n0\tExit\n";
		cin>>opt;
		switch(opt)
		{
		case 1:
			root=t.create(root);
			break;
		case 2:
			t.disp(root,0);
			break;
		case 3:
			t.inord(root);
			break;
		case 4:
			t.postord(root);
			break;
		case 5:
			t.preord(root);
			break;
		case 6:
			cout<<"Enter the element: ";
			cin>>ele;
			tmp=t.parent(root,ele);
			if(tmp==NULL)
				cout<<"Not found or root";
			else
				cout<<"Parent: "<<tmp->info;
			break;
		case 7:
			cout<<"Depth: "<<t.depth(root);
			break;
		case 8:
			cout<<"Enter the element: ";
			cin>>ele;
			cout<<"Ancestors:\n";
			t.ancestors(root,ele);
			break;
		case 9:
			cout<<"No. of leaf nodes: "<<t.leafcnt(root);
			break;
		case 0:
			exit=1;
			break;
		default:
			cout<<"Invalid choice";
		}
		//getch();
	}
	return -1 ;
}
