#include <iostream>
#include "matrix.h"
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

	matrix_3x3 mat2{2,-4, 8, 
					10,5,-2, 
					-1,-2,6}, mat1{1,2,3, 4,5,6, 7,8,9};
	cout << mat1.transpose();


	/*vector4d vec4{1,0,0,1};
	vector4d z{ 0,0,1,1 };
	matrix_4x4 mat4;
	Creyon::rotateaboutAxis(mat4, vec4, Creyon::pi);
	z = z * mat4;
	cout << z; */
	
	cin.get();
}