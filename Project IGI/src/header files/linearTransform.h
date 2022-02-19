#pragma once

#include "matrix.h"
#include "vector3d.h"
#include "vector4d.h"

namespace Creyon{

	//Rotates an input vector about X axis by given angle
	void rotateaboutXaxis(Creyon::vector3d& vec, const float angle);

	//Rotates an input vector about Y axis by given angle
	void rotateaboutYaxis(Creyon::vector3d& vec, const float angle);

	//Rotates an input vector about Z axis by given angle
	void rotateaboutZaxis(Creyon::vector3d& vec, const float angle);

	//Scales an input vector along axis by given scale factors
	void scalealongAllaxis(Creyon::vector3d& vec, const float scaleX, const float scaleY, const float scaleZ);

	//Rotate and then translate a 4d vector; v= vRT
	
	//Rotate the point about X axis and then translate
	/*void rotateX_translate(Creyon::vector4d& point, const float angle, const vector3d& v3);
	
	//Rotate the point about Y axis and then translate
	void rotateY_translate(Creyon::vector4d& point, const float angle, const vector3d& v3);
	
	//Rotate the point about Z axis and then translate
	void rotateZ_translate(Creyon::vector4d& point, const float angle, const vector3d& v3);

	//Rotate the point about Origin
	void rotateaboutOrigin(Creyon::vector4d& point, const float angle);
	*/
}