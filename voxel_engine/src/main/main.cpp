#include "MainHeader.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main() {

	Window::Initialize(WIDTH, HEIGHT, "test");
	WindowEvents::Initialize();

	glClearColor(0, 0, 0, 1);

	while (!Window::CheckWindowShouldClose()) {
		WindowEvents::PullEvents();


		if (WindowEvents::JustPressed(GLFW_KEY_ESCAPE)) {
			Window::SetWindowShouldClose(true);
		}

		if (WindowEvents::JustClicked(GLFW_MOUSE_BUTTON_1))
		{
			glClearColor(1, 0, 0, 1);
		}
		glClear(GL_COLOR_BUFFER_BIT);

		Window::SwapBuffers();
	}

	glfwTerminate();
	return 0;
}