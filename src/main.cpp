#include <GL/glut.h>

#include "palette/palette.hpp"

#include "picture/picture.hpp"

int main(int argc, char *argv[])
{
	Palette palette (250, 150, "Palette");
	// glutInit(&argc, argv);
	int w = 1366;
	int h = 768;
	// glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	// glutCreateWindow("My Paint");
	// glClearColor(1, 1, 1, 1);
	// glLoadIdentity();
	// glOrtho(0, w, h, 0, -2, 2);
	// glMatrixMode(GL_MODELVIEW);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glutDisplayFunc(display);
	// glutTimerFunc(20, timer, 0);
	// glutMouseFunc(mousePressed);
	// glutPassiveMotionFunc(mouseMove);
	// glutMotionFunc(mousePressedMove);
	// glutKeyboardFunc(keyboard);
	// glutSpecialFunc(specialKeyboard);
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	// glBegin(GL_TRIANGLE_STRIP);
	// glColor3d(1, 0, 0);
	// glVertex2i(50, 50);
	// glVertex2i(50, 100);
	// glColor3d(1, 1, 1);
	// glColor3d(0, 1, 0);
	// glVertex2i(100, 50);
	// glVertex2i(100, 100);
	// glColor3d(0, 0, 1);
	// glVertex2i(150, 50);
	// glVertex2i(150, 100);
	// glColor3d(1, 0, 0);
	// glVertex2i(200, 50);
	// glVertex2i(200, 100);
	// glEnd();
	// glBegin(GL_POINTS);
	// glVertex2i(100, 100);
	// glVertex2i(101, 100);
	// glVertex2i(100, 101);
	// glVertex2i(99, 100);
	// glColor3d(1, 0, 1);
	// glVertex2i(100, 99);
	// glEnd();
	glutSwapBuffers();
}

// void timer(int)
// {
// 	glutPostRedisplay();
// 	glutTimerFunc(20, timer, 0);
// }

void keyboard(unsigned char key, int x, int y)
{
	// std::ofstream file("asd.txt");
	// for (int i = 0; i < w; i += 5)
	// {
	// 	for (int j = 0; j < h; j += 5)
	// 	{
	// 		if (data[(i * h + j) * 3] > 0) file << "0";
	// 		else file << " ";
	// 	}	
	// 	file << "\n";
	// }
	// for (int i = 0; i < h; i += 10)
	// {
	// 	for (int j = 0; j < w; j += 10)
	// 	{
	// 		// for (int k = 0; k < 3; ++k)
	// 		if (data[(i * w + j) * 3 + 0] == 255)
	// 		{
	// 			file << "0";
	// 		}
	// 		else
	// 			file << " ";
	// 		// file << (int)data[(i * 4 + j) * 3 + k] << " ";
	// 		// file << "\t\t";
	// 	}
	// 	file << "\n";
	// }
	// file.close();
	switch(key)
	{
	case 27:
		glutDestroyWindow(1);
		exit(0);
		break;
	}
}
