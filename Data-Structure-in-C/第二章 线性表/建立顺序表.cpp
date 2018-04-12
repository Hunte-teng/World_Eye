#include<stdio.h>
#include<stdlib.h>
#define  maxsize  20
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int last;
} sequenlist;

/**********�ÿձ�********/
void SETNULL(sequenlist *L)
{
	L->last=0;
}

/*********����˳���********/
void CREAT(sequenlist *L)
{
	int i=0;
	L->last=0;
    printf("������������0����:");
	scanf("%d",&L->data[i]);
	while(L->data[i]!=0)
	{
		
		L->last++;
		i++;
		scanf("%d",&L->data[i]);
	}
}

/********���********/
void LENGTH(sequenlist *L)
{
	printf("%d\n",L->last);
}

/**********���˳���********/
void print(sequenlist *L)
{
	for(int i=0;i<L->last;i++)
		printf("%d ",L->data[i]);
	printf("\n");
}

/*********��������********/
void found1(sequenlist *L)
{
	int i;
	printf("���������i��");
	scanf("%d",&i);
	printf("%d\n",L->data[i-1]);
}

/**********��ֵ����********/
void found2(sequenlist *L)
{
	int i=0;
	datatype x;
	printf("������Ҫ���ҵ�ֵx��");
	scanf("%d",&x);
	while(L->data[i]!=x&&i<=L->last)
          i++;
	if(L->data[i]==x)
		printf("%d\n",i+1);
	else
		printf("�޴�����\n");
}

/*******�滻*********/
void exchange(sequenlist *L)
{
	int i,m;
	printf("������Ҫ�滻������λ�ú��滻�������i m����");
	scanf("%d %d",&i,&m);
	L->data[i-1]=m;
}

/**********����********/
int INSERT(sequenlist *L)
{
	int n;
	datatype x;
    printf("������Ҫ���������λ�ú����֣�n x����");
	scanf("%d %d",&n,&x);
	int j;
	if(((*L).last)>=maxsize-1)
	{
		printf("overflow");
		return NULL;             //��ռ����             
	}
    else  
		if((n<1)||(n>((*L).last)+1))
		{
			printf("error");
			return NULL;          //�Ƿ�λ��
		}
		else
		{
			for(j=(*L).last;j>=n-1;j--)
				(*L).data[j+1]=(*L).data[j];
			(*L).data[n-1]=x;
			(*L).last=(*L).last+1;
		}
		return(1);
}

/*******ɾ��********/
int DELETE(sequenlist *L,int m)
{
	int j;
	if((m<1)||(m>(*L).last+1))
	{
		printf("error");
		return NULL;
	}
	else
	{
		for(j=m;j<=(*L).last;j++)
			(*L).data[j-1]=(*L).data[j];
		(*L).last--;
	}
	return(1);
}

int GET(sequenlist *L,int i)
{
	return(L->data[i]);
}

/********���������********/
int PURGE(sequenlist *L)
{
	int i=0,j,x,y;
	while(i<L->last)
	{
		x=GET(L,i);
		j=i+1;
		while(j<=L->last)
		{
			y=GET(L,j);
			if(x==y)
				DELETE(L,j);
			else  
				j++;
		}
		i++;
	}
	return(1);
}

/*******�˵�********/
 void menu()
{
	 printf("***********�˵�**************\n");
	printf("1������˳���   2�����˳���\n");
	printf("3����������   4����ֵ����\n");
	printf("5������         6��ɾ��\n");
	printf("7�����         8���滻\n");
	printf("9�����		0���˳�\n");
	printf("*****************************\n");
	printf("�����빦��ѡ���1~8��");
}

void main()
{
    sequenlist L;    //����˳���L
	SETNULL(&L);
	int a,m;
	while(1)
	{
		system("cls");
		menu();
	    scanf("%d",&a);
		switch(a)
		{
 	    case 1:CREAT(&L);flushall();getchar();break;
	    case 2:print(&L);flushall();getchar();break;
	    case 3:found1(&L);flushall();getchar();break;
        case 4:found2(&L);flushall();getchar();break;
	    case 5:INSERT(&L);print(&L);flushall();getchar();break;
	    case 6:printf("������Ҫɾ��������λ��m��");scanf("%d",&m);DELETE(&L,m);print(&L);flushall();getchar();break;
	    case 7:PURGE(&L);print(&L);flushall();getchar();break;
	    case 8:exchange(&L);print(&L);flushall();getchar();break;
		case 9:LENGTH(&L);flushall();getchar();break;
	    case 0:printf("�˳�");
		        exit(0);
		}	
	}
}
