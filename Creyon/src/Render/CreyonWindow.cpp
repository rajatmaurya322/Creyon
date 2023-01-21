#include "CreyonWindow.h"

namespace Creyon {

	CreyonWindow::CreyonWindow(int width, int height, const char* title) 
	:m_width{ width }, m_height{ height }, mp_title{ title }
	{
		//Create a window with given width, height and title
		mp_window = glfwCreateWindow(m_width, m_height, mp_title, nullptr, nullptr);
		m_lastFrame = 0.0f;
		m_lastX = m_width / 2.0f;
		m_lastY = m_height / 2.0f;
		m_firstMouse = true;
		mp_cam = nullptr;

		if (mp_window == nullptr) {
			std::cout << "Failed to create GLFW window\n";
			glfwTerminate(); //Terminate glfw
		}

		setContextCurrent(); //Set window context as current
	}

	void CreyonWindow::Init() {
		glfwInit();  //Initialise glfw
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //Set Opengl version to 4.3 
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //Set to use core opengl profile
	}
	
	void CreyonWindow::setContextCurrent() {
		glfwMakeContextCurrent(mp_window);
	}

	void CreyonWindow::activateCamera(Camera& pcam) {
		//Takes the camera object and gives its address to the pointer
		mp_cam = &pcam;
	}

	void CreyonWindow::reg_ResizeCallback(){
		//Sets the user pointer to be retrieved back in the callback function
		glfwSetWindowUserPointer(mp_window, reinterpret_cast<void*>(this));
		glfwSetFramebufferSizeCallback(mp_window, framebuffer_size_callback);
	}

	void CreyonWindow::reg_MouseCallback() {
		glfwSetWindowUserPointer(mp_window, reinterpret_cast<void*>(this));
		glfwSetCursorPosCallback(mp_window, mouse_callback);
	}

	void CreyonWindow::closeWindow() {
		glfwSetWindowShouldClose(mp_window, true); //Close the window
	}

	bool CreyonWindow::keyPress(int key) {
		return glfwGetKey(mp_window, key) == GLFW_PRESS;
	}

	void CreyonWindow::processKeyboard() {
		float dT = deltaTime();
		float camSpeed = mp_cam->getSpeed() * dT;
		//Handle inputs related to the camera here
		if (keyPress(GLFW_KEY_ESCAPE))
			closeWindow();
		if (keyPress(GLFW_KEY_W))
			mp_cam->moveForward(camSpeed);
		if (keyPress(GLFW_KEY_S))
			mp_cam->moveBackward(camSpeed);
		if (keyPress(GLFW_KEY_A))
			mp_cam->moveLeft(camSpeed);
		if (keyPress(GLFW_KEY_D))
			mp_cam->moveRight(camSpeed);
	}

	void CreyonWindow::processMouse(float offsetX, float offsetY) {
		mp_cam->increaseAngle(offsetX, offsetY);
		mp_cam->rotateCamera();
	}

	float CreyonWindow::deltaTime() {
		//Calculating time taken to render previous frame
		float current = getTime();
		float delta = current - m_lastFrame;
		//updates lastFrame value
		m_lastFrame = current;
		return delta;
	}

	void CreyonWindow::setSize(const int nwidth, const int nheight) {
		glfwSetWindowSize(mp_window, nwidth, nheight);  //Sets window size to new width and height
	}

	void CreyonWindow::setInputMode(int mode, int value) {
		glfwSetInputMode(mp_window, mode, value);
	}
 
	void CreyonWindow::Terminate(CreyonWindow& window) {
		
		glfwDestroyWindow(window.mp_window); //Destroy the window
		window.mp_window = nullptr;  //Set object's pointers to null
		window.mp_title = nullptr;
		window.mp_cam = nullptr;
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

	void CreyonWindow::mouse_callback(GLFWwindow* window, double xpos, double ypos) {
		
		CreyonWindow* self = reinterpret_cast<CreyonWindow*>(glfwGetWindowUserPointer(window));

		float MouseXPos = static_cast<float>(xpos);
		float MouseYPos = static_cast<float>(ypos);

		//If first mouse movement, then prevent jumps by setting it to current position
		if (self->m_firstMouse) {
			self->m_lastX = MouseXPos;
			self->m_lastY = MouseYPos;
			self->m_firstMouse = false;
		}

		//Set the mouse sensitivity
		const float sensitivity = 0.5f;
		
		//Calculates the offset from mouse last position
		float offsetX = (MouseXPos - self->m_lastX)*sensitivity;
		float offsetY = (self->m_lastY - MouseYPos)*sensitivity;

		//Updates mouse last position to current position
		self->m_lastX = xpos;
		self->m_lastY = ypos;

		self->processMouse(offsetX, offsetY);
	}
}