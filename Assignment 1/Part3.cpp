#include <gl/glut.h>
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
void drawPoint(int x, int y)
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(4.0);

	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}
void drawCircleHelper(int xCenter, int yCenter, int x, int y)
{
	drawPoint(x + xCenter, y + yCenter);
	drawPoint(y + xCenter, x + yCenter);
	drawPoint(-x + xCenter, y + yCenter);
	drawPoint(-y + xCenter, x + yCenter);
	drawPoint(-x + xCenter, -y + yCenter);
	drawPoint(-y + xCenter, -x + yCenter);
	drawPoint(x + xCenter, -y + yCenter);
	drawPoint(y + xCenter, -x + yCenter);
}
void bresenhamCircle(int xCenter, int yCenter, int r)
{
	int x = 0;
	int y = r;
	int d = 3 - (2 * r);

	while (x < y)
	{		
		x++;

		if (d < 0)
		{
			d += 4 * x + 6;
		}
		else
		{
			y--;
			d += 4 * (x - y) + 10;
		}

		drawCircleHelper(xCenter, yCenter, x, y);
	}
}
void keyboard(unsigned char keyPressed, int xMouse, int yMouse)
{
	switch (keyPressed)
	{


	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				bresenhamCircle(50, 50, 25);
			glPopMatrix();
		glFlush();
		break;

	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				glTranslatef(-100, 0, 0);
				bresenhamCircle(50, 50, 25);
			glPopMatrix();
		glFlush();
		break;

	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				glTranslatef(-100, -100, 0);
				bresenhamCircle(50, 50, 25);
			glPopMatrix();
		glFlush();
		break;

	case '4':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				glTranslatef(0, -100, 0);
				bresenhamCircle(50, 50, 25);
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
	gluOrtho2D(-100, 100, -100, 100);
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