/*************************** 4105053102 唐健桓 第4次作業5/1 ***************************/
#include "GL\glut.h"
#include "stdio.h"
#include "math.h"
#define pi 3.14159
#define up 0
#define down 1
static int shoulder = 0, elbow = 0, fingerthumb = 0, fingerhead = 0;
static int eyex = 0.0, eyey = 0.0, eyez = 0.0, angle1 = 0.0, angle2 = 0.0;
static float atx = 0.0, aty = 0.0, atz = 0.0;
static float pitch = -90.0, head = 0.0, roll = 0.0;
static float spin = 0.0;
int keystates[256] = { up };


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}

void keyoperation(void)
{
	if (keystates['1'] == down)
	{
		shoulder = (shoulder - 2) % 360;
		glutPostRedisplay();
	}
	if (keystates['2'] == down)
	{
		elbow = (elbow - 2) % 360;
		glutPostRedisplay();
	}
	if (keystates['3'] == down)
	{
		fingerhead = (fingerhead - 2) % 360;
		glutPostRedisplay();
	}
	if (keystates['4'] == down)
	{
		fingerthumb = (fingerthumb + 2) % 360;
		glutPostRedisplay();
	}
	if ((keystates['W'] == down)|| (keystates['w'] == down))
	{
		atz += 0.05;
		glutPostRedisplay();
	}
	if ((keystates['A'] == down) || (keystates['a'] == down))
	{
		atx += 0.05;
		glutPostRedisplay();
	}
	if ((keystates['S'] == down) || (keystates['s'] == down))
	{
		atz -= 0.05;
		glutPostRedisplay();
	}
	
	if ((keystates['D'] == down) || (keystates['d'] == down))
	{
		atx -= 0.05;
		glutPostRedisplay();
	}
	if (keystates[27] == down)
		exit(0);
}

void display(void)
{
	keyoperation();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslated(atx, aty, atz);
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	glRotatef(eyex, 1.0, 0.0, 0.0);
	glRotatef(eyey, 0.0, 1.0, 0.0);
	glRotatef(eyez, 0.0, 0.0, 1.0);
	
	
	glColor3f(0.8, 0.8, 0.8);
	
	glPushMatrix();
	 glTranslatef(-4.0, 0.0, 0.0);
 	 glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	 glTranslatef(1.0, 0.0, 0.0);
	 glPushMatrix();
	  glScalef(1.2, 0.8, 1.2);
	  glutWireCube(1.0);
 	 glPopMatrix();
	glTranslatef(0.5, 0.0, 0.0);
	 glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	 glTranslatef(1.0, 0.0, 0.0);
	 glPushMatrix();
	  glScalef(2.0, 0.8, 1.0);
	  glutWireCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0.5, -0.25);
	glRotatef(30, 0.0, 0.0, 1.0);
	 glPushMatrix();
	  glScalef(0.5, 0.2, 0.2);
	  glutWireCube(1.0);
	 glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2, 0.5, 0.0);
	glRotatef(30, 0.0, 0.0, 1.0);
	  glPushMatrix();
	   glScalef(0.5, 0.2, 0.2);
	   glutWireCube(1.0);
	  glPopMatrix();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(1.2, 0.5, 0.25);
	 glRotatef(30, 0.0, 0.0, 1.0);
	  glPushMatrix();
	   glScalef(0.5, 0.2, 0.2);
	   glutWireCube(1.0);
	  glPopMatrix();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(1.43, 0.65, -0.25);
	 glRotatef((GLfloat)fingerhead, 0.0, 0.0, 1.0);
	 glRotatef(-30, 0.0, 0.0, 1.0);
	 glTranslatef(0.25, 0.0, 0.0);
	  glPushMatrix();
 	   glScalef(0.5, 0.2, 0.2);
	   glutWireCube(1.0);
	  glPopMatrix();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(1.43, 0.65, 0.0);
	 glRotatef((GLfloat)fingerhead, 0.0, 0.0, 1.0);
	 glRotatef(-30, 0.0, 0.0, 1.0);
	 glTranslatef(0.25, 0.0, 0.0);
	 glPushMatrix();
	 glScalef(0.5, 0.2, 0.2);
	 glutWireCube(1.0);
	 glPopMatrix();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(1.43, 0.65, 0.25);
	 glRotatef((GLfloat)fingerhead, 0.0, 0.0, 1.0);
	 glRotatef(-30, 0.0, 0.0, 1.0);
	 glTranslatef(0.25, 0.0, 0.0);
	  glPushMatrix();
	   glScalef(0.5, 0.2, 0.2);
	   glutWireCube(1.0);
	  glPopMatrix();
	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(1.0, -0.4, 0.25);
	 glRotatef((GLfloat)fingerthumb, 0.0, 0.0, 1.0);
	 glRotatef(-30, 0.0, 0.0, 1.0);
	 glTranslatef(0.25, 0.0, 0.0);
	  glPushMatrix();
	   glScalef(0.5, 0.2, 0.2);
	   glutWireCube(1.0);
	  glPopMatrix();
	 glPopMatrix();


	 glPushMatrix();
	  glTranslatef(1.5, 0.0, 0.0);
	  glPushMatrix();
	   glColor3f(1.0, 0.3, 0.3);
	   glutWireSphere(0.4, 20, 30);
	  glPopMatrix();

	  glRotatef(spin, 0.0, 1.0, 1.0);
	  glTranslated(1.25, 0.0, 0.0);
	  glRotatef(spin, 0.0, 0.0, 1.0);
	   glPushMatrix();
	    glColor3f(0.0, 0.0, 0.8);
	    glutWireSphere(0.3, 10, 20);
	   glPopMatrix();
	 glPopMatrix();

	glPopMatrix();

	glDisable(GL_DEPTH_TEST);

	//x,y,z座標
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-10.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, -10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, -10.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	glPopMatrix();

	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin = spin + 4.0;
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			eyex = (eyex + 30) % 360;
		glutPostRedisplay();
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			eyey = (eyey + 30) % 360;
		glutPostRedisplay();
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
			eyez = (eyez + 30) % 360;
		glutPostRedisplay();
		break;
	}
}
void keypress(unsigned char key, int x, int y)
{
	keystates[key] = down;
}
void keyup(unsigned char key, int x, int y)
{
	keystates[key] = up;
}

/*void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '1' :
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case '2':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case '3':
		fingerhead = (fingerhead - 5) % 360;
		glutPostRedisplay();
		break;
	case '4':
		fingerthumb = (fingerthumb + 5) % 360;
		glutPostRedisplay();
		break;
	case 'W':
	case 'w':
		atz += 0.2;
		glutPostRedisplay();
		break;
	case 'A':
	case 'a':
		atx -= 0.2;
		glutPostRedisplay();
		break;
	case 'S':
	case 's':
		atz -= 0.2;
		glutPostRedisplay();
		break;
	case 'D':
	case 'd':
		atx += 0.2;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}

}*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 720);
	glutInitWindowPosition(200, 10);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keypress);
	glutKeyboardUpFunc(keyup);
	glutIdleFunc(spinDisplay);
	glutMainLoop();
	return 0;
}
/*************************** 4105053102 唐健桓 第4次作業5/1 ***************************/