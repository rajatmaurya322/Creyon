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

		vector3d positions[] = {
			vector3d{0.0f,  0.0f,  0.0f},
			vector3d{2.0f,  5.0f, -15.0f},
			vector3d{-1.5f,-2.2f, -2.5f},
			vector3d{-3.8f,-2.0f, -12.3f},
			vector3d{2.4f, -0.4f, -3.5f},
			vector3d{-1.7f, 3.0f, -7.5f},
			vector3d{1.3f, -2.0f, -2.5f},
			vector3d{1.5f,  2.0f, -2.5f},
			vector3d{1.5f,  0.2f, -1.5f},
			vector3d{-1.3f, 1.0f, -1.5f}
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

		Texture tex1;
		
		//sampling texture colors, filtering options
		tex1.configTexWrap(GL_REPEAT, GL_REPEAT);
		
		tex1.configTexFilters(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex1.configTexFilters(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		tex1.loadImg("GOW.jpg", Texture::Format::JPG);

		Texture tex2;
		
		//sampling texture colors, filtering options
		tex2.configTexWrap(GL_REPEAT, GL_REPEAT);

		tex2.configTexFilters(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex2.configTexFilters(GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		tex2.loadImg("awesomeface.png", Texture::Format::PNG);

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

			tex1.setTexUnit(GL_TEXTURE0);
			tex2.setTexUnit(GL_TEXTURE1);

			programrect.useProgram();
			glUniform1i(glGetUniformLocation(programrect.getId(), "ourTexture"), 0);
			glUniform1i(glGetUniformLocation(programrect.getId(), "ourTexture2"), 1);

			unsigned int transformloc = glGetUniformLocation(programrect.getId(), "transform");
			glBindVertexArray(VAO);
			
			for(unsigned int i=0 ; i<10; ++i){
				mat44 trans;
				mat44 model = rotateY((float)glfwGetTime()*(i+1), false)* rotateX((float)glfwGetTime(), false) * 
					scale(sinf((float)glfwGetTime())/2.0f + 0.5f) *translate(positions[i]);
				mat44 view = translate(0.0f, 0.0f, -5.0f);
				mat44 proj = persp(800.0f / 600.0f, pi_u4, 100.0f, 0.1f);
				trans = trans  * model * view * proj;
				glUniformMatrix4fv(transformloc, 1, GL_TRUE, trans.m_elems);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			//---------------------------------------
			windowInstance.swapBuffers();
			windowInstance.pollWindowEvents();
			//---------------------------------------
		}
		CreyonWindow::CreyonWindowTerminate(windowInstance);
	}
}