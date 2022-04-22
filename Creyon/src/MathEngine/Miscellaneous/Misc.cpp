#include "MathEngine/Miscellaneous/Misc.h"
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

	matrix_4x4 convert_mat4(const matrix_3x3& mat3, const vector3d& vec3) {
		return matrix_4x4(mat3.m_elems[0], mat3.m_elems[1], mat3.m_elems[2], 0.0f,
						  mat3.m_elems[3], mat3.m_elems[4], mat3.m_elems[5], 0.0f,
						  mat3.m_elems[6], mat3.m_elems[7], mat3.m_elems[8], 0.0f,
						  vec3.m_x		 , vec3.m_y		  , vec3.m_z	   , 1.0f);
	}

}