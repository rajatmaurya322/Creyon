#pragma once

#include "OpenGL/ShaderProgram.h"

namespace Creyon {

	class Mesh {
	private:

		void setupMesh();

	public:

		void DrawMesh(ShaderProgram& shaderProgram);
	};
}
