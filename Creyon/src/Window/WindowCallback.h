#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "EventPublisher.h"

namespace Creyon {

	void cursorPositionCallback(GLFWwindow* window, double x, double y);

	void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void scrollCallback(GLFWwindow* window, double x, double y);
}