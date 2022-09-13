#include "vector4d.h"

//Namespace is Creyon
namespace Creyon {
	
	vector4d vector4d::operator*(const Creyon::matrix_4x4& mat) {
		
		return vector4d(m_x * mat.m_elems[0] + m_y * mat.m_elems[4] + m_z * mat.m_elems[8] + m_w * mat.m_elems[12],
			m_x * mat.m_elems[1] + m_y * mat.m_elems[5] + m_z * mat.m_elems[9] + m_w * mat.m_elems[13],
			m_x * mat.m_elems[2] + m_y * mat.m_elems[6] + m_z * mat.m_elems[10] + m_w * mat.m_elems[14],
			m_x * mat.m_elems[3] + m_y * mat.m_elems[7] + m_z * mat.m_elems[11] + m_w * mat.m_elems[15]);
	}

	std::ostream& operator<<(std::ostream& os, const vector4d& vec) {
		
		os << "X:" << vec.m_x << "\nY:" << vec.m_y << "\nZ:" << vec.m_z << "\nW:" << vec.m_w;
		return os;
	}
}
