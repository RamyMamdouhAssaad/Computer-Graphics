#include <gl/glut.h>
#include<math.h>
void drawAxisLines(float left, float right, float down, float up)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(left, 0);
	glVertex2f(right, 0);
	glVertex2f(0, down);
	glVertex2f(0, up);
	glEnd();
}


void keyboard(unsigned char keyPressed, int xMouse, int yMouse)
{
	switch (keyPressed)
	{


	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
			drawAxisLines(-10, 10, -10, 10);
				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(1, 1);
				glVertex2f(5, 1);
			    glVertex2f(2, 3);
				
			    glEnd();
				glPopMatrix();
				glPushMatrix();	
				glColor3f(0.0, 0.0, 1.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(1, 1);
				glVertex2f(1+2*( sqrt(2.0) ), 1+2*( sqrt(2.0) ));
			    glVertex2f(2-(sqrt(2.0)/2), (2+(3*sqrt(2.0))/2));
			    glEnd();
			glPopMatrix();
		glFlush();
		break;

	case '2':
			glClear(GL_COLOR_BUFFER_BIT);
		drawAxisLines(-10, 10, -10, 10);
				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(1, 1);
				glVertex2f(5, 1);
			    glVertex2f(2, 3);
			    glEnd();
				glPopMatrix();
				glPushMatrix();	
				glColor3f(0.0, 0.0, 1.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(1, 3);
				glVertex2f(5, 3);
			    glVertex2f(2, 1);
			    glEnd();
			glPopMatrix();
		glFlush();
		break;

	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
			drawAxisLines(-10, 10, -10, 10);
				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(1, 1);
				glVertex2f(5, 1);
			    glVertex2f(2, 3);
			    glEnd();
				glPopMatrix();
				glPushMatrix();	
				glColor3f(0.0, 0.0, 1.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(3, 1);
				glVertex2f(-1, 1);
			    glVertex2f(2, 3);
			    glEnd();
				glPopMatrix();
		glFlush();
		break;

	case '4':
		glClear(GL_COLOR_BUFFER_BIT);
			drawAxisLines(-10, 10, -10, 10);
				glPushMatrix();
				glColor3f(0.0, 0.0, 0.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(1, 1);
				glVertex2f(5, 1);
			    glVertex2f(2, 3);
			    glEnd();
				glPopMatrix();
				glPushMatrix();	
				glColor3f(0.0, 0.0, 1.0);
				glPointSize(10.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(-3/5 ,9/5);
				glVertex2f(-3, 5);
			    glVertex2f(2/5, 3.8);
			    glEnd();
				glPopMatrix();
		glFlush();
		break;

	
	default:
		glClear(GL_COLOR_BUFFER_BIT);
			drawAxisLines(-100, 100, -100, 100);
		glFlush();
		break;
	}
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void setTransformations() 
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
}

void initialize(int argc, char *argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Computer Graphics");
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboard);
	setTransformations();
	glutMainLoop();
}

void main(int argc, char *argv[])
{
	initialize(argc, argv);
}