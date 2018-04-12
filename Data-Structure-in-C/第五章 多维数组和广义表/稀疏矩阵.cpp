#include<iostream.h>
#include<stdlib.h>
#define M 4           //行数
#define N 5           //列数
#define T 6           //大于非零元素个数
#define smax 16       //大于非零元素个数的常数
typedef int datatype;
typedef struct
{
	int i,j;          //行、列号
	datatype v;       //元素值
}node;
typedef struct
{
	int m,n,t;        //行数，列数，非零元素个数
	node data[smax];  //三元组表
}spmatrix;            //稀疏矩阵类型
spmatrix *a,*b;
spmatrix *TRANSMAT(spmatrix *a,spmatrix *b)
{
	int ano,bno,col;   //ano和bno分别指示a->data和b->data中的结点序号
	                   //col指示*a的列号（即*b的行号）
	b->m=a->n;
	b->n=a->m;
	b->t=a->t;
	if(b->t>0)
	{
		bno=0;
		for(col=0;col<a->n;col++)                      //按*a的列序转置
			for(ano=0;ano<a->t;ano++)                  //扫描整个三元组表
				if(a->data[ano].j==col)                //列号为col则进行置换
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
		cout<<"请输入第"<<k+1<<"个非零元素的行号、列号、值：";
		cin>>a->data[k].i;
		cin>>a->data[k].j;
		cin>>a->data[k].v;
	}
	cout<<"置换前的矩阵："<<endl;
	printa(a);
	cout<<"置换后的矩阵："<<endl;
	b=TRANSMAT(a,b);
	printb(b);
}
