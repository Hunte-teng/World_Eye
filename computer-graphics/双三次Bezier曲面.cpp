#include<GL/glut.h>
#include<stdio.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//ªÊ÷∆Õº–Œ
	glPointSize(3.0);
	glBegin(GL_POINTS);
	
	double v,u,Bv0,Bv1,Bv2,Bv3,Bu0,Bu1,Bu2,Bu3,vx,vy,vz;

	double RX[4][4]={{240,340,460,530},{200,300,280,480},
                  {160,240,340,400},{140,210,280,350}},
           RY[4][4]={{180,120,260,230},{240,210,290,320},
	             {280,310,350,380},{300,390,430,460}},
           RZ[4][4]={{1,1,0,1},{1,0,1,0},{1,0,1,0},{1,0,1,1}},
	       ux[4],uy[4],uz[4];

	int i;
	double m1=1.0,m2=0.0,m3=1.0;
	glColor3f(m1,m2,m3);
	for(v=0;v<=1;v+=0.05)
	{
		Bv0=(1-v)*(1-v)*(1-v);
		Bv1=3*(1-v)*(1-v)*v;
		Bv2=3*(1-v)*v*v;
		Bv3=v*v*v;
    	for(u=0;u<=1;u+=0.05)
		{
		    Bu0=(1-u)*(1-u)*(1-u);
		    Bu1=3*(1-u)*(1-u)*u;
		    Bu2=3*(1-u)*u*u;
		    Bu3=u*u*u;
			for(i=0;i<=3;i++)
			{
				ux[i]=RX[0][i]*Bu0+RX[1][i]*Bu1+RX[2][i]*Bu2+RX[3][i]*Bu3;
		        uy[i]=RY[0][i]*Bu0+RY[1][i]*Bu1+RY[2][i]*Bu2+RY[3][i]*Bu3;
                uz[i]=RZ[0][i]*Bu0+RZ[1][i]*Bu1+RZ[2][i]*Bu2+RZ[3][i]*Bu3;
			}  
		vx=ux[0]*Bv0+ux[1]*Bv1+ux[2]*Bv2+ux[3]*Bv3;
		vy=uy[0]*Bv0+uy[1]*Bv1+uy[2]*Bv2+uy[3]*Bv3;
		vz=uz[0]*Bv0+uz[1]*Bv1+uz[2]*Bv2+uz[3]*Bv3;
		
		glVertex3f(vx,vy,vz);
		}
		glColor3f(m1-=0.05,m2+=0.05,m3-=0.5);
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
	gluOrtho2D(-150.0, 640.0, -150.0, 480.0);
	glutMainLoop();
	return 0;
}