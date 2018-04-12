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
//置空栈
void SETNULL(seqstack *s)
{
	s->top=-1;
}
//判空栈
int EMPTY(seqstack *s)
{
	if(s->top>=0)
        return 0;
    else 
		return 1;
}
//进栈
seqstack *PUSH(seqstack *s,datatype x)
{
	if(s->top==maxsize-1)
	{
		cout<<"上溢！";
        return NULL;
	}
    else
	{
        s->top++;
        s->data[s->top]=x;
	}
    return s;
}
//退栈
datatype POP(seqstack *s)
{
	if(EMPTY(s))
	{
        cout<<"下溢！";
        return NULL;
	}
    else
	{
        s->top--;
        return(s->data[s->top+1]);
	}
}
//编辑器
void EDIT(seqstack *s)
{
	char c;
	SETNULL(s);
	cout<<"----@：代表清除所有字符-----"<<endl;
	cout<<"----#：代表删除一个字符-----"<<endl;
	cout<<"----*：代表结束输入-----"<<endl;
	cout<<"请输入字符串s（以“*”结束）：";
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
//输出栈
void print(seqstack *s)
{
	int i;
	for(i=0;i<=s->top;i++)
		cout<<s->data[i];
	cout<<endl;
}
//主函数
void main()
{
	s=(seqstack*)malloc(sizeof(seqstack));
	s->top=-1;
	EDIT(s);
	print(s);
}
