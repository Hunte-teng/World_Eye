#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#define n 7        //Ҷ������
#define m (2*n-1)    //�������
#define maxval 50
typedef int datatype;
typedef struct
{
	float weight;
	int lchild,rchild,parent;
} hufmtree;
hufmtree tree[m];
typedef struct
{
	char bits[n];       // λ��
    int start;          //������λ���е���ʼλ��
	char ch;
} codetype;
codetype code[n];
void huffman(hufmtree tree[],int x)
{
	int i,j,p1,p2;
	float small1,small2,f;
	for(i=0;i<m;i++)               //��ʼ��
	{
		tree[i].parent=0;
		tree[i].lchild=0;
		tree[i].rchild=0;
		tree[i].weight=0.0;
	}
	for(i=0;i<n;i++)               //����ǰn������Ȩֵ
	{
		cin>>f;
		tree[i].weight=f;
	}
	for(i=n;i<m;i++)               //����n-1�κϲ�������n-1���½��
	{
		p1=0;
		p2=0;
		small1=maxval;
		small2=maxval;
		for(j=0;j<=i-1;j++)         //ѡ������Ȩֵ��С�ĸ����
			if(tree[j].parent==0)
				if(tree[j].weight<small1)
				{
					small2=small1;      //�ı���СȨ����СȨ����Ӧ��λ��
					small1=tree[j].weight;
					p2=p1;
					p1=j;
				}
				else
					if(tree[j].weight<small2)
					{
						small2=tree[j].weight;      //�ı��СȨ��λ��
						p2=j;
					}
			tree[p1].parent=i+1;
			tree[p2].parent=i+1;
			tree[i].lchild=p1+1;                          //��СȨ��������½������ӣ����������±��1
			tree[i].rchild=p2+1;                          //��СȨ��������½����Һ���
			tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
}
void output(hufmtree tree[],int x)
{
	int i;
	cout<<"����"<<"\t"<<"�±�"<<"\t"<<"weight"<<"\t"<<"parent"<<"\t"<<"lchild"<<"\t"<<"rchild"<<endl;
	for(i=0;i<m;i++)
		cout<<i+1<<"\t"<<i<<"\t"<<tree[i].weight<<"\t"<<tree[i].parent<<"\t"<<tree[i].lchild<<"\t"<<tree[i].rchild<<endl;
}
void huffmancode(hufmtree tree[],int x)
{
	int i,j,c,p;
	codetype cd;     //�������
	for(i=0;i<n;i++)
	{
		cd.start=n;
		cout<<"���������ַ���";
		cin>>cd.ch;
		c=i+1;       //��Ҷ���������ϻ���
		p=tree[i].parent;    //tree[p-1]��tree[i]��˫��
		while(p!=0)
		{
			cd.start--;
			if(tree[p-1].lchild==c)
				cd.bits[cd.start]='0';   //tree[i]�������������ɴ��롮0��
			else
				cd.bits[cd.start]='1';   //tree[i]�������������ɴ��롮1��
			c=p;
			p=tree[p-1].parent;          
		}
		code[i]=cd;
	}
	for(i=0;i<n;i++)
	{
		for(j=code[i].start;j<n;j++)
		{
			cout<<code[i].bits[j];
		}
		cout<<endl;
	}
}

void decode(codetype *code,hufmtree *tree)
{
	int i,b;
	int endflag=-1;    //���Ľ�����־ȡ-1
	i=m-1;             //�Ӹ���㿪ʼ��������
	cout<<"������һ���������루���ּ��ÿո��ԡ�-1����������"<<endl;
	cin>>b;            //����һ����������
	while(b!=endflag)
	{                
		if(b==0)       //��������
			i=tree[i].lchild-1;
		else           //�����Һ���
			i=tree[i].rchild-1;
		if(tree[i].lchild==0)     //tree[i]��Ҷ���
		{
			putchar(code[i].ch);       //���룬�����Ҷ����Ӧ���ַ�
			i=m;             //�ص������
		}
		//cout<<"��������һ���������룺";
		cin>>b;              //������һ����������
	}
	if(tree[i].lchild!=0)     //���Ķ��굫��δ��Ҷ�ӽ��
		cout<<"error"<<endl;   //��������д�
}

void main()
{
	cout<<"������������Ȩ��"<<endl;
	huffman(tree,m);
	cout<<"�ڴ�״̬"<<endl;
    output(tree,m);
	huffmancode(tree,n);
	decode(code,tree);
	int a;
	do
	{
		cout<<"\n���������������1,��������0"<<endl;
	    cin>>a;
		switch(a)
		{
	    case 1:decode(code,tree);break;
	    case 0:cout<<"�˳�"<<endl;
		       exit(0);
		}
	}while(1);
}