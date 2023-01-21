#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Camera.h"
#include <iostream>

namespace Creyon {

	//This class abstracts over GLFW Window creation for ease of use
	class CreyonWindow
	{
	private:
		GLFWwindow* mp_window;	//prefix mp_ stands for member of class and is a pointer
		const char* mp_title;
		int m_width, m_height;
		float m_lastFrame, m_lastX, m_lastY;
		bool m_firstMouse;
		Camera* mp_cam;

	public:

		//creates a glfw window with given parameters
		CreyonWindow(int width, int height, const char* title);

		//Get methods
		inline int getWidth() { return m_width; }
		inline int getHeight(){ return m_height; }
		
		//Set methods
		inline void setWidth(const int width) { m_width = width ;}
		inline void setHeight(const int height) {m_height = height ;}
		
		//Properly initialises glfw
		static void Init();
		
		//Sets context of the window object's window to current
		void setContextCurrent();

		//Activates the Camera
		void activateCamera(Camera& pcam);

		//Registers the given window for resizing callback(reg is short for register)
		void reg_ResizeCallback();

		//Registers the given window for mouse callback
		void reg_MouseCallback();

		//Closes a window
		void closeWindow();

		//Detect a KeyPress
		bool keyPress(int key);

		//Processes all keyboard based input
		void processKeyboard();

		//Processes all mouse based input
		void processMouse(float offsetX, float offsetY);

		//Returns DeltaTime
		float deltaTime();

		//Resizes the window to new height and width
		void setSize(const int nwidth,const int nheight);

		//Sets the input mode for a window
		void setInputMode(int mode, int value);
		
		//callback function which resizes the framebuffer as the window size changes
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		//callback function which calculates mouse offsets
		static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
		
		// Properly terminates glfw window
		static void Terminate(CreyonWindow& window);

		//Swap window buffers
		inline void swapBuffers() {
			glfwSwapBuffers(mp_window);
		}

		//Poll events for processing
		inline void pollWindowEvents() {
			glfwPollEvents();
		}

		//Checks if the window is closed
		bool isWindowClosed() {
			return glfwWindowShouldClose(mp_window);
		}

	};

	//Returns elapsed Time from glfw initialisation
	inline float getTime() {
		return (float)glfwGetTime();
	}

}