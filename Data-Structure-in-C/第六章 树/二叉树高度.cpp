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
//二叉树的高度
int HEIGHT(bitree *t)
{
	int l,r;
	if(!t)
		return 0;
	else
	{
		l=1+HEIGHT(t->lchild);
		r=1+HEIGHT(t->rchild);
	if(l>r)
		return l;
	else
		return r;
	}
}
void output(bitree *t)//输出二叉树
{
	if(t!=NULL)
	{
		printf("%c",t->data);
		if(t->lchild!=NULL||t->rchild!=NULL)
		{
			printf("(");//有孩子结点时输出"("
			output(t->lchild);//递归处理左子树
			if(t->rchild!=NULL)
				printf(",");//有右孩子结点时输出","
			output(t->rchild);//递归处理右子树
			printf(")");//有孩子结点时输出")"
		}
	}
}
void main()
{
	cout<<"请输入二叉树以‘#’结束："<<endl;
	root=CREATREE(root);
	output(root);
	cout<<endl;
	cout<<"树的高度为："<<HEIGHT(root)<<endl;		   
}
