#include "Shaderprogram.h"

namespace Creyon {

	Shaderprogram::Shaderprogram() {
		//Create a Shader program
		programId = glCreateProgram();
	}

	void Shaderprogram::addShader(const char* pathtoShader, GLenum Shadertype) {
		
		//Creates proper path to Shader Files
		std::filesystem::path abspath = searchRootDir() / "Creyon\\src" / pathtoShader ;

		//Read file's Shader source
		std::ifstream shaderfile;
		std::string shadercode;
		shaderfile.exceptions(std::ios::failbit | std::ios::badbit);
		try {
			shaderfile.open(abspath);
			std::stringstream shaderstream;
			shaderstream << shaderfile.rdbuf();
			shaderfile.close();
			shadercode = shaderstream.str();
		}
		catch (std::ifstream::failure e) {
			std::cout << "\nError! Can't Read Shader file Successfully";
		}

		//Convert shader code
		const char* shadersource = shadercode.c_str();

		//Create shader object
		unsigned int shaderID;
		shaderID = glCreateShader(Shadertype);
		glShaderSource(shaderID, 1, &shadersource, nullptr);
		
		//Compile Shader
		glCompileShader(shaderID);

		int success;
		char infolog[512];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shaderID, 512, nullptr, infolog);
			std::cout << "\nERROR! Shader Compilation failed\n" << infolog << "\n";
		}
		else {  //Attach shader to program
			glAttachShader(programId, shaderID);
			glDeleteShader(shaderID);
		}
	}

	void Shaderprogram::link() {
		//Links the created shader program
		glLinkProgram(programId);

		//Check for errors in linking
		int success;
		char infolog[512];
		glGetProgramiv(programId, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(programId, 512, nullptr, infolog);
			std::cout << "\nError: Shader Program linking failed!\n" << infolog << "\n";
		}
	}
}
