#include "Game.h"

namespace Creyon {

	void Game::Run() {

		Window::Init();

		Window window{ 800,600, "Use Mouse to look, WASD to move, ESC to exit" };

		window.reg_Callbacks();

		window.setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		Shaderprogram cubeShader, lightSrcShader;

		cubeShader.addShader("Shaders\\PhongLightingVS.glsl", GL_VERTEX_SHADER);
		cubeShader.addShader("Shaders\\PhongLightingFS.glsl", GL_FRAGMENT_SHADER);

		cubeShader.link();

		lightSrcShader.addShader("Shaders\\LightSourceVS.glsl", GL_VERTEX_SHADER);
		lightSrcShader.addShader("Shaders\\LightSourceFS.glsl", GL_FRAGMENT_SHADER);

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
		setVertexAttribPtr(2, 2, GL_FALSE, 8, 6);

		VertexArray lightvao;
		vbo.setBufferAsTarget();
		setVertexAttribPtr(0, 3, GL_FALSE, 8, 0);

		Texture tex1;

		//sampling texture colors, filtering options
		tex1.TexWrap(GL_REPEAT, GL_REPEAT);
		tex1.TexFilters(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex1.TexFilters(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		tex1.loadImg("TexImages\\diffusemap.png", Texture::Format::PNG);

		Texture tex2;

		//sampling texture colors, filtering options
		tex2.TexWrap(GL_REPEAT, GL_REPEAT);
		tex2.TexFilters(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex2.TexFilters(GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		tex2.loadImg("TexImages\\specularmap.png", Texture::Format::PNG);

		VertexArray::unbind();
		//---------------------------------------------------------------------------
		glEnable(GL_DEPTH_TEST);

		cubeShader.useProgram();
		cubeShader.setInt("material.diffuse", 0);
		cubeShader.setInt("material.specular", 1);

		auto cam{ std::make_unique<Camera>() };

		//Render loop
		while (!window.isWindowClosed()) {

			Entity::updateDelta();

			cam->update();

			Entity::resetMotion();

			//Render commands here------------------------
			glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			cubeShader.useProgram();
			
			SpotLight splight{
				cam->m_pos, cam->m_front,
				{0.0f, 0.0f, 0.0f}, {1.0f,1.0f,1.0f}, {1.0f,1.0f,1.0f},
				1.0f, 0.09f, 0.032f, 
				5.5f, 8.0f
			};

			//Pass the Spotlight
			cubeShader.setSpotLight("splight", splight);

			//Material shininess
			cubeShader.setFloat("material.shininess", 32.0f);

			Mat44 model;
			Mat44 view = cam->lookAt();
			Mat44 proj = persp(800.0f / 600.0f, pi_u4, 100.0f, 0.1f);
			cubeShader.setMat44("view", view);
			cubeShader.setMat44("model", model);
			cubeShader.setMat44("projection", proj);
			cubeShader.setMat33("normalmat", NormalMatrix(model * view));

			tex1.setTexUnit(GL_TEXTURE0);
			tex2.setTexUnit(GL_TEXTURE1);
			cubevao.bind();
			glDrawArrays(GL_TRIANGLES, 0, 36);

			lightSrcShader.useProgram();

			Mat44 model2 = scale(0.2f) * translate(1.2f, 1.0f, 2.0f);
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