#include<iostream.h>
#include<stdlib.h>
#define M 4           //����
#define N 5           //����
#define T 6           //���ڷ���Ԫ�ظ���
#define smax 16       //���ڷ���Ԫ�ظ����ĳ���
typedef int datatype;
typedef struct
{
	int i,j;          //�С��к�
	datatype v;       //Ԫ��ֵ
}node;
typedef struct
{
	int m,n,t;        //����������������Ԫ�ظ���
	node data[smax];  //��Ԫ���
}spmatrix;            //ϡ���������
spmatrix *a,*b;
spmatrix *TRANSMAT(spmatrix *a,spmatrix *b)
{
	int ano,bno,col;   //ano��bno�ֱ�ָʾa->data��b->data�еĽ�����
	                   //colָʾ*a���кţ���*b���кţ�
	b->m=a->n;
	b->n=a->m;
	b->t=a->t;
	if(b->t>0)
	{
		bno=0;
		for(col=0;col<a->n;col++)                      //��*a������ת��
			for(ano=0;ano<a->t;ano++)                  //ɨ��������Ԫ���
				if(a->data[ano].j==col)                //�к�Ϊcol������û�
				{
					b->data[bno].i=a->data[ano].j;          
					b->data[bno].j=a->data[ano].i;          
					b->data[bno].v=a->data[ano].v;          
					bno++;
				}
	}
	return b;
}
void printa(spmatrix *a)
{
	int x,y,q=0,k=0;
	for(x=0;x<a->m;x++)
	{
		for(y=0;y<a->n;y++)
		{
		    if(x==a->data[k].i&&y==a->data[k].j)
			      cout<<a->data[k++].v<<" ";
			else
				  cout<<'0'<<" ";
			q++;
			if(q%N==0)
				cout<<endl;
		}   
	}
}
void printb(spmatrix *b)
{
	int x,y,q=0,k=0;
	for(x=0;x<b->m;x++)
	{
		for(y=0;y<b->n;y++)
		{
		    if(x==b->data[k].i&&y==b->data[k].j)
			      cout<<b->data[k++].v<<" ";
			else
				  cout<<'0'<<" ";
			q++;
			if(q%M==0)
				cout<<endl;
		}   
	}
}
void main()
{
	int k;
	a=(spmatrix *)malloc(sizeof(spmatrix));
	b=(spmatrix *)malloc(sizeof(spmatrix));
	a->m=M;
	a->n=N;
	a->t=T;
	for(k=0;k<a->t;k++)
	{
		cout<<"�������"<<k+1<<"������Ԫ�ص��кš��кš�ֵ��";
		cin>>a->data[k].i;
		cin>>a->data[k].j;
		cin>>a->data[k].v;
	}
	cout<<"�û�ǰ�ľ���"<<endl;
	printa(a);
	cout<<"�û���ľ���"<<endl;
	b=TRANSMAT(a,b);
	printb(b);
}
