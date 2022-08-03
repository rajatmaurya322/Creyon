#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

namespace Creyon {

	class CreyonWindow
	{
	/*This class abstracts over GLFW Window creation for ease of use*/
	private:
		GLFWwindow* mp_window;	//prefix mp_ stands for member of class and is a pointer
		int m_width, m_height;
		const char* mp_title;

	public:

		//Default constructor
		CreyonWindow();

		//Overloaded Constructors
		CreyonWindow(int width, int height, const char* title);

		//Get methods
		inline int getWidth() { return m_width; }
		inline int getHeight(){ return m_height; }
		
		//Set methods
		inline void setWidth(const int nwidth) { m_width = nwidth ;}
		inline void setHeight(const int nheight) {m_height = nheight ;}

		//Methods
		static void CreyonWindowInit();
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		void setContextCurrent();
		void processInput();
		void register_Callback();
		void setSize(const int nwidth,const int nheight);
		static void CreyonWindowTerminate(CreyonWindow& window);
		
		//Inline Methods
		inline void swapBuffers() {
			glfwSwapBuffers(mp_window);
		}

		inline void pollWindowEvents() {
			glfwPollEvents();
		}

		inline bool isWindowClosed() {
			return glfwWindowShouldClose(mp_window);
		}

	};

	//Non_Member Functions
	
}
