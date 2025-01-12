#include "transforms.h"

namespace Creyon{
	
	Mat44 translate(const float x, const float y, const float z) {
		Mat44 translation;
		translation(3,0) = x;
		translation(3,1) = y;
		translation(3,2) = z;
		return translation;
	}

	Mat44 translate(const Vector3& displacement) {
		Mat44 translation;
		translation(3,0) = displacement.m_x;
		translation(3,1) = displacement.m_y;
		translation(3,2) = displacement.m_z;
		return translation;
	}

	Mat44 rotateX(const float angle) {
		float radianAngle = toRadian(angle); 
		float sinValue = sinf(radianAngle);
		
		Mat44 rotationX;
		rotationX(1,1) = rotationX(2,2) = cosf(radianAngle);
		rotationX(1,2) = sinValue;
		rotationX(2,1) = -sinValue;
		return rotationX;
	}

	Mat44 rotateY(const float angle) {
		float radianAngle = toRadian(angle);
		float sinValue = sinf(radianAngle);
		
		Mat44 rotationY;
		rotationY(0,0)= rotationY(2,2) = cosf(radianAngle);
		rotationY(0,2)= -sinValue;
		rotationY(2,0)= sinValue;
		return rotationY;
	}

	Mat44 rotateZ(const float angle) {
		float radianAngle = toRadian(angle);
		float sinValue = sinf(radianAngle);
		
		Mat44 rotationZ;
		rotationZ(0,0) = rotationZ(1,1) = cosf(radianAngle);
		rotationZ(0,1) = sinValue;
		rotationZ(1,0) = -sinValue;
		return rotationZ;
	}

	Vector3 rotateQ(const float angle, const Vector3& vec, const Vector3& axis){
		float radianAngle = toRadian(angle);
		float sinValue = sinf(radianAngle / 2.0f);
		float cosValue = cosf(radianAngle / 2.0f);
		
		Quaternion q{ cosValue, sinValue * axis.m_x, sinValue * axis.m_y, sinValue * axis.m_z };
		Quaternion qvec{ 0.0f, vec.m_x, vec.m_y, vec.m_z };
		Quaternion result= q * qvec * inverse(q);
		return Vector3{ result.m_x, result.m_y, result.m_z };
	}

	Mat44 scale(const float scaleX, const float scaleY, const float scaleZ) {
		Mat44 scaling;
		scaling(0,0) = scaleX;
		scaling(1,1) = scaleY;
		scaling(2,2) = scaleZ;
		return scaling;
	}

	Mat44 scale(const float scale) {
		Mat44 scaling;
		scaling(0,0) = scaling(1,1) = scaling(2,2) = scale;
		return scaling;
	}
	
	
	Mat44 orthographic(const float left, const float top, const float right, 
					   const float bottom, const float far, const float near) { 
		Mat44 orthographic;
		orthographic(0,0) = 2 / (right - left);
		orthographic(1,1) = 2 / (top - bottom);
		orthographic(2,2) = 2 / (near - far);
		orthographic(3,0) = (right + left) / (left - right);
		orthographic(3,1) = (top + bottom) / (bottom - top);
		orthographic(3,2) = (far + near) / (near - far);
		return orthographic;
	}
	
	Mat44 perspective(const float aspect, const float fieldofview, const float near, const float far) {
		float cotHalfFov = 1.0f / tanf( toRadian(fieldofview)/2.0f );
	
		Mat44 perspective;
		perspective(0,0) = cotHalfFov / aspect;
		perspective(1,1) = cotHalfFov;
		perspective(2,2) = (near + far) / (near - far);
		perspective(2,3) = -1.0f;
		perspective(3,2) = (2 * far * near) / (near - far);
		perspective(3,3) = 0.0f;
		return perspective;
	}

	Mat33 calculateNormalMatrix(const Mat44& mat) {
		Mat33 adjoint;
		adjoint(0,0) =  differenceOfProduct(mat(1,1), mat(2,2), mat(2,1), mat(1,2));
		adjoint(0,1) = -differenceOfProduct(mat(1,0), mat(2,2), mat(2,0), mat(1,2));
		adjoint(0,2) =  differenceOfProduct(mat(1,0), mat(2,1), mat(2,0), mat(1,1));
		adjoint(1,0) = -differenceOfProduct(mat(0,1), mat(2,2), mat(2,1), mat(0,2));
		adjoint(1,1) =  differenceOfProduct(mat(0,0), mat(2,2), mat(2,0), mat(0,2));
		adjoint(1,2) = -differenceOfProduct(mat(0,0), mat(2,1), mat(2,0), mat(0,1));
		adjoint(2,0) =  differenceOfProduct(mat(0,1), mat(1,2), mat(1,1), mat(0,2));
		adjoint(2,1) = -differenceOfProduct(mat(0,0), mat(1,2), mat(1,0), mat(0,2));
		adjoint(2,2) =  differenceOfProduct(mat(0,0), mat(1,1), mat(1,0), mat(0,1));

		float determinant = mat(0,0) * adjoint(0,0) + mat(0,1) * adjoint(0,1) + mat(0,2) * adjoint(0,2);
		return adjoint / determinant;
	}

}