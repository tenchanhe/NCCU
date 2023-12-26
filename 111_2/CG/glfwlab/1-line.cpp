#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

	}

	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	float index = 0;
	
	float pi = 3.1415926f;
	float R = 1.0f;
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBegin(GL_LINE_LOOP);
		GLfloat xA = R * cos(90 * pi / 180);
		GLfloat yA = R * sin(90 * pi / 180);
		GLfloat xB = R * cos(306 * pi / 180);
		GLfloat yB = R * sin(306 * pi / 180);
		GLfloat xC = R * cos(162 * pi / 180);
		GLfloat yC = R * sin(162 * pi / 180);
		GLfloat xD = R * cos(18 * pi / 180);
		GLfloat yD = R * sin(18 * pi / 180);
		GLfloat xE = R * cos(234 * pi / 180);
		GLfloat yE = R * sin(234 * pi / 180);
		glVertex2f(xA, yA);
		glVertex2f(xB, yB);
		glVertex2f(xC, yC);
		glVertex2f(xD, yD);
		glVertex2f(xE, yE);

		glEnd();

		//index += 0.00001f;

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
