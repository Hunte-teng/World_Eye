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
//置空栈
void SETNULL(linkstack *top)
{
	top=NULL;
}
//判空栈
int EMPTY(linkstack *top)
{
	if(top!=NULL)
        return 0;
    else 
		return 1;
}

//链栈的进栈
linkstack *PUSHLSTACK(linkstack *top,datatype x)
{
	linkstack *p;
    p=(linkstack *)malloc(sizeof(linkstack));
    p->data=x;
    p->next=top;
    top=p;
    return top;
}
//输入栈
linkstack *input(linkstack *top)
{
     datatype x;
	 cout<<"请输入数字，数字间用空格隔开，以“0”结束："<<endl;;
     cin>>x;
     while(x!=0)
     {
         top=PUSHLSTACK(top,x);
         cin>>x;
     }
     return top;
}
//链栈的出栈
linkstack *POPLSTACK(linkstack *top,datatype *datap)
{
	linkstack *p;
    if(top==NULL)
	{
		cout<<"栈空，下溢";
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
//取栈顶
datatype TOP(linkstack *top)
{
	if(EMPTY(top))
	{
		cout<<"空栈！";
        return NULL;
	}
    else
        return(top->data);
}
//输出栈
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
	cout<<"***********菜单**************"<<endl;
	cout<<"1、置空栈       2、判栈空"<<endl;
	cout<<"3、创建链栈     4、输出链栈"<<endl;
	cout<<"5、进栈         6、退栈"<<endl;
	cout<<"7、取栈顶       0、退出"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"请输入功能选项号0~7：";
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
		case 1:SETNULL(top);printf("置空栈成功！\n");flushall();getchar();break;
        case 2:if(EMPTY(top))
                   cout<<"是空栈！"<<endl;
               else
                   cout<<"不是空栈！"<<endl;
	           flushall();getchar();
               break;
        case 3:top=input(top);
	           flushall();getchar();break;
        case 4:print(top);flushall();getchar();break;
        case 5:printf("请输入要进栈的数字：");
			   cin>>x;
               top=PUSHLSTACK(top,x);
			   print(top);
               flushall();
			   getchar();break;
        case 6:top=POPLSTACK(top,datap);	
               cout<<"被删值是:"<<x<<endl;flushall();getchar();break;
        case 7:x=TOP(top);
               cout<<"栈顶是:"<<x<<endl;flushall();getchar();break;
	    case 0:cout<<"退出\n";
		       exit(0);
		}
	}
}