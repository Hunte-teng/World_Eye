//打印结果中：黄线为裁剪框     紫线为原多边形     红线为裁剪后的多边形

//缺点：此代码只能实现裁剪后的多边形仍是一个多边形不能实现裁剪后的多边形是多个多边形

#include<GL/glut.h>
#include<stdio.h>

#define N 6  //多边形顶点数
#define t 150
#define b 50
#define l 50
#define r 200

float R[N][2]={{10,100},{130,200},{180,200},{240,100},{240,70},{180,10}};   //多边形顶点坐标，坐标必须顺时针输入
float S[2*N][2];       //多边形与裁剪框的交点坐标
int m=0;    //多边形与裁剪框的交点个数

//裁剪框算法
void cut(float x1,float y1,float x2,float y2)
{
	float x3,y3,x4,y4;
	float k,c;  //k直线斜率，c直线截距
    x3=x1;x4=x2;y3=y1;y4=y2;   //保存坐标值
	if((x1>l && x1<r && x2>l && x2<r && y1>t && y2>t) || (x1>l && x1<r && x2>l && x2<r && y1<b && y2<b) || (y1<t && y1>b && y2<t && y2>b && x1<l && x2<l) || (y1<t && y1>b && y2<t && y2>b && x1>r && x2>r))
			return;      //完全在裁剪框外，并且（x1和x2都大于左边界l，小于右边界r）或者（y1和y2都大于上边界t，小于下边界b）
	else if(x1==x2 && x1>l && x1<r)     //横坐标相等，并且全部或部分在裁剪框内
	{
		if(y1>y2)
		{
		    if(y1>t && y2<t && y2>b)
			{
			    x1=x1;
			    y1=t;
			    x2=x2;
			    y2=y2;
			}
		    if(y1>t && y2<b)
			{
			    x1=x1;
			    y1=t;
			    x2=x2;
			    y2=b;
			}
		    if(y1<t && y2>b)
			{
			    x1=x1;
			    y1=y1;
			    x2=x2;
			    y2=y2;
			}
		    if(y1>b && y1<t && y2<b)
			{
			    x1=x1;
			    y1=y1;
			    x2=x2;
			    y2=b;
			}
		}
		if(y1<y2)
		{
		    if(y2>t && y1<t && y1>b)
			{
			    x1=x1;
			    y1=y1;
			    x2=x2;
			    y2=t;
			}
		    if(y2>t && y1<b)
			{
			    x1=x1;
			    y1=b;
			    x2=x2;
			    y2=t;
			}
		    if(y2<t && y1>b)
			{
			    x1=x1;
			    y1=y1;
			    x2=x2;
			    y2=y2;
			}
		    if(y2>b && y2<t && y1<b)
			{
			    x1=x1;
			    y1=b;
			    x2=x2;
			    y2=y2;
			}
		}
	}
	else if(y1==y2 && y1>b && y1<t)    //纵坐标相等，并且全部或部分在裁剪框内
	{
		if(x1<x2)
		{
		    if(x1<l && x2>l && x2<r)
			{
			    x1=l;
			    y1=y1;
			    x2=x2;
			    y2=y2;
			}
		    if(x1<l && x2>r)
			{
			    x1=l;
			    y1=y1;
			    x2=r;
			    y2=y2;
			}
		    if(x1>l && x2<r)
			{
			    x1=x1;
			    y1=y1;
			    x2=x2;
			    y2=y2;
			}
		    if(x1>l && x1<r && x2>r)
			{
			    x1=x1;
			    y1=y1;
			    x2=r;
			    y2=y2;
			}
		}
		if(x1>x2)
		{
		    if(x2<l && x1>l && x1<r)
			{
			    x1=x1;
			    y1=y1;
			    x2=l;
			    y2=y2;
			}
		    if(x2<l && x1>r)
			{
			    x1=r;
			    y1=y1;
			    x2=l;
			    y2=y2;
			}
		    if(x2>l && x1<r)
			{
			    x1=x1;
			    y1=y1;
			    x2=x2;
			    y2=y2;
			}
		    if(x2>l && x2<r && x1>r)
			{
			    x1=r;
			    y1=y1;
			    x2=x2;
			    y2=y2;
			}
		}
	}
	else
	{
		k=(y2-y1)/((x2-x1)*1.0);
		c=y1-k*x1;
		if(x1<x2)
		{
		    if(x1<l && x2>l)
			{
			    x1=l;
			    y1=k*x1+c;
			    x2=x2;
			    y2=y2;
			}
		    if(x1<r && x2>r)
			{
			    x1=x1;
			    y1=y1;
			    x2=r;
			    y2=k*x2+c;
			}
		}
		if(x1>x2)
		{
		    if(x1>l && x2<l)
			{
			    x1=x1;
			    y1=y1;
				x2=l;
			    y2=k*x2+c;	
			}
		    if(x1>r && x2<r)
			{
			    x1=r;
			    y1=k*x1+c;
				x2=x2;
			    y2=y2;
			}
		}
		if(y1>y2)
		{
		    if(y1>t && y2<t)
			{
			    y1=t;
			    x1=(y1-c)/(k*1.0);
			    x2=x2;
			    y2=y2;
			}
		
		    if(y1>b && y2<b)
			{
			    x1=x1;
			    y1=y1;
			    y2=b;
			    x2=(y2-c)/k*1.0;
			}
		}
		if(y1<y2)
		{
		    if(y1<t && y2>t)
			{
			    x1=x1;
			    y1=y1;
				y2=t;
			    x2=(y2-c)/(k*1.0);
			}
		
		    if(y1<b && y2>b)
			{
			    y1=b;
			    x1=(y1-c)/k*1.0;
				x2=x2;
			    y2=y2;
			}
		}
	}
	//判断求得的坐标是否完全在裁剪框内
	if(x1>=l && x1<=r && x2>=l && x2<=r && y1<=t && y1>=b && y2<=t && y2>=b)
	{   
		S[m][0]=x1;
		S[m][1]=y1;
		S[m+1][0]=x2;
		S[m+1][1]=y2;
		m+=2;
	}
	else
	{
	    x1=x3;x2=x4;y1=y3;y2=y4;    //最终求得的坐标不在裁剪框内，还原原本的坐标值
		//完全在裁剪框外，并且（x1-x2）或（y1-y2)的绝对值大于相邻的裁剪边
		if(x1<l && x2<l && y1<b && y2>t)
		{
		    x1=x2=l;
			y1=y2=b;
		}
		if(x1<l && x2>r && y1>t && y2>t)
		{
			x1=x2=l;
			y1=y2=t;
		}
		if(x1>r && x2>r && y1>t && y2<b)
		{
			x1=x2=r;
			y1=y2=t;
		}
		if(x1<l && x2>r && y1<b && y2<b)
		{
			x1=x2=r;
			y1=y2=b;
		}
        //完全在裁剪框外，并且只与裁剪框一个角相邻
		if(x1<l && y2>t)
		{
			x1=x2=l;
			y1=y2=t;
		}
		if(x2>r && y1>t)
		{
			x1=x2=r;
			y1=y2=t;
		}
		if(x1>r && y2<b)
		{
			x1=x2=r;
			y1=y2=b;
		}
		if(x2<l && y1<b)
		{
			x1=x2=l;
		    y1=y2=b;
		}
		S[m][0]=x1;
		S[m][1]=y1;
		S[m+1][0]=x2;
		S[m+1][1]=y2;
		m+=2;
	}
	
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,500,0,500);

	//绘制裁剪框
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
            glVertex2f(l,t);
		    glVertex2f(r,t);
			glVertex2f(r,b);
			glVertex2f(l,b);
	glEnd();

	//绘制多边形
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<N-1;i++)
	{
        glVertex2f(R[i][0],R[i][1]);
		glVertex2f(R[i+1][0],R[i+1][1]);
	}
	glEnd();

	//计算多边形与裁剪框的交点坐标
	for(i=0;i<N;i++)
	{
		if(i==N-1)
			cut(R[i][0],R[i][1],R[0][0],R[0][1]);
		else
		    cut(R[i][0],R[i][1],R[i+1][0],R[i+1][1]);
	}

    //绘制裁剪后的多边形
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(i=0;i<m-1;i++)
	{
        glVertex2f(S[i][0],S[i][1]);
		glVertex2f(S[i+1][0],S[i+1][1]);
	}
	glEnd();

	glFlush();
}

int main(int argc,char* * argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
