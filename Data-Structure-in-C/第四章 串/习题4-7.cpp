#include<iostream.h>
#include<stdlib.h>
typedef struct linknode
{
	char data;
	struct linknode *next;
} linkstring;
linkstring *S,*T,*first,*sptr,*tptr,*l;
 
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
linkstring *INDEXL(linkstring *T,linkstring *first,linkstring *sptr,linkstring *tptr)
{
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


void REVERSE(linkstring *S,linkstring *l,linkstring *T)
{
	char sa[10];
    int i;
	linkstring *p,*q;
	p=T->next;
	q=S->next;
	for(i=0;p!=NULL;i++)
	{
		sa[i]=p->data;
		p=p->next;
	}
	for(i=i-1;i>=0;i--)
	{
		l->data=sa[i];
		l=l->next;
	}
	cout<<"ÄæÖÃºóµÄS£º";
	while(q!=NULL)
	{
		cout<<q->data<<" ";
		q=q->next;
	}
}
void main()
{
	cout<<"ÇëÊäÈëÁ´´®SÒÔ¡°#¡±½áÊø£º";
	S=CREAT(S);
	cout<<"ÇëÊäÈëÁ´´®TÒÔ¡°#¡±½áÊø£º";
	T=CREAT(T);
	first=S->next;
	sptr=first;
	tptr=T->next;
	l=INDEXL(T->next,first,sptr,tptr);
	if(l==NULL)
		cout<<"Æ¥ÅäÊ§°Ü"<<endl;
	else
	{
		cout<<"Æ¥Åä³É¹¦"<<endl;
        REVERSE(S,l,T);
	}
}