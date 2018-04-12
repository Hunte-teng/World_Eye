#include<stdio.h>
#define n 11
typedef int keytype;
typedef char datatype;
typedef struct
{
	keytype key;
	datatype other;
} table;
table R[n+1];

//顺序查找
int seqsearch(table R[],keytype K)
{
	int i;
	R[n].key=K;
	i=0;
	while(R[i].key!=K)
		i++;
	if(i==n)
		return(-1);
	else
		return i;
}
//选择排序
void selectsort()
{
	int i,j,k;
	table temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(R[j].key<R[k].key)
				k=j;
		if(k!=i)
		{
			temp=R[i];
			R[i]=R[k];
			R[k]=temp;
		}
	}
}
//二分查找
int binsearch(table R[],keytype K)
{
	int low,mid,high;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(K==R[mid].key)
			return mid;
		if(K<R[mid].key)
			high=mid-1;
		else
			low=mid+1;
	}
	return(-1);
}
void main()
{
	keytype k1,k2,m;
	int i;
    printf("请输入%d条记录，每条记录包含一个关键字（数字）和其他（一个字符）：\n",n);
	for(i=0;i<n;i++)
		scanf("%d %c",&R[i].key,&R[i].other);
	printf("\n顺序查找：\n");
	printf("请输入需要查找的关键字：\n");
	scanf("%d",&k1);
    m=seqsearch(R,k1);
	if(m==-1)
		printf("无次数！\n");
	else
		printf("此关键字是顺序表中第%d个结点\n",m+1);
	printf("\n二分查找：\n");
    printf("经过选择排序后的顺序表：\n");
	selectsort();
	for(i=0;i<n;i++)
	    printf("%d\t%c\n",R[i].key,R[i].other);
	printf("请输入需要查找的关键字：\n");
	scanf("%d",&k2);
    m=binsearch(R,k2);
	if(m==-1)
		printf("无次数！\n");
	else
		printf("此关键字是顺序表中第%d个结点\n",m+1);
}

