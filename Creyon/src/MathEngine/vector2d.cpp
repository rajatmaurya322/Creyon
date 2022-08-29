#include "vector2d.h"

//Namespace is Creyon
namespace Creyon {

	//Overloaded operators
	
	//overloaded << operator to display vector directly with cout
	std::ostream& operator<<(std::ostream& os, const vector2d& vec) {
		os << "X:" << vec.m_x << "\nY:" << vec.m_y;
		return os;
	}
}