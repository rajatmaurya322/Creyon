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
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,	0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,	0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,	1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,	1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,	0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,	1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,	1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,	1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,	0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,	0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,	0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,	1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,	1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,	1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,	0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,	0.0f, 1.0f
	}; 

	unsigned int lightSrcVao;
	glGenVertexArrays(1, &lightSrcVao);
	glBindVertexArray(lightSrcVao);
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	unsigned int objectVao;
	glGenVertexArrays(1, &objectVao);
	glBindVertexArray(objectVao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	const std::filesystem::path rootPath = Creyon::searchRootDirectory();
	std::string texturePath = (rootPath / "Sandbox\\src\\container_diffuse.png").string();
	int width, height, nrChannels;
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
	unsigned int diffuseTexture;
	glGenTextures(1, &diffuseTexture);
	glBindTexture(GL_TEXTURE_2D, diffuseTexture);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load diffuse texture image";
	}
	stbi_image_free(data);
	texturePath = (rootPath / "Sandbox\\src\\container_specular.png").string();
	data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
	unsigned int specularTexture;
	glGenTextures(1, &specularTexture);
	glBindTexture(GL_TEXTURE_2D, specularTexture);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load specular texture image";
	}

	Creyon::ShaderProgram lightSrcShader;
	lightSrcShader.addShader(rootPath / "Creyon\\src\\Shaders\\LightSourceVS.glsl", GL_VERTEX_SHADER);
	lightSrcShader.addShader(rootPath / "Creyon\\src\\Shaders\\LightSourceFS.glsl", GL_FRAGMENT_SHADER);
	lightSrcShader.link();

	Creyon::ShaderProgram phongMaterialShader;
	phongMaterialShader.addShader(rootPath / "Creyon\\src\\Shaders\\PhongMaterialsVS.glsl", GL_VERTEX_SHADER);
	phongMaterialShader.addShader(rootPath / "Creyon\\src\\Shaders\\PhongMaterialsFS.glsl", GL_FRAGMENT_SHADER);
	phongMaterialShader.link();
	
	glEnable(GL_DEPTH_TEST);
	Creyon::Vector3 lightSrcPosition{1.2f, 1.0f, 2.0f};
	Creyon::Mat44 model, view, projection;
	Creyon::Mat33 normalMat;

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
		phongMaterialShader.useProgram();
		phongMaterialShader.setMat44("model", model);
		phongMaterialShader.setMat33("normalMat", normalMat);
		phongMaterialShader.setMat44("view", view);
		phongMaterialShader.setMat44("projection", projection);
		phongMaterialShader.setFloat("material.shininess", 64.0);
		phongMaterialShader.setVec3("directionalLight.direction", -lightSrcPosition);
		phongMaterialShader.setVec3("directionalLight.ambient", { 0.1f, 0.1f, 0.1f });
		phongMaterialShader.setVec3("directionalLight.diffuse", { 0.8f, 0.8f, 0.8f });
		phongMaterialShader.setVec3("directionalLight.specular", { 1.0f, 1.0f, 1.0f });
		phongMaterialShader.setInt("material.diffuse", 0);
		phongMaterialShader.setInt("material.specular", 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, diffuseTexture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, specularTexture);
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