#include "WindowCallback.h"

namespace Creyon {

	void mousePositionCallback(GLFWwindow* window, double x, double y) {
		float mouseX = static_cast<float>(x);
		float mouseY = static_cast<float>(y);
	}

	void framebufferSizeCallback(GLFWwindow* window, int width, int height) {

	}

	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
		else if (action == GLFW_PRESS) {
		}
		else if (action == GLFW_RELEASE) {
		}

	}

}