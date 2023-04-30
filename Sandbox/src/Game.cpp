#include "Game.h"

namespace Creyon {

	void Game::Run() {

		Window::Init();

		Window window{ 800,600, "Use Mouse to look, WASD to move, ESC to exit" };

		window.reg_Callbacks();

		window.setInputMode(GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		
		//Flip image to look correct
		//stbi_set_flip_vertically_on_load(true);
		
		glEnable(GL_DEPTH_TEST);

		Shaderprogram cubeShader;

		cubeShader.addShader("Shaders\\PhongLightingVS.glsl", GL_VERTEX_SHADER);
		cubeShader.addShader("Shaders\\PhongLightingFS.glsl", GL_FRAGMENT_SHADER);

		cubeShader.link();
			  
		Model sponza{"sponza\\scene.gltf"};
		//Set the data for rendering------------------------------------------------
		
		auto cam{ std::make_unique<Camera>() };
		
		DirectionalLight Dlight{
			{-0.4f, -1.0f, -0.3f},
			{0.2f,0.2f,0.2f},
			{0.9f, 0.9f, 0.9f},
			{1.0f, 1.0f, 1.0f}
		};

		//Render loop
		while (!window.isWindowClosed()) {

			Entity::updateDelta();

			cam->update();

			Entity::resetMotion();

			//Render commands here------------------------
			glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			cubeShader.useProgram();

			//Pass the Spotlight
			cubeShader.setDirectionalLight("Dlight", Dlight);

			Mat44 model = scale(0.01f) * rotateX(-90.0f);
			Mat44 view = cam->lookAt();
			Mat44 proj = persp(800.0f / 600.0f, 45.0f, 0.1f, 100.0f);
			cubeShader.setMat44("model", model);
			cubeShader.setMat44("view", view);
			cubeShader.setMat44("projection", proj);
			cubeShader.setMat33("normalmat", NormalMatrix(model * view));
			sponza.Draw(cubeShader);
			
			//---------------------------------------
			window.swapBuffers();
			window.pollWindowEvents();
		}
		Window::Terminate();
	}
}