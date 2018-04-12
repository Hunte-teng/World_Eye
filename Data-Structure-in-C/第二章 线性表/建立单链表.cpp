#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} linklist;

linklist *head;

/********建立单链表*********/
linklist *CREATLISTR()
{
	char ch;
	linklist *head,*s,*r;
	head=(linklist *)malloc(sizeof(linklist));
	r=head;
	printf("请输入字符以“#”结束：");
	scanf("%c",&ch);
	while(ch!='#')
	{
		s=(linklist *)malloc(sizeof(linklist));
		s->data=ch;
		r->next=s;       //新结点插入表尾
		r=s;             //尾指针r指向新的表尾
	    scanf("%c",&ch);
	}
	r->next=NULL;
	return head;
}

/*********输出单链表*********/
void print(linklist *head)
{
	linklist *p;
	p=head->next;
	while(p)
	{
		printf("%c ",(*p).data);
		p=p->next;
	}
}

/*********按序号查找**********/	
linklist *GET(linklist *head,int i)
{
	int j;
	linklist *p;
	p=head;  j=0;     //从头结点开始扫描
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;     //扫描下一个结点
		j++;           //已扫描结点计数器
	}
	if(i==j)
	{
		printf("找到了第i个结点：");
		printf("%c\n",p->data);
		return p;      //找到了第i个结点
	}
	else 
	{
		printf("找不到");
		printf("\n");
		return NULL;   //找不到，i<=0或i>n
	}
}

/********按值查找********/
void LOCATE(linklist *head,datatype key)
{
	linklist *p;
	p=head->next;      //从开始结点比较
	while(p!=NULL)
	    if(p->data!=key)
			p=p->next;      //没找到，继续循环
		else
		{
			printf("找到了");
			printf("\n");
			printf("%c",p->data);
			break;          //找到结点key,退出循环
		}
	if(p==NULL)
		printf("无此字符！");
	 //return p;
}

/*******定位********/
linklist *GET1(linklist *head,int i)
{
	int j;
	linklist *p;
	p=head;  j=0;     //从头结点开始扫描
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;     //扫描下一个结点
		j++;           //已扫描结点计数器
	}
	if(i==j)
		return p;      //找到了第i个结点
	else 
		return NULL;   //找不到，i<=0或i>n
}

/********插入*********/
void INSERTAFIER(linklist *p,datatype x)
{
	linklist *s;
	s=(linklist *)malloc(sizeof(linklist));
	s->data=x;
	s->next=p->next;
	p->next=s;
}

/*******删除********/
void DELETEAFTER(linklist *p)
{
	linklist *r;
	r=p->next;
	p->next=r->next;
	free(r);
}

/*******菜单********/
 void menu()
{
	 printf("***********菜单**************\n");
	printf("1、创建单链表   2、输出单链表\n");
	printf("3、按序号查找   4、按值查找\n");
	printf("5、插入         6、删除\n");
	printf("		0、退出\n");
	printf("*****************************\n");
	printf("请输入功能选项号0~6：");
}

void main()
{
	linklist *p;
	int a,i,i1,x1;
	datatype key1,key2;
	while(1)
	{
		system("cls");
		menu();
	    scanf("%d",&a);
		switch(a)
		{
 	    case 1:head=CREATLISTR();flushall();getchar();break;
	    case 2:print(head);flushall();getchar();break;
	    case 3:printf("请输入i：");scanf("%d",&i);GET(head,i+1);flushall();getchar();break;
        case 4:printf("请输入key1：");flushall();scanf("%c",&key1);LOCATE(head,key1);flushall();getchar();break;
	    case 5:printf("请输入x1,key2《形式为（x1,key2）》：");scanf("%d,%c",&x1,&key2);p=GET1(head,x1);INSERTAFIER(p,key2);print(head);flushall();getchar();break;
	    case 6:printf("请输入i1：");scanf("%d",&i1);p=GET1(head,i1);DELETEAFTER(p);print(head);flushall();getchar();break;
	    case 0:printf("退出\n");
		        exit(0);
		}	
	}
}
