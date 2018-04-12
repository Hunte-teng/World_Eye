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
//�������Ĳ���
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
//������������
bstnode *creatbst(bstnode *t)
{
	bstnode *s;
	keytype key,endflag=0;
	datatype data;
	t=NULL;
	cout<<"�������¼������һ�����ֺ�һ���ַ����ԡ�0����������"<<endl;
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
//�������������
void inorder(bstnode *t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->key<<" "<<t->other<<endl;//printf("%c ",t->data);
        inorder(t->rchild);
	}
}
//��������ɾ��
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
//�������Ĳ���
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

	cout<<"������������Ľ�㣺"<<endl;
	t=creatbst(t);

	cout<<"���������������"<<endl;
	inorder(t);

	cout<<endl<<"��������Ҫ����ļ�¼��һ�����ֺ�һ���ַ�����"<<endl;
	cin>>s->key;
	cin>>s->other;
	s->lchild=s->rchild=NULL;	
	t=insertbst(t,s);
	cout<<endl;
	inorder(t);

	cout<<endl<<"��������Ҫɾ���ļ�¼�Ĺؼ��֣�"<<endl;
	cin>>key1;
	t=delbstnode(t,key1);
	cout<<endl;
	inorder(t);

	cout<<endl<<"��������Ҫ���ҵļ�¼�Ĺؼ��֣�"<<endl;
	cin>>key2;
	t=bstsearch(t,key2);
	if(t!=NULL)
		cout<<"�ҵ��ˣ�"<<endl;
	else
		cout<<"�޴˹ؼ��֣�"<<endl;
	cout<<endl;
}

	

