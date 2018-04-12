#include<iostream.h>
#define N 3
void main()
{
	int sa[N*(N+1)/2];
	int i,j,k=0,m=0;
	cout<<"请把对称矩阵的一半输入到数组中："<<endl;
	for(i=1;i<=N;i++)
	{
		cout<<"请输入矩阵第"<<i<<"行要存入数组中的数字（"<<i<<"个数字）：";
		for(j=0;j<i;j++)	 
		    cin>>sa[k++];
	}
	cout<<"\n对称矩阵的为："<<endl;
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