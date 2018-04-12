#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#define n 7        //叶子总数
#define m (2*n-1)    //结点总数
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
	char bits[n];       // 位串
    int start;          //编码在位串中的起始位置
	char ch;
} codetype;
codetype code[n];
void huffman(hufmtree tree[],int x)
{
	int i,j,p1,p2;
	float small1,small2,f;
	for(i=0;i<m;i++)               //初始化
	{
		tree[i].parent=0;
		tree[i].lchild=0;
		tree[i].rchild=0;
		tree[i].weight=0.0;
	}
	for(i=0;i<n;i++)               //读入前n个结点的权值
	{
		cin>>f;
		tree[i].weight=f;
	}
	for(i=n;i<m;i++)               //进行n-1次合并，产生n-1个新结点
	{
		p1=0;
		p2=0;
		small1=maxval;
		small2=maxval;
		for(j=0;j<=i-1;j++)         //选出两个权值最小的根结点
			if(tree[j].parent==0)
				if(tree[j].weight<small1)
				{
					small2=small1;      //改变最小权、次小权及对应的位置
					small1=tree[j].weight;
					p2=p1;
					p1=j;
				}
				else
					if(tree[j].weight<small2)
					{
						small2=tree[j].weight;      //改变次小权及位置
						p2=j;
					}
			tree[p1].parent=i+1;
			tree[p2].parent=i+1;
			tree[i].lchild=p1+1;                          //最小权根结点是新结点的左孩子，分量号是下标加1
			tree[i].rchild=p2+1;                          //次小权根结点是新结点的右孩子
			tree[i].weight=tree[p1].weight+tree[p2].weight;
	}
}
void output(hufmtree tree[],int x)
{
	int i;
	cout<<"结点号"<<"\t"<<"下标"<<"\t"<<"weight"<<"\t"<<"parent"<<"\t"<<"lchild"<<"\t"<<"rchild"<<endl;
	for(i=0;i<m;i++)
		cout<<i+1<<"\t"<<i<<"\t"<<tree[i].weight<<"\t"<<tree[i].parent<<"\t"<<tree[i].lchild<<"\t"<<tree[i].rchild<<endl;
}
void huffmancode(hufmtree tree[],int x)
{
	int i,j,c,p;
	codetype cd;     //缓冲变量
	for(i=0;i<n;i++)
	{
		cd.start=n;
		cout<<"请输入结点字符：";
		cin>>cd.ch;
		c=i+1;       //从叶结点出发向上回溯
		p=tree[i].parent;    //tree[p-1]是tree[i]的双亲
		while(p!=0)
		{
			cd.start--;
			if(tree[p-1].lchild==c)
				cd.bits[cd.start]='0';   //tree[i]是左子树，生成代码‘0’
			else
				cd.bits[cd.start]='1';   //tree[i]是右子树，生成代码‘1’
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
	int endflag=-1;    //电文结束标志取-1
	i=m-1;             //从根结点开始往下搜索
	cout<<"请输入一个二进制码（数字间用空格并以‘-1’结束）："<<endl;
	cin>>b;            //读入一个二进制码
	while(b!=endflag)
	{                
		if(b==0)       //走向左孩子
			i=tree[i].lchild-1;
		else           //走向右孩子
			i=tree[i].rchild-1;
		if(tree[i].lchild==0)     //tree[i]是叶结点
		{
			putchar(code[i].ch);       //译码，即输出叶结点对应的字符
			i=m;             //回到根结点
		}
		//cout<<"请输入下一个二进制码：";
		cin>>b;              //读入下一个二进制码
	}
	if(tree[i].lchild!=0)     //电文读完但尚未到叶子结点
		cout<<"error"<<endl;   //输入电文有错
}

void main()
{
	cout<<"请输入树结点的权："<<endl;
	huffman(tree,m);
	cout<<"内存状态"<<endl;
    output(tree,m);
	huffmancode(tree,n);
	decode(code,tree);
	int a;
	do
	{
		cout<<"\n如果继续，请输入1,否则输入0"<<endl;
	    cin>>a;
		switch(a)
		{
	    case 1:decode(code,tree);break;
	    case 0:cout<<"退出"<<endl;
		       exit(0);
		}
	}while(1);
}