#include "Model.h"

namespace Creyon {

	Model::Model(const std::filesystem::path& modelPath) {
		loadModel(CreyonSrcPath / modelPath);
	}

	void Model::Draw(Shaderprogram& shader) {
		for (Mesh &mesh : m_meshes)
			mesh.DrawMesh(shader);
	}

	void Model::loadModel(const std::filesystem::path& path) {
		Assimp::Importer importer;

		const aiScene* scene = importer.ReadFile(path.u8string(), aiProcess_Triangulate | aiProcess_FlipUVs);

		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
			std::cout << "\nERROR::ASSIMP::" << importer.GetErrorString();
			return;
		}

		m_directory = path.parent_path().u8string();
		processNode(scene->mRootNode, scene);
	}

	void Model::processNode(aiNode* node, const aiScene* scene) {
		for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			m_meshes.push_back(processMesh(mesh, scene));
		}

		for (unsigned int i = 0; i < node->mNumChildren; ++i) {
			processNode(node->mChildren[i], scene);
		}
	}

	Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
		//Stores the processed Vertex of the mesh
		std::vector<Vertex> vertices;

		//Process Vertices in the model
		for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
			Vertex vertex;
			
			//Get the position
			aiVector3D meshVertice = mesh->mVertices[i];
			vertex.Position = Vector3d(meshVertice.x, meshVertice.y, meshVertice.z);

			//Get the normals
			if (mesh->HasNormals()) {
				aiVector3D meshNormal = mesh->mNormals[i];
				vertex.Normal = Vector3d(meshNormal.x, meshNormal.y, meshNormal.z);
			}

			//Get the Texture Coordinates
			if (mesh->mTextureCoords[0]) {
				aiVector3D meshTexCoords = mesh->mTextureCoords[0][i];
				vertex.TexCoords = Vector2d(meshTexCoords.x, meshTexCoords.y);
			}
			else vertex.TexCoords = Vector2d(0.0f, 0.0f);
			
			//Stores the vertex data of mesh in a vector
			vertices.push_back(vertex);
		}
		
		//Stores the processed indices of the mesh
		std::vector<unsigned int> indices;
		
		//Process indices in the model
		for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
			aiFace face = mesh->mFaces[i];
			for (unsigned int j = 0; j < face.mNumIndices; ++j)
				indices.push_back(face.mIndices[j]);
		}

		//Stores the processed textures of the mesh
		std::vector<Texture> textures;

		if (mesh->mMaterialIndex >= 0) {
			aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

			std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, Texture::Type::Diffuse);
			textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

			std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, Texture::Type::Specular);
			textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		}

		return Mesh(vertices, indices, textures);
	}

	std::vector<Texture> Model::loadMaterialTextures(aiMaterial* material, aiTextureType type, Texture::Type typeName) {
		
		std::vector<Texture> textures;
		std::vector<Texture> textures_loaded;
		
		for (unsigned int i = 0; i < material->GetTextureCount(type); ++i) {
			aiString str;
			material->GetTexture(type, i, &str);
			const char* str_path = str.C_Str();
			
			bool skip = false;
			
			for (unsigned int j = 0; j < textures_loaded.size(); ++j) {
				if (std::strcmp(textures_loaded[j].m_path.data(), str_path) == 0) {
					textures.push_back(textures_loaded[j]);
					skip = true;
					break;
				}
			}
			if (!skip) {
				Texture texture{ typeName };
				texture.loadImg(str_path, m_directory);
				texture.m_path = str_path;
				textures.push_back(texture);
				textures_loaded.push_back(texture);
			}
		}

		return textures;
	}

}