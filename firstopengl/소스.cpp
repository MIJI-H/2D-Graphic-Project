// Material properties
#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <stdlib.h>
GLfloat diffuseMaterial[4] = { 0.5, 0.5, 0.5, 1.0 };
// Define light and material properties
void myinit(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // Directional light
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 25.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}
// Define keyboard event for incrementally changing the RGB component values separately
//void keyboard_input(unsigned char key, int x, int y) {
//	if (key == 'r' || key == 'R') {
//		diffuseMaterial[0] += 0.1;
//		if (diffuseMaterial[0] > 1.0)
//			diffuseMaterial[0] = 0.0;
//	}
//	else if (key == 'g' || key == 'G') {
//		diffuseMaterial[1] += 0.1;
//		if (diffuseMaterial[1] > 1.0)
//			diffuseMaterial[1] = 0.0;
//	}
//	else if (key == 'b' || key == 'B') {
//		diffuseMaterial[2] += 0.1;
//		if (diffuseMaterial[2] > 1.0)
//			diffuseMaterial[2] = 0.0;
//	}
//	glColor4fv(diffuseMaterial);
//	glutPostRedisplay();
//}
// Draw a solid sphere
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidSphere(1.0, 50, 10); // Radius, Longitude subdivisions and Latitude subdivisions
	glFlush();
}
//This will be called when the viewport is changed
void myReshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
		glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lighting Materials");
	myinit();
	/*glutKeyboardFunc(keyboard_input);*/
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMainLoop();
}