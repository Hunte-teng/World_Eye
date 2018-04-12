#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;
    struct node *next;
} linkstack;
linkstack *top;
//�ÿ�ջ
void SETNULL(linkstack *top)
{
	top=NULL;
}
//�п�ջ
int EMPTY(linkstack *top)
{
	if(top!=NULL)
        return 0;
    else 
		return 1;
}

//��ջ�Ľ�ջ
linkstack *PUSHLSTACK(linkstack *top,datatype x)
{
	linkstack *p;
    p=(linkstack *)malloc(sizeof(linkstack));
    p->data=x;
    p->next=top;
    top=p;
    return top;
}
//����ջ
linkstack *input(linkstack *top)
{
     datatype x;
	 cout<<"���������֣����ּ��ÿո�������ԡ�0��������"<<endl;;
     cin>>x;
     while(x!=0)
     {
         top=PUSHLSTACK(top,x);
         cin>>x;
     }
     return top;
}
//��ջ�ĳ�ջ
linkstack *POPLSTACK(linkstack *top,datatype *datap)
{
	linkstack *p;
    if(top==NULL)
	{
		cout<<"ջ�գ�����";
        return NULL;
	}
    else
	{
        *datap=top->data;
        p=top;
        top=top->next;
        free(p);
        return top;
	}
}
//ȡջ��
datatype TOP(linkstack *top)
{
	if(EMPTY(top))
	{
		cout<<"��ջ��";
        return NULL;
	}
    else
        return(top->data);
}
//���ջ
void print(linkstack *top)
{
	linkstack *p;
	p=top;
    while(top)
	{ 
		cout<<top->data<<" ";
        top=top->next;
	}
    top=p;
	cout<<endl;
}

void menu()
{
	cout<<"***********�˵�**************"<<endl;
	cout<<"1���ÿ�ջ       2����ջ��"<<endl;
	cout<<"3��������ջ     4�������ջ"<<endl;
	cout<<"5����ջ         6����ջ"<<endl;
	cout<<"7��ȡջ��       0���˳�"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"�����빦��ѡ���0~7��";
}
void main()
{
    datatype x,*datap;datap=(datatype*)malloc(sizeof(datatype));
    int a;
    while(1)
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
		case 1:SETNULL(top);printf("�ÿ�ջ�ɹ���\n");flushall();getchar();break;
        case 2:if(EMPTY(top))
                   cout<<"�ǿ�ջ��"<<endl;
               else
                   cout<<"���ǿ�ջ��"<<endl;
	           flushall();getchar();
               break;
        case 3:top=input(top);
	           flushall();getchar();break;
        case 4:print(top);flushall();getchar();break;
        case 5:printf("������Ҫ��ջ�����֣�");
			   cin>>x;
               top=PUSHLSTACK(top,x);
			   print(top);
               flushall();
			   getchar();break;
        case 6:top=POPLSTACK(top,datap);	
               cout<<"��ɾֵ��:"<<x<<endl;flushall();getchar();break;
        case 7:x=TOP(top);
               cout<<"ջ����:"<<x<<endl;flushall();getchar();break;
	    case 0:cout<<"�˳�\n";
		       exit(0);
		}
	}
}