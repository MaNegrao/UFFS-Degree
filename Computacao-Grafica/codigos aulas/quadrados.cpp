/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500

float x = -1.0, y = -0.3, yt = 1, xt = -0.3, sentido = 1;

int main() {
	GLFWwindow* window;
	int width, height;



	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		x += (0.00001 * sentido);

		if(x <= -1.0 || x >= 0.4){
			sentido *=-1;
		} 

		glBegin(GL_LINES);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(x, y, 0.f);
			glVertex3f(x, y+0.6, 0.f);
			glVertex3f(x, y, 0.f);
			glVertex3f(x+0.6, y, 0.f);
			glVertex3f(x+0.6, y, 0.f);
			glVertex3f(x+0.6, y+0.6, 0.f);
			glVertex3f(x+0.6, y+0.6, 0.f);
			glVertex3f(x, y+0.6, 0.f);			
		glEnd();

		glBegin(GL_LINES);
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(x*-1, y, 0.f);
			glVertex3f(x*-1, y+0.6, 0.f);
			glVertex3f(x*-1, y, 0.f);
			glVertex3f((x*-1)-0.6, y, 0.f);
			glVertex3f((x*-1)-0.6, y, 0.f);
			glVertex3f((x*-1)-0.6, y+0.6, 0.f);
			glVertex3f((x*-1)-0.6, y+0.6, 0.f);
			glVertex3f(x*-1, y+0.6, 0.f);			
		glEnd();

		glBegin(GL_TRIANGLES);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.f, yt, 0.f);
			glVertex3f(xt, yt-0.3, 0.f);
			glVertex3f(xt+0.6, yt-0.3, 0.f);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
