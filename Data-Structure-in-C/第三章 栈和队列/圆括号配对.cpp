#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
#define maxsize 64
typedef struct
{
	datatype data[maxsize];
    int top;
} seqstack;
seqstack *s;

int sign=1;

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
//��ջ
datatype POP(seqstack *s)
{
	if(EMPTY(s))
        return NULL;
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
        return NULL;
    else
        return(s->data[s->top]);
}
//���
void p(seqstack *s)
{
	datatype ch,x;

    cout<<"�������ַ��ԡ�#��������";
	cin>>ch;
	while(ch!='#')
	{
		switch(ch)
		{
		case '(':   s=PUSH(s,ch);break;
		case ')':	if(TOP(s)=='(')
						x=POP(s);
		        	else  sign=0;
						break;
        }
		
		cin>>ch;
	}
}

void main()
{
	s=(seqstack *)malloc(sizeof(seqstack));
	SETNULL(s);
    p(s);
	if(EMPTY(s)==0||sign==0)
		cout<<"Բ���Ų����"<<endl;
	else
		cout<<"Բ�������"<<endl;
}



