#include "EngineApp.h"

namespace Creyon {

	EngineApp::EngineApp()
	{
		CreyonWindow::CreyonWindowInit();
		
		windowInstance = CreyonWindow(800,600, "Learnopengl");

		if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			cout << "Failed to initialize GLAD\n";
		}

		glViewport(0, 0, 800, 600);

		windowInstance.register_Callback();
	}

	void EngineApp::Run() {
		Shaderprogram programrect;
		
		programrect.addShader(
		"Render\\VertexShader.glsl", GL_VERTEX_SHADER);
		programrect.addShader(
		"Render\\FragmentShader.glsl",  GL_FRAGMENT_SHADER);
		
		programrect.link();

		//Set the data for rendering------------------------------------------------
		float vertices[]{ //position	//Texutre Coords
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};	 

		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		unsigned int texture, texture2;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		

		//sampling texture colors, filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		int width, height, nrchannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("GOW.jpg", &width, &height, &nrchannels, 0);
		if(data){
			//Creating textures
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "\nERROR: Failed to load texture";
		}
		stbi_image_free(data);

		glGenTextures(1, &texture2);
		glBindTexture(GL_TEXTURE_2D, texture2);
		
		//sampling texture colors, filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		data = stbi_load("awesomeface.png", &width, &height, &nrchannels, 0);
		if (data) {
			//Creating textures
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			std::cout << "\nERROR: Failed to load texture";
		}
		stbi_image_free(data);

		//unbind vao
		glBindVertexArray(0);
		//---------------------------------------------------------------------------
		glEnable(GL_DEPTH_TEST);
		//Render loop
		while (!windowInstance.isWindowClosed()) {

			//Processes all Input
			windowInstance.processInput();

			//Render commands here------------------------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, texture2);

			programrect.useProgram();
			glUniform1i(glGetUniformLocation(programrect.getId(), "ourTexture"), 0);
			glUniform1i(glGetUniformLocation(programrect.getId(), "ourTexture2"), 1);

			unsigned int transformloc = glGetUniformLocation(programrect.getId(), "transform");
			
			mat44 trans;
			mat44 model = /* rotateX((float)glfwGetTime(), false) */ rotateY((float)glfwGetTime(), false);
			mat44 view = translate(0.0f, 0.0f, -4.0f);
			mat44 proj = persp(800.0f / 600.0f, pi_u4, 100.0f, 0.1f);
			trans = trans  * model * view * proj;
			glUniformMatrix4fv(transformloc, 1, GL_TRUE, trans.m_elems);

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 36);

			//---------------------------------------
			windowInstance.swapBuffers();
			windowInstance.pollWindowEvents();
			//---------------------------------------
		}
		CreyonWindow::CreyonWindowTerminate(windowInstance);
	}
}