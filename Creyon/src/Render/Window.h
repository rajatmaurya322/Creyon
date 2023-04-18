#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Core/Entity.h"
#include <iostream>

namespace Creyon {

	//This class abstracts over GLFW Window creation
	class Window
	{
	private:		//All class members begin with m_ prefix
		GLFWwindow* mp_window;
		std::string m_title;
		int m_width, m_height;
		float m_lastX, m_lastY, m_sensitivity;
		bool m_firstMouse;

	public:

		//creates a glfw window with given parameters
		Window(int width, int height, std::string title);
		
		//Properly initialises glfw
		static void Init();
		
		//Sets context of the window object's window to current
		void setContextCurrent();

		//Closes a window
		void closeWindow();

		//Sets the input mode for a window
		void setInputMode(int mode, int value);

		//Registers the given window for mouse callback
		void reg_Callbacks();

		//Executes when cursor position changes 
		static void mousepos_callback(GLFWwindow* window, double xpos, double ypos);
		
		//Executes when window size changes
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		//Executes when a key is pressed
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		
		~Window();

		// Properly terminates glfw
		static void Terminate();

		//Swap window buffers
		void swapBuffers() { glfwSwapBuffers(mp_window);}

		//Poll events for processing
		void pollWindowEvents() { glfwPollEvents();}
		
		//Checks if the window is closed
		bool isWindowClosed() { return glfwWindowShouldClose(mp_window);}

	};

}