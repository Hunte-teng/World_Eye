#include<stdio.h>
#include<stdlib.h>
#define n 8
#define e 7
#define maxsize 20
typedef int datatype;
typedef char vextype;
typedef struct
{
	datatype data[maxsize];
    int front,rear;
} seqstack;
seqstack *Q;
typedef struct node
{
	int adjvex;
	struct node *next;
} edgenode;
typedef struct
{
	vextype vertex;
	edgenode *link;
} vexnode;
vexnode ga[n];
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
void creatadjlist(vexnode ga[],int x)
{
	int i,j;
	edgenode *s;
	printf("������%d�����㣺",n);
	for(i=0;i<n;i++)
	{
		ga[i].vertex=getchar();
		ga[i].link=NULL;
	}
	for(int k=0;k<e;k++)
	{
        printf("������%d���ߵĶ������ţ�i,j����",e);
		scanf("%d%d",&i,&j);
		s=(edgenode *)malloc(sizeof(edgenode));
		s->adjvex=j;
		s->next=ga[i].link;
		ga[i].link=s;
		s=(edgenode *)malloc(sizeof(edgenode));
		s->adjvex=i;
		s->next=ga[j].link;
		ga[j].link=s;
	}
}
//��������ʼ��Ϊ0
void visit()
{
	for(int i=0;i<n;i++)
		visited[i]=0;
}
//��ͨͼ��ȱ���
void bfsl(int k)
{
	int i;
	edgenode *p;	
	SETNULL(Q);
	visit();
	//printf("��ȱ�����");
	printf("%c ",ga[k].vertex);
	visited[k]=1;
	ENQUEUE(Q,k);
	while(!EMPTY(Q))
	{
		i=DEQUEUE(Q);
		p=ga[i].link;
		while(p!=NULL)
		{
			if(!visited[p->adjvex])
			{
				printf("%c ",ga[p->adjvex].vertex);
				visited[p->adjvex]=1;
				ENQUEUE(Q,p->adjvex);
			}
			p=p->next;
		}
	}
}
//������ȱ���
void DFSL(int i)
{
	//int j;
	edgenode *p;
	printf("node:%c\n",ga[i].vertex);
	visited[i]=1;
	p=ga[i].link;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
			DFSL(p->adjvex);
		p=p->next;
	}
}
//����ͨ������ȱ���
void TRAVER(vexnode ga[],int x)
{
	int i;
	printf("������ȱ�����\n������������������i��");
	scanf("%d",&i);
	visit();
	for(i=0;i<n;i++)
	{
		if(!visited[i])
			bfsl(i);
		printf("comp end\n");
	}
}
//����ͨ������ȱ���
void traver(vexnode ga[],int x)
{
	int i;
	printf("\n\n������ȱ�����\n������������������i��");
	scanf("%d",&i);
	visit();
	for(i=0;i<n;i++)
	{
		if(!visited[i])
			DFSL(i);
		printf("comp end\n");
	}
}
void main()
{
	Q=(seqstack *)malloc(sizeof(seqstack));
	SETNULL(Q);	
	creatadjlist(ga,n);	
	TRAVER(ga,n);
	traver(ga,n);
}