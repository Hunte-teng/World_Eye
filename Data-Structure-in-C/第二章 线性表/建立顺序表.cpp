#include<stdio.h>
#include<stdlib.h>
#define  maxsize  20
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int last;
} sequenlist;

/**********置空表********/
void SETNULL(sequenlist *L)
{
	L->last=0;
}

/*********建立顺序表********/
void CREAT(sequenlist *L)
{
	int i=0;
	L->last=0;
    printf("请输入数字以0结束:");
	scanf("%d",&L->data[i]);
	while(L->data[i]!=0)
	{
		
		L->last++;
		i++;
		scanf("%d",&L->data[i]);
	}
}

/********测表长********/
void LENGTH(sequenlist *L)
{
	printf("%d\n",L->last);
}

/**********输出顺序表********/
void print(sequenlist *L)
{
	for(int i=0;i<L->last;i++)
		printf("%d ",L->data[i]);
	printf("\n");
}

/*********按结点查找********/
void found1(sequenlist *L)
{
	int i;
	printf("请输入结点号i：");
	scanf("%d",&i);
	printf("%d\n",L->data[i-1]);
}

/**********按值查找********/
void found2(sequenlist *L)
{
	int i=0;
	datatype x;
	printf("请输入要查找的值x：");
	scanf("%d",&x);
	while(L->data[i]!=x&&i<=L->last)
          i++;
	if(L->data[i]==x)
		printf("%d\n",i+1);
	else
		printf("无此数！\n");
}

/*******替换*********/
void exchange(sequenlist *L)
{
	int i,m;
	printf("请输入要替换的数的位置和替换后的数（i m）：");
	scanf("%d %d",&i,&m);
	L->data[i-1]=m;
}

/**********插入********/
int INSERT(sequenlist *L)
{
	int n;
	datatype x;
    printf("请输入要插入的数的位置和数字（n x）：");
	scanf("%d %d",&n,&x);
	int j;
	if(((*L).last)>=maxsize-1)
	{
		printf("overflow");
		return NULL;             //表空间溢出             
	}
    else  
		if((n<1)||(n>((*L).last)+1))
		{
			printf("error");
			return NULL;          //非法位置
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

/*******删除********/
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

/********清除多余结点********/
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

/*******菜单********/
 void menu()
{
	 printf("***********菜单**************\n");
	printf("1、创建顺序表   2、输出顺序表\n");
	printf("3、按结点查找   4、按值查找\n");
	printf("5、插入         6、删除\n");
	printf("7、清除         8、替换\n");
	printf("9、测表长		0、退出\n");
	printf("*****************************\n");
	printf("请输入功能选项号1~8：");
}

void main()
{
    sequenlist L;    //建立顺序表L
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
	    case 6:printf("请输入要删除的数的位置m：");scanf("%d",&m);DELETE(&L,m);print(&L);flushall();getchar();break;
	    case 7:PURGE(&L);print(&L);flushall();getchar();break;
	    case 8:exchange(&L);print(&L);flushall();getchar();break;
		case 9:LENGTH(&L);flushall();getchar();break;
	    case 0:printf("退出");
		        exit(0);
		}	
	}
}
