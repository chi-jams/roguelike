
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include "GameWindow.h"

GameWindow::GameWindow() {

    width = 1280;
    height = 720;

    window = SetupGLFW();
}

void GameWindow::RunGame() {
    while( !glfwWindowShouldClose( window ) ) {
        glfwPollEvents();

        glfwSwapBuffers( window );
    }   
}


GLFWwindow* GameWindow::SetupGLFW() {

    // Fire up GLFW, if it fails kill the program
    if(!glfwInit()) {
        std::cout << "Error! Failed to initialize glfw!" << std::endl;
        return NULL;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = 
        glfwCreateWindow(width, height, "", NULL, NULL);

    glfwMakeContextCurrent(window);

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

    glViewport(0, 0, fbWidth, fbHeight);

    //glfwSetWindowAspectRatio(window, 16, 9);

    // The wonders of working with state machines and dynamic memory allocation
    return window;
}