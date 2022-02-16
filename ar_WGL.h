#pragma once
#include "glfw3.h"
#include <string>

#define ar_WGLKeyHandler(HandlerName) void HandlerName (GLFWwindow* window, int key, int scancode, int action, int mods)
#define ar_WGLIsKeyPressed(clicked) (key==clicked && action == GLFW_PRESS)
#define ar_WGLIsKeyReleased(clicked) (key==clicked && action == GLFW_RELEASE)
#define ar_WGLIsKeyRepeated(clicked) (key==clicked && action == GLFW_REPEAT)

#define ar_WGLMouseButtonHandler(HandlerName) void HandlerName (GLFWwindow* window, int button, int action, int mods)
#define ar_WGLIsMouseBtnPressed(clicked) (button==clicked && action == GLFW_PRESS)
#define ar_WGLIsMouseBtnReleased(clicked) (button==clicked && action == GLFW_RELEASE)



struct WGLSize {
private:
	int m_height;
	int m_width;
public:

	WGLSize(int width, int height);

	int height();
	int width();
};
struct WGLCoords {
private:
	double m_x;
	double m_y;
public:

	WGLCoords(double x, double y);

	double x();
	double y();
};

typedef GLFWmonitor* WGLMonitor;

class WGLWindow {

	GLFWwindow* m_Window;
	int m_isFullscreen;
public:

	
	WGLWindow();
	/*
		if primaryMonir is not specified, it initializes to null
		if primary monitor is specified with getPrimaryMonitor, window launchs in fullscreen mode
	*/
	WGLWindow(int width, int height, const std::string& title, WGLMonitor primaryMonitor = NULL);
	/*
	if primaryMonir is not specified, it initializes to null
	if primary monitor is specified with getPrimaryMonitor, window launchs in fullscreen mode
	*/
	WGLWindow(WGLSize size, const std::string& title, WGLMonitor primaryMonitor = NULL);
	~WGLWindow();

	void destroyWindow();

	static int init();
	static void terminate();
	static void initHint(int hint, int value);
	static void pollEvents();

	static WGLMonitor getPrimaryMonitor();

	void makeContextCurrent();
	void detachContext();

	void swapInterval(int value);
	void swapBuffers();

	double getTime();
	
	int shouldClose();
	void setShouldClose(int value);
	
	int isKeyPressed(int key);
	int isKeyReleased(int key);
	int isMousePressed(int button);
	int isMouseReleased(int button);

	GLFWkeyfun setKeyCallback(GLFWkeyfun callback_handler);
	GLFWmousebuttonfun setMouseButtonCallback(GLFWmousebuttonfun callback_handler);

	WGLSize getWindowSize();
	void setWindowSize(WGLSize size);
	void setWindowSize(int width,int height);

	WGLCoords getCursorPosition();
	void setCursorPosition(double x, double y);
	void setCursorPosition(WGLCoords coords);
	
	WGLCoords getWindowPosition();
	void setWindowPosition(WGLCoords coords);
	void setWindowPosition(int x,int y);

	void setInputMode(int mode, int value);
	void setTitle(const std::string& title);

	int isFullScreen();
	void setFullScreen();
	void setWindowed(int height, int width, int positionX, int positionY);
	void setWindowed(WGLSize size, WGLCoords coords);
};