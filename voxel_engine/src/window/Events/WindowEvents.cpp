#include "WindowEvents.h"
#include <GLFW/glfw3.h>
#include <string.h>

#define _MOUSE_BUTTONS 1024

bool* WindowEvents::_keys;
uint WindowEvents::numberOfKeys = 1032;
uint* WindowEvents::_frames;
uint WindowEvents::numberOfFrames = 1032;
uint WindowEvents::_current = 0;
float WindowEvents::deltaX = 0.0f;
float WindowEvents::deltaY = 0.0f;
float WindowEvents::x = 0.0f;
float WindowEvents::y = 0.0f;
bool WindowEvents::_cursor_loced = false;
bool WindowEvents::_cursor_started = false;


void curosr_position_callback(GLFWwindow* window, double xpos, double ypos) {
	if (WindowEvents::_cursor_started) {
		WindowEvents::deltaX += xpos - WindowEvents::x;
		WindowEvents::deltaY += ypos - WindowEvents::y;
	}
	else {
		WindowEvents::x = xpos;
		WindowEvents::y = ypos;
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) {
		WindowEvents::_keys[_MOUSE_BUTTONS + button] = true;
		WindowEvents::_frames[_MOUSE_BUTTONS + button] = WindowEvents::_current;
	}
	else if (action == GLFW_RELEASE) {
		WindowEvents::_keys[_MOUSE_BUTTONS + button] = false;
		WindowEvents::_frames[_MOUSE_BUTTONS + button] = WindowEvents::_current;
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		WindowEvents::_keys[key] = true;
		WindowEvents::_frames[key] = WindowEvents::_current;
	}
	else if (action == GLFW_RELEASE) {
		WindowEvents::_keys[key] = false;
		WindowEvents::_frames[key] = WindowEvents::_current;
	}
}

int WindowEvents::Initialize()
{
	GLFWwindow* window = Window::window;
	_keys = new bool[numberOfKeys]; // mouse and keyboard buttons
	_frames = new uint[numberOfFrames];

	memset(_keys, false, numberOfKeys * sizeof(bool));
	memset(_frames, false, numberOfFrames * sizeof(bool));

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, curosr_position_callback);

	return 0;
}


bool WindowEvents::Pressed(int keycode) {
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS) {
		return false;
	}
	return _keys[keycode];
}

bool WindowEvents::JustPressed(int keycode) {
	if (keycode < 0 || keycode >= _MOUSE_BUTTONS) {
		return false;
	}
	return _keys[keycode] && _frames[keycode] == _current;
}

bool WindowEvents::Clicked(int button)
{
	int index = _MOUSE_BUTTONS + button;
	return _keys[index];
}

bool WindowEvents::JustClicked(int button)
{
	int index = _MOUSE_BUTTONS + button;
	return _keys[index] && _frames[index] == _current;
}

void WindowEvents::PullEvents()
{
	_current++;
	deltaX = 0.0f;
	deltaY = 0.0f;
	glfwPollEvents();
}