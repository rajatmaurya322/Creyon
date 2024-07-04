#include "Shaderprogram.h"

namespace Creyon {

	ShaderProgram::ShaderProgram() {
		m_id = glCreateProgram();
	}

	void ShaderProgram::addShader(const char* shaderPath, GLenum shaderType) {

		//read shader source
		std::ifstream shaderFile;
		std::string shaderCode;
		shaderFile.exceptions(std::ios::failbit | std::ios::badbit);
		try {
			shaderFile.open(shaderPath);
			std::stringstream shaderStream;
			shaderStream << shaderFile.rdbuf();
			shaderFile.close();
			shaderCode = shaderStream.str();
		}
		catch (std::ifstream::failure e) {
			std::cout << "\nError! Can't Read Shader file Successfully";
		}

		//convert shader code
		const char* shaderSource = shaderCode.c_str();

		//create shader object
		unsigned int shaderID;
		shaderID = glCreateShader(shaderType);
		glShaderSource(shaderID, 1, &shaderSource, nullptr);
		
		//compile Shader
		glCompileShader(shaderID);

		//check errors
		int success;
		char infoLog[512];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		
		if (!success) {
			glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
			std::cout << "\nERROR! Shader Compilation failed\n" << infoLog << "\n";
		}
		else {
			glAttachShader(m_id, shaderID);
			glDeleteShader(shaderID);
		}
	}

	void ShaderProgram::link() {
		glLinkProgram(m_id);

		//check for errors in linking
		int success;
		char infolog[512];
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(m_id, 512, nullptr, infolog);
			std::cout << "\nError: Shader Program linking failed!\n" << infolog << "\n";
		}
	}

	GLint ShaderProgram::locateUniform(const std::string &uniformName) {
		try {
			GLint location = glGetUniformLocation(m_id, uniformName.c_str());
			if (location == -1) { throw uniformName;}
			return location;
		}
		catch (std::string e) {
			std::cout << "\nUniform not found:" << e;
			exit(EXIT_FAILURE);
		}
	}

	void ShaderProgram::setInt(const std::string& uniformName, int value) {
		glUniform1i(locateUniform(uniformName), value);
	}

	void ShaderProgram::setFloat(const std::string& uniformName, float value) {
		glUniform1f(locateUniform(uniformName), value);
	}

	void ShaderProgram::setVec3(const std::string& uniformName, const Vector3& value) {
		glUniform3f(locateUniform(uniformName), value.m_x, value.m_y, value.m_z);
	}

	void ShaderProgram::setMat44(const std::string& uniformName, const Mat44& value) {
		glUniformMatrix4fv(locateUniform(uniformName), 1, GL_TRUE, &value);
	}

	void ShaderProgram::setMat33(const std::string& uniformName, const Mat33& value) {
		glUniformMatrix3fv(locateUniform(uniformName), 1, GL_TRUE, &value);
	}
}
