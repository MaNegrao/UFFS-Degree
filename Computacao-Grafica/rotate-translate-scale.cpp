/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>

int bTran = 1, bScale = 0, bRotate = 0, sTran = 1, sScale = 1, sRotate = 1;
float xTran = 0, xRotate = 0, xScale = 1;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();


	// Render a red square
	// glColor3f(1, 0, 0);
	// glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	// glTranslatef(0.2f, 0.2f, 0);
	// glRectf(-0.1f, 0.1f, 0.1f, -0.1f);


	// Render a blue square
	glColor3f(0, 0, 1);
	if(bScale){
		xScale += (0.00001 * sScale);
	}
	glScalef(xScale, xScale, 0);
	
	if(bRotate){
		xRotate += (0.001);
		if(xRotate >= 360){
			xRotate = 0;
		}
	}

	glRotatef(xRotate, 0, 0, 1.0f);
	if(bTran){
		xTran += (0.00001 * sTran);
		if(xTran <= -0.9 || xTran >= 0.9){
			sTran *=-1;
		} 
	}
	glTranslatef(xTran, 0, 0);
	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 49){
		if(bRotate)
			bRotate = 0;
		else
			bRotate = 1;
	}
	
	else if (key == 50) {
		if(bTran)
			bTran = 0;
		else
			bTran = 1;
	}
	else if (key == 51){
		if(bScale)
			bScale = 0;
		else
			bScale = 1;
	}	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);

	glutMainLoop();
	return 0;
}