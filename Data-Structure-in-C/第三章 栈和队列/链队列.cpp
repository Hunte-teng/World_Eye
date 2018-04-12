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
//置空队
void SETNULL(linkqueue *q)
{
	q->front=(linkstack *)malloc(sizeof(linkstack));
	q->front->next=NULL;
	q->rear=q->front;
}
//判队空
int EMPTY(linkqueue *q)
{
	if(q->front==q->rear)
        return 1;
    else 
		return 0;
}
//入队
linkqueue *ENQUEUE(linkqueue *q,datatype x)
{
    q->rear->next=(linkstack *)malloc(sizeof(linkstack));     //新结点插入尾端
    q->rear=q->rear->next;                    //尾指针指向新结点
    q->rear->data=x;                        //给新结点赋值
    q->rear->next=NULL;
    return q;
}
//输入队
linkqueue *input(linkqueue *q)
{
     datatype x;
	 cout<<"请输入数字,数字间用空格隔开，以“0”结束："<<endl;
     cin>>x;//scanf("%d",&x);
     while(x!=0)
     {
         q=ENQUEUE(q,x);
         cin>>x;//scanf("%d",&x);
     }
     return q;
}
//出队
datatype DEQUEUE(linkqueue *q)
{
	linkstack *s;
    if(EMPTY(q))
	{
		cout<<"队空";
        return NULL;
	}
    else
	{
        s=q->front;                 //s指向头结点
        q->front=q->front->next;   //头指针指向原队头
        free(s);                   //释放原头结点        
        return(q->front->data);     //返回原队头数据
	}
}
//取队头结点数据
datatype FRONT(linkqueue *q)
{
	if(EMPTY(q))
	{
		cout<<"队列空！";
        return NULL;
	}
    else
        return(q->front->next->data);
}
//输出队
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
		case 1:SETNULL(q);printf("置空队成功！");flushall();getchar();break;
        case 2:if(EMPTY(q))
                   cout<<"是空队！"<<endl;
               else
                   cout<<"不是空队！"<<endl;
	               flushall();getchar();
               break;
        case 3:q=input(q);
	           flushall();getchar();break;
        case 4:print(q);flushall();getchar();break;
        case 5:printf("请输入要进队的数字：");
			   cin>>x;
               q=ENQUEUE(q,x);
               print(q);
               flushall();getchar();break;
        case 6:x=DEQUEUE(q);
               cout<<"被删值是:"<<x<<endl;flushall();getchar();break;
        case 7:x=FRONT(q);
               cout<<"队头元素是:"<<x<<endl;flushall();getchar();break;
	    case 0:cout<<"退出\n";
		       exit(0);
		}
	}
}