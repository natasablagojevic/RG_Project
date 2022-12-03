#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;

void frame_buffer_function(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void pressed_key(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    // inicijalizacija
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(1600, 900, "Hello, window", NULL, NULL);
        if (window == NULL) {
            cout << "main: glfwCreateWindow failed" << endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frame_buffer_function);

    if (!gladLoadGLLoader((GLADloaderpoc) glfwGetProcAddress)) {
        cout << "main: GLAD initialization failed" << endl;
        exit(EXIT_FAILURE);
    }

    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();


    return 0;
}
