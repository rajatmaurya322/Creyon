#include "CreyonWindow.h"

namespace Creyon {

	CreyonWindow::CreyonWindow():m_width{600}, m_height{600}, mp_title{"New Window"}
	{
		//Create a window with default width(600), height(600) and title(New Window)
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
	}
	
	CreyonWindow::CreyonWindow(int width, int height, const char* title) 
	:m_width{ width }, m_height{ height }, mp_title{ title }
	{
		//Create a window with given width, height and title
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
		
		if (mp_window == nullptr) {
			std::cout << "Failed to create GLFW window\n";
			glfwTerminate(); //Terminate glfw
		}

		setContextCurrent(); //Set window context as current
	}

	void CreyonWindow::CreyonWindowInit() {
		glfwInit();  //Initialise glfw
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //Set Opengl version to 4.3 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Set to use core opengl profile
	}
	
	void CreyonWindow::setContextCurrent() {
		glfwMakeContextCurrent(mp_window);
	}

	void CreyonWindow::register_Callback(){
		//Sets the user pointer to be retrieved back in the callback function
		glfwSetWindowUserPointer(mp_window, reinterpret_cast<void*>(this));  

		glfwSetFramebufferSizeCallback(mp_window, framebuffer_size_callback);
	}

	void CreyonWindow::processInput() {
		if (glfwGetKey(mp_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { //If ESC key is pressed
			glfwSetWindowShouldClose(mp_window, true); //Close the window
		}
	}

	void CreyonWindow::setSize(const int nwidth, const int nheight) {
		glfwSetWindowSize(mp_window, nwidth, nheight);  //Sets window size to new width and height
	}
 
	void CreyonWindow::CreyonWindowTerminate(CreyonWindow& window) {
		
		glfwDestroyWindow(window.mp_window); //Destroy the window
		window.mp_window = nullptr;  //Set object's pointers to null
		window.mp_title = nullptr;
		
		window.m_width = window.m_height = 0; //Set height and width to 0
		
		glfwTerminate(); //Terminate glfw
	}

	void CreyonWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height){
		
		//Get the user pointer of the window so as to get the class instance back
		CreyonWindow* self = reinterpret_cast<CreyonWindow*>(glfwGetWindowUserPointer(window));
		
		//Sets the members to new width and height
		self->setWidth(width);
		self->setHeight(height);

		glViewport(0, 0, width, height); //Resize viewport to new width and height
	}
}