#include<stdio.h>
#include<stdlib.h>
#define n 6   //ͼ�Ķ�����
#define e 10   //ͼ�ı���
typedef char vextype;    //�������������
typedef float adjtype;   //Ȩֵ����
typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
} graph;
graph *ga;
typedef struct
{
	int fromvex,endvex;    //�ߵ������յ�
	float length;          //�ߵ�Ȩֵ
} edge;
edge T[n-1];
void creatgraph()    //������������
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
		printf("������ĺ�������i,j,��Ȩֵw��i,j,w����");
		scanf("%d%d%f",&i,&j,&w);        //����ߣ�vi,vj���ϵ�Ȩw
		ga->arcs[i][j]=w;
		ga->arcs[j][i]=w;
	}
}
void prim()
{
	int j,k,m,v,min,max=10000;
	float d;
	edge b;
	for(j=1;j<n;j++)     //�����ʼ��ѡ�ϱ߼�
	{
		T[j-1].fromvex=1;      //����1�ǵ�һ���������еĺ��
		T[j-1].endvex=j+1;
		T[j-1].length=ga->arcs[0][j];
	}
	for(k=0;k<n-1;k++)          //���k����
	{
		min=max;
		for(j=k;j<n-1;j++)       //�ں�ѡ�ϱ߼���������ϱ�
			if(T[j].length<min)
			{
				min=T[j].length;
				m=j;
			}            //T[m]�ǵ�ǰ����ϱ�
			b=T[m];
			T[m]=T[k];
			T[k]=b;       //T[k]��T[m]������T[k]�ǵ�K����ɫ����
			v=T[k].endvex;    //v���º��
			for(j=k+1;j<n-1;j++)     //������ѡ�ϱ߼�
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
//�����С������
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


