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
//�������ĸ߶�
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
void output(bitree *t)//���������
{
	if(t!=NULL)
	{
		printf("%c",t->data);
		if(t->lchild!=NULL||t->rchild!=NULL)
		{
			printf("(");//�к��ӽ��ʱ���"("
			output(t->lchild);//�ݹ鴦��������
			if(t->rchild!=NULL)
				printf(",");//���Һ��ӽ��ʱ���","
			output(t->rchild);//�ݹ鴦��������
			printf(")");//�к��ӽ��ʱ���")"
		}
	}
}
void main()
{
	cout<<"������������ԡ�#��������"<<endl;
	root=CREATREE(root);
	output(root);
	cout<<endl;
	cout<<"���ĸ߶�Ϊ��"<<HEIGHT(root)<<endl;		   
}
