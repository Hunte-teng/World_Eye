#include<stdio.h>
#include<stdlib.h>
#define  n1  8
#define  n2  10
#define  t   3
typedef char datatype;
typedef struct
{
	int key;
	datatype other;
} rectype;
rectype R[n1];
rectype S[n2];
int d[t]={5,3,1};
/**********直接插入排序******/
void insertsort()
{
	int i,j;
	for(i=2;i<=n1;i++)
	{
		R[0]=R[i];
		j=i-1;
		while(R[0].key<R[j].key)
			R[j+1]=R[j--];
		R[j+1]=R[0];
	}
}
/*******希尔排序******/
void shellsort()
{
	int i,j,k,h;
	rectype temp;
	k=0;
	do
	{
		h=d[k];
		for(i=h;i<n2;i++)
		{
			temp=S[i];
			j=i-h;
			while(temp.key<S[j].key)
			{
				S[j+h]=S[j];
				j=j-h;
			}
			S[j+h]=temp;
		}
		k++;
	}while(h!=1);
}
/*******起泡排序*******/
void bubblesort()
{
	int i,j,noswap;
	rectype temp;
	for(i=0;i<n1-1;i++)
	{
		noswap=1;
		for(j=n1-2;j>=i;j--)
			if(R[j+1].key<R[j].key)
			{
				temp=R[j+1];
				R[j+1]=R[j];
				R[j]=temp;
				noswap=0;
			}
			if(noswap)
				break;
	}
}
/********选择排序********/
void selectsort()
{
	int i,j,k;
	rectype temp;
	for(i=0;i<n1-1;i++)
	{
		k=i;
		for(j=i+1;j<n1;j++)
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
/*******快速排序*******/
int partition(rectype R[n1],int l,int h)
{
	int i,j;
	rectype temp;	
	i=l;
	j=h;
	temp=R[i];
	do
	{
		while((R[j].key>=temp.key)&&(i<j))
			j--;
		if(i<j)
			R[i++]=R[j];
		while((R[i].key<=temp.key)&&(i<j))
			i++;
		if(i<j)
			R[j--]=R[i];
	}while(i!=j);
	R[i]=temp;
	return i;
}
void quicksort(rectype R[n1],int s1,int t1)
{
	int i;
	if(s1<t1)
	{
		i=partition(R,s1,t1);
		quicksort(R,s1,i-1);
		quicksort(R,i+1,t1);
	}
}
/*******堆排序*******/
void sift(rectype R[n1],int i,int m)
{
	int j;
	rectype temp;
	temp=R[i];
	j=2*i;
	while(j<=m)
	{
		if((j<m)&&(R[j].key<R[j+1].key))
			j++;
		if(temp.key<R[j].key)
		{
			R[i]=R[j];
			i=j;
			j=2*i;
		}
		else
			break;
	}
	R[i]=temp;
}
void heapsort(rectype R[n1])
{
	int i;
	rectype temp;
	for(i=(n1)/2;i>=1;i--)
		sift(R,i,n1);
	for(i=n1;i>=1;i--)
	{
		temp=R[1];
		R[1]=R[i];
		R[i]=temp;
		sift(R,1,i-1);
	}
}
void menu()
{
	printf("-----------菜单-----------\n");
	printf("    1、直接插入排序\n");
	printf("    2、希尔排序\n");
	printf("    3、起泡排序\n");
	printf("    4、选择排序\n");
	printf("    5、快速排序\n");
	printf("    6、堆排序\n");
	printf("    7、退出\n");
	printf("请输入功能选项号：");
}
void main()
{
	int i,a;
	do
	{
		system("cls");
		menu();
		scanf("%d",&a);
		switch(a)
		{
		case 1:printf("请输入%d组记录的关键字和一个字符：\n",n1);
			   R[0].key=0;
			   R[0].other=' ';
	           for(i=1;i<=n1;i++)
			   {
		            scanf("%d %c",&R[i].key,&R[i].other);
		            getchar();
			   }
	           insertsort();
			   printf("\n排序结果：\n");
			   for(i=1;i<=n1;i++)
	            	printf("%d\t%c\n",R[i].key,R[i].other);
			   flushall();
			   getchar();
			   break;

		case 2:printf("请输入%d组记录的关键字和一个字符：\n",n2);
	           for(i=0;i<n2;i++)
			   {
		            scanf("%d %c",&S[i].key,&S[i].other);
		            getchar();
			   }
	           shellsort();
			   printf("\n排序结果：\n");
			   for(i=0;i<n2;i++)
	            	printf("%d\t%c\n",S[i].key,S[i].other);
			   flushall();
			   getchar();
			   break;

		case 3:printf("请输入%d组记录的关键字和一个字符：\n",n1);
	           for(i=0;i<n1;i++)
			   {
		            scanf("%d %c",&R[i].key,&R[i].other);
		            getchar();
			   }
	           bubblesort();
			   printf("\n排序结果：\n");
			   for(i=0;i<n1;i++)
	            	printf("%d\t%c\n",R[i].key,R[i].other);
			   flushall();
			   getchar();
			   break;

		case 4:printf("请输入%d组记录的关键字和一个字符：\n",n1);
	           for(i=0;i<n1;i++)
			   {
		            scanf("%d %c",&R[i].key,&R[i].other);
		            getchar();
			   }
	           selectsort();
			   printf("\n排序结果：\n");
			   for(i=0;i<n1;i++)
	            	printf("%d\t%c\n",R[i].key,R[i].other);
			   flushall();
			   getchar();
			   break;

		case 5:printf("请输入%d组记录的关键字和一个字符：\n",n1);
	           for(i=0;i<n1;i++)
			   {
		            scanf("%d %c",&R[i].key,&R[i].other);
		            getchar();
			   }
	           quicksort(R,0,n1-1);
			   printf("\n排序结果：\n");
			   for(i=0;i<n1;i++)
	            	printf("%d\t%c\n",R[i].key,R[i].other);
			   flushall();
			   getchar();
			   break;

	    case 6:printf("请输入%d组记录的关键字和一个字符：\n",n1);
	           for(i=1;i<=n1;i++)
			   {
		            scanf("%d %c",&R[i].key,&R[i].other);
		            getchar();
			   }
	           heapsort(R);
			   printf("\n排序结果：\n");
			   for(i=1;i<=n1;i++)
	            	printf("%d\t%c\n",R[i].key,R[i].other);
			   flushall();
			   getchar();
			   break;
		case 7:printf("退出！\n");exit(0);
		}
	}while(1);
}


	
