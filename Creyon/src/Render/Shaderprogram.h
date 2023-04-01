#pragma once

#include "MathEngine/matrix4x4.h"
#include "MathEngine/vector3d.h"
#include "Utilities/Utility.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace Creyon {

	class Shaderprogram
	{
	private:
		unsigned int programId;
	
	public:
		
		//Creates a Shaderprogram object
		Shaderprogram();
		
		//Gets the Shaderprogram ID
		inline unsigned int getId() {
			return programId;
		}

		//Use the Shader Program
		inline void useProgram() {
			glUseProgram(programId);
		}
		
		// Add a Shader to program object
		void addShader(const char* pathtoShader,GLenum Shadertype);
		
		//Link the Shaderprogram
		void link();

		//Returns the Uniform's location
		GLint locateUniform(const std::string &uniformName);

		//Locates and sets int value to a uniform
		void setInt(const std::string& uniformName, int value);

		//Locates and sets float value to a uniform
		void setFloat(const std::string& uniformName, float value);

		//Locates and sets vec3 value to a uniform
		void setVec3(const std::string& uniformName, vector3d& value);

		//Locates and sets Mat44 value to a uniform
		void setMat44(const std::string& uniformName, Mat44& value);
	};
}

