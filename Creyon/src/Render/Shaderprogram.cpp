#include "Shaderprogram.h"

namespace Creyon {

	Shaderprogram::Shaderprogram() {
		//Create a Shader program
		m_programId = glCreateProgram();
	}

	void Shaderprogram::addShader(const char* pathtoShader, GLenum Shadertype) {
		
		//Creates proper path to Shader Files
		std::filesystem::path abspath = CreyonSrcPath / pathtoShader ;

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
		shaderID = glCreateShader(Shadertype);   //Create shader of provided type
		glShaderSource(shaderID, 1, &shadersource, nullptr);  //Give shader object its source code
		
		//Compile Shader
		glCompileShader(shaderID);

		//Check errors
		int success;
		char infolog[512];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		
		if (!success) {
			glGetShaderInfoLog(shaderID, 512, nullptr, infolog);  //Get shader log if errors are found
			std::cout << "\nERROR! Shader Compilation failed\n" << infolog << "\n";
		}
		else {  //Attach shader to program
			glAttachShader(m_programId, shaderID);
			glDeleteShader(shaderID);  //Delete shader as already attached to program object
		}
	}

	void Shaderprogram::link() {
		//Links the created shader program
		glLinkProgram(m_programId);

		//Check for errors in linking
		int success;
		char infolog[512];
		glGetProgramiv(m_programId, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_programId, 512, nullptr, infolog);
			std::cout << "\nError: Shader Program linking failed!\n" << infolog << "\n";
		}
	}

	GLint Shaderprogram::locateUniform(const std::string &uniformName) {
		try {
			GLint location = glGetUniformLocation(m_programId, uniformName.c_str());
			if (location == -1) { throw uniformName;}
			return location;
		}
		catch (std::string e) {
			std::cout << "\nUniform not found:" << e;
			exit(EXIT_FAILURE);
		}
	}

	void Shaderprogram::setInt(const std::string& uniformName, int value) {
		glUniform1i(locateUniform(uniformName), value);
	}

	void Shaderprogram::setFloat(const std::string& uniformName, float value) {
		glUniform1f(locateUniform(uniformName), value);
	}

	void Shaderprogram::setVec3(const std::string& uniformName, Vector3d& value) {
		glUniform3f(locateUniform(uniformName), value.m_x, value.m_y, value.m_z);
	}

	void Shaderprogram::setMat44(const std::string& uniformName, const Mat44& value) {
		glUniformMatrix4fv(locateUniform(uniformName), 1, GL_TRUE, &value);
	}

	void Shaderprogram::setMat33(const std::string& uniformName, const Mat33& value) {
		glUniformMatrix3fv(locateUniform(uniformName), 1, GL_TRUE, &value);
	}
}
