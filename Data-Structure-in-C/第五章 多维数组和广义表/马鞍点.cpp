#include<iostream.h>
#include<stdlib.h>
#include<time.h> 
#include<stdio.h>
#define M 4    //����
#define N 4    //����
void creat1(int A[M][N])
{
	int i,j;
	cout<<"������"<<M<<"��"<<N<<"�о���"<<endl;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			cin>>A[i][j];
}
void creat2(int A[M][N])
{
	int i,j,k,m=0;
	cout<<"�������"<<M<<"��"<<N<<"�о���"<<endl;
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
					cout<<"�к�:"<<i+1<<" "<<"�к�:"<<s[j]+1<<" ";
					cout<<"ֵ:"<<A[i][s[j]]<<" "<<endl;
				}
			}
		}
	}
		if(count==0)
			cout<<"û������"<<endl;
		else
		{
			cout<<"��"<<count<<"������"<<endl;
			
		}
}
void menu()
{
	cout<<"***********�˵�**********"<<endl;
	cout<<"   1�������������"<<endl;
	cout<<"   2��ϵͳ����������"<<endl;
	cout<<"   3���������"<<endl;
	cout<<"   0���˳�"<<endl;
	cout<<"*************************"<<endl;
	cout<<"�����빦��ѡ���0~3��";
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
	    case 0:cout<<"�˳�";
		       exit(0);
		}
	}
}		
