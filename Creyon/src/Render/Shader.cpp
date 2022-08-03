#include "Shader.h"

namespace Creyon {

	std::vector<unsigned int> Shader::shaderIds{};
	
	Shader::Shader(GLenum type) {
		shaderId = glCreateShader(type);    //Creates a shader of given type
		shaderIds.push_back(shaderId);   //Stores the shaderId in a vector
	}

	std::vector<unsigned int> Shader::getallIds()
	{
		return Shader::shaderIds;
	}

	void Shader::shaderCompile() {
		//Compiles the shader program
		glCompileShader(shaderId);
		//Check for errors and print them
		int success;
		char infolog[512];
		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
		
		if (!success) {
			glGetShaderInfoLog(shaderId, 512, nullptr, infolog);
			std::cout << "Error: Shader compilation failed!" << infolog << "\n";
		}
	}

	void Shader::shaderDelete() {
		glDeleteShader(shaderId);
	}

}
