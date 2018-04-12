#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#define maxsize 20
typedef char datatype;
typedef struct node
{
	int ltag,rtag;
    datatype data;
    struct node *lchild,*rchild;
} bithptr;          
bithptr *root,*Q[maxsize];       //队列Q为bitree指针类型的数组//全程量pre，初值应为NULL
bithptr *CREATREE(bithptr *root)
{
	char ch;
	int front,real;            //队头和队尾指针
	bithptr *s;
	root=NULL;                   //置空二叉树
	front=1;
	real=0;                     //置空队列
	ch=getchar();
	while(ch!='#')               //不是结束符号时重复做
	{
		s=NULL;
		if(ch!='@')              //@表示虚结点，不是虚结点时建立新结点
		{
			s=(bithptr *)malloc(sizeof(bithptr));
			s->data=ch;
			s->ltag=0;
			s->lchild=NULL;
			s->rtag=0;
			s->rchild=NULL;
		}
		real++;
		Q[real]=s;               //将虚结点指针NULL或新结点地址入队
		if(real==1)    root=s;   //输入的一个结点为根结点
		else
		{
			if(s&&Q[front])          //孩子和双亲结点均不是虚结点
				if(real%2==0)
					Q[front]->lchild=s;     //real为偶数，新结点是左孩子
				else     //real为奇数
					Q[front]->rchild=s;           //新结点是右孩子
			if(real%2==1)   front++;      //结点*Q[front]的两个孩子已处理完毕，出队列
		}
		ch=getchar();
	}
	return root;     
}
//线索化
bithptr *pre=NULL;
void INTHREAD(bithptr *p)
{
	if(p!=NULL)
	{
		INTHREAD(p->lchild);      //左子树线索化
        if(p->lchild==NULL)  
			p->ltag=1;    //建立左线索标志
        if(p->rchild==NULL)
			p->rtag=1;
        if(pre!=NULL)
		{
			if(pre->rtag==1)
				pre->rchild=p;
			if(p->ltag==1)
				p->lchild=pre;
		}
		pre=p;
		INTHREAD(p->rchild);
	}
}
//中序后继结点
bithptr *INORDERNEXT(bithptr *p)
{
	bithptr *q;
	if(p->rtag==1)
		return(p->rchild);
	else
	{
		q=p->rchild;
		while(q->ltag==0)
			q=q->lchild;
		return(q);
	}
}
//中序遍历二叉树
void TRAVERSEINTHREAD(bithptr *p)
{
	if(p!=NULL)
	{
		while(p->ltag==0)
			p=p->lchild;
		do
		{
			cout<<p->data<<" ";
			p=INORDERNEXT(p);
		}while(p!=NULL);
	}
	cout<<endl;
}
void menu()
{
	cout<<"***********菜单**************"<<endl;
	cout<<"   1、输入二叉树"<<endl;
	cout<<"   2、二叉树线索化"<<endl;
	cout<<"   3、中序遍历二叉树"<<endl;
	cout<<"   0、退出"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"请输入功能选项号0~4：";
}
void main()
{
    int a;
    while(1)
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
        case 1:cout<<"请输入二叉树以‘#’结束："<<endl;
	           root=CREATREE(root);
			   flushall();getchar();break;
        case 2:INTHREAD(root);cout<<"线索化成功"<<endl;flushall();getchar();break;
        case 3:TRAVERSEINTHREAD(root);flushall();getchar();break;
	    case 0:cout<<"退出"<<endl;
		       exit(0);
		}
	}
}