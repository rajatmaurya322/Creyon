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
		int getWidth();
		int getHeight();

		//Methods
		static void CreyonWindowInit();
		void setContextCurrent();
		void processInput();
		void register_Callback();
		static void CreyonWindowTerminate();
		
		inline void swapBuffers() {
			glfwSwapBuffers(mp_window);
		}

		inline void pollWindowEvents() {
			glfwPollEvents();
		}

		inline bool isWindowClosed() {
			return glfwWindowShouldClose(mp_window);
		}

		//Destructor
		~CreyonWindow();
	};

	//Non_Member Functions
	void framebuffer_size_callback(GLFWwindow* window, int width, int height);
}
