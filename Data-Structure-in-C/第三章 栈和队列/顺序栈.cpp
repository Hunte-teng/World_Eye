#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
#define maxsize 64
typedef struct
{
	datatype data[maxsize];
    int top;
} seqstack;
seqstack *s;
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
//����ջ
seqstack *input(seqstack *s)
{
	cout<<"���������֣����ּ��ÿո�������ԡ�0��������"<<endl;
    datatype x;
    cin>>x;
    while(x!=0)
	{
       s=PUSH(s,x);
       cin>>x;
	}
    return(s);
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
	cout<<endl;
}
//�����ջ
void print2(seqstack *s)
{
	int i;
	for(i=0;i<=s->top;i++)
		cout<<s->data[i]<<" ";
	cout<<endl;
}

void menu()
{
	cout<<"***********�˵�**************"<<endl;
	cout<<"1���ÿ�ջ       2����ջ��"<<endl;
	cout<<"3������˳��ջ   4�����˳��ջ"<<endl;
	cout<<"5����ջ         6����ջ"<<endl;
	cout<<"7��ȡջ��       8�������ջ"<<endl;
	cout<<"         0���˳�     "<<endl;
	cout<<"*****************************"<<endl;
	cout<<"�����빦��ѡ���0~8��";
}
void main()
{
	s=(seqstack*)malloc(sizeof(seqstack));
	s->top=-1;
    datatype x;
    int a;
    while(1)
	{
		system("cls");
        menu();
        cin>>a;
        switch(a)
		{
		case 1:SETNULL(s);printf("�ÿ�ջ�ɹ���");flushall();getchar();break;
        case 2:if(EMPTY(s))
                   cout<<"�ǿ�ջ��"<<endl;
               else
                   cout<<"���ǿ�ջ��"<<endl;
	               flushall();getchar();
               break;
        case 3:s=input(s);
	           flushall();getchar();break;
        case 4:print1(s);flushall();getchar();break;
        case 5:printf("������Ҫ��ջ�����֣�");
			   cin>>x;
               s=PUSH(s,x);
			   print1(s);
               flushall();getchar();break;
        case 6:x=POP(s);
               cout<<"��ɾֵ��:"<<x<<endl;flushall();getchar();break;
        case 7:x=TOP(s);
               cout<<"ջ����:"<<x<<endl;flushall();getchar();break;
		case 8:print2(s);flushall();getchar();break;
	    case 0:cout<<"�˳�\n";
		       exit(0);
		}
	}
}