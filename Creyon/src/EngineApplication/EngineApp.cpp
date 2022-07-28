#include "EngineApp.h"

//Shader code here------------------------------------------------
const char* vertexShaderSource =
"#version 430 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 acolor;\n"
"out vec3 ourcolor;\n"
"void main()\n"
"{\n"
"gl_Position= vec4(aPos, 1.0);\n"
"ourcolor = acolor;\n"
"}\0";

const char* fragmentShaderSource =
"#version 430 core\n"
"out vec4 FragColor;\n"
"in vec3 ourcolor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(ourcolor, 1.0);\n"
"}\0";

//----------------------------------------------------------------

namespace Creyon {

	EngineApp::EngineApp()
	{
		CreyonWindow::CreyonWindowInit();
		
		windowInstance = CreyonWindow{ 800,600,"LearnOpengl" };
		windowInstance.setContextCurrent();
		
		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			cout << "Failed to initialize GLAD\n";
		}

		glViewport(0, 0, 800, 600);

		windowInstance.register_Callback();

		Run();
	}

	void EngineApp::Run() {

		//Build, compile and link shader here---------------------------------------
		Shader vertexshader{ GL_VERTEX_SHADER };
		glShaderSource(vertexshader.getId(), 1, &vertexShaderSource, nullptr);
		vertexshader.shadercompile();

		//fragment shader
		Shader fragmentshader{ GL_FRAGMENT_SHADER };
		glShaderSource(fragmentshader.getId(), 1, &fragmentShaderSource, nullptr);
		fragmentshader.shadercompile();
		//Create shader program and link
		Shaderprogram programrect{ Creyon::Shader::getallIds() };
		programrect.link();
		//--------------------------------------------------------------------------

		//Set the data for rendering------------------------------------------------
		float vertices[]{ //position            //color
						  0.5f,  0.5f , 0.0f,	1.0f, 0.0f, 0.0f,
						  0.5f, -0.5f , 0.0f,	0.0f, 1.0f, 0.0f,
						 -0.5f, -0.5f , 0.0f,   0.0f, 0.0f, 1.0f,
						 -0.5f,  0.5f , 0.0f,	0.5f, 0.5f, 0.5f };

		unsigned int  indices[]{ 0, 1, 3,   //triangle 1
								 1, 2, 3 }; //triangle 2


		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//---------------------------------------------------------------------------

		//Render loop
		while (!windowInstance.isWindowClosed()) {

			//Processes all Input
			windowInstance.processInput();

			//Render commands here------------------------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(programrect.getId());
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			//---------------------------------------
			windowInstance.swapBuffers();
			windowInstance.pollWindowEvents();
		}
		CreyonWindow::CreyonWindowTerminate();
	}
}