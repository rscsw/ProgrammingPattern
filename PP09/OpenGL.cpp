#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#pragma comment(lib,"OpenGL32")

using namespace std;

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void MonsterisComing(float x)
{
	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(x, 0.0f);
	glEnd();
}

void main()
{
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) exit(EXIT_FAILURE);
	window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	float x = 1.0f;

	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0, 0, 0, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
		{
			glPointSize(10);
			glBegin(GL_POINTS);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(-0.5f, 0.5f);
			glEnd();
		}
		else
		{
			glPointSize(10);
			glBegin(GL_POINTS);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(-0.5f, 0.0f);
			glEnd();
		}

		MonsterisComing(x);
		x -= 0.001f;
		if (x >= 1.0f) x = -1.0f;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}