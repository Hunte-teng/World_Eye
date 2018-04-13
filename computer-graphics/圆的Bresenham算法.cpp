#include <GL/glut.h>

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);//圆的轮廓的颜色
	gluOrtho2D(0.0,500.0,0.0,500.0);//屏幕区域对应得模型坐标范围
}

void CirclePixel(int xc,int yc,int x,int y)
{
	glBegin(GL_POINTS);
    glVertex2i(xc+x,yc+y);
	glVertex2i(xc-x,yc+y);
	glVertex2i(xc+x,yc-y);
	glVertex2i(xc-x,yc-y);
	glVertex2i(xc+y,yc+x);
	glVertex2i(xc-y,yc+x);
	glVertex2i(xc+y,yc-x);
	glVertex2i(xc-y,yc-x);
	glEnd();
}


void bresenham(int xc,int yc,int r)
{
	int x,y,d;
	x=0;
	y=r;
	d=3-2*y;
	while(x<y)
	{
		CirclePixel(xc,yc,x,y);
		x++;
		if(d<0)
		{
			d=d+4*x+6;
		}
		else
		{
			d=d+4*(x-y)+10;
			y--;
		}
	} 
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	bresenham(250,250,150);
	glFlush();
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
	glutMainLoop();
	return 0;
}
