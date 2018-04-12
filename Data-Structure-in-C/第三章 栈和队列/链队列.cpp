#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;
    struct node *next;
} linkstack;
typedef struct
{
	linkstack *front,*rear;
} linkqueue;
linkqueue *q;
//�ÿն�
void SETNULL(linkqueue *q)
{
	q->front=(linkstack *)malloc(sizeof(linkstack));
	q->front->next=NULL;
	q->rear=q->front;
}
//�жӿ�
int EMPTY(linkqueue *q)
{
	if(q->front==q->rear)
        return 1;
    else 
		return 0;
}
//���
linkqueue *ENQUEUE(linkqueue *q,datatype x)
{
    q->rear->next=(linkstack *)malloc(sizeof(linkstack));     //�½�����β��
    q->rear=q->rear->next;                    //βָ��ָ���½��
    q->rear->data=x;                        //���½�㸳ֵ
    q->rear->next=NULL;
    return q;
}
//�����
linkqueue *input(linkqueue *q)
{
     datatype x;
	 cout<<"����������,���ּ��ÿո�������ԡ�0��������"<<endl;
     cin>>x;//scanf("%d",&x);
     while(x!=0)
     {
         q=ENQUEUE(q,x);
         cin>>x;//scanf("%d",&x);
     }
     return q;
}
//����
datatype DEQUEUE(linkqueue *q)
{
	linkstack *s;
    if(EMPTY(q))
	{
		cout<<"�ӿ�";
        return NULL;
	}
    else
	{
        s=q->front;                 //sָ��ͷ���
        q->front=q->front->next;   //ͷָ��ָ��ԭ��ͷ
        free(s);                   //�ͷ�ԭͷ���        
        return(q->front->data);     //����ԭ��ͷ����
	}
}
//ȡ��ͷ�������
datatype FRONT(linkqueue *q)
{
	if(EMPTY(q))
	{
		cout<<"���пգ�";
        return NULL;
	}
    else
        return(q->front->next->data);
}
//�����
void print(linkqueue *q)
{
	linkstack *m,*n;
	m=q->front;
	n=q->rear;
    while(q->front->next!=q->rear->next)
	{ 
		cout<<q->front->next->data<<" ";
        q->front=q->front->next;
	}
    q->front=m;
	q->rear=n;
	cout<<endl;
}
void menu()
{
	cout<<"***********�˵�**************"<<endl;
	cout<<"1���ÿն�       2���пն�"<<endl;
	cout<<"3��������       4�������"<<endl;
	cout<<"5�����         6������"<<endl;
	cout<<"7��ȡ��ͷԪ��   0���˳�"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"�����빦��ѡ���0~7��";
}
void main()
{
	q=(linkqueue *)malloc(sizeof(linkqueue));
    datatype x;
    int a;
    while(1)
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
		case 1:SETNULL(q);printf("�ÿնӳɹ���");flushall();getchar();break;
        case 2:if(EMPTY(q))
                   cout<<"�ǿնӣ�"<<endl;
               else
                   cout<<"���ǿնӣ�"<<endl;
	               flushall();getchar();
               break;
        case 3:q=input(q);
	           flushall();getchar();break;
        case 4:print(q);flushall();getchar();break;
        case 5:printf("������Ҫ���ӵ����֣�");
			   cin>>x;
               q=ENQUEUE(q,x);
               print(q);
               flushall();getchar();break;
        case 6:x=DEQUEUE(q);
               cout<<"��ɾֵ��:"<<x<<endl;flushall();getchar();break;
        case 7:x=FRONT(q);
               cout<<"��ͷԪ����:"<<x<<endl;flushall();getchar();break;
	    case 0:cout<<"�˳�\n";
		       exit(0);
		}
	}
}