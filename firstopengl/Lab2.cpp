// File ID: prog2.cpp
// Title: Working with Graphics Primitives
#define FREEGLUT_STATIC
#include <GL/freeglut.h>
void define_to_OpenGL();
///////////////////////////////////
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	// Task 2
	glutCreateWindow("Graphics Primitives");
	glutDisplayFunc(define_to_OpenGL);
	glutMainLoop();
}
///////////////////////////////////
void define_to_OpenGL()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	// The stuff to appear on screen goes here
	// Task 2
	// Task 3
	// Task 4
	// Task 5
	// Tasks 6, 7 and 8
	glFlush();
}
///////////////////////////////////