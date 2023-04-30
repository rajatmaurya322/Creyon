#include "transforms.h"

//Namespace is Creyon
namespace Creyon{
	
	Mat44 translate(const float dX, const float dY, const float dZ) {
		return Mat44{	1.0f,	0.0f,	0.0f,	0.0f,
						0.0f,	1.0f,	0.0f,	0.0f,
						0.0f,	0.0f,	1.0f,	0.0f,
						dX,		dY,		dZ,		1.0f };

	}

	Mat44 translate(const Vector3d& disp) {
		return Mat44{	1.0f,		0.0f,		0.0f,		0.0f,
						0.0f,		1.0f,		0.0f,		0.0f,
						0.0f,		0.0f,		1.0f,		0.0f,
						disp.m_x,	disp.m_y,	disp.m_z,	1.0f };
	}

	Mat44 rotateX(const float angle) {
		float radangle = toRad(angle); 
		
		//Matrix to rotate about X axis
		return Mat44{	1.0f,   0.0f,           0.0f,           0.0f,
						0.0f,   cos(radangle),  sin(radangle),  0.0f,
						0.0f,  -sin(radangle),  cos(radangle),  0.0f,
						0.0f,   0.0f,           0.0f,           1.0f };

	}

	Mat44 rotateY(const float angle) {
		float radangle = toRad(angle);
		
		//Matrix to rotate about Y axis
		return Mat44{	cos(radangle), 0.0f,   -sin(radangle),	0.0f,
						0.0f,		   1.0f,	0.0f,			0.0f,
						sin(radangle), 0.0f,	cos(radangle),	0.0f,
						0.0f,		   0.0f,	0.0f,			1.0f};

	}

	Mat44 rotateZ(const float angle) {
		float radangle = toRad(angle);

		//Matrix to rotate about Z axis
		return Mat44{	cos(radangle),	sin(radangle),	0.0f,	0.0f,
						-sin(radangle),	cos(radangle),	0.0f,	0.0f,
						0.0f,			0.0f,			1.0f,	0.0f,
						0.0f,			0.0f,			0.0f,	1.0f};

	}

	Mat44 timeRotateX() {
		float angle = getTime();

		//Matrix to rotate about X axis
		return Mat44 {	1.0f,   0.0f,           0.0f,           0.0f,
						0.0f,   cos(angle),		sin(angle),		0.0f,
						0.0f,  -sin(angle),		cos(angle),		0.0f,
						0.0f,   0.0f,			0.0f,			1.0f };
	}

	Mat44 timeRotateY() {
		float angle = getTime();

		//Matrix to rotate about Y axis
		return Mat44 {	cos(angle),	0.0f,	-sin(angle),	0.0f,
						0.0f,		1.0f,	0.0f,			0.0f,
						sin(angle), 0.0f,	cos(angle),		0.0f,
						0.0f,		0.0f,   0.0f,			1.0f };
	}

	Mat44 timeRotateZ() {
		float angle = getTime();

		//Matrix to rotate about Z axis
		return Mat44 {	cos(angle),		sin(angle),	0.0f,	0.0f,
						-sin(angle),	cos(angle),	0.0f,	0.0f,
						0.0f,			0.0f,		1.0f,	0.0f,
						0.0f,			0.0f,		0.0f,	1.0f };
	}

	Vector3d qrotate(const float angle, const Vector3d& vec, const Vector3d& axis){
		float radangle = toRad(angle);

		float sinRadAngle = sinf(radangle / 2.0f);

		Quaternion q{ cosf(radangle / 2.0f), sinRadAngle * axis.m_x, sinRadAngle * axis.m_y,
		sinRadAngle * axis.m_z };
		Quaternion qvec{ 0.0f, vec.m_x, vec.m_y, vec.m_z };

		//perform quaternion rotation
		Quaternion result= q * qvec * inverse(q);
		return Vector3d{ result.m_x, result.m_y, result.m_z };
	}

