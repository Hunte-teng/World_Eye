#include<stdio.h>
#include<stdlib.h>
#define n 5   //图的顶点数
#define e 7   //图的边数
typedef int vextype;    //顶点的数据类型
typedef float adjtype;   //权值类型
typedef struct
{
	vextype vexs[n];
	adjtype C[n][n];
} graph;
graph *ga;
void creatgraph(graph *ga)    //建立无向网络
{
	int i,j,k;
	float w;
    printf("请输入顶点信息，建立顶点表：\n");
	printf("请输入%d个顶点：",n);
	for(i=0;i<n;i++)
	{
		ga->vexs[i]=getchar();      //读入顶点信息，建立顶点表
		getchar();  
		//scanf("%d",&ga->vexs[i]);
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ga->C[i][j]=600;    //邻接矩阵初始化
	printf("请输入图的%d条边：\n",e);
	for(k=0;k<e;k++)         //读入e条边
	{
		printf("输入结点的横纵坐标i,j,及权值w（i,j,w）：");
		scanf("%d%d%f",&i,&j,&w);        //读入边（vi,vj）上的权w
		ga->C[i][j]=w;
	}
}
void output(graph *ga)
{
	int i,j,m=0;
	printf("\n图的邻接矩阵：\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("%.1f ",ga->C[i][j]);
			m++;
			if(m%n==0)
				printf("\n");
		}
	printf("\n");
}

void dijkstra(graph *ga,int v)
{
	float D[n];
    int P[n],S[n];
	int i,j,k,vl,pre;
	float min,max=600,inf=800;
	vl=v-1;

	for(i=0;i<n;i++)
	{
		D[i]=ga->C[vl][i];
		if(D[i]!=max)
			P[i]=v;
		else
			P[i]=0;
	}

	for(i=0;i<n;i++)
		S[i]=0;
	S[vl]=1;
	D[vl]=0;
	for(i=0;i<n-1;i++)
	{
		min=inf;
		for(j=0;j<n;j++)
			if((!S[j])&&(D[j]<min))
			{
				min=D[j];
				k=j;
			}
		S[k]=1;
		for(j=0;j<n;j++)
			if((!S[j])&&(D[j]>(D[k]+ga->C[k][j])))
			{
				D[j]=D[k]+ga->C[k][j];
				P[j]=k+1;
			}
	}
	for(i=0;i<n;i++)
	{
		printf("%.0f\t%d",D[i],i+1);
		pre=P[i];
		while(pre!=0)
		{
			printf("<--%d",pre);
			pre=P[pre-1];
		}
		printf("\n");
	}
}
void main()
{
	ga=(graph *)malloc(sizeof(graph));
	creatgraph(ga);
	output(ga);
	printf("\n");
	dijkstra(ga,4);
}