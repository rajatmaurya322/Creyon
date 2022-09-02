#include "Texture.h"

namespace Creyon {
	
	Texture::Texture() {
		//Generate single texture
		glGenTextures(1, &texId);
		//SetasTarget
		glBindTexture(GL_TEXTURE_2D, texId);
	}

	void Texture::setTexAsTarget() {
		glBindTexture(GL_TEXTURE_2D, texId); //Set current texture as target
	}

	void Texture::configTexWrap(GLint mode_Xaxis, GLint mode_Yaxis) {
		//Set texture wrap on X axis
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mode_Xaxis);
		//Set texture wrap on Y axis
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mode_Yaxis);
	}

	void Texture::configTexFilters(GLenum filter, GLint mode) {
		//Set texture filtering and its mode
		glTexParameteri(GL_TEXTURE_2D, filter , mode);
	}

	void Texture::loadImg(const char* pathtoimg, Format imgformat) {
		
		//Compose the path to image
		std::filesystem::path abspath = searchRootDir() / "Creyon\\src" / pathtoimg;

		int width, height, nrchannels;
		
		//Flip image to look correct
		stbi_set_flip_vertically_on_load(true);
		
		//Load Image data
		unsigned char* data = stbi_load( abspath.string().c_str(), &width, &height, &nrchannels, 0);

		//Different formats : JPG, PNG
		switch (imgformat) {
		case Format::JPG: {
				if (data) {
					//Creating textures
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
					glGenerateMipmap(GL_TEXTURE_2D);
				}
				else {
					std::cout << "\nERROR: Failed to load texture";
				}
				stbi_image_free(data);
			}
			break;

		case Format::PNG: {
				if (data) {
					//Creating textures
					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
					glGenerateMipmap(GL_TEXTURE_2D);
				}
				else {
					std::cout << "\nERROR: Failed to load texture";
				}
				stbi_image_free(data);
			}
			break;

			default: std::cout << "\nUnknown Format Error! Please give correct format";
		}

	}

	void Texture::setTexUnit(GLenum TextureUnit) {
		//Activates the texture unit to be used
		glActiveTexture(TextureUnit);
		
		//Bind the texture with the texture unit
		glBindTexture(GL_TEXTURE_2D, texId);
	}
}