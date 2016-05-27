//
// Created by Darren Mothersele on 24/04/2016.
//

#ifndef EDITOR_RENDERER_H
#define EDITOR_RENDERER_H

#include <stdio.h>
#include <string.h>
#include "fontstash.h"

#include <iostream>
#include <GLFW/glfw3.h>
#include "glfontstash.h"

class Renderer {
private:
    GLFWwindow* window = nullptr;

    struct FONScontext* fs;
    int fontNormal;
    float dx, dy;
    unsigned int white;
    unsigned int brown;

public:
    int status;

    Renderer();
    ~Renderer();

    static void errorCallback(int error, const char* description);
    static void keyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

    int shouldClose();
    void render();
};


#endif //EDITOR_RENDERER_H
