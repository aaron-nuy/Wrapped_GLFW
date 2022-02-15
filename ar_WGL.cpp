#pragma once
#include "ar_WGL.h"

WGLWindow::WGLWindow(int width, int height, const std::string& title)
	:
	m_Window(glfwCreateWindow(width, height, title.c_str(), NULL, NULL))
{
}

WGLWindow::WGLWindow(WGLSize size, const std::string& title)
	:
	m_Window(glfwCreateWindow(size.width(), size.height(), title.c_str(), NULL, NULL))
{

}


int WGLWindow::init()
{
	return glfwInit();
}

void WGLWindow::terminate()
{
	glfwTerminate();
}

void WGLWindow::initHint(int hint, int value)
{
	glfwInitHint(hint, value);
}

void WGLWindow::pollEvents()
{
	glfwPollEvents();
}

void WGLWindow::setTitle(const std::string& title)
{
	glfwSetWindowTitle(m_Window, title.c_str());
}

void WGLWindow::makeContextCurrent()
{
	glfwMakeContextCurrent(m_Window);
}

void WGLWindow::detachContext()
{
	glfwMakeContextCurrent(NULL);
}

void WGLWindow::swapInterval(int value)
{
	glfwSwapInterval(value);
}

void WGLWindow::swapBuffers()
{
	glfwSwapBuffers(m_Window);
}

double WGLWindow::getTime()
{
	return glfwGetTime();
}

int WGLWindow::shouldClose()
{
	return glfwWindowShouldClose(m_Window);
}

void WGLWindow::setShouldClose(int value)
{
	glfwSetWindowShouldClose(m_Window, value);
}

int WGLWindow::isKeyPressed(int key)
{
	return glfwGetKey(m_Window,key) == GLFW_PRESS;
}

int WGLWindow::isKeyReleased(int key)
{
	return glfwGetKey(m_Window, key) == GLFW_RELEASE;;
}



int WGLWindow::isMousePressed()
{
	return glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}

int WGLWindow::isMouseReleased()
{
	return glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE;
}

WGLSize WGLWindow::getWindowSize()
{
	int width, height;
	glfwGetWindowSize(m_Window, &width, &height);
	return WGLSize(width,height);
}

void WGLWindow::setWindowSize(WGLSize size)
{
	glfwSetWindowSize(m_Window, size.width(), size.height());
}

void WGLWindow::setWindowSize(int width, int height)
{
	glfwSetWindowSize(m_Window, width, height);
}

WGLCoords WGLWindow::getCursorPosition()
{
	double x, y;
	glfwGetCursorPos(m_Window,&x,&y);
	return WGLCoords(x, y);
}

void WGLWindow::setCursorPosition(double x, double y)
{
	glfwSetCursorPos(m_Window, x, y);
}

void WGLWindow::setCursorPosition(WGLCoords coords)
{
	glfwSetCursorPos(m_Window, coords.x(), coords.y());
}

void WGLWindow::setInputMode(int mode, int value)
{
	glfwSetInputMode(m_Window, mode, value);
}

GLFWkeyfun WGLWindow::setKeyCallback(GLFWkeyfun callback_handler)
{
	return glfwSetKeyCallback(m_Window, callback_handler);
}

WGLCoords WGLWindow::getWindowPosition()
{
	int x, y;
	glfwGetWindowPos(m_Window, &x, &y);
	return WGLCoords(x,y);
}

void WGLWindow::setWindowPosition(WGLCoords coords)
{
	glfwSetWindowPos(m_Window, coords.x(), coords.y());
}

void WGLWindow::setWindowPosition(int x, int y)
{
	glfwSetWindowPos(m_Window, x, y);
}

WGLCoords::WGLCoords(double x, double y)
{
	m_x = x;
	m_y = y;
}

double WGLCoords::x()
{
	return m_x;
}

double WGLCoords::y()
{
	return m_y;
}

WGLSize::WGLSize(int width, int height)
{
	m_height = height;
	m_width = width;
}

int WGLSize::height()
{
	return m_height;
}

int WGLSize::width()
{
	return m_width;
}
