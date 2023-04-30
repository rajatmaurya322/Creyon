#pragma once

#include "glad/glad.h"

namespace Creyon {
	
	class VertexArray{
	private:
		unsigned int m_vaoId;
	
	public:

		//Generates a single Vertex Array
		VertexArray();

		//Binds a Vertex Array
		void bind();
		
		//Unbinds all Vertex Arrays
		static void unbind();
	};


}
