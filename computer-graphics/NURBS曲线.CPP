#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#define N 8

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//绘制图形
	glPointSize(3.0);
	glBegin(GL_POINTS);
	
	double X[]={0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7},Y[]={0.2,0.4,0.6,0.4,0.2,0.0,0.2,0.4},w[]={0.3,0.3,0.4,0.3,0.3,0.0,0.3,0.3};
    double u,N02,N12,N22,x,y;
	float m1=1.0,m2=0.0,m3=0.0;
    int i;
	//点（0,0,1）
	for(i=0,u=i;u<(i+1);u+=0.01)
	{
	    N02=(1.0/2)*(1-2*(u-i)+(u-i)*(u-i));
	    N12=(1.0/2)*(1+2*(u-i)-2*(u-i)*(u-i));
	    N22=(1.0/2)*(u-i)*(u-i);
        x=(w[i]*X[i]*N02+w[i]*X[i]*N12+w[i+1]*X[i+1]*N22)/(w[i]*N02+w[i]*N12+w[i+1]*N22);
	    y=(w[i]*Y[i]*N02+w[i]*Y[i]*N12+w[i+1]*Y[i+1]*N22)/(w[i]*N02+w[i]*N12+w[i+1]*N22);
		glColor3f(1.0,0.0,1.0);
		glVertex2f(x,y);
	}
	//点（0,1,2；1,2,3；2,3,4；3,4,5；4,5,6；5,6,7）
    for(i=0;i<N-2;i++)
	{
		glColor3f(m1-=0.1,m2+=0.1,m3+=0.1);
        for(u=i;u<(i+1);u+=0.01)
		{
	        N02=(1.0/2)*(1-2*(u-i)+(u-i)*(u-i));
	        N12=(1.0/2)*(1+2*(u-i)-2*(u-i)*(u-i));
	        N22=(1.0/2)*(u-i)*(u-i);
	        x=(w[i]*X[i]*N02+w[i+1]*X[i+1]*N12+w[i+2]*X[i+2]*N22)/(w[i]*N02+w[i+1]*N12+w[i+2]*N22);
	        y=(w[i]*Y[i]*N02+w[i+1]*Y[i+1]*N12+w[i+2]*Y[i+2]*N22)/(w[i]*N02+w[i+1]*N12+w[i+2]*N22);
	        glVertex2f(x,y);
		}
	}
    //点（6,6,7）
	for(i=N-1,u=i;u<(i+1);u+=0.01)
	{
	    N02=(1.0/2)*(1-2*(u-i)+(u-i)*(u-i));
	    N12=(1.0/2)*(1+2*(u-i)-2*(u-i)*(u-i));
	    N22=(1.0/2)*(u-i)*(u-i);
        x=(w[i-1]*X[i-1]*N02+w[i-1]*X[i-1]*N12+w[i]*X[i]*N22)/(w[i-1]*N02+w[i-1]*N12+w[i]*N22);
	    y=(w[i-1]*Y[i-1]*N02+w[i-1]*Y[i-1]*N12+w[i]*Y[i]*N22)/(w[i-1]*N02+w[i-1]*N12+w[i]*N22);
		glColor3f(1.0,0.0,1.0);
		glVertex2f(x,y);
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