#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#define maxsize 20
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
} bitree;
bitree *root1,*root2,*Q[maxsize];       //����QΪbitreeָ�����͵�����
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

//�ȼ��ж�
bool JUDGE(bitree *root1,bitree *root2)
{
	if(root1==NULL&&root2==NULL)
		return true;
	else
		if(root1==NULL||root2==NULL)
			return false;
		else if(root1!=NULL&&root2!=NULL)//&&(root1->data == root2->data)&&JUDGE((root1->lchild,root2->lchild))&&(JUDGE(root1->rchild,root2->rchild)))
		         //return true;
    //else 
		//return false;
		//return(
		JUDGE(root1->lchild,root2->lchild)&&JUDGE(root1->rchild,root2->rchild);
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
	cout<<"�����������T1�ԡ�#��������"<<endl;
    root1=CREATREE(root1);
	getchar();
	cout<<"�����������T2�ԡ�#��������"<<endl;
    root2=CREATREE(root2);
	output(root1);
	cout<<endl;
	output(root2);
	cout<<endl;
	if(JUDGE(root1,root2)==true)
		cout<<"T1��T2�ȼ�"<<endl;
	else 
		cout<<"T1��T2���ȼ�"<<endl;
}
