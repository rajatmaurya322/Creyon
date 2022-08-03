#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>

namespace Creyon {
	
	class Shader
	{
	private:
		unsigned int shaderId;
		static std::vector<unsigned int> shaderIds;   //Stores all the shaderIds created
	public:
		//Constructors
		
		//Creates a shader object of given type: Vertex or fragment
		Shader(GLenum type);

		//returns the shaderid of the shader object
		inline unsigned int getId() {
			return shaderId;
		}

		static std::vector<unsigned int> getallIds();
		
		//Compiles the shader
		void shaderCompile();

		void shaderDelete();
	};
}

