#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Utilities/Utility.h"

namespace Creyon {

	class Shaderprogram
	{
	private:
		unsigned int programId;
	
	public:
		//Constructors
		
		//Creates a Shaderprogram object
		Shaderprogram();

		//Inline Methods
		//returns the shaderid of the program object
		inline unsigned int getId() {
			return programId;
		}

		//Methods
		// Add a Shader to program object
		void addShader(const char* pathtoShader,GLenum Shadertype);
		void link();//Link the Shaderprogram
		inline void useProgram() { //Use the Shader Program
			glUseProgram(programId);
		}
	};
}

