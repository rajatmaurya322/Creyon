#pragma once

#include "Render/GL_Objects/Shaderprogram.h"
#include "Render/GL_Objects/VertexArray.h"
#include "Render/GL_Objects/VertexBuffer.h"
#include "Render/GL_Objects/ElementBuffer.h"

namespace Creyon {

	class Mesh {
	private:
		VertexArray VAO;
		VertexBuffer VBO;
		ElementBuffer EBO;

		void setupMesh();

	public:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;
		std::vector<Texture> m_textures;

		Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices, 
			 std::vector<Texture>& textures);

		void DrawMesh(Shaderprogram& shaderProgram);
	};
}
