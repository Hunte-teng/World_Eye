//��ӡ����У�����Ϊ�ü���     ����Ϊԭ�����     ����Ϊ�ü���Ķ����

//ȱ�㣺�˴���ֻ��ʵ�ֲü���Ķ��������һ������β���ʵ�ֲü���Ķ�����Ƕ�������

#include<GL/glut.h>
#include<stdio.h>

#define N 6  //����ζ�����
#define t 150
#define b 50
#define l 50
#define r 200

float R[N][2]={{10,100},{130,200},{180,200},{240,100},{240,70},{180,10}};   //����ζ������꣬�������˳ʱ������
float S[2*N][2];       //�������ü���Ľ�������
int m=0;    //�������ü���Ľ������

//�ü����㷨
void cut(float x1,float y1,float x2,float y2)
{
	float x3,y3,x4,y4;
	float k,c;  //kֱ��б�ʣ�cֱ�߽ؾ�
    x3=x1;x4=x2;y3=y1;y4=y2;   //��������ֵ
	if((x1>l && x1<r && x2>l && x2<r && y1>t && y2>t) || (x1>l && x1<r && x2>l && x2<r && y1<b && y2<b) || (y1<t && y1>b && y2<t && y2>b && x1<l && x2<l) || (y1<t && y1>b && y2<t && y2>b && x1>r && x2>r))
			return;      //��ȫ�ڲü����⣬���ң�x1��x2��������߽�l��С���ұ߽�r�����ߣ�y1��y2�������ϱ߽�t��С���±߽�b��
	else if(x1==x2 && x1>l && x1<r)     //��������ȣ�����ȫ���򲿷��ڲü�����
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
	else if(y1==y2 && y1>b && y1<t)    //��������ȣ�����ȫ���򲿷��ڲü�����
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
	//�ж���õ������Ƿ���ȫ�ڲü�����
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
	    x1=x3;x2=x4;y1=y3;y2=y4;    //������õ����겻�ڲü����ڣ���ԭԭ��������ֵ
		//��ȫ�ڲü����⣬���ң�x1-x2����y1-y2)�ľ���ֵ�������ڵĲü���
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
        //��ȫ�ڲü����⣬����ֻ��ü���һ��������
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

	//���Ʋü���
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
            glVertex2f(l,t);
		    glVertex2f(r,t);
			glVertex2f(r,b);
			glVertex2f(l,b);
	glEnd();

	//���ƶ����
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<N-1;i++)
	{
        glVertex2f(R[i][0],R[i][1]);
		glVertex2f(R[i+1][0],R[i+1][1]);
	}
	glEnd();

	//����������ü���Ľ�������
	for(i=0;i<N;i++)
	{
		if(i==N-1)
			cut(R[i][0],R[i][1],R[0][0],R[0][1]);
		else
		    cut(R[i][0],R[i][1],R[i+1][0],R[i+1][1]);
	}

    //���Ʋü���Ķ����
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
