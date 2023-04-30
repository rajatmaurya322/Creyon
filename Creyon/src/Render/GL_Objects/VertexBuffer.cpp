#include "VertexBuffer.h"

namespace Creyon {

	VertexBuffer::VertexBuffer() {
		//Generates a single Vertex Buffer Object
		glGenBuffers(1, &m_vboId);
	}

	void VertexBuffer::setTarget() {
		//Sets the buffer as Target
		glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	}

	void VertexBuffer::loadData(const std::vector<Vertex>& data, GLenum usagemode) {
		//Sets the buffer object as target
		glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
		
		//Loads array data and sets the usage mode
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Vertex) , &data[0] , usagemode);
	}

	//Non-member functions

	void setVertexAttribPtr(GLuint locationIndex, GLint size, GLenum type , GLboolean normalized, int stride, int offset) {
		//Sets location index, stride and offset of data
		glVertexAttribPointer(locationIndex, size, type, normalized, stride, (void*)offset);
		
		//Enables Vertex Attribute
		glEnableVertexAttribArray(locationIndex);
	}

}