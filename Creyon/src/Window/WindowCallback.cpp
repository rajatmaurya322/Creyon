#include "WindowCallback.h"

namespace Creyon {

	void cursorPositionCallback(GLFWwindow* window, double x, double y) {
		EventPublisher* p_eventPublisher = reinterpret_cast<EventPublisher*>(glfwGetWindowUserPointer(window));
		p_eventPublisher->notifyCursor(static_cast<float>(x), static_cast<float>(y));
	}

	void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		EventPublisher* p_eventPublisher = reinterpret_cast<EventPublisher*>(glfwGetWindowUserPointer(window));
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
		else if(action == GLFW_PRESS){
			p_eventPublisher->setKeyState(key, true);
		}
		else if (action == GLFW_RELEASE) {
			p_eventPublisher->setKeyState(key, false);
		}
			
	}

	void scrollCallback(GLFWwindow* window, double x, double y) {
		EventPublisher* p_eventPublisher = reinterpret_cast<EventPublisher*>(glfwGetWindowUserPointer(window));
		p_eventPublisher->notifyMouseScroll(static_cast<float>(x), static_cast<float>(y));
	}

}