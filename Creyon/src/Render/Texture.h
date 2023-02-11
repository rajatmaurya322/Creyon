#pragma once

#include "glad/glad.h"
#include "stb_image.h"
#include "Utilities/Utility.h"
#include <iostream>
#include <string>

//Namespace is Creyon
namespace Creyon {
	
	//Class representing a texture object
	class Texture{
	private:
		unsigned int texId;

	public:

		enum class Format { JPG, PNG };
		
		//Generates a single texture and sets it as target
		Texture();

		//Sets the calling texture object as target texture
		void setTexAsTarget();

		//Get the texture Id
		inline unsigned int getTexId() {
			return texId;
		}

		//Configures texture wrapping modes
		void configTexWrap(GLint mode_Xaxis, GLint mode_Yaxis);

		//Configures texture filtering modes
		void configTexFilters(GLenum filter, GLint mode);

		//Loads an image into the texture object
		void loadImg(const char* pathtoimg, Format imgformat);
		
		//Sets the texture unit location for texture object
		void setTexUnit(GLenum TextureUnit);
	};
}

