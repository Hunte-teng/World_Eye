#include<GL/glut.h>
#include<stdio.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	double v,u,Bv0,Bv1,Bv2,Bv3,Bu0,Bu1,Bu2,Bu3;

	double RX[6][6]={{80,150,210,270,300,350},{70,120,170,230,265,300},{55,100,150,190,240,270},
                  {30,80,120,170,200,240},{20,70,105,140,175,220},{0,50,90,125,160,190}},
           RY[6][6]={{0,10,70,75,100,130},{50,70,80,130,115,155},{75,110,125,145,160,180},
	              {130,130,175,175,190,210},{160,160,215,215,215,230},{180,190,215,230,230,260}},
           RZ[6][6]={{1,0,0,1,1,1},{0,1,1,0,1,1},{1,1,0,1,0,1},{1,1,0,1,0,1},{1,1,0,1,1,1},{1,0,1,1,1,1}};
       
    double ux[4],uy[4],uz[4],vx[4],vy[4],vz[4];

	int i,j,k;

	glPointSize(3.0);
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 1.0);
	for(i=0;i<6;i++)
	    for(j=0;j<6;j++)
	    {
	    	glVertex3f(RX[i][j],RY[i][j],RZ[i][j]);
	    }		
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 1.0);
	for(i=0;i<6;i++)
	    for(j=0;j<6;j++)
	    {
	    	glVertex3f(RX[i][j],RY[i][j],RZ[i][j]);
	    }		
	glEnd();

	glBegin(GL_LINES);
	for(i=0;i<6;i++)
	    for(j=0;j<5;j++)
	    {
	    	glVertex3f(RX[i][j],RY[i][j],RZ[i][j]);
	    	glVertex3f(RX[i][j+1],RY[i][j+1],RZ[i][j+1]);
	    }
	for(j=0;j<6;j++)
	    for(i=0;i<5;i++)
	    {
	    	glVertex3f(RX[i][j],RY[i][j],RZ[i][j]);
	    	glVertex3f(RX[i+1][j],RY[i+1][j],RZ[i+1][j]);
	    }		
	glEnd();

	glBegin(GL_POINTS);
	double m1=0.0,m2=1.0,m3=0.0;	
	    for(i=0;i<3;i++)
		{
		    glColor3f(m1+=0.3,m2-=0.3,m3+=0.3);
	        for(v=i;v<(i+1);v+=0.01)
			{
		        Bv0=1-3*(v-i)+3*(v-i)*(v-i)-(v-i)*(v-i)*(v-i);
		        Bv1=4-6*(v-i)*(v-i)+3*(v-i)*(v-i)*(v-i);
		        Bv2=1+3*(v-i)+3*(v-i)*(v-i)-3*(v-i)*(v-i)*(v-i);
		        Bv3=(v-i)*(v-i)*(v-i);
    	        for(u=i;u<(i+1);u+=0.01)
				{
		            Bu0=1-3*(u-i)+3*(u-i)*(u-i)-(u-i)*(u-i)*(u-i);
		            Bu1=4-6*(u-i)*(u-i)+3*(u-i)*(u-i)*(u-i);
		            Bu2=1+3*(u-i)+3*(u-i)*(u-i)-3*(u-i)*(u-i)*(u-i);
		            Bu3=(u-i)*(u-i)*(u-i);
			        for(k=1;k<5;k++)
					{
						ux[k]=RX[i][k]*Bu0+RX[i+1][k]*Bu1+RX[i+2][k]*Bu2+RX[i+3][k]*Bu3;
						uy[k]=RY[i][k]*Bu0+RY[i+1][k]*Bu1+RY[i+2][k]*Bu2+RY[i+3][k]*Bu3;
						uz[k]=RZ[i][k]*Bu0+RZ[i+1][k]*Bu1+RZ[i+2][k]*Bu2+RZ[i+3][k]*Bu3;
						glVertex3f(ux[k]/6.0,uy[k]/6.0,uz[k]/6.0);
					}
					
				}
				for(k=1;k<5;k++)
				{
					vx[k]=RX[k][i]*Bv0+RX[k][i+1]*Bv1+RX[k][i+2]*Bv2+RX[k][i+3]*Bv3;
					vy[k]=RY[k][i]*Bv0+RY[k][i+1]*Bv1+RY[k][i+2]*Bv2+RY[k][i+3]*Bv3;
					vz[k]=RZ[k][i]*Bv0+RZ[k][i+1]*Bv1+RZ[k][i+2]*Bv2+RZ[k][i+3]*Bv3;
					glVertex3f(vx[k]/6.0,vy[k]/6.0,vz[k]/6.0);
				}
			}
		}
	glEnd();

	glFlush();
}

int main(int argc, char* * argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	gluOrtho2D(-150.0, 640.0, -150.0, 480.0);
	glutMainLoop();
	return 0;
}
