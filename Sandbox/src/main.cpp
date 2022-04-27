#include "CreyonEng.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

//Shader code here------------------------------------------------
const char* vertexShaderSource =
"#version 430 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 acolor;\n"
"out vec3 ourcolor;\n"
"void main()\n"
"{\n"
"gl_Position= vec4(aPos, 1.0);\n"
"ourcolor = acolor;\n"
"}\0";

const char* fragmentShaderSource =
"#version 430 core\n"
"out vec4 FragColor;\n"
"in vec3 ourcolor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(ourcolor, 1.0);\n"
"}\0";

//----------------------------------------------------------------

int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpengl", nullptr, nullptr);
	if (window == nullptr) {
		cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "Failed to initialize GLAD\n";
		return -1;
	}
	glViewport(0, 0, 800, 600);

	glfwSetFramebufferSizeCallback(window, Creyon::framebuffer_size_callback);
	
	//Build, compile and link shader here---------------------------------------
	unsigned int vertexShader;   //vertexshader
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);
	//Check for compilation errors
	int successv;
	char infolog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successv);
	if (!successv) {
		glGetShaderInfoLog(vertexShader, 512, nullptr, infolog);
		cout << "Error: Vertex Shader compilation failed\n" << infolog << "\n";
	}
	//fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);
	//Check for compilation errors
	int successf;
	char infologf[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &successf);
	if (!successf) {
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infologf);
		cout << "Error: Fragment Shader compilation failed\n" << infologf << "\n";
	}
	//Create shader program and link
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	//Linking
	glLinkProgram(shaderProgram);
	//Check for linking errors
	int successp;
	char infologp[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &successp);
	if (!successp) {
		glGetProgramInfoLog(shaderProgram, 512, nullptr, infologp);
		cout << "Error: Shader Program linking failed\n" << infologp << "\n";
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	//--------------------------------------------------------------------------
	
	//Set the data for rendering------------------------------------------------
	float vertices[]{ //position            //color
					  0.5f,  0.5f , 0.0f,	1.0f, 0.0f, 0.0f,
					  0.5f, -0.5f , 0.0f,	0.0f, 1.0f, 0.0f,
					 -0.5f, -0.5f , 0.0f,   0.0f, 0.0f, 1.0f,
					 -0.5f,  0.5f , 0.0f,	0.5f, 0.5f, 0.5f};

	unsigned int  indices[]{ 0, 1, 3,   //triangle 1
							 1, 2, 3 }; //triangle 2

	
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)) );
	glEnableVertexAttribArray(1);
	
	//---------------------------------------------------------------------------
	
	//Render loop
	while (!glfwWindowShouldClose(window)) {
		//Processes all Input
		Creyon::processInput(window);
		
		//Render commands here------------------------
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		//---------------------------------------

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();

	return 0;
}