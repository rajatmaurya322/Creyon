#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Creyon {

	void mousePositionCallback(GLFWwindow* window, double x, double y);

	void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
}