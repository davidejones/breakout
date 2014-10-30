#include <GLFW/glfw3.h>
#include <iostream>
#include "GameWindow.h"

using namespace std;

GameWindow *gameWindow;

int main(void)
{
    gameWindow = new GameWindow();

    cout << "game running.." << endl;

    /* Loop until the user closes the window */
    while (!gameWindow->windowShouldClose())
    {
        gameWindow->render();
        gameWindow->update();
    }

    gameWindow->terminate();
    delete gameWindow;
    
    return 0;
}