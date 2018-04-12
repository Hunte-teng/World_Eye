#include<iostream.h>
#include<stdlib.h>
#include<time.h> 
#include<stdio.h>
#define M 4    //行数
#define N 4    //列数
void creat1(int A[M][N])
{
	int i,j;
	cout<<"请输入"<<M<<"行"<<N<<"列矩阵："<<endl;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			cin>>A[i][j];
}
void creat2(int A[M][N])
{
	int i,j,k,m=0;
	cout<<"随机产生"<<M<<"行"<<N<<"列矩阵："<<endl;
	srand((unsigned int)time(NULL));
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
		{
			k=rand()%100+9;
			A[i][j]=k;
			m++;
			cout<<A[i][j]<<" ";
			if(m%N==0)
				cout<<endl;
		}
}
void maandian(int A[M][N])
{
	int i,j,c,k,m,count=0,s[M*N];
	for(i=0;i<M;i++)
	{
		m=A[i][0];
		c=1;s[1]=0;
		for(j=1;j<N;j++)
		{
			if(A[i][j]<m)
			{
				m=A[i][j];
				c=1;
				s[1]=j;
			}
			else if(A[i][j]==m)
			{
				c++;
				s[c]=j;
			}
		}
		for(j=1;j<=c;j++)
		{
			k=0;
			while(k<M&&A[i][s[j]]>=A[k][s[j]])
			{
				k++;
				if(k>=M)
				{
					count++;
					cout<<"行号:"<<i+1<<" "<<"列号:"<<s[j]+1<<" ";
					cout<<"值:"<<A[i][s[j]]<<" "<<endl;
				}
			}
		}
	}
		if(count==0)
			cout<<"没有马鞍点"<<endl;
		else
		{
			cout<<"有"<<count<<"个马鞍点"<<endl;
			
		}
}
void menu()
{
	cout<<"***********菜单**********"<<endl;
	cout<<"   1、键盘输入矩阵"<<endl;
	cout<<"   2、系统随机输入矩阵"<<endl;
	cout<<"   3、输出马鞍点"<<endl;
	cout<<"   0、退出"<<endl;
	cout<<"*************************"<<endl;
	cout<<"请输入功能选项号0~3：";
}
void main()
{
	int A[M][N];
    int a;
    while(1)
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
		case 1:creat1(A);flushall();getchar();break;
        case 2:creat2(A);flushall();getchar();break;
        case 3:maandian(A);flushall();getchar();break;
	    case 0:cout<<"退出";
		       exit(0);
		}
	}
}		
