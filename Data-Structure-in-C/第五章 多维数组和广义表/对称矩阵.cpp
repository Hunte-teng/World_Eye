#include<iostream.h>
#define N 3
void main()
{
	int sa[N*(N+1)/2];
	int i,j,k=0,m=0;
	cout<<"��ѶԳƾ����һ�����뵽�����У�"<<endl;
	for(i=1;i<=N;i++)
	{
		cout<<"����������"<<i<<"��Ҫ���������е����֣�"<<i<<"�����֣���";
		for(j=0;j<i;j++)	 
		    cin>>sa[k++];
	}
	cout<<"\n�Գƾ����Ϊ��"<<endl;
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(i>=j)
				cout<<sa[i*(i+1)/2+j]<<" ";
			else
				cout<<sa[j*(j+1)/2+i]<<" ";
			m++;
			if(m%N==0)
				cout<<endl;
		}
}