
#include <gl/glut.h>
#include <math.h>
#define PI 3.14159
float angle=0.0 ; 
void drawChess()
{
	int coloumns,rows ; 
	coloumns=8 ; 
	float Xstart=0 ;
	float Ystart ; 
	float Yend ; 
	float Xend ; 
	rows=8 ;
	int counter =0 ; 

	glBegin(GL_QUADS);

	for(int i =0 ; i<rows ; i++)
	{	
			Ystart=i*(100/8);
			Yend=(i+1)*(100/8);
	     	
			for(int j=0 ; j<coloumns ; j++)

			{
				Xstart=j*(100/8);
				Xend=(j+1)*(100/8);
				if(counter %2==0)
				{
				if(j%2==0)
						{
						glColor3f(0.0, 0.0, 0.0);
						}
					else 
						{
							
						glColor3f(1.0, 1.0, 1.0);
						}
				
					glVertex2f(Xstart, Ystart);
					glVertex2f(Xend, Ystart);
					glVertex2f(Xend, Yend);	
					glVertex2f(Xstart, Yend);	
					
				
				}
				else
				{

					if(j%2!=0)
						{
							glColor3f(0.0, 0.0, 0.0);
						}
					else 
						{
							
							glColor3f(1.0, 1.0, 1.0);
						}
					glVertex2f(Xstart, Ystart);
					glVertex2f(Xend, Ystart);
					glVertex2f(Xend, Yend);	
					glVertex2f(Xstart, Yend);	
					
				}

			}
		counter++ ; 
	}
	
	
		glEnd();
		
}
void drawyang()
{
	float i, x, y;

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	for (i = -PI/2; i <=  PI/2; i += 0.01)
	{
		x = 50 * cos(i);
		y = 50 * sin(i);
		glVertex2f(x, y);
	}


	glEnd();

	glBegin(GL_LINE_STRIP);
	for (i = -PI; i <=  PI; i += 0.01)
	{
		x = 50 * cos(i);
		y = 50 * sin(i);
		glVertex2f(x, y);
	}

	glEnd() ; 
	glColor3f(0.0,0.0, 0.0);

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0, -25, 1.0); //Move to the center of the pentagon
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i <= 2 * PI; i += 0.1)
	{
		x = 25 * cos(i);
		y = 25 * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
	
	glPopMatrix();
	
	glColor3f(1.0,1.0, 1.0);

	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0, 25, 1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i <= 2 * PI; i += 0.1)
	{
		x = 25 * cos(i);
		y = 24.5 * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
	
	glPopMatrix();
	glColor3f(0.0,0.0, 0.0);
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0, 25, 1.0); //Move to the center of the pentagon
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i <= 2 * PI; i += 0.1)
	{
		x = 8.5 * cos(i);
		y = 8.5 * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
	
	glPopMatrix();
	glColor3f(1.0,1.0, 1.0);
	glPushMatrix(); //Save the current state of transformations
	glTranslatef(0, -25, 1.0); //Move to the center of the pentagon
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i <= 2 * PI; i += 0.1)
	{
		x = 8.5 * cos(i);
		y = 8.5 * sin(i);
		glVertex2f(x, y);
	}

	glEnd();
	
	glPopMatrix();
		
}
void drawTriangle()
{

	glPushMatrix();
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-25, 0);
	glVertex2f(25, 0);
	glVertex2f(0, 50);
	glutPostRedisplay() ; 
	glPopMatrix(); 
	glEnd();
		
			 
}
void drawTriangle1()
{


	glColor3f(1.0, 0.5, 0.0);
	glPointSize(10.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(-25, 0);
	glVertex2f(25, 0);
	glVertex2f(0, 50);
 
	glEnd();
		
			 
}
void update(int value) {
			angle += 0.10f;
			 if(angle > 360) 
			{
					angle -= 360;
			}
			  //Tell GLUT that the display has changed
	//	glutTimerFunc(50, update, 0);
		glutPostRedisplay() ; 
			 
	}

void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	
		glPushMatrix();
		drawTriangle() ; 
		glPopMatrix(); 
		glFlush() ; 
		glutPostRedisplay(); 
		glutSwapBuffers();
	
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)

	{
		drawTriangle1() ; 
	}
}
		

void keyboard(unsigned char keyPressed, int xMouse, int yMouse)
{
	
	switch (keyPressed)
	{
	
	case '1':
			glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
			glScalef(2,2,1);
			glTranslatef(-45,-45,1);
			drawChess() ; 
			glPopMatrix();
			glFlush();
		break;

	case '2':
		glClear(GL_COLOR_BUFFER_BIT);
			glPushMatrix();
			drawyang() ;
			glPopMatrix();
			glFlush();
	break ; 
	case'3':
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		drawTriangle1()  ;
		glPopMatrix();
		glFlush();
		break;
	default:
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush() ; 
		break ; 
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
	glutMouseFunc(myMouse);
	//glutTimerFunc(25, update, 0);
	setTransformations();
	glutMainLoop();
}

void main(int argc, char *argv[])
{
	initialize(argc, argv);
}
