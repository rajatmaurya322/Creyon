#pragma once

#include "matrix4x4.h"
#include "quaternion.h"
#include "vector3d.h"
#include "vector4d.h"
#include "Utilities/Utility.h"
#include <cmath>

/*Tranforms applied as : v * ABC where v is a vector  */

namespace Creyon{

	/* All functions assume degree values for angles. Boolean "convtorad" can be
	used to turn off conversion to radians (default conversion set to true) */

	//Translates the object by specified displacements
	Mat44 translate(const float dX, const float dY, const float dZ);

	//Translates the object by specified by given vector displacements
	Mat44 translate(const vector3d disp);

	//Rotates about X axis by given angle
	Mat44 rotateX(const float angle, bool convtorad = true);

	//Rotates about Y axis by given angle
	Mat44 rotateY(const float angle, bool convtorad = true);

	//Rotates about Z axis by given angle
	Mat44 rotateZ(const float angle, bool convtorad = true);

	//Rotates about axis by given angle by using Quaternions 
	vector3d qrotate(const float& angle, const vector3d& vec, const vector3d& axis, bool convtorad = true);

	//Scales along the axes by given scale factors
	Mat44 scale(const float scaleX, const float scaleY, const float scaleZ);

	//Uniform Scale along all coordinates axes
	Mat44 scale(const float uni_scale);

	//Reflection about the given axis
	Mat44 reflectaboutaxis(const vector4d& vec4);

	//Orthographic(Parallel) projection
	Mat44 ortho(const float left, const float top, const float right, const float bottom, const float far, const float near);

	//Perspective projection
	Mat44 persp(const float aspect, const float fieldofview, const float far, const float near);
}