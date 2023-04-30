#pragma once

#include "glad/glad.h"
#include <vector>

namespace Creyon {

	class ElementBuffer {
	private:
		unsigned int m_eboId;
	public:

		//Generates a single element buffer
		ElementBuffer();

		//Set as Element Array target
		void setTarget();

		//Sets as Element Array target loads the data
		void loadData(const std::vector<unsigned int>& data, GLenum usagemode);

	};
}