#include <iostream>
#include "ar_WGL.h"


ar_WGLKeyHandler(callbackFunction) {
    if (ar_WGLIsKeyPressed(GLFW_KEY_SPACE)) {
        std::cout << "Callback called(?)\n";
    }
}


int main()
{
    WGLWindow::init();

    WGLWindow winodw(250,250,"Window", NULL);
	
    while (!winodw.shouldClose()) { 

        winodw.setKeyCallback(callbackFunction);

        WGLWindow::pollEvents();
    }
	
    winodw.destroyWindow();
	WGLWindow::terminate();
}
