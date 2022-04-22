#include "transforms.h"
#include <cmath>

//All vectors are treated as row vectors(or row major) and so vectors are pre-multiplied before in matrix transformation
//Transformations are then read (general vector v) as: vABC as first A is applied on v then B and then C like a sentence

//Namespace is Creyon
namespace Creyon{
	
	matrix_4x4 translate(const float dX, const float dY, const float dZ) {
		matrix_4x4 trans{	1.0f,	0.0f,	0.0f,	0.0f,
							0.0f,	1.0f,	0.0f,	0.0f,
							0.0f,	0.0f,	1.0f,	0.0f,
							dX,		dY,		dZ,		1.0f };

		return trans;
	}
	
	matrix_4x4 rotateX(const float angle) {
		
		//Matrix to rotate about X axis
		matrix_4x4 rotateaboutX{1.0f,   0.0f,           0.0f,           0.0f,
                                0.0f,   cos(angle),     sin(angle),     0.0f,
                                0.0f,   -sin(angle),    cos(angle),     0.0f, 
                                0.0f,   0.0f,           0.0f,           1.0f};
		
		return rotateaboutX ;
	}

	matrix_4x4 rotateY(const float angle) {
		
		//Matrix to rotate about Y axis
		matrix_4x4 rotateaboutY{cos(angle), 0.0f,   -sin(angle),    0.0f,
                                0.0f,       1.0f,   0.0f,           0.0f,
                                sin(angle), 0.0f,   cos(angle),     0.0f,
                                0.0f,       0.0f,   0.0f,           1.0f};
		
		return rotateaboutY ;
	}

	matrix_4x4 rotateZ(const float angle) {
		
		//Matrix to rotate about Z axis
		matrix_4x4 rotateaboutZ{cos(angle),     sin(angle),	 0.0f,      0.0f,
                                -sin(angle),    cos(angle),	 0.0f,      0.0f,
                                0.0f,           0.0f,        1.0f,      0.0f,
                                0.0f,           0.0f,        0.0f,      1.0f};
		
		return rotateaboutZ ;
	}

	//Assumes that given vector is a unit vector for now
	matrix_4x4 rotateaboutAxis_origin(const vector4d& Axis , const float angle) {
		//Matrix to rotate about arbitrary axis
		matrix_4x4 rotateArb;
		
		rotateArb.m_elems[0]  = square(Axis.m_x) * (1 - cos(angle)) + cos(angle);
		rotateArb.m_elems[1]  = Axis.m_x * Axis.m_y * (1 - cos(angle)) + Axis.m_z * sin(angle);
		rotateArb.m_elems[2]  = Axis.m_x * Axis.m_z * (1 - cos(angle)) - Axis.m_y * sin(angle);
		rotateArb.m_elems[3]  = 0.0f;

		rotateArb.m_elems[4]  = Axis.m_x * Axis.m_y * (1 - cos(angle)) - Axis.m_z * sin(angle);
		rotateArb.m_elems[5]  = square(Axis.m_y) * (1 - cos(angle)) + cos(angle);
		rotateArb.m_elems[6]  = Axis.m_y * Axis.m_z * (1 - cos(angle)) + Axis.m_x * sin(angle);
		rotateArb.m_elems[7]  = 0.0f,

		rotateArb.m_elems[8]  = Axis.m_x * Axis.m_z * (1 - cos(angle)) + Axis.m_y * sin(angle);
		rotateArb.m_elems[9]  = Axis.m_y * Axis.m_z * (1 - cos(angle)) - Axis.m_x * sin(angle);
		rotateArb.m_elems[10] = square(Axis.m_z) * (1 - cos(angle)) + cos(angle);
		rotateArb.m_elems[11] = 0.0f;
		
		rotateArb.m_elems[12] = rotateArb.m_elems[13] = rotateArb.m_elems[14] = 0.0f;
		rotateArb.m_elems[15] = 1.0f;
		
		return rotateArb;
	}

