#pragma once
#include "matrix.h"
#include "vector4d.h"

namespace Creyon {

	//Epsilon checks for floating-point comparisons

	//Absolute epsilon comparison
	bool abscompare(float a, float b, float abs_epsilon);

	//Relative epsilon comparison
	bool relcompare(float a, float b, float rel_epsilon);

	//Coversion functions
	//function which returns a 4x4 matrix with given 3x3 matrix and 4d vector
	matrix_4x4 convert_mat4(const matrix_3x3& mat3, const vector4d& vec4);


}