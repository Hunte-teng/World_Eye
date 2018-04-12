#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct dnode
{
	datatype data;
	struct dnode *prior,*next;
} dlinklist;
dlinklist *head;

/******˫����Ľ���********/
dlinklist *CREATLISTR()
{
	datatype a;
	dlinklist *s,*r;
	head=(dlinklist *)malloc(sizeof(dlinklist));
	head->next=NULL;
	head->prior=NULL;
    r=head;
	printf("�������ַ��ԡ�#��������");
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

/*********���˫����*********/
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

/********��ֵ����*******/
dlinklist *LOCATE(dlinklist *head,datatype key)
{
	dlinklist *p;
	p=head->next;      //�ӿ�ʼ���Ƚ�
	while(p!=head)
	    if(p->data!=key)
			p=p->next;      //û�ҵ�������ѭ��
		else   break;          //�ҵ����key,�˳�ѭ��
	 return p;
}

/********˫�����ǰ��*********/
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

/********˫�����ɾ��********/
void DELETENODEp(dlinklist *p)
{
	p->prior->next=p->next;
	p->next->prior=p->prior;
	free(p);
}

/*******�˵�********/
 void menu()
{
	 printf("***********�˵�**************\n");
	printf("1������˫����   2�����˫����\n");
	printf("3������         4��ɾ��\n");
	printf("	0���˳�\n");
	printf("*****************************\n");
	printf("�����빦��ѡ���0~4��");
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
	    case 3:printf("��ֵΪx���½����뵽ֵΪkey�Ľ��֮ǰ��������x,key��");
			   getchar();
	           scanf("%c %c",&x,&key);
	           p=LOCATE(head,key);
	           DINSERTBEFORE(p,x);
	           printf("�������������");
	           print(head);
			   flushall();
			   getchar();
			   break;
	    case 4:printf("ɾ��ֵΪn�Ľ�㣬������n��");
			   getchar();
	           scanf("%c",&n);
	           p=LOCATE(head,n);
               DELETENODEp(p);
	           printf("���ɾ���������:");
               print(head);
			   flushall();
			   getchar();
			   break;
	    case 0:printf("�˳�\n");
		        exit(0);
		}	
	}
}


