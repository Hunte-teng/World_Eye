#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct linknode
{
	char data;
	struct linknode *next;
} linkstring;
linkstring *X,*Y;
linkstring *INDEXL(linkstring *X,linkstring *Y)
{
	linkstring *first,*sptr,*tptr;
	sptr=X->next;
	first=Y->next;
	tptr=first;
	while(sptr!=NULL&&tptr!=NULL)
	{
		
			if(sptr->data==tptr->data)
			{
				tptr=first;
				sptr=sptr->next;
			}
			else
				tptr=tptr->next;
		
	}
	if(tptr==NULL)
		return(sptr);
	else
		return(NULL);
}
linkstring *CREAT(linkstring *head)
{
	linkstring *r,*s;
	char c;
	head=(linkstring *)malloc(sizeof(linkstring));
	r=head;
	cin>>c;
	while(c!='#')
	{
        s=(linkstring *)malloc(sizeof(linkstring));
		s->data=c;
		r->next=s;
		r=s;
		cin>>c;
	}
	r->next=NULL;
	return head;
}

void main()
{
	cout<<"����������X�ԡ�#��������";
	X=CREAT(X);
	cout<<"����������Y�ԡ�#��������";
	Y=CREAT(Y);
	if(INDEXL(X,Y)==NULL)
		cout<<"X�в�������Y�в�ͬ���ַ�"<<endl;
	else
		cout<<"X�е�һ������Y�г��ֵ��ַ���"<<INDEXL(X,Y)->data<<endl;
}
