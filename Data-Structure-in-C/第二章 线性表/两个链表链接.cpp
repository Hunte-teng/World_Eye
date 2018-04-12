#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} linklist;

/********����������*********/
linklist *CREATLISTR()
{
	char ch;
	linklist *head,*s,*r;
	head=(linklist *)malloc(sizeof(linklist));
	r=head;
	ch=getchar();
	while(ch!='#')
	{
		s=(linklist *)malloc(sizeof(linklist));
		s->data=ch;
		r->next=s;       //�½������β
		r=s;             //βָ��rָ���µı�β
		ch=getchar();
	}
	r->next=head;
	return r;
}

/*********����*********/
linklist *CONNECT(linklist *ra,linklist *rb)
{
	linklist *p;
	p=ra->next;
	ra->next=rb->next->next;
    free(rb->next);
	rb->next=p;
	return rb;
}

/*******���*******/
void print(linklist *rb)
{
	linklist *p;
	p=rb->next->next;
	while(p!=rb->next)
	{
		printf("%c",p->data);
		p=p->next;
	}
}

void main()
{
	linklist *ra;
	linklist *rb;
	printf("�������ַ��ԡ�#������  ra��");
	ra=CREATLISTR();
	printf("�������ַ��ԡ�#������  rb��");
	getchar();
	rb=CREATLISTR();
	rb=CONNECT(ra,rb);
	print(rb);
	printf("\n");
}
