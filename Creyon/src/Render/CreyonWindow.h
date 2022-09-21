#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

namespace Creyon {

	//This class abstracts over GLFW Window creation for ease of use
	class CreyonWindow
	{

	private:
		GLFWwindow* mp_window;	//prefix mp_ stands for member of class and is a pointer
		int m_width, m_height;
		const char* mp_title;

	public:

		//creates a default glfw window
		CreyonWindow();

		//creates a glfw window with given parameters
		CreyonWindow(int width, int height, const char* title);

		//Get methods
		inline int getWidth() { return m_width; }
		inline int getHeight(){ return m_height; }
		
		//Set methods
		inline void setWidth(const int nwidth) { m_width = nwidth ;}
		inline void setHeight(const int nheight) {m_height = nheight ;}
		
		//Properly initialises glfw
		static void CreyonWindowInit();
		
		//Sets context of the window object's window to current
		void setContextCurrent();

		//Registers the given window for resizing callback
		void register_Callback();

		//Processes the keyboard input events
		void processInput();

		//Resizes the window to new height and width
		void setSize(const int nwidth,const int nheight);
		
		//callback function which resizes the framebuffer as the window size changes
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		
		// Properly terminates glfw window
		static void CreyonWindowTerminate(CreyonWindow& window);

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

		//Returns elapsed Time from glfw initialisation
		static float getTime() {
			return (float)glfwGetTime();
		}

	};

}
