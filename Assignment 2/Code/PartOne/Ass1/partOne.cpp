
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <windows.h>
#include <gl/glut.h>
#include <fstream>

const int WIDTH = 500;
const int HEIGHT = 500;

const int IMG_WIDTH = 250;
const int IMG_HEIGHT = 250;

GLuint LoadTextureRAW(const char * filename, int wrap)
{
	GLuint texture;
	int width, height;
	BYTE * data;
	FILE * file;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		return 0;
	}

	width = IMG_WIDTH;
	height = IMG_HEIGHT;

	data = (byte*)malloc(width * height * 3);

	fread(data, width * height * 3, 1, file);

	fclose(file);

	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glEnable(GL_TEXTURE_2D);

	return texture;
}

void drawQuad()
{
	GLuint texture1 = LoadTextureRAW("dice1.bmp", 0); 
	
	GLuint texture2 = LoadTextureRAW("dice2.bmp", 0);
	
	GLuint texture3 = LoadTextureRAW("dice3.bmp", 0);
	
	GLuint texture4 = LoadTextureRAW("dice4.bmp", 0);
	
	GLuint texture5 = LoadTextureRAW("dice5.bmp", 0);

	GLuint texture6 = LoadTextureRAW("dice6.bmp", 0);

	 // glBegin(GL_QUADS);		// Draw The Cube Using quads
  //  glColor3f(0.0f,1.0f,0.0f);	// Color Blue
  //  glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Top)
  //  glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Top)
  //  glVertex3f(-1.0f, 1.0f, 1.0f);	// Bottom Left Of The Quad (Top)
  //  glVertex3f( 1.0f, 1.0f, 1.0f);	// Bottom Right Of The Quad (Top)
  //  glColor3f(1.0f,0.5f,0.0f);	// Color Orange
  //  glVertex3f( 1.0f,-1.0f, 1.0f);	// Top Right Of The Quad (Bottom)
  //  glVertex3f(-1.0f,-1.0f, 1.0f);	// Top Left Of The Quad (Bottom)
  //  glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Bottom)
  //  glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Bottom)
  //  glColor3f(1.0f,0.0f,0.0f);	// Color Red	
  //  glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Front)
  //  glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Front)
  //  glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Front)
  //  glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Front)
  //  glColor3f(1.0f,1.0f,0.0f);	// Color Yellow
  //  glVertex3f( 1.0f,-1.0f,-1.0f);	// Top Right Of The Quad (Back)
  //  glVertex3f(-1.0f,-1.0f,-1.0f);	// Top Left Of The Quad (Back)
  //  glVertex3f(-1.0f, 1.0f,-1.0f);	// Bottom Left Of The Quad (Back)
  //  glVertex3f( 1.0f, 1.0f,-1.0f);	// Bottom Right Of The Quad (Back)
  //  glColor3f(0.0f,0.0f,1.0f);	// Color Blue
  //  glVertex3f(-1.0f, 1.0f, 1.0f);	// Top Right Of The Quad (Left)
  //  glVertex3f(-1.0f, 1.0f,-1.0f);	// Top Left Of The Quad (Left)
  //  glVertex3f(-1.0f,-1.0f,-1.0f);	// Bottom Left Of The Quad (Left)
  //  glVertex3f(-1.0f,-1.0f, 1.0f);	// Bottom Right Of The Quad (Left)
  //  glColor3f(1.0f,0.0f,1.0f);	// Color Violet
  //  glVertex3f( 1.0f, 1.0f,-1.0f);	// Top Right Of The Quad (Right)
  //  glVertex3f( 1.0f, 1.0f, 1.0f);	// Top Left Of The Quad (Right)
  //  glVertex3f( 1.0f,-1.0f, 1.0f);	// Bottom Left Of The Quad (Right)
  //  glVertex3f( 1.0f,-1.0f,-1.0f);	// Bottom Right Of The Quad (Right)
  //glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture2); //binding the texture with each side
	glBegin(GL_QUADS);
								// top
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-6.0f, 6.0f, 6.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(6.0f, 6.0f, 6.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(6.0f, 6.0f, -6.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-6.0f, 6.0f, -6.0f);
 
	glEnd();
 
	glBindTexture(GL_TEXTURE_2D, texture1);
	glBegin(GL_QUADS);
	// front
	glTexCoord2f(1.0, 1.0);
	glVertex3f(6.0f, -6.0f, 6.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(6.0f, 6.0f, 6.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-6.0f, 6.0f, 6.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-6.0f, -6.0f, 6.0f);
 
	glEnd();
 
	glBindTexture(GL_TEXTURE_2D, texture3);
	glBegin(GL_QUADS);
	// right
	glTexCoord2f(1.0, 1.0);
	glVertex3f(6.0f, 6.0f, -6.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(6.0f, 6.0f, 6.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(6.0f, -6.0f, 6.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(6.0f, -6.0f, -6.0f);
 
	glEnd();
 
	glBindTexture(GL_TEXTURE_2D, texture4);
	glBegin(GL_QUADS);
	// left
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-6.0f, -6.0f, 6.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-6.0f, 6.0f, 6.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-6.0f, 6.0f, -6.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-6.0f, -6.0f, -6.0f);
 
	glEnd();
 
	glBindTexture(GL_TEXTURE_2D, texture5);
	glBegin(GL_QUADS);
	// bottom
	glTexCoord2f(1.0, 1.0);
	glVertex3f(6.0f, -6.0f, 6.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-6.0f, -6.0f, 6.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-6.0f, -6.0f, -6.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(6.0f, -6.0f, -6.0f);
 
	glEnd();
 
	glBindTexture(GL_TEXTURE_2D, texture6);
	glBegin(GL_QUADS);
	//back
	glTexCoord2f(1.0, 1.0);
	glVertex3f(6.0f, 6.0f, -6.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(6.0f, -6.0f, -6.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-6.0f, -6.0f, -6.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-6.0f, 6.0f, -6.0f);
 
	glEnd();

}
//  Dice appears with an incline ,that is done intentionally 
void keyboard(unsigned char keyPressed, int xMouse, int yMouse)
{
	
	switch (keyPressed)
	{

	case '1':
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(5, 1.0f, 0.0f, 0.0f); //5 not 0 as to visualize the dice as a real object
		drawQuad();
		glPopMatrix();
		glFlush();
		break;

	case '2':
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(60, 1.0f, 0.0f, 0.0f);
		drawQuad();
		glPopMatrix();
		glFlush();
		break;

	case '3':
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(-90, 0.0f, 1.0f, 0.0f);
		drawQuad();
		glPopMatrix();
		glFlush();
		break;

	case '4':
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(75, 0.0f, 1.0f, 0.0f);
		drawQuad();
		glPopMatrix();
		glFlush();
		break;

	case '5':
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(285, 1.0f, 0.0f, 0.0f);
		drawQuad();
		glPopMatrix();
		glFlush();
		break;

	case '6':

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushMatrix();
		glRotatef(180, 1.0f, 0.0f, 0.0f);
		drawQuad();
		glPopMatrix();
		glFlush();
		break;


	default:
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glFlush();
		break;
	}
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glClearColor(0, 0, 0, 0);
	glClearDepth(1);
	drawQuad() ; 
	glEnable(GL_DEPTH_TEST);
	glFlush();
	glDisable(GL_TEXTURE_2D);
}

void setTransformations()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 400 / 400, 10, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 50, 0, 0, 0, 0, 1, 0);
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

void main(int argc, char **argv)
{
	initialize(argc, argv);
}

