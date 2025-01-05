#pragma once

#include "Mesh.h"

namespace Creyon {

	class Model {
	private:
		std::vector<Mesh> m_meshes;
		std::string m_directory;
		
		void loadModel(const std::filesystem::path& path);

	public:

		Model(const std::filesystem::path& modelPath);
		
		void Draw(ShaderProgram& shader);
	};
}
