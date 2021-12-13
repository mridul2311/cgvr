#include<stdio.h>
#include<gl/glut.h>
static GLfloat spin = 0;
void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(-0.25, -0.25);			//Use different coordinates to change the width and height
	glColor3f(0, 1, 0);
	glVertex2f(0.25, -0.25);
	glColor3f(0, 0, 1);
	glVertex2f(0.25, 0.25);
	glColor3f(1, 1, 0);
	glVertex2f(-0.25, 0.25);
	glEnd();
	glLoadIdentity();
	glRotatef(spin, 0, 0, 1);
	glFlush();
	glutSwapBuffers();

}
void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(-0.25, -0.25);			//Use different coordinates to change the width and height
	glColor3f(0, 1, 0);
	glVertex2f(0.25, -0.25);
	glColor3f(0, 0, 1);
	glVertex2f(0.25, 0.25);
	glColor3f(1, 1, 0);
	glVertex2f(-0.25, 0.25);
	glEnd();
	glFlush();
}

void spinDisplay() {
	spin += 0.02;
	glutPostRedisplay();
}

void mouse1(int button, int state, int x, int y) {

	if (button== GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
			glutIdleFunc(spinDisplay);
	else if(button== GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
			glutIdleFunc(NULL);
		
}
void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Single");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutDisplayFunc(display1);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Double");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutDisplayFunc(display2);
	glutMouseFunc(mouse1);
	glutMainLoop();
}
