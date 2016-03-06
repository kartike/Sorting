#include<iostream.h>
#include<conio.h>

class node
{
	node* lft,* rit;
public:
	int nfo;
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
	node* insbst(node* r)
	{
		node* tmp=new node,* pre,* cur;
		cout<<"Enter the element: ";
		cin>>tmp->nfo;
		tmp->rit=tmp->lft=NULL;
		if(r==NULL)
			return tmp;
		pre=NULL;
		cur=r;
		while(cur!=NULL)
		{
			pre=cur;
			if(tmp->nfo==cur->nfo)
			{
				cout<<"\nNo duplicates allowed";
				delete(tmp);
				return r;
			}
			if(tmp->nfo<cur->nfo)
				cur=cur->lft;
			else
				cur=cur->rit;
		}
		if(tmp->nfo<pre->nfo)
			pre->lft=tmp;
		else
			pre->rit=tmp;
		return r;
	}
	node* delbst(node* r,int ele)
	{
		node *par,* cur,* suc;
		if(r==NULL)
			return NULL;
		if(r->nfo==ele)
			return NULL;
		par=cur=NULL;
		node* q=r;
		while(q!=NULL)
		{
			if(q->nfo==ele)
			{
				cur=q;
				break;
			}
			par=q;
			if(q->nfo>ele)
				q=q->lft;
			else
				q=q->rit;
		}
		if(cur->lft!=NULL && cur->rit!=NULL)
		{
			par=cur;
			suc=cur->rit;
			while(suc->lft!=NULL)
			{
				par=suc;
				suc=suc->lft;
			}
			cur->nfo=suc->nfo;
			cur=suc;
		}
		if(cur->lft==NULL && cur->rit==NULL)
		{
			if(par->lft==cur)
				par->rit=NULL;
			else
				par->lft=NULL;
			delete(cur);
			return r;
		}
		if(cur->lft==NULL && cur->rit!=NULL)
		{
			if(par->lft==cur)
				par->lft=cur->rit;
			else
				par->rit=cur->rit;
			delete(cur);
			return r;
		}
		if(cur->lft!=NULL && cur->rit==NULL)
		{
			if(par->lft==cur)
				par->lft=cur->lft;
			else
				par->rit=cur->lft;
			delete(cur);
			return r;
		}
	}
	void search(node* root,int ele)
	{
		if(root==NULL)
		{
			cout<<"Not found";
			return;
		}
		else if(root->nfo==ele)
		{
			cout<<"Found";
			return;
		}
		else if(root->nfo>ele)
			search(root->lft,ele);
		else if(root->nfo<ele)
			search(root->rit,ele);
	}
	void lod(node* r)
	{
		queue q;
		node* tmp;
		if(r==NULL)
			return;
		else
			q.insq(r);
		while(!q.isEmpty())
		{
			tmp=q.delq();
			cout<<tmp->nfo<<" ";
			if(tmp->lft)
				q.insq(tmp->lft);
			if(tmp->rit)
				q.insq(tmp->rit);
		}
	}
};

class queue
{
	int f,r;
	node* q[100];
public:
	queue()
	{
		f=0;
		r=-1;
	}
	void insq(node* i)
	{
		if(r==99)
		{
			cout<<"\nQueue overflow\n";
			return;
		}
		q[++r]=i;
	}
	node* delq()
	{
		if(f>r)
		{
			cout<<"Empty queue!";
			return NULL;
		}
		return q[f++];
	}
	int isEmpty()
	{
		if(f>r)
			return 1;
		else
			return 0;
	}
};

void main()
{
	clrscr();
	node t,*bt=NULL,*tmp;
	int exit=0,opt,ele;
	while(exit==0)
	{
		clrscr();
		cout<<"1.Insert\n2.Display\n3.Delete\n4.Search\n5.Level order traversal\n0.Exit\n";
		cin>>opt;
		switch(opt)
		{
		case 1:
			bt=t.insbst(bt);
			break;
		case 2:
			t.disp(bt,0);
			break;
		case 3:
			cout<<"Enter the element: ";
			cin>>ele;
			bt=t.delbst(bt,ele);
			break;
		case 4:
			cout<<"Enter the search term: ";
			cin>>ele;
			t.search(bt,ele);
			break;
		case 5:
			t.lod(bt);
			break;
		case 0:
			exit=1;
			break;
		default:
			cout<<"Invalid option";
			break;
		}
		getch();
	}
}