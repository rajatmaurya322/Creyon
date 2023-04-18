#include "vector2d.h"

//Namespace is Creyon
namespace Creyon {
	
	std::ostream& operator<<(std::ostream& os, const Vector2d& vec) {
		os << "X:" << vec.m_x << "\nY:" << vec.m_y;
		return os;
	}
}