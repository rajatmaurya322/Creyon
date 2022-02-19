#include "linearTransform.h"
#include <cmath>

//All vectors are treated as row vectors(or row major) and so vectors are pre-multiplied before in matrix transformation
/*Transformations are then read (general vector v) as: vABC as first A is applied on v then B and then C like a sentence
	therefore vABC is equivalent to (((vA)B)C) */

//Namespace is Creyon
namespace Creyon{
	
	void rotateaboutXaxis(Creyon::vector3d& vec, const float angle) {
		
		//Matrix to rotate about X axis
		Creyon::matrix_3x3 mat{	   1.0f,	0.0f,			0.0f,
								   0.0f,	cos(angle),		sin(angle),
								   0.0f,   -sin(angle),		cos(angle) };
		
		vec = vec * mat;
	}

	void rotateaboutYaxis(Creyon::vector3d& vec, const float angle) {
		
		//Matrix to rotate about Y axis
		Creyon::matrix_3x3 mat{    cos(angle),	0.0f,	-sin(angle),
								   0.0f,		1.0f,	0.0f,
								   sin(angle),	0.0f,	cos(angle) };
		
		vec = vec * mat;
	}

	void rotateaboutZaxis(Creyon::vector3d& vec, const float angle) {
		
		//Matrix to rotate about Z axis
		Creyon::matrix_3x3 mat{    cos(angle),	sin(angle),	0.0f,
								  -sin(angle),	cos(angle),	0.0f,
								   0.0f		,	0.0f	  ,	1.0f };
		
		vec = vec * mat;
	}

	void scalealongAllaxis(Creyon::vector3d& vec, const float scaleX, const float scaleY, const float scaleZ) {
		
		//Scaling matrix to scale along all axis at once
		Creyon::matrix_3x3 mat{   scaleX,	0.0f,	0.0f,
								  0.0f,		scaleY, 0.0f,
								  0.0f,		0.0f,	scaleZ };

		vec = vec * mat;
	}

	/*
	void rotateX_translate(Creyon::vector4d& point,const float angle, const vector3d& v3) {
		
		//4x4 matrix to first perform rotation given in mat3 and then translation in v3 : vRT
		Creyon::matrix_4x4 mat{	   1.0f,	0.0f,			0.0f,        0.0f,
								   0.0f,	cos(angle),		sin(angle),  0.0f,
								   0.0f,   -sin(angle),		cos(angle),  0.0f,
								   v3.m_x	, v3.m_y	   , v3.m_z	  ,  1.0f};
		
		point = point * mat;
	}

	void rotateY_translate(Creyon::vector4d& point, const float angle, const vector3d& v3) {

		//4x4 matrix to first perform rotation given in mat3 and then translation in v3 : vRT
		Creyon::matrix_4x4 mat{    1.0f,	0.0f,			0.0f,        0.0f,
								   0.0f,	cos(angle),		sin(angle),  0.0f,
								   0.0f,   -sin(angle),		cos(angle),  0.0f,
								   v3.m_x	, v3.m_y	   , v3.m_z	  ,  1.0f };

		point = point * mat;
	}

	void rotateZ_translate(Creyon::vector4d& point, const float angle, const vector3d& v3) {

		//4x4 matrix to first perform rotation given in mat3 and then translation in v3 : vRT
		Creyon::matrix_4x4 mat{    1.0f,	0.0f,			0.0f,        0.0f,
								   0.0f,	cos(angle),		sin(angle),  0.0f,
								   0.0f,   -sin(angle),		cos(angle),  0.0f,
								   v3.m_x	, v3.m_y	   , v3.m_z	  ,  1.0f };

		point = point * mat;
	}
	*/
}