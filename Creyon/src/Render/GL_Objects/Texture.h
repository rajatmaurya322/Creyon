#pragma once

#include "stb_image/stb_image.h"
#include "Utilities/Utility.h"
#include <iostream>

//Namespace is Creyon
namespace Creyon {
	
	class Texture{
	private:
		unsigned int m_texId;
	
	public:
		enum class Type{Diffuse, Specular};
		Type m_texType;
		std::string m_path;

		//Generates a single texture and sets it as target
		Texture(Type Texturetype);

		//Sets the calling texture object as target texture
		void setTexAsTarget();

		//Configures texture wrapping modes
		void TexWrap(GLint mode_Xaxis, GLint mode_Yaxis);

		//Configures texture filtering modes
		void TexFilters(GLenum filter, GLint mode);

		//Loads an image into the texture object
		void loadImg(const char* path, const std::string& directory, bool gamma = false);
		
		//Sets the texture unit location for texture object
		void setTexUnit(GLenum TextureUnit);
	};
}

