#pragma once

#include "glad/glad.h"
#include <vector>

namespace Creyon {

	class VertexBuffer{
	private:
		unsigned int m_vboId;

	public:

		//Generate a single Vertex Buffer and sets it as Array Buffer target
		VertexBuffer();

		//Set as Array Buffer Target
		void setBufferAsTarget();

		//Loads the data in currently bound buffer
		void loadData(const std::vector<float> &data, GLenum usagemode);

	};

	//Non-member functions

	//Sets Vertex Attributes of the Shader(assumes data is of float type)
	void setVertexAttribPtr(GLuint locationIndex, GLint size, GLboolean normalized, int stride, int offset);

}

