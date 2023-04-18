#include "Window.h"

namespace Creyon {

	Window::Window(int width, int height, std::string title) 
	:m_width{ width }, 
	 m_height{ height }, 
	 m_title{ title },
	 m_lastX{ width / 2.0f },
	 m_lastY{ height / 2.0f },
	 m_firstMouse{ true },
	 m_sensitivity{ 0.3f}

	{
		//Creates a window
		mp_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

		if (mp_window == nullptr) {
			std::cout << "Failed to create GLFW window\n";
			glfwTerminate(); //Terminate glfw
		}

		setContextCurrent();

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD\n";
		}

		glViewport(0, 0, m_width , m_height);

		//Sets the user pointer to be retrieved back in the callback function
		glfwSetWindowUserPointer(mp_window, reinterpret_cast<void*>(this));
	}

	void Window::Init() {
		glfwInit();  //Initialise glfw
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //Set Opengl version to 4.3 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Set to use core opengl profile
	}
	
	void Window::setContextCurrent() {
		glfwMakeContextCurrent(mp_window);
	}

	void Window::closeWindow() {
		glfwSetWindowShouldClose(mp_window, true); //Sets flag to close the window
	}

	void Window::setInputMode(int mode, int value) {
		glfwSetInputMode(mp_window, mode, value);
	}

	void Window::reg_Callbacks(){
		glfwSetCursorPosCallback(mp_window, mousepos_callback);
		glfwSetFramebufferSizeCallback(mp_window, framebuffer_size_callback);
		glfwSetKeyCallback(mp_window, key_callback);
	}

	void Window::mousepos_callback(GLFWwindow* window, double xpos, double ypos) {

		Window* self = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));

		float mouseX = static_cast<float>(xpos);
		float mouseY = static_cast<float>(ypos);
		
		//If first mouse movement, then prevent jumps by setting it to current position
		if (self->m_firstMouse) {
			self->m_lastX = mouseX;
			self->m_lastY = mouseY;
			self->m_firstMouse = false;
		}

		//Calculates the offset from mouse last position
		float offsetX = (mouseX - self->m_lastX) * self->m_sensitivity;
		float offsetY = (self->m_lastY - mouseY) * self->m_sensitivity;

		//Updates mouse last position to current position
		self->m_lastX = mouseX;
		self->m_lastY = mouseY;

		Entity::changeMousePosition(offsetX, offsetY);
	}

	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height){
		
		//Get the user pointer of the window so as to get the class instance back
		Window* self = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		
		//Set the members to new width and height
		self->m_width = width;
		self->m_height = height;
		
		glViewport(0, 0, width, height); //Resize viewport to new width and height
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		
		Window* self = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			self->closeWindow();
		else if (action == GLFW_PRESS) {
			Entity::changeKeyState(true, key, scancode, mods);
		}
		else if (action == GLFW_RELEASE) {
			Entity::changeKeyState(false, key, scancode, mods);
		}
		
	}

	Window::~Window() {
		glfwDestroyWindow(mp_window); //Destroy the window
		mp_window = nullptr;
	}

	void Window::Terminate() {
		glfwTerminate(); //Terminate glfw
	}

}