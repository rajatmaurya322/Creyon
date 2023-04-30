#pragma once

#include "Mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace Creyon {

	class Model {
	private:
		std::vector<Mesh> m_meshes;
		std::string m_directory;
		
		void loadModel(const std::filesystem::path& path);
		
		void processNode(aiNode* node, const aiScene* scene);
		
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		
		std::vector<Texture> loadMaterialTextures(aiMaterial* material, aiTextureType type, Texture::Type typeName);

	public:
		//Takes relative path to model from Creyon/src and loads it
		Model(const std::filesystem::path& modelPath);
		
		void Draw(Shaderprogram& shader);
	};
}
