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
//置空队
void SETNULL(seqstack *sq)
{
	sq->front=maxsize-1;
    sq->rear=maxsize-1;
}
//判队空
int EMPTY(seqstack *sq)
{
	if(sq->rear==sq->front)
        return 1;
    else 
		return 0;
}
//入队
seqstack *ENQUEUE(seqstack *sq,datatype x)
{
	if(sq->front==(sq->rear+1)%maxsize)
	{
		cout<<"队满上溢！";
        return NULL;
	}
    else
	{
        sq->rear=(sq->rear+1)%maxsize;
        sq->data[sq->rear]=x;
	}
    return sq;
}
//输入栈
seqstack *input(seqstack *sq)
{
	cout<<"请输入数字，数字间用空格隔开，以“0”结束："<<endl;
    datatype x;
    cin>>x;
    while(x!=0)
	{
       sq=ENQUEUE(sq,x);
       cin>>x;
	}
    return(sq);
}

//出队
datatype DEQUEUE(seqstack *sq)
{
	if(EMPTY(sq))
	{
        cout<<"队空下溢！";
        return NULL;
	}
    else
	{
        sq->front=(sq->front+1)%maxsize;
        return(sq->data[sq->front]);
	}
}
//取队头元素
datatype FRONT(seqstack *sq)
{
	if(EMPTY(sq))
	{
		cout<<"空栈！";
        return NULL;
	}
    else
        return(sq->data[(sq->front+1)%maxsize]);
}
//输出队
void print(seqstack *sq)
{
	int i;
	for(i=(sq->front+1)%maxsize;i<(sq->rear+1)%maxsize;i++)
		cout<<sq->data[i]<<" ";
	cout<<endl;
}

void menu()
{
	cout<<"***********菜单**************"<<endl;
	cout<<"1、置空队       2、判空队"<<endl;
	cout<<"3、创建队       4、输出队"<<endl;
	cout<<"5、入队         6、出队"<<endl;
	cout<<"7、取队头元素   0、退出"<<endl;
	cout<<"*****************************"<<endl;
	cout<<"请输入功能选项号0~7：";
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
		case 1:SETNULL(sq);printf("置空队成功！");flushall();getchar();break;
        case 2:if(EMPTY(sq))
                   cout<<"是空队！"<<endl;
               else
                   cout<<"不是空队！"<<endl;
	               flushall();getchar();
               break;
        case 3:sq=input(sq);
	           flushall();getchar();break;
        case 4:print(sq);flushall();getchar();break;
        case 5:printf("请输入要入队的数字：");cin>>x;
               sq=ENQUEUE(sq,x);
			   print(sq);
               flushall();getchar();break;
        case 6:x=DEQUEUE(sq);
               cout<<"被删值是:"<<x<<endl;flushall();getchar();break;
        case 7:x=FRONT(sq);
               cout<<"队头元素是:"<<x<<endl;flushall();getchar();break;
	    case 0:cout<<"退出"<<endl;
		       exit(0);
		}
	}
}