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
//输入栈
seqstack *input(seqstack *s)
{
	cout<<"请输入数字，数字间用空格隔开，以“0”结束："<<endl;
    datatype x;
    cin>>x;
    while(x!=0)
	{
       s=PUSH(s,x);
       cin>>x;
	}
    return(s);
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
//取栈顶
datatype TOP(seqstack *s)
{
	if(EMPTY(s))
	{
		cout<<"空栈！";
        return NULL;
	}
    else
        return(s->data[s->top]);
}
//输出栈
void print1(seqstack *s)
{
	int m;
	m=s->top;
	cout<<"栈中元素为：";
    for(;s->top>=0;s->top--)
        cout<<s->data[s->top];
    s->top=m;
	cout<<endl;
}
//逆输出栈
void print2(seqstack *s)
{
	int i;
	for(i=0;i<=s->top;i++)
		cout<<s->data[i]<<" ";
	cout<<endl;
}

void menu()
{
	cout<<"***********菜单**************"<<endl;
	cout<<"1、置空栈       2、判栈空"<<endl;
	cout<<"3、创建顺序栈   4、输出顺序栈"<<endl;
	cout<<"5、进栈         6、退栈"<<endl;
	cout<<"7、取栈顶       8、逆输出栈"<<endl;
	cout<<"         0、退出     "<<endl;
	cout<<"*****************************"<<endl;
	cout<<"请输入功能选项号0~8：";
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
		case 1:SETNULL(s);printf("置空栈成功！");flushall();getchar();break;
        case 2:if(EMPTY(s))
                   cout<<"是空栈！"<<endl;
               else
                   cout<<"不是空栈！"<<endl;
	               flushall();getchar();
               break;
        case 3:s=input(s);
	           flushall();getchar();break;
        case 4:print1(s);flushall();getchar();break;
        case 5:printf("请输入要入栈的数字：");
			   cin>>x;
               s=PUSH(s,x);
			   print1(s);
               flushall();getchar();break;
        case 6:x=POP(s);
               cout<<"被删值是:"<<x<<endl;flushall();getchar();break;
        case 7:x=TOP(s);
               cout<<"栈顶是:"<<x<<endl;flushall();getchar();break;
		case 8:print2(s);flushall();getchar();break;
	    case 0:cout<<"退出\n";
		       exit(0);
		}
	}
}