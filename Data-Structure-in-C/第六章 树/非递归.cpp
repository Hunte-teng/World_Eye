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
bitptr *root,*Q[maxsize];       //����QΪbitreeָ�����͵�����;
typedef struct
{
	bitptr *data[maxsize];
    int top;
} seqstack;
seqstack *s;
//�ÿ�ջ
void SETNULL(seqstack *s)
{
	s->top=-1;
}
//�п�ջ
int EMPTY(seqstack *s)
{
	if(s->top>=0)
        return 0;
    else 
		return 1;
}
//��ջ
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
//��ջ
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
//ȡջ��
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
	int front,real;            //��ͷ�Ͷ�βָ��
	bitptr *s;
	root=NULL;                   //�ÿն�����
	front=1;
	real=0;                     //�ÿն���
	ch=getchar();
	while(ch!='#')               //���ǽ�������ʱ�ظ���
	{
		s=NULL;
		if(ch!='@')              //@��ʾ���㣬��������ʱ�����½��
		{
			s=(bitptr *)malloc(sizeof(bitptr));
			s->data=ch;
			s->lchild=NULL;
			s->rchild=NULL;
		}
		real++;
		Q[real]=s;               //������ָ��NULL���½���ַ���
		if(real==1)    root=s;   //�����һ�����Ϊ�����
		else
		{
			if(s&&Q[front])          //���Ӻ�˫�׽�����������
				if(real%2==0)
					Q[front]->lchild=s;     //realΪż�����½��������
				else     //realΪ����
					Q[front]->rchild=s;           //�½�����Һ���
			if(real%2==1)   front++;      //���*Q[front]�����������Ѵ�����ϣ�������
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
	cout<<"***********�˵�**************"<<endl;
	cout<<"   1�����������"<<endl;
	cout<<"   2��ǰ������������ķǵݹ�"<<endl;
	cout<<"   3����������������ķǵݹ�"<<endl;
	cout<<"   0���˳�"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"�����빦��ѡ���0~3��";
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
        case 1:cout<<"������������ԡ�#��������"<<endl;
	           root=CREATREE(root);
			   flushall();getchar();break;
        case 2:PREORD(root,s);flushall();getchar();break;
        case 3:INORDER(root,s);flushall();getchar();break;
	    case 0:cout<<"�˳�";
		       exit(0);
		}
	}while(1);
}
