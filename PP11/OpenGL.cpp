//#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <Windows.h>

#pragma comment(lib, "OpenGL32")

using namespace std;

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

class MyRectangle
{
public:
    float x;
    float y;
    void DrawRectangle(float r, float g, float b, float a, float xp, float yp)
    {
        glBegin(GL_TRIANGLE_STRIP);
        glColor4f(r, g, b, a);
        glVertex2f(x, y + yp);
        glVertex2f(x + xp, y + yp);
        glVertex2f(x, y);
        glVertex2f(x + xp, y);
        glEnd();
    }
    void Move()
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
        {
            x -= 0.00075f;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
        {
            x += 0.00075f;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
        {
            y += 0.00075f;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8001)
        {
            y -= 0.00075f;
        }
    }
};

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

    MyRectangle* player = new MyRectangle();
    MyRectangle* monster = new MyRectangle();

    player->x = 0.0f;
    player->y = 0.0f;
    monster->x = 0.0f;
    monster->y = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        player->DrawRectangle(0.0f, 0.0f, 1.0f, 1.0f, 0.3f, 0.3f);
        monster->DrawRectangle(1.0f, 0.0f, 0.0f, 1.0f, 0.4f, 0.4f);
        
        player->Move();

        //面倒 贸府
        if (player->x >= monster->x - 0.3f && player->x + 0.3f <= monster->x + 0.7f && player->y <= monster->y + 0.4f && player->y >= monster->y - 0.3f)
        {
            cout << "面倒 惯积" << endl;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}