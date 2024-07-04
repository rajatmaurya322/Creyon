#include <iostream>

int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(600, 300, "CreyonEngine", nullptr, nullptr);

	if (window == nullptr) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
	}

	glfwSetCursorPosCallback(window, mousepos_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	while (!glfwWindowShouldClose(window)) {
		glViewport(0, 0, 600, 300);
		glClearColor(0.0f, 0.4f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);

		cubeShader.useProgram();
		cubeShader.setDirectionalLight("Dlight", Dlight);

		Mat44 model = scale(0.01f) * rotateX(-90.0f);
		Mat44 view = cam->lookAt();
		Mat44 proj = persp((float)600 / 300, 45.0f, 0.1f, 100.0f);

		sponza.Draw(cubeShader);

		//---------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}