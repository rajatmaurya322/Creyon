#include "Miscellaneous/Misc.h"
#include <cmath>

namespace Creyon {

	bool abscompare(float a, float b, float abs_epsilon) {
		//If absolute difference between a and b is less than or equal to epsilon value, they are said to be equal
		return std::fabs(a - b) <= abs_epsilon;
	}

	bool relcompare(float a, float b, float rel_epsilon) {
		//If difference between a and b is within epsilon percent of larger of a and b, they are said to be equal
		return ( std::fabs(a - b) <= std::fmax( std::fabs(a), std::fabs(b) ) * rel_epsilon );
	}

	matrix_4x4 convert_mat4(const matrix_3x3& mat3, const vector4d& vec4) {
		return matrix_4x4{ mat3.m_a[0], mat3.m_b[0], mat3.m_c[0],   0.0f,
						   mat3.m_a[1], mat3.m_b[1], mat3.m_c[1],   0.0f,
						   mat3.m_a[2], mat3.m_b[2], mat3.m_c[2],   0.0f,
						   vec4.m_v.m_z,vec4.m_v.m_x, vec4.m_v.m_y  ,vec4.m_w };
	}

}