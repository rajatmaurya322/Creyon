#include "vector4d.h"

//Namespace is Creyon
namespace Creyon {
	
	Vector4d Vector4d::operator*(const Creyon::Mat44& mat) {
		return Vector4d(m_x * mat[0] + m_y * mat[4] + m_z * mat[8] + m_w * mat[12],
						m_x * mat[1] + m_y * mat[5] + m_z * mat[9] + m_w * mat[13],
						m_x * mat[2] + m_y * mat[6] + m_z * mat[10] + m_w *mat[14],
						m_x * mat[3] + m_y * mat[7] + m_z * mat[11] + m_w *mat[15]);
	}

	std::ostream& operator<<(std::ostream& os, const Vector4d& vec) {
		os << "X:" << vec.m_x << "\nY:" << vec.m_y << "\nZ:" << vec.m_z << "\nW:" << vec.m_w;
		return os;
	}
}
