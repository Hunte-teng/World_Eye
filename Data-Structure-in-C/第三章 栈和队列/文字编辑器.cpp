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
//�༭��
void EDIT(seqstack *s)
{
	char c;
	SETNULL(s);
	cout<<"----@��������������ַ�-----"<<endl;
	cout<<"----#������ɾ��һ���ַ�-----"<<endl;
	cout<<"----*�������������-----"<<endl;
	cout<<"�������ַ���s���ԡ�*����������";
	cin>>c;
	while(c!='*')    
	{
		if(c=='#')
			POP(s);
		else
			if(c=='@')
				SETNULL(s);
			else
				PUSH(s,c);
		cin>>c;  
	}
}
//���ջ
void print(seqstack *s)
{
	int i;
	for(i=0;i<=s->top;i++)
		cout<<s->data[i];
	cout<<endl;
}
//������
void main()
{
	s=(seqstack*)malloc(sizeof(seqstack));
	s->top=-1;
	EDIT(s);
	print(s);
}
