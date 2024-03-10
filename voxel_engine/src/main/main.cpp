#include "MainHeader.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main() {
	if (glfwInit() != GLFW_TRUE) {
		std::cerr << "Faild to initialize GLFW" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "test", nullptr, nullptr);
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


	glViewport(0, 0, WIDTH, HEIGHT);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}