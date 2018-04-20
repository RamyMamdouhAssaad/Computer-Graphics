
#include <gl/glut.h>
void drawPoint(int x, int y)
{
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(4.0);

	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}
void bresenhamLine(int x1, int y1, int x2, int y2)
{
	int x = x1;
	int y = y1;
	int dx = x2 - x1;
	int dy = y2 - y1;
	int dT = 2 * (dy - dx);
	int dS = 2 * dy;
	int d = (2 * dy) - dx;
	
	drawPoint(x, y);

	while (x < x2)
	{
		x++;

		if (d < 0)
		{
			d += dS;
		}
		else
		{
			y++;
			d += dT;
		}

		drawPoint(x, y);
	}
}
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
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				bresenhamLine(5, 5, 50, 50);
			glPopMatrix();
		glFlush();
		break;

	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				glRotated(90, 0.0, 0.0,1.0);
				bresenhamLine(5, 5, 50, 50);
			glPopMatrix();
		glFlush();
		break;

	case '3':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				glRotated(180, 0.0, 0.0,1.0);
				bresenhamLine(5, 5, 50, 50);
			glPopMatrix();
		glFlush();
		break;

	case '4':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
				drawAxisLines(-100, 100, -100, 100);
				glRotated(270, 0.0, 0.0,1.0);
				bresenhamLine(5, 5, 50, 50);
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