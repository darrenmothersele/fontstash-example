#include <iostream>
#define FONTSTASH_IMPLEMENTATION
#define GLFONTSTASH_IMPLEMENTATION
#include "src/Renderer.h"

using namespace std;

Renderer* renderer;

int main() {

    renderer = new Renderer();

    if (!renderer->status)
    {
        exit(EXIT_FAILURE);
    }


    while (!renderer->shouldClose())
    {

        renderer->render();
    }

    delete renderer;
    exit(EXIT_SUCCESS);
}