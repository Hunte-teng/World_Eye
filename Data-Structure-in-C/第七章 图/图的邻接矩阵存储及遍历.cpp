#include<stdio.h>
#include<stdlib.h>
#define n 5   //图的顶点数
#define e 8   //图的边数
#define maxsize 20
typedef int datatype;
typedef char vextype;    //顶点的数据类型
typedef float adjtype;   //权值类型
typedef struct
{
	datatype data[maxsize];
    int front,rear;
} seqstack;
seqstack *Q;
typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
} graph;
graph *ga;
int visited[n];
//置空队
void SETNULL(seqstack *sq)
{
	sq->front=maxsize-1;
    sq->rear=maxsize-1;
}
//判队空
int EMPTY(seqstack *sq)
{
	if(sq->rear==sq->front)
        return 1;
    else 
		return 0;
}
//入队
seqstack *ENQUEUE(seqstack *sq,datatype x)
{
	if(sq->front==(sq->rear+1)%maxsize)
	{
		printf("队满上溢！");
        return NULL;
	}
    else
	{
        sq->rear=(sq->rear+1)%maxsize;
        sq->data[sq->rear]=x;
	}
    return sq;
}
//出队
datatype DEQUEUE(seqstack *sq)
{
	if(EMPTY(sq))
	{
        printf("队空下溢！");
        return NULL;
	}
    else
	{
        sq->front=(sq->front+1)%maxsize;
        return(sq->data[sq->front]);
	}
}
void creatgraph(graph *ga)    //建立无向网络
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
		printf("输入结点的横纵坐标i,j（i,j）：");
		scanf("%d%d",&i,&j); 
		ga->arcs[i][j]=1;
		ga->arcs[j][i]=1;
		//printf("输入结点的横纵坐标i,j,及权值w（i,j,w）：");
		//scanf("%d%d%f",&i,&j,&w);        //读入边（vi,vj）上的权w
		//ga->arcs[i][j]=w;
		//ga->arcs[j][i]=w;
	}
}
void output(graph *ga)
{
	int i,j,m=0;
	printf("\n图的邻接矩阵：\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("%.1f ",ga->arcs[i][j]);
			m++;
			if(m%n==0)
				printf("\n");
		}
	printf("\n");
}
//标记数组初始化为0
void visit()
{
	for(int i=0;i<n;i++)
		visited[i]=0;
}
//广度优先遍历
void bfs(int k)
{
	int i,j;
    visit();
	SETNULL(Q);
	printf("%c ",ga->vexs[k]);
	visited[k]=1;
	ENQUEUE(Q,k);
	while(!EMPTY(Q))
	{
		i=DEQUEUE(Q);
		for(j=0;j<n;j++)
			if((ga->arcs[i][j]==1)&&(!visited[j]))
			{
				printf("%c ",ga->vexs[j]);
				visited[j]=1;
				ENQUEUE(Q,j);
			}
	}
}
//深度优先遍历
void DFS(int i)
{
	int j;	
	printf("node:%c\n",ga->vexs[i]);
	visited[i]=1;
	for(j=0;j<n;j++)
		if((ga->arcs[i][j]==1)&&(!visited[j]))
			DFS(j);
}
void main()
{
	int i,k;
	ga=(graph *)malloc(sizeof(graph));
	Q=(seqstack *)malloc(sizeof(seqstack));
	SETNULL(Q);
	creatgraph(ga);
	output(ga);
	printf("广度优先遍历：\n请输入遍历出发点序号k：");
	scanf("%d",&k);
	bfs(k);
	printf("\n\n深度优先遍历：\n请输入遍历出发点序号i：");
	scanf("%d",&i);
	visit();
	DFS(i);
}
