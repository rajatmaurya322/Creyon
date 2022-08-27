#pragma once

#include "MathEngine/matrix3x3.h"
#include "MathEngine/matrix4x4.h"
#include "MathEngine/vector3d.h"
#include "MathEngine/vector2d.h"
#include "MathEngine/Constants/constants.h"
#include <cmath>
#include <filesystem>

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

	//Converts from degree to radian angles
	inline float degToRad(const float angleInDeg) {
		return angleInDeg * degtorad;
	}
	
	matrix_4x4 convert_mat4(const matrix_3x3& mat3, const vector3d& vec3);

	//Search root directory
	std::filesystem::path searchRootDir();
}