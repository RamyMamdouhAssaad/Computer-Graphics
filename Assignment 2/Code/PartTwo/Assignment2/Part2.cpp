


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <windows.h>
#include <gl/glut.h>
#include <fstream>

const int WIDTH = 800;
const int HEIGHT = 600;

const int IMG_WIDTH = 1024;
const int IMG_HEIGHT = 768;
const int IMG_WIDTH1 = 450;
const int IMG_HEIGHT1 = 300;
GLuint LoadTextureRAW1(const char * filename, int wrap)
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

	width = IMG_WIDTH1;
	height = IMG_HEIGHT1;

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
void background ()
{	
	
		GLuint texture1 = LoadTextureRAW1("sand1.bmp", 0);
		glBindTexture(GL_TEXTURE_2D, texture1);
	    glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0); 
		glVertex2f(-50, -50);
        glTexCoord2d(1.0,0.0); 
		glVertex2f(50, -50);
        glTexCoord2d(1.0,1.0);
		glVertex2f(50, 50);
        glTexCoord2d(0.0,1.0); 
		glVertex2f(-50, 50);
        glEnd();

}
void drawQuad()
{
	GLuint texture1 = LoadTextureRAW("pyramid.bmp", 0);


	glBindTexture(GL_TEXTURE_2D, texture1);
	glBegin(GL_TRIANGLES);
		glNormal3f(1,0,1); 
// first triangle
		glTexCoord2f(1.0, 1.0);
		glVertex3f(19,0,19); //
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0,29,0); //
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-19,0,19); //
	glEnd() ;
// second triangle
	glBindTexture(GL_TEXTURE_2D, texture1);
	glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(-19,0,19); 
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0,29,0); //
		glTexCoord2f(1.0, 0.0);
		glVertex3f(-19,0,-19); 
		glEnd() ;
// third triangle
		glBindTexture(GL_TEXTURE_2D, texture1);
		glBegin(GL_TRIANGLES);
		//glTexCoord2f(1.0, 1.0);
		glVertex3f(-19,0,-19);
		//glTexCoord2f(0.0, 1.0);
		glVertex3f(0,29,0); //
		//glTexCoord2f(1.0, 0.0);
		glVertex3f(19,0,-19); 
		glEnd() ;
// last triangle
		glBindTexture(GL_TEXTURE_2D, texture1);
		glBegin(GL_TRIANGLES);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(19,0,-19);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(0,29,0); //
		glTexCoord2f(1.0, 0.0);
		glVertex3f(19,0,19); //
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
	glRotatef(45, 0.0f, 1.0f, 0.0f);
	glTranslatef(0, 0, -8);
	background() ; 
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, -16.8, 0);
	glRotatef(-5, 0.0f, 1.0f, 0.0f);
	drawQuad();
	glFlush();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void setTransformations()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 400 / 400, 10, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(45, -15, 50, 0, 0, 0, 0, 1, 0);
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
