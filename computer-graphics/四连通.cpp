#include <GL/glut.h>
typedef float Color[3];

void getpixel(GLint x, GLint y, Color color) 
{
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

void setpixel(GLint x, GLint y) 
{
	glPointSize(1.0);
    glBegin(GL_POINTS);	
    glVertex2f(x, y);
    glEnd();
}

int compareColor(Color color1, Color color2) 
{
    if (color1[0] != color2[0] || color1[1] != color2[1] || color1[2] != color2[2]) 
	{ 
		return 0; 
	}
    else 
	{ 
		return 1; 
	}
}

void boundaryFill4(int x, int y, Color fillColor, Color boarderColor) 
{
    Color interiorColor;
    getpixel(x, y, interiorColor);
    if (compareColor(interiorColor, fillColor) == 0 && compareColor(interiorColor, boarderColor) == 0) 
	{
        setpixel(x, y);
        boundaryFill4(x + 1, y, fillColor, boarderColor);
        boundaryFill4(x - 1, y, fillColor, boarderColor);
        boundaryFill4(x, y + 1, fillColor, boarderColor);
        boundaryFill4(x, y - 1, fillColor, boarderColor);
    }

}

void display(void) 
{
    Color fillColor = {0.0, 1.0, 0.0};//�����ɫ ��ɫɫ
    Color boarderColor = {1.0, 0.0, 0.0};//�߽���ɫ ��ɫ
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 500, 500);
    glColor3fv(boarderColor);
    glBegin(GL_LINE_LOOP);
    glLineWidth(5);
        glVertex2f(100, 100);
        glVertex2f(100, 200);
        glVertex2f(200, 200);
        glVertex2f(200, 100);
    glEnd();
    glColor3fv(fillColor);
    boundaryFill4(150, 150, fillColor, boarderColor);//����������꼰��ɫ
    glFlush();
}
void init(void)
{
    glClearColor(1, 1, 1, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RED);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("�������---����ͨ");
	init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}