#pragma once

#include "glad/glad.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Utilities/Utility.h"
#include "Utilities/EngineConstants.h"

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
		
		// Add a Shader to program object
		void addShader(const char* pathtoShader,GLenum Shadertype);
		
		//Link the Shaderprogram
		void link();

		//Use the Shader Program
		inline void useProgram() {
			glUseProgram(programId);
		}
	};
}

