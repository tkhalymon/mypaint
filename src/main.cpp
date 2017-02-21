#include <GL/glut.h>

#include "picture/picture.hpp"

void display();
// void timer(int);
void mousePressed(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mousePressedMove(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	int w = 1366;
	int h = 768;
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(w, h);
	glutCreateWindow("My Paint");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	glOrtho(0, w, h, 0, -2, 2);
	glMatrixMode(GL_MODELVIEW);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(display);
	// glutTimerFunc(20, timer, 0);
	glutMouseFunc(mousePressed);
	glutPassiveMotionFunc(mouseMove);
	glutMotionFunc(mousePressedMove);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

// void timer(int)
// {
// 	glutPostRedisplay();
// 	glutTimerFunc(20, timer, 0);
// }

void mousePressed(int button, int state, int x, int y)
{

}

void mouseMove(int x, int y)
{

}

void mousePressedMove(int x, int y)
{
	display();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		glutDestroyWindow(1);
		exit(0);
		break;
	}
}

void specialKeyboard(int key, int x, int y)
{

}
