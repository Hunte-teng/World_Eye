#include<iostream.h>
#define N 5
void A()
{
	int sa[N*(N+1)/2+1];
	int i,j,k=0,m=0;
	cout<<"�����������Ǿ���Ҫ���뵽�����е����֣�"<<endl;
	for(i=1;i<=N;i++)
	{
		cout<<"����������"<<i<<"��Ҫ���������е����֣�"<<i<<"�����֣���";
		for(j=0;j<i;j++)	 
		    cin>>sa[k++];
	}
    cout<<"����������е��ظ�Ԫ�أ�";
	cin>>sa[k];
	cout<<"\n�����Ǿ����Ϊ��"<<endl;
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(i>=j)
				cout<<sa[i*(i+1)/2+j]<<" ";
			else
				cout<<sa[N*(N+1)/2]<<" ";
			m++;
			if(m%N==0)
				cout<<endl;
		}
}

void main()
{
	A();
}