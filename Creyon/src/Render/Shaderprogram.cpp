#include "Shaderprogram.h"

namespace Creyon {

	Shaderprogram::Shaderprogram(const std::vector<unsigned int>& shaderIds) {
		//Create a Shader program
		programId = glCreateProgram();

		//Attaches all the shaders in the vector to the shaderprogram
		for (auto& shaderId : shaderIds) {
			glAttachShader(programId, shaderId);
		}
	}

	void Shaderprogram::link() {
		//Links the created shader program
		glLinkProgram(programId);

		//Check for errors in linking
		int success;
		char infolog[512];
		glGetProgramiv(programId, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(programId, 512, nullptr, infolog);
			std::cout << "Error: Shader Program linking failed!\n" << infolog << "\n";
		}

	}
}
