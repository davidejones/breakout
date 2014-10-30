#include <GLFW/glfw3.h>
#include <iostream>
#include "GameWindow.h"
#include "Triangle.h"

using namespace std;

GameWindow *gameWindow;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

Triangle *triangle;

int main(void)
{  
    gameWindow = new GameWindow();
    triangle = new Triangle();

    cout << "game running.." << endl;

    /* Loop until the user closes the window */
    while (!gameWindow->windowShouldClose())
    {
        // Set frame time
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        triangle->render();

        gameWindow->render();
        gameWindow->update(deltaTime);
    }

    gameWindow->terminate();
    delete gameWindow;

    cout << "game ended.." << endl;
    
    return 0;
}