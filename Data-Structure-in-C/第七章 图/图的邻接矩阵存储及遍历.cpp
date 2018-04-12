#include<stdio.h>
#include<stdlib.h>
#define n 5   //ͼ�Ķ�����
#define e 8   //ͼ�ı���
#define maxsize 20
typedef int datatype;
typedef char vextype;    //�������������
typedef float adjtype;   //Ȩֵ����
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
//�ÿն�
void SETNULL(seqstack *sq)
{
	sq->front=maxsize-1;
    sq->rear=maxsize-1;
}
//�жӿ�
int EMPTY(seqstack *sq)
{
	if(sq->rear==sq->front)
        return 1;
    else 
		return 0;
}
//���
seqstack *ENQUEUE(seqstack *sq,datatype x)
{
	if(sq->front==(sq->rear+1)%maxsize)
	{
		printf("�������磡");
        return NULL;
	}
    else
	{
        sq->rear=(sq->rear+1)%maxsize;
        sq->data[sq->rear]=x;
	}
    return sq;
}
//����
datatype DEQUEUE(seqstack *sq)
{
	if(EMPTY(sq))
	{
        printf("�ӿ����磡");
        return NULL;
	}
    else
	{
        sq->front=(sq->front+1)%maxsize;
        return(sq->data[sq->front]);
	}
}
void creatgraph(graph *ga)    //������������
{
	int i,j,k;
	float w;
    printf("�����붥����Ϣ�����������\n");
	printf("�������%d�����㣺",n);
	for(i=0;i<n;i++)
	{
		ga->vexs[i]=getchar();  //���붥����Ϣ�����������
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ga->arcs[i][j]=0;    //�ڽӾ����ʼ��
	printf("������ͼ��%d���ߣ�\n",e);
	for(k=0;k<e;k++)         //����e����
	{
		printf("������ĺ�������i,j��i,j����");
		scanf("%d%d",&i,&j); 
		ga->arcs[i][j]=1;
		ga->arcs[j][i]=1;
		//printf("������ĺ�������i,j,��Ȩֵw��i,j,w����");
		//scanf("%d%d%f",&i,&j,&w);        //����ߣ�vi,vj���ϵ�Ȩw
		//ga->arcs[i][j]=w;
		//ga->arcs[j][i]=w;
	}
}
void output(graph *ga)
{
	int i,j,m=0;
	printf("\nͼ���ڽӾ���\n");
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
//��������ʼ��Ϊ0
void visit()
{
	for(int i=0;i<n;i++)
		visited[i]=0;
}
//������ȱ���
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
//������ȱ���
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
	printf("������ȱ�����\n������������������k��");
	scanf("%d",&k);
	bfs(k);
	printf("\n\n������ȱ�����\n������������������i��");
	scanf("%d",&i);
	visit();
	DFS(i);
}