	matrix_4x4 rotate(const vector4d& Axis, const float angle) {
		//Matrix to rotate about arbitrary axis
		matrix_3x3 rotatearb; 
		
		rotatearb.m_elems[0] = square(Axis.m_x) * (1 - cos(angle)) + cos(angle);
		rotatearb.m_elems[1] = Axis.m_x * Axis.m_y * (1 - cos(angle)) + Axis.m_z * sin(angle);
		rotatearb.m_elems[2] = Axis.m_x * Axis.m_z * (1 - cos(angle)) - Axis.m_y * sin(angle);

		rotatearb.m_elems[3] = Axis.m_x * Axis.m_y * (1 - cos(angle)) - Axis.m_z * sin(angle);
		rotatearb.m_elems[4] = square(Axis.m_y) * (1 - cos(angle)) + cos(angle);
		rotatearb.m_elems[5] = Axis.m_y * Axis.m_z * (1 - cos(angle)) + Axis.m_x * sin(angle);

		rotatearb.m_elems[6] = Axis.m_x * Axis.m_z * (1 - cos(angle)) + Axis.m_y * sin(angle);
		rotatearb.m_elems[7] = Axis.m_y * Axis.m_z * (1 - cos(angle)) - Axis.m_x * sin(angle);
		rotatearb.m_elems[8] = square(Axis.m_z) * (1 - cos(angle)) + cos(angle);
		
		vector3d vec3{ Axis.m_x, Axis.m_y, Axis.m_z };
		vec3 = (-vec3) * rotatearb + vec3;
		
		return convert_mat4(rotatearb, vec3);
	}

	matrix_4x4 scale(const float scaleX, const float scaleY, const float scaleZ) {
		
		//Scaling matrix to scale along all axis
		matrix_4x4 scale{ scaleX,   0.0f,   0.0f,   0.0f,
                          0.0f,     scaleY, 0.0f,   0.0f,
                          0.0f,     0.0f,   scaleZ, 0.0f, 
                          0.0f,     0.0f,   0.0f,   1.0f};

		return scale;
	}

	matrix_4x4 scale(const float uni_scale) {
		
		//Scaling matrix for uniform scale
		matrix_4x4 scale{ uni_scale,    0.0f,       0.0f,      0.0f,
                          0.0f,         uni_scale,  0.0f,      0.0f,
                          0.0f,         0.0f,       uni_scale, 0.0f,
                          0.0f,         0.0f,       0.0f,      1.0f };

		return scale;
	}

	matrix_4x4 reflectaboutaxis(const vector4d& vec4) {
		
		matrix_4x4 reflect{ 1- 2* square(vec4.m_x),		-2* vec4.m_x* vec4.m_y,		-2* vec4.m_x* vec4.m_z,   0.0f, 
							-2*vec4.m_x*vec4.m_y  ,		1- 2* square(vec4.m_y),		-2* vec4.m_y* vec4.m_z,   0.0f,
							-2*vec4.m_x*vec4.m_z  ,		-2* vec4.m_y* vec4.m_z,		1- 2* square(vec4.m_z),   0.0f, 
							0.0f				  ,		0.0f				  ,     0.0f				  ,   1.0f};

		return reflect;
	}

	matrix_4x4 ortho(const float aspect, const float fieldofview, const float far, const float near) {
		matrix_4x4 orthographic;
		
		float half_fov = fieldofview / 2.0f;

		orthographic.m_elems[0] = 1.0f / (aspect * tanf(half_fov));
		orthographic.m_elems[5] = 1.0f / tanf(half_fov);
		orthographic.m_elems[10] = 2 / (near - far);
		orthographic.m_elems[14] = (far + near) / (near - far);

		return orthographic;
	}

	matrix_4x4 persp(const float aspect, const float fieldofview, const float far, const float near) {
		
		matrix_4x4 perspective;
		
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