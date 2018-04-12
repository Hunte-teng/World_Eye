#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#define maxsize 20
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
} bitree;
bitree *root,*Q[maxsize];       //队列Q为bitree指针类型的数组
bitree *CREATREE(bitree *root)
{
	char ch;
	int front,real;            //队头和队尾指针
	bitree *s;
	root=NULL;                   //置空二叉树
	front=1;
	real=0;                     //置空队列
	ch=getchar();
	while(ch!='#')               //不是结束符号时重复做
	{
		s=NULL;
		if(ch!='@')              //@表示虚结点，不是虚结点时建立新结点
		{
			s=(bitree *)malloc(sizeof(bitree));
			s->data=ch;
			s->lchild=NULL;
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
//前序遍历二叉树
void PREORDER(bitree *t)
{
	if(t)
	{
		printf("%c ",t->data);
		PREORDER(t->lchild);
        PREORDER(t->rchild);
	}
}
//中序遍历二叉树
void INORDER(bitree *t)
{
	if(t)
	{
		INORDER(t->lchild);
		printf("%c ",t->data);
        INORDER(t->rchild);
	}
}
//后序遍历二叉树
void POSTORDER(bitree *t)
{
	if(t)
	{	
		POSTORDER(t->lchild);
        POSTORDER(t->rchild);
		printf("%c ",t->data);
	}
}

void menu()
{
	cout<<"***********菜单**************"<<endl;
	cout<<"   1、输入二叉树"<<endl;
	cout<<"   2、前序遍历二叉树结果"<<endl;
	cout<<"   3、中序遍历二叉树结果"<<endl;
	cout<<"   4、后序遍历二叉树结果"<<endl;
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
        case 2:PREORDER(root);flushall();getchar();break;
        case 3:INORDER(root);
               flushall();getchar();break;
        case 4:POSTORDER(root);flushall();getchar();break;
	    case 0:cout<<"退出";
		       exit(0);
		}
	}
}


