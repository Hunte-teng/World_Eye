#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
#define maxsize 64
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
} bitptr;
bitptr *root,*Q[maxsize];       //队列Q为bitree指针类型的数组;
typedef struct
{
	bitptr *data[maxsize];
    int top;
} seqstack;
seqstack *s;
//置空栈
void SETNULL(seqstack *s)
{
	s->top=-1;
}
//判空栈
int EMPTY(seqstack *s)
{
	if(s->top>=0)
        return 0;
    else 
		return 1;
}
//进栈
seqstack *PUSH(seqstack *s,bitptr *x)
{
	if(s->top==maxsize-1)
	{
        return NULL;
	}
    else
	{
        s->top++;
        s->data[s->top]=x;
	}
    return s;
}
//退栈
bitptr *POP(seqstack *s)
{
	if(EMPTY(s))
	{
        return NULL;
	}
    else
	{
        s->top--;
        return(s->data[s->top+1]);
	}
}
//取栈顶
bitptr *TOP(seqstack *s)
{
	if(EMPTY(s))
	{
        return NULL;
	}
    else
        return(s->data[s->top]);
}
bitptr *CREATREE(bitptr *root)
{
	char ch;
	int front,real;            //队头和队尾指针
	bitptr *s;
	root=NULL;                   //置空二叉树
	front=1;
	real=0;                     //置空队列
	ch=getchar();
	while(ch!='#')               //不是结束符号时重复做
	{
		s=NULL;
		if(ch!='@')              //@表示虚结点，不是虚结点时建立新结点
		{
			s=(bitptr *)malloc(sizeof(bitptr));
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
void INORDER(bitptr *t,seqstack *s)
{
	bitptr *p;
	SETNULL(s);
	p=t;
	if(p!=NULL)
		do
		{
			while(p!=NULL)
			{
				PUSH(s,p);
                p=p->lchild;
			}
			if(!EMPTY(s))
			{
				p=POP(s);
				cout<<p->data<<" ";
				p=p->rchild;
			}
		}while(!EMPTY(s)||p);
	cout<<endl;
}
void PREORD(bitptr *t,seqstack *s)
{
	bitptr *p;
	SETNULL(s);
	p=t;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		if(p->rchild!=NULL)
			PUSH(s,p->rchild);
		p=p->lchild;
		if(p==NULL)
			p=POP(s);
	}
	cout<<endl;
}
void menu()
{
	cout<<"***********菜单**************"<<endl;
	cout<<"   1、输入二叉树"<<endl;
	cout<<"   2、前序遍历二叉树的非递归"<<endl;
	cout<<"   3、中序遍历二叉树的非递归"<<endl;
	cout<<"   0、退出"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"请输入功能选项号0~3：";
}
void main()
{
	s=(seqstack *)malloc(sizeof(seqstack));
	SETNULL(s);
    int a;
    do
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
        case 1:cout<<"请输入二叉树以‘#’结束："<<endl;
	           root=CREATREE(root);
			   flushall();getchar();break;
        case 2:PREORD(root,s);flushall();getchar();break;
        case 3:INORDER(root,s);flushall();getchar();break;
	    case 0:cout<<"退出";
		       exit(0);
		}
	}while(1);
}
