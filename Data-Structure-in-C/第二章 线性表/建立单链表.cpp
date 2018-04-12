#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *next;
} linklist;

linklist *head;

/********����������*********/
linklist *CREATLISTR()
{
	char ch;
	linklist *head,*s,*r;
	head=(linklist *)malloc(sizeof(linklist));
	r=head;
	printf("�������ַ��ԡ�#��������");
	scanf("%c",&ch);
	while(ch!='#')
	{
		s=(linklist *)malloc(sizeof(linklist));
		s->data=ch;
		r->next=s;       //�½������β
		r=s;             //βָ��rָ���µı�β
	    scanf("%c",&ch);
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
		printf("%c ",(*p).data);
		p=p->next;
	}
}

/*********����Ų���**********/	
linklist *GET(linklist *head,int i)
{
	int j;
	linklist *p;
	p=head;  j=0;     //��ͷ��㿪ʼɨ��
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;     //ɨ����һ�����
		j++;           //��ɨ���������
	}
	if(i==j)
	{
		printf("�ҵ��˵�i����㣺");
		printf("%c\n",p->data);
		return p;      //�ҵ��˵�i�����
	}
	else 
	{
		printf("�Ҳ���");
		printf("\n");
		return NULL;   //�Ҳ�����i<=0��i>n
	}
}

/********��ֵ����********/
void LOCATE(linklist *head,datatype key)
{
	linklist *p;
	p=head->next;      //�ӿ�ʼ���Ƚ�
	while(p!=NULL)
	    if(p->data!=key)
			p=p->next;      //û�ҵ�������ѭ��
		else
		{
			printf("�ҵ���");
			printf("\n");
			printf("%c",p->data);
			break;          //�ҵ����key,�˳�ѭ��
		}
	if(p==NULL)
		printf("�޴��ַ���");
	 //return p;
}

/*******��λ********/
linklist *GET1(linklist *head,int i)
{
	int j;
	linklist *p;
	p=head;  j=0;     //��ͷ��㿪ʼɨ��
	while((p->next!=NULL)&&(j<i))
	{
		p=p->next;     //ɨ����һ�����
		j++;           //��ɨ���������
	}
	if(i==j)
		return p;      //�ҵ��˵�i�����
	else 
		return NULL;   //�Ҳ�����i<=0��i>n
}

/********����*********/
void INSERTAFIER(linklist *p,datatype x)
{
	linklist *s;
	s=(linklist *)malloc(sizeof(linklist));
	s->data=x;
	s->next=p->next;
	p->next=s;
}

/*******ɾ��********/
void DELETEAFTER(linklist *p)
{
	linklist *r;
	r=p->next;
	p->next=r->next;
	free(r);
}

/*******�˵�********/
 void menu()
{
	 printf("***********�˵�**************\n");
	printf("1������������   2�����������\n");
	printf("3������Ų���   4����ֵ����\n");
	printf("5������         6��ɾ��\n");
	printf("		0���˳�\n");
	printf("*****************************\n");
	printf("�����빦��ѡ���0~6��");
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
	    case 3:printf("������i��");scanf("%d",&i);GET(head,i+1);flushall();getchar();break;
        case 4:printf("������key1��");flushall();scanf("%c",&key1);LOCATE(head,key1);flushall();getchar();break;
	    case 5:printf("������x1,key2����ʽΪ��x1,key2������");scanf("%d,%c",&x1,&key2);p=GET1(head,x1);INSERTAFIER(p,key2);print(head);flushall();getchar();break;
	    case 6:printf("������i1��");scanf("%d",&i1);p=GET1(head,i1);DELETEAFTER(p);print(head);flushall();getchar();break;
	    case 0:printf("�˳�\n");
		        exit(0);
		}	
	}
}
