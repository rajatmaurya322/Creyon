#include "Texture.h"

namespace Creyon {
	
	Texture::Texture(Type Texturetype) :m_texType{Texturetype} {
		//Generate single texture
		glGenTextures(1, &m_texId);
		//Set as Target
		glBindTexture(GL_TEXTURE_2D, m_texId);
	}

	void Texture::setTexAsTarget() {
		glBindTexture(GL_TEXTURE_2D, m_texId); //Set current texture as target
	}

	void Texture::TexWrap(GLint mode_Xaxis, GLint mode_Yaxis) {
		//Set texture wrap on X axis
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mode_Xaxis);
		//Set texture wrap on Y axis
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mode_Yaxis);
	}

	void Texture::TexFilters(GLenum filter, GLint mode) {
		//Set texture filtering and its mode
		glTexParameteri(GL_TEXTURE_2D, filter , mode);
	}

	void Texture::loadImg(const char* path, const std::string& directory, bool gamma) {
		
		std::string filename = directory + "\\" + path;

		int width, height, nrComponents;
		
		//Load Image data
		unsigned char* data = stbi_load( filename.c_str(), &width, &height, &nrComponents, 0);
		
		if(data) {

			GLenum format = GL_RGB;
			
			switch (nrComponents) {
				case 1: format = GL_RED;
				break;

				case 3: format = GL_RGB;
				break;

				case 4: format = GL_RGBA;
				break;

				default: std::cout << "ERROR: Format of file unknown";
			}
			
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D); //Generate mipmap

			TexWrap(GL_REPEAT, GL_REPEAT);
			TexFilters(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			TexFilters(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		else {
			std::cout << "\nERROR: Texture failed to load at path:" << path;
		}

		stbi_image_free(data); //Free image data

	}

	void Texture::setTexUnit(GLenum TextureUnit) {
		//Activates the texture unit to be used
		glActiveTexture(TextureUnit);
		
		//Bind the texture with the texture unit
		glBindTexture(GL_TEXTURE_2D, m_texId);
	}
}