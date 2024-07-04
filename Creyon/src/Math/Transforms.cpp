#include "transforms.h"

namespace Creyon{
	
	Mat44 translate(const float x, const float y, const float z) {
		Mat44 translation;
		translation[12] = x;
		translation[13] = y;
		translation[14] = z;
		return translation;
	}

	Mat44 translate(const Vector3& displacement) {
		Mat44 translation;
		translation[12] = displacement.m_x;
		translation[13] = displacement.m_y;
		translation[14] = displacement.m_z;
		return translation;
	}

	Mat44 rotateX(const float angle) {
		float radianAngle = toRadian(angle); 
		float sinValue = sinf(radianAngle);
		
		Mat44 rotationX;
		rotationX[5] = rotationX[10] = cosf(radianAngle);
		rotationX[6] = sinValue;
		rotationX[9] = -sinValue;
		return rotationX;
	}

	Mat44 rotateY(const float angle) {
		float radianAngle = toRadian(angle);
		float sinValue = sinf(radianAngle);
		
		Mat44 rotationY;
		rotationY[0] = rotationY[10] = cosf(radianAngle);
		rotationY[2] = -sinValue;
		rotationY[8] = sinValue;
		return rotationY;
	}

	Mat44 rotateZ(const float angle) {
		float radianAngle = toRadian(angle);
		float sinValue = sinf(radianAngle);
		
		Mat44 rotationZ;
		rotationZ[0] = rotationZ[5] = cosf(radianAngle);
		rotationZ[1] = sinValue;
		rotationZ[4] = -sinValue;
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
		scaling[0] = scaleX;
		scaling[5] = scaleY;
		scaling[10] = scaleZ;
		return scaling;
	}

	Mat44 scale(const float scale) {
		Mat44 scaling;
		scaling[0] = scaling[5] = scaling[10] = scale;
		return scaling;
	}
	
	
	Mat44 orthographic(const float left, const float top, const float right, 
					   const float bottom, const float far, const float near) { 
		Mat44 orthographic;
		orthographic[0] = 2 / (right - left);
		orthographic[5] = 2 / (top - bottom);
		orthographic[10] = 2 / (near - far);
		orthographic[12] = (right + left) / (left - right);
		orthographic[13] = (top + bottom) / (bottom - top);
		orthographic[14] = (far + near) / (near - far);
		return orthographic;
	}
	
	Mat44 perspective(const float aspect, const float fieldofview, const float near, const float far) {
		float cotHalfFov = 1.0f / tanf( toRadian(fieldofview)/2.0f );

		Mat44 perspective;
		perspective[0] = cotHalfFov / aspect;
		perspective[5] = cotHalfFov;
		perspective[10] = (near + far) / (near - far);
		perspective[11] = -1.0f;
		perspective[14] = (2 * far * near) / (near - far);
		perspective[15] = 0.0f;
		return perspective;
	}

	Mat33 calculateNormalMatrix(const Mat44& mat) {
		float cofactor0 =  differenceOfProduct(mat[5], mat[10], mat[9], mat[6]);
		float cofactor1 = -differenceOfProduct(mat[4], mat[10], mat[8], mat[6]);
		float cofactor2 =  differenceOfProduct(mat[4], mat[9],  mat[8], mat[5]);
		float cofactor3 = -differenceOfProduct(mat[1], mat[10], mat[9], mat[2]);
		float cofactor4 =  differenceOfProduct(mat[0], mat[10], mat[8], mat[2]);
		float cofactor5 = -differenceOfProduct(mat[0], mat[9],  mat[8], mat[1]);
		float cofactor6 =  differenceOfProduct(mat[1], mat[6],  mat[5], mat[2]);
		float cofactor7 = -differenceOfProduct(mat[0], mat[6],  mat[4], mat[2]);
		float cofactor8 =  differenceOfProduct(mat[0], mat[5],  mat[4], mat[1]);

		float determinant = mat[0] * cofactor0 + mat[1] * cofactor1 + mat[2] * cofactor2;

		Mat33 adjoint{ cofactor0, cofactor1, cofactor2,
					   cofactor3, cofactor4, cofactor5,
					   cofactor6, cofactor7, cofactor8 };

		return adjoint / determinant;
	}

}