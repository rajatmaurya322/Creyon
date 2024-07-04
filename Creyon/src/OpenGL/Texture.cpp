#include "Texture.h"

namespace Creyon {

	void loadTexture(const char* path) {
		int width, height, nrComponents;
		unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
		if(!data) {
			throw path;
		}

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
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);
	}

}