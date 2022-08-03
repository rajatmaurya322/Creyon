#include "CreyonWindow.h"

namespace Creyon {
	
	//Constructors
	CreyonWindow::CreyonWindow():m_width{600}, m_height{600}, mp_title{"New Window"}
	{
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
	}

	//Overloaded Constructors
	CreyonWindow::CreyonWindow(int width, int height, const char* title) 
	:m_width{ width }, m_height{ height }, mp_title{ title }
	{
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
		if (mp_window == nullptr) {
			std::cout << "Failed to create GLFW window\n";
			glfwTerminate();
		}
		setContextCurrent();
	}

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
		//Sets the user pointer to be retrieved back in the callback function
		glfwSetWindowUserPointer(mp_window, reinterpret_cast<void*>(this));  

		glfwSetFramebufferSizeCallback(mp_window, framebuffer_size_callback);
	}

	//Processes the keyboard input events
	void CreyonWindow::processInput() {
		if (glfwGetKey(mp_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetWindowShouldClose(mp_window, true);
		}
	}

	//Resizes the window to new height and width
	void CreyonWindow::setSize(const int nwidth, const int nheight) {
		glfwSetWindowSize(mp_window, nwidth, nheight);
	}

	// Properly terminates GLFW 
	void CreyonWindow::CreyonWindowTerminate(CreyonWindow& window) {
		glfwDestroyWindow(window.mp_window);
		window.mp_window = nullptr;
		window.mp_title = nullptr;
		glfwTerminate();
	}

	//callback function which resizes the framebuffer as the window size changes
	void CreyonWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height){
		
		//Get the user pointer of the window so as to get the class instance back
		CreyonWindow* self = reinterpret_cast<CreyonWindow*>(glfwGetWindowUserPointer(window));
		
		//Sets the members to new width and height
		self->setWidth(width);
		self->setHeight(height);

		glViewport(0, 0, width, height);

		std::cout << "\nheight:" << height << "width:" << width;
	}
}