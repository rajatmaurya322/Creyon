#pragma once

#include "matrix3x3.h"
#include "matrix4x4.h"
#include "vector3d.h"
#include "vector2d.h"

namespace Creyon {

	//Epsilon checks for floating-point comparisons

	//Absolute epsilon comparison
	bool abscompare(float a, float b, float abs_epsilon);

	//Relative epsilon comparison
	bool relcompare(float a, float b, float rel_epsilon);

	//Square function
	inline float square(const float value) {
		return value * value;
	}
	
	matrix_4x4 convert_mat4(const matrix_3x3& mat3, const vector3d& vec3);
}