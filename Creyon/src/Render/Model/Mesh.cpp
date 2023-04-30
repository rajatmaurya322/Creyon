#include "Mesh.h"

namespace Creyon {

	Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices,
			   std::vector<Texture>& textures)
	:m_vertices{vertices}, m_indices{indices}, m_textures{textures}
	{
		setupMesh();
	}

	void Mesh::setupMesh() {
		VAO.bind();
		VBO.loadData(m_vertices, GL_STATIC_DRAW);
		EBO.loadData(m_indices, GL_STATIC_DRAW);

		setVertexAttribPtr(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		setVertexAttribPtr(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetof(Vertex, Normal));
		setVertexAttribPtr(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetof(Vertex, TexCoords));

		VertexArray::unbind();
	}

	void Mesh::DrawMesh(Shaderprogram& shaderProgram) {
		
		unsigned int no_diffuse = 1;
		unsigned int no_specular = 1;

		std::string name;
		
		for (unsigned int i = 0; i < m_textures.size(); i++) {
			
			switch (m_textures[i].m_texType) {
			case Texture::Type::Diffuse: {
				name = "Tex_diffuse[" + std::to_string(no_diffuse - 1) + "]";
				no_diffuse++;
			}
				break;

			case Texture::Type::Specular: {
				name = "Tex_specular[" + std::to_string(no_specular - 1) + "]";
				no_specular++;
			}
				break;
			
			default: std::cout << "Can't recognize Texture type";
			}
			
			shaderProgram.useProgram();
			shaderProgram.setInt(name, i);

			m_textures[i].setTexUnit(GL_TEXTURE0 + i);
		}

		VAO.bind();
		glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
		VertexArray::unbind();

		glActiveTexture(GL_TEXTURE0);
	}
}