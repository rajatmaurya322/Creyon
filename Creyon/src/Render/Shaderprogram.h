#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>

namespace Creyon {
	
	class Shaderprogram
	{
	private:
		unsigned int programId;
	public:
		//Constructors
		
		//Creates a Shaderprogram object and attach all shaders
		Shaderprogram(const std::vector<unsigned int>& shaderIds );
		
		//returns the shaderid of the program object
		inline unsigned int getId() {
			return programId;
		}

		//Link the Shaderprogram
		void link();
	};
}

