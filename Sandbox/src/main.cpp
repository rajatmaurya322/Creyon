#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window/WindowCallback.h"
#include "OpenGL/ShaderProgram.h"
#include "Math/Vector3.h"

int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(800, 600, "CreyonEngine", nullptr, nullptr);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
	}

	glfwSetFramebufferSizeCallback(window, Creyon::framebufferSizeCallback);
	glfwSetKeyCallback(window, Creyon::keyboardCallback);

	const std::filesystem::path rootPath = Creyon::searchRootDirectory();
	
	float triangle[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	Creyon::ShaderProgram simpleShader;
	simpleShader.addShader(rootPath / "Creyon/src/Shaders/LightSourceVS.glsl", GL_VERTEX_SHADER);
	simpleShader.addShader(rootPath / "Creyon/src/Shaders/LightSourceFS.glsl", GL_FRAGMENT_SHADER);
	simpleShader.link();

	//render loop
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.3f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		simpleShader.useProgram();
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}