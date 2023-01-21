#include "EngineApp.h"

namespace Creyon {

	void EngineApp::Run() {

		CreyonWindow::Init();

		CreyonWindow window{ 800,600, "Learnopengl" };

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			cout << "Failed to initialize GLAD\n";
		}

		glViewport(0, 0, 800, 600);

		window.reg_ResizeCallback();
		window.reg_MouseCallback();

		window.setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		Shaderprogram programrect;
		
		programrect.addShader("Render\\VertexShader.glsl", GL_VERTEX_SHADER);
		programrect.addShader("Render\\FragmentShader.glsl",  GL_FRAGMENT_SHADER);
		
		programrect.link();

		//Set the data for rendering------------------------------------------------
		std::vector<float> vertices{ //position	//Texture Coords
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

		//----------Camera Defined Here------------------------------
		
		Camera fpsCam;
		window.activateCamera(fpsCam);
		//-----------------------------------------------------------

		VertexArray vao;

		VertexBuffer vbo;
		vbo.loadData(vertices, GL_STATIC_DRAW);

		setVertexAttribPtr(0, 3, GL_FALSE, 5, 0);
		setVertexAttribPtr(1, 2, GL_FALSE, 5, 3);

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

		vao.unbind();
		//---------------------------------------------------------------------------
		glEnable(GL_DEPTH_TEST);
		
		//Render loop
		while (!window.isWindowClosed()) {

			//Processes all Input
			window.processKeyboard();

			//Render commands here------------------------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			tex1.setTexUnit(GL_TEXTURE0);
			tex2.setTexUnit(GL_TEXTURE1);

			programrect.useProgram();
			programrect.setInt("ourTexture", 0);
			programrect.setInt("ourTexture2", 1);
			
			unsigned int modelId = programrect.locateUniform("model");
			unsigned int viewId = programrect.locateUniform("view");	
			unsigned int projId = programrect.locateUniform("projection");
			
			vao.bind();
			
			mat44 view = fpsCam.lookAt();
			glUniformMatrix4fv(viewId, 1, GL_TRUE, view.m_elems);

			for(unsigned int i=0 ; i<10; ++i){
				mat44 model = rotateY(getTime()*(i+1), false) * translate(positions[i]);
				mat44 proj = persp(800.0f / 600.0f, pi_u4, 100.0f, 0.1f);
				glUniformMatrix4fv(modelId, 1, GL_TRUE, model.m_elems);
				glUniformMatrix4fv(projId, 1, GL_TRUE, proj.m_elems);

				glDrawArrays(GL_TRIANGLES, 0, 36);
			}

			//---------------------------------------
			window.swapBuffers();
			window.pollWindowEvents();
			//---------------------------------------
		}
		CreyonWindow::Terminate(window);
	}
}