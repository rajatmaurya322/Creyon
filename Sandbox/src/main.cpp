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
	p_camera->m_speed = 2.5f;
	p_camera->m_fieldOfView = 45.0f;
	p_camera->m_yaw = 0.0f;

	glfwSetWindowUserPointer(window, p_eventPublisher);
	glfwSetFramebufferSizeCallback(window, Creyon::framebufferSizeCallback);
	glfwSetKeyCallback(window, Creyon::keyboardCallback);
	glfwSetCursorPosCallback(window, Creyon::cursorPositionCallback);
	glfwSetScrollCallback(window, Creyon::scrollCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	float cube[] = {
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
	}; 

	unsigned int lightSrcVao;
	glGenVertexArrays(1, &lightSrcVao);
	glBindVertexArray(lightSrcVao);
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	unsigned int objectVao;
	glGenVertexArrays(1, &objectVao);
	glBindVertexArray(objectVao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	const std::filesystem::path rootPath = Creyon::searchRootDirectory();
	std::string texturePath = (rootPath / "Sandbox\\src\\container.jpg").string();
	int width, height, nrChannels;
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

	Creyon::ShaderProgram lightSrcShader;
	lightSrcShader.addShader(rootPath / "Creyon\\src\\Shaders\\LightSourceVS.glsl", GL_VERTEX_SHADER);
	lightSrcShader.addShader(rootPath / "Creyon\\src\\Shaders\\LightSourceFS.glsl", GL_FRAGMENT_SHADER);
	lightSrcShader.link();

	Creyon::ShaderProgram phongShader;
	phongShader.addShader(rootPath / "Creyon\\src\\Shaders\\PhongLightingVS.glsl", GL_VERTEX_SHADER);
	phongShader.addShader(rootPath / "Creyon\\src\\Shaders\\PhongLightingFS.glsl", GL_FRAGMENT_SHADER);
	phongShader.link();
	
	glEnable(GL_DEPTH_TEST);
	
	Creyon::Mat44 model, view, projection;
	Creyon::Mat33 normalMat;
	Creyon::Vector3 lightSrcPosition{ 1.2f, 1.0f, 2.0f };

	const float aspect = static_cast<float>(windowWidth)/windowHeight;
	float lastFrame = 0.0f, currentFrame = 0.0f, deltaTime = 0.0f;
	//render loop
	while (!glfwWindowShouldClose(window)) {
		currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame; 
		
		glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		p_eventPublisher->notifyKeyboard(deltaTime);
		model = Creyon::scale(0.2f) * Creyon::translate(lightSrcPosition) ;
		view = p_camera->lookAt();
		projection = Creyon::perspective(aspect, p_camera->m_fieldOfView, 0.1f, 100.0f);
		
		lightSrcShader.useProgram();
		lightSrcShader.setMat44("model", model);
		lightSrcShader.setMat44("view", view);
		lightSrcShader.setMat44("projection", projection);
		glBindVertexArray(lightSrcVao);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		model = Creyon::rotateY(Creyon::toDegree(currentFrame));
		normalMat = Creyon::calculateNormalMatrix(model * view);
		phongShader.useProgram();
		phongShader.setMat44("model", model);
		phongShader.setMat33("normalMat", normalMat);
		phongShader.setMat44("view", view);
		phongShader.setMat44("projection", projection);
		phongShader.setVec3("objectColor", Creyon::Vector3{1.0f, 0.5f, 0.31f});
		phongShader.setVec3("lightColor", Creyon::Vector3{1.0f, 1.0f, 1.0f});
		phongShader.setVec3("lightCoords", lightSrcPosition);
		glBindVertexArray(objectVao);
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