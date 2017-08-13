
#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>

class GameWindow {
    public:
        GameWindow();
        void RunGame();

    private:
        GLFWwindow *window;
        int width, height;
        std::string window_name;

        GLFWwindow* SetupGLFW();
};

#endif