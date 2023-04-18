#include "Game.h"

namespace Creyon {

	void Game::Run() {

		Window::Init();

		Window window{ 800,600, "Use Mouse to look, WASD to move, ESC to exit" };

		window.reg_Callbacks();

		window.setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		Shaderprogram cubeShader, lightSrcShader;
		
		cubeShader.addShader("Render\\Shaders\\VertexShader.glsl", GL_VERTEX_SHADER);
		cubeShader.addShader("Render\\Shaders\\FragmentShader.glsl",  GL_FRAGMENT_SHADER);
		
		cubeShader.link();

		lightSrcShader.addShader("Render\\Shaders\\lightSource.glsl", GL_VERTEX_SHADER);
		lightSrcShader.addShader("Render\\Shaders\\lightSourceFragment.glsl", GL_FRAGMENT_SHADER);

		lightSrcShader.link();

		//Set the data for rendering------------------------------------------------
		std::vector<float> vertices{ 
		//position				//Normals			//Texture Coords
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,	0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,	1.0f, 0.0f,
		 0.5f, 0.5f, -0.5f,		0.0f, 0.0f, -1.0f,	1.0f, 1.0f,
		 0.5f, 0.5f, -0.5f,		0.0f, 0.0f, -1.0f,	1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f,		0.0f, 0.0f, -1.0f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, -1.0f,	0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,
		 0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	1.0f, 0.0f,
		 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,
		 0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,		-1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	-1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		-1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		 0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
		 0.5f, 0.5f, -0.5f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
		 0.5f, -0.5f, 0.5f,		1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
		 0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,	0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,	1.0f, 1.0f,
		 0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,	1.0f, 0.0f,
		 0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,	1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,		0.0f, -1.0f, 0.0f,	0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, -1.0f, 0.0f,	0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,
		 0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
		 0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		 0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f
		};

		VertexArray cubevao;

		VertexBuffer vbo;
		vbo.loadData(vertices, GL_STATIC_DRAW);
		setVertexAttribPtr(0, 3, GL_FALSE, 8, 0);
		setVertexAttribPtr(1, 3, GL_FALSE, 8, 3);

		VertexArray lightvao;
		vbo.setBufferAsTarget();
		setVertexAttribPtr(0, 3, GL_FALSE, 8, 0);

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
		Vector3d lightpos{ 1.2f, 1.0f, 2.0f };
		
		//Render loop
		while (!window.isWindowClosed()) {
			
			Entity::updateDelta();

			cam->update();

			Entity::resetMotion();

			//Render commands here------------------------
			glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			cubeShader.useProgram();
			Vector3d objcolor{ 1.0f, 0.5f, 0.31f };
			Vector3d ligcolor{ 1.0f, 1.0f, 1.0f };
			cubeShader.setVec3("lightColor", ligcolor);
			cubeShader.setVec3("objectColor", objcolor);
			cubeShader.setVec3("lightPos", lightpos);
			
			Mat44 model;
			Mat44 view = cam->lookAt() ;
			Mat44 proj = persp(800.0f / 600.0f, pi_u4, 100.0f, 0.1f);
			cubeShader.setMat44("view", view);
			cubeShader.setMat44("model", model);
			cubeShader.setMat44("projection", proj);
			cubeShader.setMat33("normalmat", NormalMatrix(model* view));
			
			cubevao.bind();
			glDrawArrays(GL_TRIANGLES, 0, 36);

			lightSrcShader.useProgram();
			
			Mat44 model2 = scale(0.2f) * translate(lightpos);
			lightSrcShader.setMat44("model", model2);
			lightSrcShader.setMat44("view", view);
			lightSrcShader.setMat44("projection", proj);
			
			lightvao.bind();
			glDrawArrays(GL_TRIANGLES, 0, 36);

			//---------------------------------------
			window.swapBuffers();
			window.pollWindowEvents();
		}

		Window::Terminate();
	}
}