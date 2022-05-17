//#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#pragma comment(lib, "OpenGL32")

namespace MuSeoun
{
    struct vec2
    {
        float x;
        float y;

        vec2(int x_, int y_)
        {
            x = x_;
            y = y_;
        }
    };
    vec2 operator+(vec2 a, vec2 b)
    {
        vec2 result(a.x + b.x, a.y + b.y);
        return result;
    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(1000, 700, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    float x = -1;
    float y = -1;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            x -= 0.0005f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            x += 0.0005f;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            y += 0.0005f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            y -= 0.0005f;
        }

        glClearColor(1.0f, 1.0f, 1.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        //사각형 만들기
        glBegin(GL_TRIANGLE_STRIP);
        glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
        glVertex2f(x, y+0.4f);
        glVertex2f(x+0.4f, y+0.4f);
        glVertex2f(x, y);
        glVertex2f(x+0.4f, y);
        glEnd();

        glBegin(GL_TRIANGLE_STRIP);
        glColor4f(0.0f, 1.0f, 0.0f, 0.1f);
        glVertex2f(x, y + 0.4f);
        glVertex2f(x + 0.4f, y + 0.4f);
        glVertex2f(x, y);
        glVertex2f(x + 0.4f, y);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}