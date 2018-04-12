#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
#define maxsize 20
typedef struct
{
	datatype data[maxsize];
    int front,rear;
} seqstack;
seqstack *sq;
//�ÿն�
void SETNULL(seqstack *sq)
{
	sq->front=maxsize-1;
    sq->rear=maxsize-1;
}
//�жӿ�
int EMPTY(seqstack *sq)
{
	if(sq->rear==sq->front)
        return 1;
    else 
		return 0;
}
//���
seqstack *ENQUEUE(seqstack *sq,datatype x)
{
	if(sq->front==(sq->rear+1)%maxsize)
	{
		cout<<"�������磡";
        return NULL;
	}
    else
	{
        sq->rear=(sq->rear+1)%maxsize;
        sq->data[sq->rear]=x;
	}
    return sq;
}
//����ջ
seqstack *input(seqstack *sq)
{
	cout<<"���������֣����ּ��ÿո�������ԡ�0��������"<<endl;
    datatype x;
    cin>>x;
    while(x!=0)
	{
       sq=ENQUEUE(sq,x);
       cin>>x;
	}
    return(sq);
}

//����
datatype DEQUEUE(seqstack *sq)
{
	if(EMPTY(sq))
	{
        cout<<"�ӿ����磡";
        return NULL;
	}
    else
	{
        sq->front=(sq->front+1)%maxsize;
        return(sq->data[sq->front]);
	}
}
//ȡ��ͷԪ��
datatype FRONT(seqstack *sq)
{
	if(EMPTY(sq))
	{
		cout<<"��ջ��";
        return NULL;
	}
    else
        return(sq->data[(sq->front+1)%maxsize]);
}
//�����
void print(seqstack *sq)
{
	int i;
	for(i=(sq->front+1)%maxsize;i<(sq->rear+1)%maxsize;i++)
		cout<<sq->data[i]<<" ";
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
	sq=(seqstack*)malloc(sizeof(seqstack));
	sq->front=maxsize-1;
    sq->rear=maxsize-1;
    datatype x;
    int a;
    while(1)
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
		case 1:SETNULL(sq);printf("�ÿնӳɹ���");flushall();getchar();break;
        case 2:if(EMPTY(sq))
                   cout<<"�ǿնӣ�"<<endl;
               else
                   cout<<"���ǿնӣ�"<<endl;
	               flushall();getchar();
               break;
        case 3:sq=input(sq);
	           flushall();getchar();break;
        case 4:print(sq);flushall();getchar();break;
        case 5:printf("������Ҫ��ӵ����֣�");cin>>x;
               sq=ENQUEUE(sq,x);
			   print(sq);
               flushall();getchar();break;
        case 6:x=DEQUEUE(sq);
               cout<<"��ɾֵ��:"<<x<<endl;flushall();getchar();break;
        case 7:x=FRONT(sq);
               cout<<"��ͷԪ����:"<<x<<endl;flushall();getchar();break;
	    case 0:cout<<"�˳�"<<endl;
		       exit(0);
		}
	}
}