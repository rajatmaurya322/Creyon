#include "transforms.h"
#include <cmath>
#include "Miscellaneous/Misc.h"

//All vectors are treated as row vectors(or row major) and so vectors are pre-multiplied before in matrix transformation
/*Transformations are then read (general vector v) as: vABC as first A is applied on v then B and then C like a sentence
	therefore vABC is equivalent to (((vA)B)C) */

//Namespace is Creyon
namespace Creyon{
	
	void rotateaboutXaxis(matrix_4x4& mat4,const float angle) {
		
		//Matrix to rotate about X axis
		Creyon::matrix_4x4 rotateX{1.0f,	0.0f,		    0.0f,		    0.0f,
								   0.0f,	cos(angle),		sin(angle),		0.0f,
								   0.0f,   -sin(angle),		cos(angle),		0.0f, 
								   0.0f,	0.0f,			0.0f,			1.0f};
		
		mat4 = mat4 * rotateX ;
	}

	void rotateaboutYaxis(matrix_4x4& mat4,const float angle) {
		
		//Matrix to rotate about Y axis
		Creyon::matrix_4x4 rotateY{cos(angle),	0.0f,   -sin(angle),	0.0f,
								   0.0f,		1.0f,	0.0f,			0.0f,
								   sin(angle),	0.0f,	cos(angle),		0.0f,
								   0.0f,	    0.0f,	0.0f,			1.0f};
		
		mat4 = mat4 * rotateY ;
	}

	void rotateaboutZaxis(matrix_4x4& mat4,const float angle) {
		
		//Matrix to rotate about Z axis
		Creyon::matrix_4x4 rotateZ{cos(angle),	sin(angle),	 0.0f,		0.0f,
								  -sin(angle),	cos(angle),	 0.0f,		0.0f,
								   0.0f,	    0.0f,	     1.0f,		0.0f,
								   0.0f,    	0.0f,		 0.0f,		1.0f};
		
		mat4 = mat4 * rotateZ ;
	}

	//Assumes that given vector is a unit vector for now
	void rotateaboutAxis_origin(matrix_4x4& mat4, const vector4d& Axis , const float angle) {
		//Matrix to rotate about arbitrary axis
		Creyon::matrix_4x4 rotateArb{ square(Axis.m_x)*(1-cos(angle)) + cos(angle)          , Axis.m_x*Axis.m_y*(1-cos(angle)) + Axis.m_z*sin(angle), Axis.m_x*Axis.m_z*(1-cos(angle)) - Axis.m_y*sin(angle), 0.0f,
									  Axis.m_x*Axis.m_y*(1-cos(angle)) - Axis.m_z*sin(angle), square(Axis.m_y)*(1-cos(angle)) + cos(angle)          , Axis.m_y*Axis.m_z*(1-cos(angle)) + Axis.m_x*sin(angle), 0.0f,
									  Axis.m_x*Axis.m_z*(1-cos(angle)) + Axis.m_y*sin(angle), Axis.m_y*Axis.m_z*(1-cos(angle)) - Axis.m_x*sin(angle), square(Axis.m_z)*(1-cos(angle)) + cos(angle)          , 0.0f,
									  0.0f													, 0.0f													, 0.0f													, 1.0f};
		
		mat4 = mat4 * rotateArb;
	}

	void rotateaboutAxis(matrix_4x4& mat4, const vector4d& Axis, const float angle) {
		//Matrix to rotate about arbitrary axis
		Creyon::matrix_3x3 mat3{      square(Axis.m_x) * (1 - cos(angle)) + cos(angle)              , Axis.m_x * Axis.m_y * (1 - cos(angle)) + Axis.m_z * sin(angle), Axis.m_x * Axis.m_z * (1 - cos(angle)) - Axis.m_y * sin(angle),
									  Axis.m_x * Axis.m_y * (1 - cos(angle)) - Axis.m_z * sin(angle), square(Axis.m_y) * (1 - cos(angle)) + cos(angle)              , Axis.m_y * Axis.m_z * (1 - cos(angle)) + Axis.m_x * sin(angle),
									  Axis.m_x * Axis.m_z * (1 - cos(angle)) + Axis.m_y * sin(angle), Axis.m_y * Axis.m_z * (1 - cos(angle)) - Axis.m_x * sin(angle), square(Axis.m_z) * (1 - cos(angle)) + cos(angle) };
		
		vector3d vec3{ Axis.m_x, Axis.m_y, Axis.m_z };
		vec3 = (-vec3) * mat3 + vec3;
		
		mat4 = mat4 * convert_mat4(mat3, vec3);

	}

	void scalealongAllaxis(matrix_4x4& mat4, const float scaleX, const float scaleY, const float scaleZ) {
		
		//Scaling matrix to scale along all axis at once
		Creyon::matrix_4x4 scale{ scaleX,	0.0f,	0.0f,   0.0f,
								  0.0f,		scaleY, 0.0f,   0.0f,
								  0.0f,		0.0f,	scaleZ, 0.0f, 
								  0.0f,     0.0f,   0.0f,   1.0f};

		mat4 = mat4 * scale;
	}

	void reflectaboutaxis(matrix_4x4& mat4, const vector4d& vec4) {
		Creyon::matrix_4x4 reflect{ 1- 2* square(vec4.m_x), -2* vec4.m_x* vec4.m_y, -2* vec4.m_x* vec4.m_z, 0.0f, 
									-2*vec4.m_x*vec4.m_y  , 1- 2* square(vec4.m_y), -2* vec4.m_y* vec4.m_z, 0.0f,
									-2*vec4.m_x*vec4.m_z  , -2* vec4.m_y* vec4.m_z, 1- 2* square(vec4.m_z), 0.0f, 
									0.0f				  , 0.0f				  , 0.0f				  , 1.0f};

		mat4 = mat4 * reflect;
	}

}