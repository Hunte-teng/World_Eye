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
bitree *root,*Q[maxsize];       //����QΪbitreeָ�����͵�����
bitree *CREATREE(bitree *root)
{
	char ch;
	int front,real;            //��ͷ�Ͷ�βָ��
	bitree *s;
	root=NULL;                   //�ÿն�����
	front=1;
	real=0;                     //�ÿն���
	ch=getchar();
	while(ch!='#')               //���ǽ�������ʱ�ظ���
	{
		s=NULL;
		if(ch!='@')              //@��ʾ���㣬��������ʱ�����½��
		{
			s=(bitree *)malloc(sizeof(bitree));
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
//ǰ�����������
void PREORDER(bitree *t)
{
	if(t)
	{
		printf("%c ",t->data);
		PREORDER(t->lchild);
        PREORDER(t->rchild);
	}
}
//�������������
void INORDER(bitree *t)
{
	if(t)
	{
		INORDER(t->lchild);
		printf("%c ",t->data);
        INORDER(t->rchild);
	}
}
//�������������
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
	cout<<"***********�˵�**************"<<endl;
	cout<<"   1�����������"<<endl;
	cout<<"   2��ǰ��������������"<<endl;
	cout<<"   3������������������"<<endl;
	cout<<"   4������������������"<<endl;
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
        case 2:PREORDER(root);flushall();getchar();break;
        case 3:INORDER(root);
               flushall();getchar();break;
        case 4:POSTORDER(root);flushall();getchar();break;
	    case 0:cout<<"�˳�";
		       exit(0);
		}
	}
}


