#include<iostream.h>
#include<stdlib.h>
typedef struct linknode
{
	char data;
	struct linknode *next;
} linkstring;
linkstring *S,*T;
linkstring *INDEXL(linkstring *S,linkstring *T)
{
	linkstring *first,*sptr,*tptr;
	first=S;
	sptr=first;
	tptr=T;
	while(sptr&&tptr)
		if(sptr->data==tptr->data)
		{
			sptr=sptr->next;
			tptr=tptr->next;
		}
		else
		{
			first=first->next;
			sptr=first;
			tptr=T;
		}
	if(tptr==NULL)
		return(first);
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
	cout<<"����������S�ԡ�#��������";
	S=CREAT(S);
	cout<<"����������T�ԡ�#��������";
	T=CREAT(T);
	if(INDEXL(S->next,T->next)==NULL)
		cout<<"ƥ��ʧ��"<<endl;
	else
		cout<<"ƥ��ɹ�"<<endl;
}
