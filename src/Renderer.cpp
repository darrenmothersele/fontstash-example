//
// Created by Darren Mothersele on 24/04/2016.
//

#include "Renderer.h"


Renderer::Renderer() {
    glfwSetErrorCallback(this->errorCallback);
    status = glfwInit();
    if (status)
    {
        window = glfwCreateWindow(640, 480, "Editor", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            status = GL_FALSE;
        }
        else
        {
            glfwMakeContextCurrent(window);
            glfwSwapInterval(1);
            glfwSetKeyCallback(window, this->keyCallback);
        }
    }

    fs = glfonsCreate(512, 512, FONS_ZERO_TOPLEFT);
    fontNormal = fonsAddFont(fs, "sans", "res/DroidSansMono.ttf");
    if (fontNormal == FONS_INVALID)
    {
        std::cout << "Could not load font" << std::endl;
    }

    dx = 10;
    dy = 10;
    white = glfonsRGBA(255,255,255,255);
    brown = glfonsRGBA(192,128,0,128);
}

Renderer::~Renderer() {

    glfonsDelete(fs);

    if (status)
    {
        if (window)
        {
            glfwDestroyWindow(window);
        }
        glfwTerminate();
    }
}

void Renderer::errorCallback(int error, const char* description) {
    std::cerr << "[" << error << "] " << description << std::endl;
}

void Renderer::keyCallback(GLFWwindow *window, int key, int scanCode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

int Renderer::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Renderer::render() {

    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

//    glViewport(0, 0, width, height);
//    glClearColor(0.3f, 0.3f, 0.32f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glDisable(GL_TEXTURE_2D);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0,width,height,0,-1,1);
//
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glDisable(GL_DEPTH_TEST);
//    glColor4ub(255,255,255,255);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_CULL_FACE);



    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_TEXTURE_2D);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glOrtho(0,width,height,0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glDisable(GL_DEPTH_TEST);
    glColor4ub(255,255,255,255);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);

    fonsClearState(fs);

//    glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.f, 0.f, 0.f);
//    glVertex3f(-0.6f, -0.4f, 0.f);
//    glColor3f(0.f, 1.f, 0.f);
//    glVertex3f(0.6f, -0.4f, 0.f);
//    glColor3f(0.f, 0.f, 1.f);
//    glVertex3f(0.f, 0.6f, 0.f);
//    glEnd();

    fonsSetFont(fs, fontNormal);
    fonsSetSize(fs, 124.0f);
    fonsSetColor(fs, white);
    fonsDrawText(fs, dx,dy,"The big ", NULL);

    fonsSetSize(fs, 24.0f);
    fonsSetColor(fs, brown);
    fonsDrawText(fs, dx,dy,"brown fox", NULL);

    fonsDrawDebug(fs, 800.0, 50.0);

    glEnable(GL_DEPTH_TEST);


    glfwSwapBuffers(window);
    glfwPollEvents();
}











