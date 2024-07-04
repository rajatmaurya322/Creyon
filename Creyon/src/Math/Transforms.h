#pragma once

#include "matrix4x4.h"
#include "quaternion.h"
#include "vector3d.h"
#include "Utility/Utility.h"

//Transforms applied as : v * ABC where v is a vector 

namespace Creyon{

	Mat44 translate(const float x, const float y, const float z);

	Mat44 translate(const Vector3& displacement);

	//rotate about X axis
	Mat44 rotateX(const float angle);

	//rotate about Y axis
	Mat44 rotateY(const float angle);

	//rotate about Z axis
	Mat44 rotateZ(const float angle);

	//rotate about axis by given angle using Quaternions 
	Vector3 rotateQ(const float angle, const Vector3& vec, const Vector3& axis);

	//non-uniform scale
	Mat44 scale(const float scaleX, const float scaleY, const float scaleZ);

	//uniform scale along all coordinates axes
	Mat44 scale(const float scale);
	
	//resource: scratchapixel.com
	
	//orthographic(parallel) projection
	Mat44 orthographic(const float left, const float top, const float right, const float bottom, const float far, const float near);
	
	//perspective projection
	Mat44 perspective(const float aspect, const float fieldofview, const float near, const float far);

	Mat33 calculateNormalMatrix(const Mat44& mat);
}