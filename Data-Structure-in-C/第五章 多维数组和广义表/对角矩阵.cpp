#include<iostream.h>
#define N 5
void main()
{
	int sa[3*N-2+1];
	int i,j,k=0,m=0;
	cout<<"��ѶԽǾ���ķ����������뵽�����У�"<<endl;
	for(i=1;i<=N;i++)
	{
		
		if(i==1||i==N)
		{
			cout<<"����������"<<i<<"�еķ������֣�2�����֣���";
			for(j=0;j<2;j++)
				cin>>sa[k++];
		}
		else
		{
			cout<<"����������"<<i<<"�еķ������֣�3�����֣���";
			for(j=0;j<3;j++)	 
		        cin>>sa[k++];
		}
	}
    sa[k]=0;
	cout<<"\n�ԽǾ����Ϊ��"<<endl;
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			if(i-1==j)
				cout<<sa[3*i-1+0]<<" ";
			else if(i==j)
				     cout<<sa[3*i-1+1]<<" ";
			     else if(i+1==j)
					      cout<<sa[3*i-1+2]<<" ";
				      else
						  cout<<'0'<<" ";
			m++;
			if(m%5==0)
				cout<<endl;
		}
}