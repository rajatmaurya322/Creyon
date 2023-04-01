#include "transforms.h"

//Namespace is Creyon
namespace Creyon{
	
	Mat44 translate(const float dX, const float dY, const float dZ) {
		Mat44 trans{	1.0f,	0.0f,	0.0f,	0.0f,
						0.0f,	1.0f,	0.0f,	0.0f,
						0.0f,	0.0f,	1.0f,	0.0f,
						dX,		dY,		dZ,		1.0f };

		return trans;
	}

	Mat44 translate(const vector3d disp) {
		Mat44 trans{	1.0f,		0.0f,		0.0f,		0.0f,
						0.0f,		1.0f,		0.0f,		0.0f,
						0.0f,		0.0f,		1.0f,		0.0f,
						disp.m_x,	disp.m_y,	disp.m_z,	1.0f };
		return trans;
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
		Mat44 rotateaboutX{ 1.0f,   0.0f,           0.0f,           0.0f,
							0.0f,   cos(angle),		sin(angle),		0.0f,
							0.0f,  -sin(angle),		cos(angle),		0.0f,
							0.0f,   0.0f,			0.0f,			1.0f };

		return rotateaboutX;
	}

	Mat44 timeRotateY() {
		float angle = getTime();

		//Matrix to rotate about Y axis
		Mat44 rotateaboutY{ cos(angle),	0.0f,	-sin(angle),	0.0f,
							0.0f,		1.0f,	0.0f,			0.0f,
							sin(angle), 0.0f,	cos(angle),		0.0f,
							0.0f,		0.0f,   0.0f,			1.0f };

		return rotateaboutY;
	}

	Mat44 timeRotateZ() {
		float angle = getTime();

		//Matrix to rotate about Z axis
		Mat44 rotateaboutZ{ cos(angle),		sin(angle),	0.0f,	0.0f,
							-sin(angle),	cos(angle),	0.0f,	0.0f,
							0.0f,			0.0f,		1.0f,	0.0f,
							0.0f,			0.0f,		0.0f,	1.0f };

		return rotateaboutZ;
	}

	vector3d qrotate(const float& angle, const vector3d& vec, const vector3d& axis, bool convtorad){
		float radangle{ 0.0f };

		//Get Radian Angle if conversion specified to be true
		if (convtorad) { radangle = toRad(angle); }
		else { radangle = angle; }

		float sinRadAngle = sinf(radangle / 2.0f);

		Quaternion q{ cosf(radangle / 2.0f), sinRadAngle * axis.m_x, sinRadAngle * axis.m_y,
		sinRadAngle * axis.m_z };
		Quaternion qvec{ 0.0f, vec.m_x, vec.m_y, vec.m_z };

		//perform quaternion rotation
		Quaternion result= q * qvec * inverse(q);
		return vector3d{ result.m_x, result.m_y, result.m_z };
	}

	Mat44 scale(const float scaleX, const float scaleY, const float scaleZ) {
		
		//Scaling matrix to scale along all axis
		Mat44 scale{scaleX,   0.0f,   0.0f,   0.0f,
					0.0f,     scaleY, 0.0f,   0.0f,
					0.0f,     0.0f,   scaleZ, 0.0f, 
					0.0f,     0.0f,   0.0f,   1.0f};

		return scale;
	}

	Mat44 scale(const float uni_scale) {
		
		//Scaling matrix for uniform scale
		Mat44 scale{uni_scale,    0.0f,       0.0f,      0.0f,
					0.0f,         uni_scale,  0.0f,      0.0f,
					0.0f,         0.0f,       uni_scale, 0.0f,
					0.0f,         0.0f,       0.0f,      1.0f };

		return scale;
	}

	Mat44 reflectaboutaxis(const vector4d& vec4) {
		
		Mat44 reflect{ 1 - 2 * vec4.m_x * vec4.m_x ,		-2 * vec4.m_x * vec4.m_y,	  -2 * vec4.m_x * vec4.m_z,   0.0f,
						 - 2 * vec4.m_x * vec4.m_y  ,  1 - 2 * vec4.m_y * vec4.m_y,	  -2 * vec4.m_y * vec4.m_z,   0.0f,
						 - 2 * vec4.m_x * vec4.m_z  ,		-2 * vec4.m_y * vec4.m_z,	1 - 2 * vec4.m_z * vec4.m_z,   0.0f,
						 0.0f				  ,		0.0f				  ,     0.0f				  ,   1.0f };

		return reflect;
	}

	//Resource: scratchapixel.com
	//Orthographic Projection converts 3D coordinates to 2D and does not consider depth 
	Mat44 ortho(const float left, const float top, const float right, const float bottom, const float far, const float near) {
		Mat44 orthographic;
		
		orthographic.m_elems[0] = 2 / (right - left);
		orthographic.m_elems[5] = 2 / (top - bottom);
		orthographic.m_elems[10] = 2 / (near - far);
		orthographic.m_elems[12] = (right + left) / (left - right);
		orthographic.m_elems[13] = (top + bottom) / (bottom - top);
		orthographic.m_elems[14] = (far + near) / (near - far);

		return orthographic;
	}

	//Resource: scratchapixel.com
	//Perspective Projection: Converts 3D coordinates to project onto view frustum and considers depth
	Mat44 persp(const float aspect, const float fieldofview, const float far, const float near) {
		
		Mat44 perspective;
		
		float half_fov = fieldofview / 2.0f;

		perspective.m_elems[0] = 1.0f / ( aspect * tanf(half_fov) );
		perspective.m_elems[5] = 1.0f / tanf(half_fov);
		perspective.m_elems[10] = (far + near) / (near - far);
		perspective.m_elems[11] = -1.0f;
		perspective.m_elems[14] = (2 * far * near) / (near - far);
		perspective.m_elems[15] = 0.0f;

		return perspective;
	}

}