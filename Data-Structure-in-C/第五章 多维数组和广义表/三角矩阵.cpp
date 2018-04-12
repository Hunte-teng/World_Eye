#include<iostream.h>
#define N 5
void A()
{
	int sa[N*(N+1)/2+1];
	int i,j,k=0,m=0;
	cout<<"请输入下三角矩阵要存入到数组中的数字："<<endl;
	for(i=1;i<=N;i++)
	{
		cout<<"请输入矩阵第"<<i<<"行要存入数组中的数字（"<<i<<"个数字）：";
		for(j=0;j<i;j++)	 
		    cin>>sa[k++];
	}
    cout<<"请输入矩阵中的重复元素：";
	cin>>sa[k];
	cout<<"\n下三角矩阵的为："<<endl;
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