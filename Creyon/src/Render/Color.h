#pragma once

namespace Creyon {

	class Color{
	public: //All data members begin with m_ prefix
		float m_red, m_green, m_blue;

		//Creates default color to black
		Color();
		
		//Creates color of given color value(rgb)
		Color(const float r, const float g, const float b);

	};

	//Non-member functions

}

