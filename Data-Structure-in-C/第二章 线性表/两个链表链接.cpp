#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} linklist;

/********建立单链表*********/
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
		r->next=s;       //新结点插入表尾
		r=s;             //尾指针r指向新的表尾
		ch=getchar();
	}
	r->next=head;
	return r;
}

/*********链接*********/
linklist *CONNECT(linklist *ra,linklist *rb)
{
	linklist *p;
	p=ra->next;
	ra->next=rb->next->next;
    free(rb->next);
	rb->next=p;
	return rb;
}

/*******输出*******/
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
	printf("请输入字符以“#”结束  ra：");
	ra=CREATLISTR();
	printf("请输入字符以“#”结束  rb：");
	getchar();
	rb=CREATLISTR();
	rb=CONNECT(ra,rb);
	print(rb);
	printf("\n");
}
