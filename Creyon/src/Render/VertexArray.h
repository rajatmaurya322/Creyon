#pragma once

#include "glad/glad.h"

namespace Creyon {
	
	class VertexArray{
	private:
		unsigned int m_vaoId;
	
	public:

		//Generates a single Vertex Array and binds it
		VertexArray();

		//Binds a Vertex Array
		void bind();

		//Unbinds a Vertex Array
		void unbind();

	};

}
