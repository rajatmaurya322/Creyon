#include "VertexArray.h"

namespace Creyon {

	VertexArray::VertexArray() {
		//Generates a single Vertex Array Object
		glGenVertexArrays(1, &m_vaoId);

		//Binds the Vertex Array object
		glBindVertexArray(m_vaoId);
	}

	void VertexArray::bind() {
		glBindVertexArray(m_vaoId);
	}

	void VertexArray::unbind() {
		//Unbinds all the Vertex Array objects
		glBindVertexArray(0);
	}

}