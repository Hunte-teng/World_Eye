#include<GL/glut.h>
#include<stdio.h>

#define N 5  //线段数
#define t 150
#define b 50
#define l 50
#define r 200


float R[N][4]={{10,130,10,20},{10,10,150,10},{100,300,100,0},{20,250,150,60},{130,130,300,70}};   //线条坐标

//裁剪框的算法
void cut(float x1,float y1,float x2,float y2)
{
	float k,c;    //k直线斜率，c直线截距
	if(x1==x2 && x1>l && x1<r)
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
	else if(y1==y2 && y1>b && y1<t)
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
	if(x1>=l && x1<=r && x2>=l && x2<=r && y1<=t && y1>=b && y2<=t && y2>=b)
	{   
		glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
            glVertex2f(x1,y1);
		    glVertex2f(x2,y2);
		glEnd();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,500,0,500);

	//绘制图形
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
            glVertex2f(l,t);
		    glVertex2f(r,t);
			glVertex2f(r,b);
			glVertex2f(l,b);
		glEnd();

	//绘制线条
	glBegin(GL_LINES);
	glColor3f(1.0,0.0,1.0);
            glVertex2f(R[0][0],R[0][1]);
		    glVertex2f(R[0][2],R[0][3]);
			glVertex2f(R[1][0],R[1][1]);
			glVertex2f(R[1][2],R[1][3]);
			glVertex2f(R[2][0],R[2][1]);
			glVertex2f(R[2][2],R[2][3]);
			glVertex2f(R[3][0],R[3][1]);
			glVertex2f(R[3][2],R[3][3]);
			glVertex2f(R[4][0],R[4][1]);
			glVertex2f(R[4][2],R[4][3]);
		glEnd();

	//计算线条与裁剪框的交点坐标并绘制裁剪后的线条
	for(int i=0;i<N;i++)
		cut(R[i][0],R[i][1],R[i][2],R[i][3]);

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
