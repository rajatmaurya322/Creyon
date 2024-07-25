#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window/WindowCallback.h"
#include "OpenGL/ShaderProgram.h"
#include "OpenGL/Camera.h"
#include "stb_image/stb_image.h"
#include "Math/Transforms.h"

int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	const int windowWidth = 800, windowHeight = 600;
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "CreyonEngine", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
	}

	Creyon::EventPublisher* p_eventPublisher = new Creyon::EventPublisher();
	std::shared_ptr<Creyon::Camera> p_camera{ std::make_shared<Creyon::Camera>() };
	p_eventPublisher->addSubscriber(p_camera);
	p_camera->m_position = Creyon::Vector3{ 0.0f, 0.0f, 3.0f };
	p_camera->m_front = Creyon::Vector3{ 0.0f, 0.0f, -1.0f };
	p_camera->m_worldUp = Creyon::Vector3{ 0.0f,1.0f,0.0f };
	p_camera->m_speed = 2.5f;
	p_camera->m_fieldOfView = 45.0f;
	p_camera->m_yaw = -90.0f;

	glfwSetFramebufferSizeCallback(window, Creyon::framebufferSizeCallback);
	glfwSetKeyCallback(window, Creyon::keyboardCallback);
	glfwSetCursorPosCallback(window, Creyon::cursorPositionCallback);
	glfwSetScrollCallback(window, Creyon::scrollCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetWindowUserPointer(window, p_eventPublisher);

	float cube[] = {
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

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	const std::filesystem::path rootPath = Creyon::searchRootDirectory();
	int width, height, nrChannels;
	std::string texturePath = (rootPath / "Sandbox\\src\\container.jpg").string();
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "failed to load image";
	}
	stbi_image_free(data);

	Creyon::ShaderProgram simpleShader;
	simpleShader.addShader(rootPath / "Creyon\\src\\Shaders\\LightSourceVS.glsl", GL_VERTEX_SHADER);
	simpleShader.addShader(rootPath / "Creyon\\src\\Shaders\\LightSourceFS.glsl", GL_FRAGMENT_SHADER);
	simpleShader.link();

	Creyon::Mat44 model;
	Creyon::Mat44 view;
	Creyon::Mat44 projection;
	glEnable(GL_DEPTH_TEST);
	
	float lastFrame = 0.0f, currentFrame = 0.0f;
	//render loop
	while (!glfwWindowShouldClose(window)) {
		currentFrame = (float)glfwGetTime();
		p_eventPublisher->m_deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame; 
		p_camera->m_target = p_camera->m_position + p_camera->m_front;
		p_eventPublisher->notifyKeyboard();
		glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		simpleShader.useProgram();
		model = Creyon::rotateY(currentFrame * Creyon::radianToDegree);
		view = p_camera->lookAt();
		projection = Creyon::perspective((float)windowWidth / windowHeight, p_camera->m_fieldOfView, 0.1f, 100.0f);
		simpleShader.setMat44("model", model);
		simpleShader.setMat44("view", view);
		simpleShader.setMat44("projection", projection);
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	delete p_eventPublisher;
	p_eventPublisher = nullptr;
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}