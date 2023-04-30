#pragma once

#include "glad/glad.h"
#include "MathEngine/vector2d.h"
#include "MathEngine/vector3d.h"
#include "Texture.h"
#include <vector>

namespace Creyon {

	struct Vertex {
		Vector3d Position;
		Vector3d Normal;
		Vector2d TexCoords;
	};

	class VertexBuffer{
	private:
		unsigned int m_vboId;

	public:

		//Generate a single Vertex Buffer 
		VertexBuffer();

		//Set as Array Buffer Target
		void setTarget();

		//Sets as Array Buffer target and loads the data
		void loadData(const std::vector<Vertex> &data, GLenum usagemode);

	};

	//Non-member functions

	//Sets Vertex Attributes for the Shader and enables it
	void setVertexAttribPtr(GLuint locationIndex, GLint size, GLenum type, GLboolean normalized, int stride, int offset);

}

