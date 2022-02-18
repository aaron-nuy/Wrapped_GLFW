#include <iostream>
#include "ar_WGL.h"

// Macro that defines a callback function "callbackFunction" 
// with the corrent signature
ar_WGLKeyHandler(callbackFunction) {
	
	// Macro that tests if space key is pressed
    if (ar_WGLIsKeyPressed(GLFW_KEY_SPACE)) {
        std::cout << "Callback called(?)\n";
    }
}


int main()
{
    WGLWindow::init();

    WGLWindow window(250,250,"Window", NULL);
	
    while (!window.shouldClose()) { 

        window.setKeyCallback(callbackFunction);

        WGLWindow::pollEvents();
    }
	
    window.destroyWindow();
    WGLWindow::terminate();
}
