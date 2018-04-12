#include<iostream.h>
#include<stdlib.h>
typedef int keytype;
typedef char datatype;
typedef struct node
{
	keytype key;
	datatype other;
	struct node *lchild,*rchild;
} bstnode;
bstnode *t;
//二叉树的插入
bstnode *insertbst(bstnode *t,bstnode *s)
{
	bstnode *f,*p;
	p=t;
	while(p!=NULL)
	{
		f=p;
		if(s->key==p->key)
			return t;
		if(s->key<p->key)
			p=p->lchild;
		else
			p=p->rchild;
	}
	if(t==NULL)
		return s;
	if(s->key<f->key)
		f->lchild=s;
	else
		f->rchild=s;
	return t;
}
//二叉树的生成
bstnode *creatbst(bstnode *t)
{
	bstnode *s;
	keytype key,endflag=0;
	datatype data;
	t=NULL;
	cout<<"请输入记录，包含一个数字和一个字符（以‘0’结束）："<<endl;
	cin>>key;
	while(key!=endflag)
	{
		s=(bstnode *)malloc(sizeof(bstnode));
		s->lchild=s->rchild=NULL;
		s->key=key;
		cin>>data;
		s->other=data;
		t=insertbst(t,s);
		cin>>key;
	}
	return t;
}
//中序遍历二叉树
void inorder(bstnode *t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->key<<" "<<t->other<<endl;//printf("%c ",t->data);
        inorder(t->rchild);
	}
}
//二叉树的删除
bstnode *delbstnode(bstnode *t,keytype k)
{
	bstnode *p,*f,*s,*q;
	p=t;
	f=NULL;
	while(p!=NULL)
	{
		if(p->key==k)
			break;
		f=p;
		if(p->key>k)
			p=p->lchild;
		else
			p=p->rchild;
	}
	if(p==NULL)
		return t;
	if(p->lchild==NULL)
	{
		if(f==NULL)
			t=p->rchild;
		else if(f->lchild==p)
			f->lchild=p->rchild;
		else
			f->rchild=p->rchild;
		free(p);
	}
	else
	{
		q=p;
		s=p->lchild;
		while(s->rchild!=NULL)
		{
			q=s;
			s=s->rchild;
		}
		if(q==p)
			q->lchild=s->lchild;
		else
			q->rchild=s->lchild;
		p->key=s->key;
		p->other=s->other;
		free(s);
	}
	return t;
}
//二叉树的查找
bstnode *bstsearch(bstnode *t,keytype k)
{
	while(t!=NULL)
	{
		if(t->key==k)
			return t;
		if(t->key>k)
			t=t->lchild;
		else
			t=t->rchild;
	}
	return NULL;
}
void main()
{
	bstnode *s;
	keytype key1,key2;
	t=(bstnode *)malloc(sizeof(bstnode));
	s=(bstnode *)malloc(sizeof(bstnode));

	cout<<"请输入二叉树的结点："<<endl;
	t=creatbst(t);

	cout<<"中序遍历二叉树："<<endl;
	inorder(t);

	cout<<endl<<"请输入需要插入的记录（一个数字和一个字符）："<<endl;
	cin>>s->key;
	cin>>s->other;
	s->lchild=s->rchild=NULL;	
	t=insertbst(t,s);
	cout<<endl;
	inorder(t);

	cout<<endl<<"请输入需要删除的记录的关键字："<<endl;
	cin>>key1;
	t=delbstnode(t,key1);
	cout<<endl;
	inorder(t);

	cout<<endl<<"请输入需要查找的记录的关键字："<<endl;
	cin>>key2;
	t=bstsearch(t,key2);
	if(t!=NULL)
		cout<<"找到了！"<<endl;
	else
		cout<<"无此关键字！"<<endl;
	cout<<endl;
}

	

