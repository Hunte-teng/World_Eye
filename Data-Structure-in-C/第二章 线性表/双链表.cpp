#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct dnode
{
	datatype data;
	struct dnode *prior,*next;
} dlinklist;
dlinklist *head;

/******双链表的建立********/
dlinklist *CREATLISTR()
{
	datatype a;
	dlinklist *s,*r;
	head=(dlinklist *)malloc(sizeof(dlinklist));
	head->next=NULL;
	head->prior=NULL;
    r=head;
	printf("请输入字符以“#”结束：");
	scanf("%c",&a);
	while(a!='#')
	{
		s=(dlinklist *)malloc(sizeof(dlinklist));
		s->data=a;
		r->next=s;
		s->prior=r;
		r=s;
		scanf("%c",&a);
	}
	r->next=head;
    return head;
}

/*********输出双链表*********/
void print(dlinklist *head)
{
	dlinklist *p;
	p=head->next;
	while(p!=head)
	{
		printf("%c ",(*p).data);
		p=p->next;
	}
}

/********按值查找*******/
dlinklist *LOCATE(dlinklist *head,datatype key)
{
	dlinklist *p;
	p=head->next;      //从开始结点比较
	while(p!=head)
	    if(p->data!=key)
			p=p->next;      //没找到，继续循环
		else   break;          //找到结点key,退出循环
	 return p;
}

/********双链表的前插*********/
void DINSERTBEFORE(dlinklist *p,datatype x)
{
	dlinklist *s;
	s=(dlinklist *)malloc(sizeof(dlinklist));
	s->data=x;
	s->prior=p->prior;
	s->next=p;
	p->prior->next=s;
	p->prior=s;
}

/********双链表的删除********/
void DELETENODEp(dlinklist *p)
{
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
}

/*******菜单********/
 void menu()
{
	 printf("***********菜单**************\n");
	printf("1、创建双链表   2、输出双链表\n");
	printf("3、插入         4、删除\n");
	printf("	0、退出\n");
	printf("*****************************\n");
	printf("请输入功能选项号0~4：");
}

void main()
{
    int a;
	dlinklist *p;
	datatype x,key,n;
	while(1)
	{
		system("cls");
		menu();
	    scanf("%d",&a);
		switch(a)
		{
 	    case 1:head=CREATLISTR();flushall();getchar();break;
	    case 2:print(head);flushall();getchar();break;
	    case 3:printf("将值为x的新结点插入到值为key的结点之前，请输入x,key：");
			   getchar();
	           scanf("%c %c",&x,&key);
	           p=LOCATE(head,key);
	           DINSERTBEFORE(p,x);
	           printf("输出插入后的链表：");
	           print(head);
			   flushall();
			   getchar();
			   break;
	    case 4:printf("删除值为n的结点，请输入n：");
			   getchar();
	           scanf("%c",&n);
	           p=LOCATE(head,n);
               DELETENODEp(p);
	           printf("输出删除后的链表:");
               print(head);
			   flushall();
			   getchar();
			   break;
	    case 0:printf("退出\n");
		        exit(0);
		}	
	}
}


