#pragma once

#include "matrix.h"
#include "vector3d.h"

namespace Creyon_linearTransform {

	//Rotates an input vector about X axis by given angle
	void rotateaboutXaxis(Creyon::vector3d& vec, const float angle);

	//Rotates an input vector about Y axis by given angle
	void rotateaboutYaxis(Creyon::vector3d& vec, const float angle);

	//Rotates an input vector about Z axis by given angle
	void rotateaboutZaxis(Creyon::vector3d& vec, const float angle);

	//Scales an input vector along axis by given scale factors
	void scalealongAllaxis(Creyon::vector3d& vec, const float scaleX, const float scaleY, const float scaleZ);

}