
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <windows.h>
#include <gl/glut.h>
#include <fstream>
#include <math.h> 

const int WIDTH = 800;
const int HEIGHT = 600;
const double x=2 ; 
static float vertexafter[8][4]={{1/2,(1/2)-(1/2*sqrt(x)),(-1/2)+(1/2*sqrt(x))},{(1/2)+(1/sqrt(x)),1-(1/2*sqrt(x)),-1+(1/2*sqrt(x))},{(1/sqrt(x)),3/2,-1/2},{0,1,0},{1,(1)-(1/sqrt(x)),(1/sqrt(x))},{(1)+(1/sqrt(x)),(3/2)-(1/sqrt(x)),(-1/2)+(1/sqrt(x))},{(1/2)+(1/sqrt(x)),(2)-(1/2*sqrt(x)),(1/2*sqrt(x))},{1/2,(3/2)-(1/2*sqrt(x)),(-1/2)+(1/2*sqrt(x))} };
static float vertexbefore[8][4]={{0,0,0},{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1} };

void drawQuad()
{
	

	 glBegin(GL_QUADS);		// Draw The Cube Using quads
    glColor3f(0.0f,1.0f,0.0f);	// Color Blue
    glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);	// Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);	// Color Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);	// Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);	// Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);	// Color Red	
    glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);	// Color Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);	// Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);	// Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);	// Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);	// Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);	// Color Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);	// Color Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Right)
  glEnd();
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glClearColor(0, 0, 0, 0);
	glClearDepth(1);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	glTranslatef(0,0,25);//just for depth to see the cube more clearly  
	glTranslatef(0,1,0);//translate
	glRotatef(45,0,1,0) ; //alignment 1 
	glRotatef(-45,1,0,0) ; //allignment 1 
	glRotatef(45,0,0,1);   //rotation around z-axis 
	glRotatef(45,1,0,0) ; //alignment 2 
	glRotatef(-45,0,1,0) ; //allignment 2 
	glTranslatef(0,-1,0);//translate
	drawQuad();
	glPopMatrix();
	glFlush();
}

void setTransformations()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 400 / 400, 10, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 40, 0, 0, 0, 0, 1, 0);
}

void initialize(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGBA);
	glutCreateWindow("Quad Textures");
	setTransformations();
	glutDisplayFunc(draw);
	glutMainLoop();
}

void main(int argc, char **argv)
{
	initialize(argc, argv);
}


