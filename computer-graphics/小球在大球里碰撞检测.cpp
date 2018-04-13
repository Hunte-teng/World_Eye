#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glaux.h>
#include <math.h> 

//(v1,v2)ΪС���λ�ã���С��Բ�ģ���(x,y)Ϊ��ʼλ�ã�(m,n)Ϊ���㣬(a,b)�ֱ�ΪС���˶�ʱx��y���ϵ�������
//r1ΪС��뾶,r2����뾶��r3=r2-r1��(250,250)����Բ��
float v1=200.0f, v2=230.0f, x=200.0f, y=230.0f, m=150.0f, n=sqrt(180*180-100*100)+250, a=0.0f, b=0.0f, 
      r1=20.0f, r2=200.0f, r3=r2-r1, rotate=(int)(sqrt((m-x)*(m-x)+(n-y)*(n-y))*15);

void plotCirclePixel(int xc,int yc,int x1,int y1)
{
	glBegin(GL_POINTS);
    glVertex2i(xc+x1,yc+y1);
	glVertex2i(xc-x1,yc+y1);
	glVertex2i(xc+x1,yc-y1);
	glVertex2i(xc-x1,yc-y1);
	glVertex2i(xc+y1,yc+x1);
	glVertex2i(xc-y1,yc+x1);
	glVertex2i(xc+y1,yc-x1);
	glVertex2i(xc-y1,yc-x1);
	glEnd();
}

void bresenham(int xc,int yc,int rc)
{
	int x1,y1,d;
	x1=0;
	y1=rc;
	d=3-2*y1;
	while(x1<y1)
	{
		plotCirclePixel(xc,yc,x1,y1);
		x1++;
		if(d<0)
		{
			d=d+4*x1+6;
		}
		else
		{
			d=d+4*(x1-y1)+10;
			y1--;
		}
	} 
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//������
    glEnable (GL_LINE_SMOOTH);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

	//����ֹ�Ĵ���
	bresenham(250,250,r2);

	//���˶���С��
	bresenham(v1,v2,r1);

	//����С���ķ�����
    glColor3ub(0,128,255);
    glBegin(GL_LINES);
	   glVertex2f (x,y);
	   glVertex2f (v1,v2);
    glEnd();
  
    //����(С��)
    glEnable(GL_POINT_SMOOTH); 
    glColor3f(0.8,0.2,0.0);
    glPointSize(1);
    glBegin(GL_POINTS);
      glVertex3f (v1, v2, 0.0);	  
    glEnd();

	glFlush();
}

//����ֱ�������Ľ���(m,n)
void point(float i1, float j1, float i2, float j2)  //���뷴����
{
    float A,B,C,k,m1=0.0f,n1=0.0f,m2=0.0f,n2=0.0f;
	x=i1;
	y=j1;
	k=(j2-j1)/(i2-i1);
	A=1+k*k;
	B=-500-2*k*k*i1+2*k*j1-500*k;
	C=k*k*i1*i1+2*250*250-2*k*i1*j1+500*k*i1+j1*j1-500*j1-r3*r3;
	if(B*B-4*A*C>=0)
	{
	m1=(-B+sqrt(B*B-4*A*C))/(2*A);
	n1=k*(m1-i1)+j1;
	m2=(-B-sqrt(B*B-4*A*C))/(2*A);
	n2=k*(m2-i1)+j1;
	if(m1>m-1&&m1<m+1)//�ж�m�Ƿ����m1������m,m1��Ϊ�������ͣ����������ֵ���������Բ�ֱ��дif(m==m1),���Ǹ�һ����Χ
		m=m2;
	else
		m=m1;
	if(n1>n-1&&n1<n+1)
		n=n2;
	else
		n=n1;	
	rotate=(int)(sqrt((m-x)*(m-x)+(n-y)*(n-y))*15);
	}
}

void reflect()  //����������ʽv=a-2(a*n)*n��ÿ���߶εķ��������㷴����
{
	float rr1,rr2;
	//rr1=(x-m)-((2*((x-m)*(m-250)+(y-n)*(n-250)))*(m-250));
	//rr2=(y-n)-((2*((x-m)*(m-250)+(y-n)*(n-250)))*(n-250));
	rr1=2*m-x-2*((m-x)*(250-m)+(n-y)*(250-n))*(250-m)/((250-m)*(250-m)+(250-n)*(250-n));
	rr2=2*n-y-2*((m-x)*(250-m)+(n-y)*(250-n))*(250-n)/((250-m)*(250-m)+(250-n)*(250-n));
	point(m,n,rr1,rr2);	
}

void goDisplay()
{
	if(v1==m && v2==n)  reflect();
	a=(m-v1)/rotate;
	b=(n-v2)/rotate;  //����0��û��������
	if(rotate>1) rotate=rotate-1;	
	v1=v1+a;
	v2=v2+b;
	glutPostRedisplay();
}

void mouse(int button, int state, int i, int j) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(goDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
