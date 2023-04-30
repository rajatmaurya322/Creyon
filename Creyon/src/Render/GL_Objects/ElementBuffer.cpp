#include "ElementBuffer.h"

namespace Creyon {

	ElementBuffer::ElementBuffer(){
		//Generate an EBO
		glGenBuffers(1, &m_eboId);
	}

	void ElementBuffer::setTarget() {
		//Sets as Element Buffer target
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
	}

	void ElementBuffer::loadData(const std::vector<unsigned int>& data, GLenum usagemode) {
		//Sets as Element Buffer target
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
		
		//Loads array data and sets the usage mode
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], usagemode);
	}
}