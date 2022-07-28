#include "windowmanage.h"

namespace Creyon {

	//Constructors
	CreyonWindow::CreyonWindow():m_width{600}, m_height{600}, mp_title{"New window"}
	{
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
	}

	//Overloaded Constructor
	CreyonWindow::CreyonWindow(int width, int height, const char* title) 
	:m_width{ width }, m_height{ height }, mp_title{ title }
	{
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
		if (mp_window == nullptr) {
			std::cout << "Failed to create GLFW window\n";
			glfwTerminate();
		}
	}

	//Getters
	int CreyonWindow::getWidth() {
		return m_width;
	}

	int CreyonWindow::getHeight() {
		return m_height;
	}

	//Methods

	//Initializes glfw with Opengl version 4.3 and uses Core profile
	void CreyonWindow::CreyonWindowInit() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	
	//Sets the window as the context of the window object to current 
	void CreyonWindow::setContextCurrent() {
		glfwMakeContextCurrent(mp_window);
	}

	//Registers the given window for resizing callback
	void CreyonWindow::register_Callback(){
		glfwSetFramebufferSizeCallback(mp_window, framebuffer_size_callback);
	}

	//Processes the keyboard input events
	void CreyonWindow::processInput() {
		if (glfwGetKey(mp_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(mp_window, true);
		}
	}

	// Properly terminates GLFW 
	void CreyonWindow::CreyonWindowTerminate() {
		glfwTerminate();
	}

	//callback function which resizes the framebuffer as the window size changes
	void framebuffer_size_callback(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
	}

	//Destructors
	CreyonWindow::~CreyonWindow()
	{
		mp_window = nullptr;
		mp_title = nullptr;
	}
}