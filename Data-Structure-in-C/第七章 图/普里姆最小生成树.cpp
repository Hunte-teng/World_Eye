#include<stdio.h>
#include<stdlib.h>
#define n 6   //图的顶点数
#define e 10   //图的边数
typedef char vextype;    //顶点的数据类型
typedef float adjtype;   //权值类型
typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
} graph;
graph *ga;
typedef struct
{
	int fromvex,endvex;    //边的起点和终点
	float length;          //边的权值
} edge;
edge T[n-1];
void creatgraph()    //建立无向网络
{
	int i,j,k;
	float w;
    printf("请输入顶点信息，建立顶点表：\n");
	printf("请输入第%d个顶点：",n);
	for(i=0;i<n;i++)
	{
		ga->vexs[i]=getchar();  //读入顶点信息，建立顶点表
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ga->arcs[i][j]=0;    //邻接矩阵初始化
	printf("请输入图的%d条边：\n",e);
	for(k=0;k<e;k++)         //读入e条边
	{
		printf("输入结点的横纵坐标i,j,及权值w（i,j,w）：");
		scanf("%d%d%f",&i,&j,&w);        //读入边（vi,vj）上的权w
		ga->arcs[i][j]=w;
		ga->arcs[j][i]=w;
	}
}
void prim()
{
	int j,k,m,v,min,max=10000;
	float d;
	edge b;
	for(j=1;j<n;j++)     //构造初始候选紫边集
	{
		T[j-1].fromvex=1;      //顶点1是第一个加入树中的红点
		T[j-1].endvex=j+1;
		T[j-1].length=ga->arcs[0][j];
	}
	for(k=0;k<n-1;k++)          //求第k条边
	{
		min=max;
		for(j=k;j<n-1;j++)       //在候选紫边集中找最短紫边
			if(T[j].length<min)
			{
				min=T[j].length;
				m=j;
			}            //T[m]是当前最短紫边
			b=T[m];
			T[m]=T[k];
			T[k]=b;       //T[k]和T[m]交换后，T[k]是第K条红色树边
			v=T[k].endvex;    //v是新红点
			for(j=k+1;j<n-1;j++)     //调整候选紫边集
			{
				d=ga->arcs[v-1][T[j].endvex-1];
				if(d<T[j].length)
				{
					T[j].length=d;
					T[j].fromvex=v;
				}
			}
	}
}
//输出最小生成树
void output()
{
	int i;
	for(i=0;i<n-1;i++)
	{
		printf("%d %d",T[i].fromvex,T[i].endvex);
		printf("%.1f\n",T[i].length);
	}
	printf("\n");
}

void main()
{
	ga=(graph *)malloc(sizeof(graph));
    creatgraph();
	prim();
	output();
}


