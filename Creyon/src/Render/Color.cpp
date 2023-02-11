#include "Color.h"

namespace Creyon {

	Color::Color():m_red{0.0f}, m_green{ 0.0f }, m_blue{0.0f}
	{}

	Color::Color(const float r, const float g, const float b):m_red{r}, m_green{g}, m_blue{b}
	{}
}
