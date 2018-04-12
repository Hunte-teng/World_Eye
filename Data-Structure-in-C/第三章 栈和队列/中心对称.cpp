#include<iostream.h>
#include<stdlib.h>
#define maxsize 64
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} linklist;
linklist *head;

typedef struct
{
	datatype data[maxsize];
    int top;
} seqstack;
seqstack *s;

/********����������*********/
linklist *CREATLISTR()
{
	char ch;
	linklist *head,*s,*r;
	head=(linklist *)malloc(sizeof(linklist));
	r=head;
	cout<<"�������ַ��ԡ�#��������";
	cin>>ch;
	while(ch!='#')
	{
		s=(linklist *)malloc(sizeof(linklist));
		s->data=ch;
		r->next=s;       //�½������β
		r=s;             //βָ��rָ���µı�β
	    cin>>ch;
	}
	r->next=NULL;
	return head;
}
/*********���������*********/
void print(linklist *head)
{
	linklist *p;
	p=head->next;
	while(p)
	{
		cout<<(*p).data;
		p=p->next;
	}
}

int LENGTH(linklist *head)
{
	int n=0;
	linklist *p;
	p=head->next;
	while(p)
	{
		n++;
		p=p->next;
	}
	return n;
}

//�ÿ�ջ
void SETNULL(seqstack *s)
{
	s->top=-1;
}
//�п�ջ
int EMPTY(seqstack *s)
{
	if(s->top>=0)
        return 0;
    else 
		return 1;
}
//��ջ
seqstack *PUSH(seqstack *s,datatype x)
{
	if(s->top==maxsize-1)
	{
		cout<<"���磡";
        return NULL;
	}
    else
	{
        s->top++;
        s->data[s->top]=x;
	}
    return s;
}
//��ջ
datatype POP(seqstack *s)
{
	if(EMPTY(s))
	{
        cout<<"���磡";
        return NULL;
	}
    else
	{
        s->top--;
        return(s->data[s->top+1]);
	}
}
//ȡջ��
datatype TOP(seqstack *s)
{
	if(EMPTY(s))
	{
		cout<<"��ջ��";
        return NULL;
	}
    else
        return(s->data[s->top]);
}
//���ջ
void print1(seqstack *s)
{
	int m;
	m=s->top;
	cout<<"ջ��Ԫ��Ϊ��";
    for(;s->top>=0;s->top--)
        cout<<s->data[s->top];
    s->top=m;
}
//�ж�
seqstack *dc(seqstack *s,linklist *head)
{
	linklist *p,*q;
    p=head->next;
	int n=LENGTH(head)/2;
	char c;
	while(n>0)
	{
	    n--;c=p->data;
        s=PUSH(s,c);
        p=p->next;
	}
    //print1(s);
	if(LENGTH(head)%2==0)
    while(p)
	{
		if(p->data==TOP(s))
		{
		    p=p->next;
		    POP(s);
		}
		else
			break;
	}
	else
	{
		q=p->next;
        while(q)
		{
		
		if(q->data==TOP(s))
		{   
			q=q->next;
		    POP(s);
		}
		else
            break;
		}
	}
	return s;
}

void main()
{
	s=(seqstack *)malloc(sizeof(seqstack));
	SETNULL(s);
	head=CREATLISTR();
	print(head);
	cout<<endl;
	s=dc(s,head);
	if(EMPTY(s)==1)
		cout<<"���ĶԳ�"<<endl;
	else
		cout<<"�������ĶԳ�"<<endl;
}

