#include "VertexBuffer.h"

namespace Creyon {

	VertexBuffer::VertexBuffer() {
		//Generates a single Vertex Buffer Object
		glGenBuffers(1, &m_vboId);
		
		//Sets the buffer object as target
		glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	}

	void VertexBuffer::setBufferAsTarget() {
		//Sets the buffer as Target
		glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	}

	void VertexBuffer::loadData(const std::vector<float>& data, GLenum usagemode) {
		//Loads array data and sets the usage mode
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float) , &data[0] , usagemode);
	}

	//Non-member functions

	void setVertexAttribPtr(GLuint locationIndex, GLint size, GLboolean normalized, int stride, int offset) {
		//Sets location index, stride and offset of data
		glVertexAttribPointer(locationIndex, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), 
							 (void*)(offset * sizeof(float)) );

		//Enables Vertex Attribute
		glEnableVertexAttribArray(locationIndex);
	}

}