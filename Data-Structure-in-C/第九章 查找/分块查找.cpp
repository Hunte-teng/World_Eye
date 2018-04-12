#include<stdio.h>
#define n 18
#define b 3
typedef int keytype;
typedef char datatype;
typedef struct
{
	keytype key;
	datatype other;
} table;
table R[n+1];

typedef struct
{
	keytype key;
	int addr;
} IDtable;
IDtable ID[b];

int blksearch(table R[],IDtable ID[],keytype K)
{
	int i,low1,low2,mid,high1,high2;
	low1=0;
	high1=b-1;
	while(low1<=high1)
	{
		mid=(low1+high1)/2;
		if(K<=ID[mid].key)
			high1=mid-1;
		else
			low1=mid+1;
	}
	if(low1<b)
	{
		low2=ID[low1].addr;
		if(low1==b-1)
			high2=n-1;
		else
			high2=ID[low1+1].addr-1;
		for(i=low2;i<=high2;i++)
			if(R[i].key==K)
				return i;
	}
	return(-1);
}
void main()
{
	keytype k;
	int i,m;
    printf("请输入%d条记录，每条记录包含一个关键字（数字）和其他（一个字符）：\n",n);
	for(i=0;i<n;i++)
		scanf("%d %c",&R[i].key,&R[i].other);
    printf("请输入索引表关键字和地址：\n",n);
	for(i=0;i<b;i++)
		scanf("%d %d",&ID[i].key,&ID[i].addr);
	printf("\n分块查找：\n");
	printf("请输入需要查找的关键字：\n");
	scanf("%d",&k);
    m=blksearch(R,ID,k);
	if(m==-1)
		printf("无次数！\n");
	else
		printf("此关键字是顺序表中第%d个结点\n",m+1);
}
