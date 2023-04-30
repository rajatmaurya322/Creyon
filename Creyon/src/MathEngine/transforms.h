#pragma once

#include "matrix4x4.h"
#include "quaternion.h"
#include "vector3d.h"
#include "vector4d.h"
#include "Utilities/Utility.h"

// Tranforms applied as : v * ABC where v is a vector 

namespace Creyon{

	//Translates the object by specified displacements
	Mat44 translate(const float dX, const float dY, const float dZ);

	//Translates the object by specified by given vector displacement
	Mat44 translate(const Vector3d& disp);

	//All functions assume degree values for angles

	//Rotates about X axis by given angle
	Mat44 rotateX(const float angle);

	//Rotates about Y axis by given angle
	Mat44 rotateY(const float angle);

	//Rotates about Z axis by given angle
	Mat44 rotateZ(const float angle);

	//Rotates about X axis by time value
	Mat44 timeRotateX();

	//Rotates about Y axis by time value
	Mat44 timeRotateY();

	//Rotates about Z axis by time value
	Mat44 timeRotateZ();

	//Rotates about axis by given angle by using Quaternions 
	Vector3d qrotate(const float angle, const Vector3d& vec, const Vector3d& axis);

	//Scales along the axes by given scale factors
	Mat44 scale(const float scaleX, const float scaleY, const float scaleZ);

	//Uniform Scale along all coordinates axes
	Mat44 scale(const float uni_scale);

	//Reflection about the given axis
	Mat44 reflectaboutaxis(const Vector4d& vec4);
	
	//Resource: scratchapixel.com
	
	//Orthographic(Parallel) projection
	Mat44 ortho(const float left, const float top, const float right, const float bottom, const float far, const float near);
	
	//Reference: https://chaosinmotion.com/2010/09/06/goodbye-far-clipping-plane/
	
	//Perspective projection
	Mat44 persp(const float aspect, const float fieldofview, const float near, const float far);

	//Returns the Normal Matrix
	Mat33 NormalMatrix(const Mat44& mat);
}