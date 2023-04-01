#include "EngineApp.h"

namespace Creyon {

	void EngineApp::Run() {

		CreyonWindow::Init();

		CreyonWindow window{ 800,600, "Use Mouse to look, WASD to move, ESC to exit" };

		window.reg_Callbacks();
		
		window.setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		Shaderprogram lightprog, lightcube;
		
		lightprog.addShader("Render\\Shaders\\VertexShader.glsl", GL_VERTEX_SHADER);
		lightprog.addShader("Render\\Shaders\\FragmentShader.glsl",  GL_FRAGMENT_SHADER);
		
		lightprog.link();

		lightcube.addShader("Render\\Shaders\\lightSource.glsl", GL_VERTEX_SHADER);
		lightcube.addShader("Render\\Shaders\\lightSourceFragment.glsl", GL_FRAGMENT_SHADER);

		lightcube.link();

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

		vector3d lightpos{ 1.2f, 1.0f, 2.0f };

		VertexArray cubevao;

		VertexBuffer vbo;
		vbo.loadData(vertices, GL_STATIC_DRAW);
		setVertexAttribPtr(0, 3, GL_FALSE, 5, 0);

		VertexArray lightvao;
		vbo.setBufferAsTarget();
		setVertexAttribPtr(0, 3, GL_FALSE, 5, 0);

		Texture tex1;
		
		//sampling texture colors, filtering options
		tex1.TexWrap(GL_REPEAT, GL_REPEAT);
		tex1.TexFilters(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex1.TexFilters(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		tex1.loadImg("GOW.jpg", Texture::Format::JPG);

		Texture tex2;
		
		//sampling texture colors, filtering options
		tex2.TexWrap(GL_REPEAT, GL_REPEAT);
		tex2.TexFilters(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex2.TexFilters(GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		tex2.loadImg("awesomeface.png", Texture::Format::PNG);

		cubevao.unbind();
		//---------------------------------------------------------------------------
		glEnable(GL_DEPTH_TEST);
		
		auto cam{ std::make_unique<Camera>() };
		
		//Render loop
		while (!window.isWindowClosed()) {
			
			Entity::updateDelta();

			cam->update();

			Entity::resetMotion();

			//Render commands here------------------------
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			lightprog.useProgram();
			vector3d objcolor{ 1.0f, 0.5f, 0.31f };
			vector3d ligcolor{ 1.0f, 1.0f, 1.0f };
			lightprog.setVec3("lightColor", ligcolor);
			lightprog.setVec3("objectColor", objcolor);
			
			Mat44 view = cam->lookAt() ;
			lightprog.setMat44("view", view);
			Mat44 model = timeRotateY();
			Mat44 proj = persp(800.0f / 600.0f, pi_u4, 100.0f, 0.1f);
			lightprog.setMat44("model", model);
			lightprog.setMat44("projection", proj);

			cubevao.bind();
			glDrawArrays(GL_TRIANGLES, 0, 36);

			lightcube.useProgram();
			
			Mat44 model2 = scale(0.2f) * translate(lightpos);
			lightcube.setMat44("model", model2);
			lightcube.setMat44("view", view);
			lightcube.setMat44("projection", proj);
			
			lightvao.bind();
			glDrawArrays(GL_TRIANGLES, 0, 36);

			//---------------------------------------
			window.swapBuffers();
			window.pollWindowEvents();
			//---------------------------------------
		}

		CreyonWindow::Terminate();
	}
}