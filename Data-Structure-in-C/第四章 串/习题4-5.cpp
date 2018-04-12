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
	cout<<"请输入链串X以“#”结束：";
	X=CREAT(X);
	cout<<"请输入链串Y以“#”结束：";
	Y=CREAT(Y);
	if(INDEXL(X,Y)==NULL)
		cout<<"X中不存在与Y中不同的字符"<<endl;
	else
		cout<<"X中第一个不在Y中出现的字符："<<INDEXL(X,Y)->data<<endl;
}
