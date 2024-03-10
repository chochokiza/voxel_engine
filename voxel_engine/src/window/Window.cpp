#include "Window.h"
#include<iostream>


GLFWwindow* Window::window;

int Window::Initialize(int width, int height, const char* title)
{
	if (glfwInit() != GLFW_TRUE) {
		std::cerr << "Faild to initialize GLFW" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr) {
		std::cerr << "Faild to create GLFW Window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Faild to initialize GLEW" << std::endl;
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, width, height);

	return 0;
}

void Window::Terminate()
{
}

bool Window::CheckWindowShouldClose()
{
	return glfwWindowShouldClose(window);
}

void  Window::SetWindowShouldClose(bool flag)
{
	glfwSetWindowShouldClose(window, flag);
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(window);
}