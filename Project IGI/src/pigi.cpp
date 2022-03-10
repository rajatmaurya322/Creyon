#include <iostream>
#include "matrix4x4.h"
#include "matrix3x3.h"
#include "matrix2x2.h"
#include "vector4d.h"
#include "vector3d.h"
#include "vector2d.h"
#include "transforms.h"
#include "Constants/constants.h"
#include "Miscellaneous/Misc.h"

int main() {
	using std::cout;
	using std::cin;
	
	using Creyon::matrix_4x4;
	using Creyon::matrix_3x3;
	using Creyon::matrix_2x2;
	using Creyon::vector3d;
	using Creyon::vector4d;

	vector4d vec4{1,0,0,1};
	vector4d z{ 0,0,1,1 };
	matrix_4x4 mat4;
	Creyon::rotate(mat4, vec4, Creyon::pi);
	z = z * mat4;
	cout << z; 
	
	cin.get();
}