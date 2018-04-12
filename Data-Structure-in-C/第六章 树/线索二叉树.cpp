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
bithptr *root,*Q[maxsize];       //����QΪbitreeָ�����͵�����//ȫ����pre����ֵӦΪNULL
bithptr *CREATREE(bithptr *root)
{
	char ch;
	int front,real;            //��ͷ�Ͷ�βָ��
	bithptr *s;
	root=NULL;                   //�ÿն�����
	front=1;
	real=0;                     //�ÿն���
	ch=getchar();
	while(ch!='#')               //���ǽ�������ʱ�ظ���
	{
		s=NULL;
		if(ch!='@')              //@��ʾ���㣬��������ʱ�����½��
		{
			s=(bithptr *)malloc(sizeof(bithptr));
			s->data=ch;
			s->ltag=0;
			s->lchild=NULL;
			s->rtag=0;
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
//������
bithptr *pre=NULL;
void INTHREAD(bithptr *p)
{
	if(p!=NULL)
	{
		INTHREAD(p->lchild);      //������������
        if(p->lchild==NULL)  
			p->ltag=1;    //������������־
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
//�����̽��
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
//�������������
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
	cout<<"***********�˵�**************"<<endl;
	cout<<"   1�����������"<<endl;
	cout<<"   2��������������"<<endl;
	cout<<"   3���������������"<<endl;
	cout<<"   0���˳�"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"�����빦��ѡ���0~4��";
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
        case 1:cout<<"������������ԡ�#��������"<<endl;
	           root=CREATREE(root);
			   flushall();getchar();break;
        case 2:INTHREAD(root);cout<<"�������ɹ�"<<endl;flushall();getchar();break;
        case 3:TRAVERSEINTHREAD(root);flushall();getchar();break;
	    case 0:cout<<"�˳�"<<endl;
		       exit(0);
		}
	}
}