	Mat44 scale(const float scaleX, const float scaleY, const float scaleZ) {
		//Scaling matrix to scale along all axis
		return Mat44 {	scaleX,   0.0f,   0.0f,   0.0f,
						0.0f,     scaleY, 0.0f,   0.0f,
						0.0f,     0.0f,   scaleZ, 0.0f, 
						0.0f,     0.0f,   0.0f,   1.0f};
	}

	Mat44 scale(const float uni_scale) {
		//Scaling matrix for uniform scale
		return Mat44 {	uni_scale,    0.0f,       0.0f,      0.0f,
						0.0f,         uni_scale,  0.0f,      0.0f,
						0.0f,         0.0f,       uni_scale, 0.0f,
						0.0f,         0.0f,       0.0f,      1.0f };
	}

	Mat44 reflectaboutaxis(const Vector4d& vec4) {
		
		Mat44 reflect{ 1 - 2 * vec4.m_x * vec4.m_x ,		-2 * vec4.m_x * vec4.m_y,	  -2 * vec4.m_x * vec4.m_z,   0.0f,
						 - 2 * vec4.m_x * vec4.m_y  ,  1 - 2 * vec4.m_y * vec4.m_y,	  -2 * vec4.m_y * vec4.m_z,   0.0f,
						 - 2 * vec4.m_x * vec4.m_z  ,		-2 * vec4.m_y * vec4.m_z,	1 - 2 * vec4.m_z * vec4.m_z,   0.0f,
						 0.0f				  ,		0.0f				  ,     0.0f				  ,   1.0f };

		return reflect;
	}
	
	
	Mat44 ortho(const float left, const float top, const float right, const float bottom, const float far, const float near) {
		//Orthographic Projection converts 3D coordinates to 2D and does not consider depth 
		Mat44 orthographic;
		
		orthographic[0] = 2 / (right - left);
		orthographic[5] = 2 / (top - bottom);
		orthographic[10] = 2 / (near - far);
		orthographic[12] = (right + left) / (left - right);
		orthographic[13] = (top + bottom) / (bottom - top);
		orthographic[14] = (far + near) / (near - far);

		return orthographic;
	}
	
	Mat44 persp(const float aspect, const float fieldofview, const float near, const float far) {
		//Perspective Projection: Converts 3D coordinates to project onto view frustum and considers depth
		
		float cotHalfFov = 1.0f / tanf( toRad(fieldofview)/2.0f );
		
		//Default matrix is always identity matrix so diagonal values need to be changed
		Mat44 perspective;

		perspective[0] = cotHalfFov / aspect;
		perspective[5] = cotHalfFov;
		perspective[10] = (near + far) / (near - far);
		perspective[11] = -1.0f;
		perspective[14] = (2 * far * near) / (near - far);
		perspective[15] = 0.0f;

		return perspective;
	}

	Mat33 NormalMatrix(const Mat44& mat) {
	/* Upper left 3x3 matrix:	mat[0], mat[1], mat[2],
								mat[4], mat[5], mat[6],
								mat[8], mat[9], mat[10] */

		float cofactor0 =  DOP(mat[5], mat[10], mat[9], mat[6]);
		float cofactor1 = -DOP(mat[4], mat[10], mat[8], mat[6]);
		float cofactor2 =  DOP(mat[4], mat[9],  mat[8], mat[5]);
		
		float cofactor3 = -DOP(mat[1], mat[10], mat[9], mat[2]);
		float cofactor4 =  DOP(mat[0], mat[10], mat[8], mat[2]);
		float cofactor5 = -DOP(mat[0], mat[9],  mat[8], mat[1]);
		
		float cofactor6 =  DOP(mat[1], mat[6],  mat[5], mat[2]);
		float cofactor7 = -DOP(mat[0], mat[6],  mat[4], mat[2]);
		float cofactor8 =  DOP(mat[0], mat[5],  mat[4], mat[1]);

		float determinant = mat[0] * cofactor0 + mat[1] * cofactor1 + mat[2] * cofactor2;

		return Mat33{cofactor0, cofactor1, cofactor2,
					 cofactor3, cofactor4, cofactor5,
					 cofactor6, cofactor7, cofactor8 } / determinant;
	}

}