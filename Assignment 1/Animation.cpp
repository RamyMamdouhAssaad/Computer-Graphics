
#include <GL/glut.h>
float angle = 30.0f; 
void drawTriangle()
{
	
	glPushMatrix();
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glColor3f(1.0, 0.5, 0.0);
	glPointSize(10.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-25, 0);
	glVertex2f(25, 0);
	glVertex2f(0, 50);
	glutPostRedisplay() ; 
	glPopMatrix(); 
	glEnd();
	glPopMatrix();
	glutSwapBuffers();	

}


void update(int value) {
	
	angle += 2.0f;
	if (angle > 360) {
		angle -= 360;
	}
	
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
	

}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawTriangle() ; 
	
	glFlush();
}
void keyboard(unsigned char keyPressed, int xMouse, int yMouse)
{
	switch (keyPressed)
	{
	
	case '1':
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(draw);
			glFlush();
		break;
	}
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
	glutTimerFunc(25, update, 0);
	setTransformations();
	glutMainLoop();
}

void main(int argc, char *argv[])
{
	initialize(argc, argv);
}








