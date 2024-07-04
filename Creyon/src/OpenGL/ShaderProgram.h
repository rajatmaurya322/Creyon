#pragma once

#include "Math/Matrix3x3.h"
#include "Math/Matrix4x4.h"
#include "Math/Vector3.h"
#include "Utility/Utility.h"
#include "glad/glad.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace Creyon {

	class ShaderProgram
	{
	private:
		unsigned int m_id;
	
	public:
		
		ShaderProgram();

		void useProgram() {
			glUseProgram(m_id);
		}
		
		void addShader(const char* shaderPath,GLenum shaderType);
		
		//link the shader program
		void link();

		//return the uniform's location
		GLint locateUniform(const std::string &uniformName);

		//set int value to a uniform
		void setInt(const std::string& uniformName, int value);

		//locates and sets float value to a uniform
		void setFloat(const std::string& uniformName, float value);

		//locates and sets vec3 value to a uniform
		void setVec3(const std::string& uniformName, const Vector3& value);

		//locates and sets Mat44 value to a uniform
		void setMat44(const std::string& uniformName, const Mat44& value);

		//locates and sets Mat33 value to a uniform
		void setMat33(const std::string& uniformName, const Mat33& value);
	};
}

