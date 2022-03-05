#pragma once

#include "matrix.h"
#include "vector3d.h"
#include "vector4d.h"

namespace Creyon{

	//Rotates about X axis by given angle
	void rotateaboutXaxis(matrix_4x4& mat4, const float angle);

	//Rotates about Y axis by given angle
	void rotateaboutYaxis(matrix_4x4& mat4, const float angle);

	//Rotates about Z axis by given angle
	void rotateaboutZaxis(matrix_4x4& mat4, const float angle);

	//Rotates about given arbitrary axis(passes through origin) by given angle
	void rotateaboutAxis_origin(matrix_4x4& mat4, const vector4d& Axis, const float angle);

	//Rotates about given arbitrary axis(does not pass through origin) by given angle
	void rotateaboutAxis(matrix_4x4& mat4, const vector4d& Axis, const float angle);

	//Scales along axis by given scale factors
	void scalealongAllaxis(matrix_4x4& mat4, const float scaleX, const float scaleY, const float scaleZ);

	//Reflection about the given axis
	void reflectaboutaxis(matrix_4x4& mat4, const vector4d& vec4);
}