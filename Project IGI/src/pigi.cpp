#include <iostream>
#include "matrix.h"
#include "vector4d.h"
#include "vector3d.h"
#include "vector2d.h"
#include "linearTransform.h"
#include "Constants/constants.h"

int main() {
	using std::cout;
	using std::cin;
	
	using Creyon::matrix_4x4;
	using Creyon::matrix_3x3;
	using Creyon::matrix_2x2;
	using Creyon::vector3d;
	using Creyon::vector4d;
	
	vector4d vec4{2,3,4,5};
	matrix_3x3 mat3{ 1,2,3,
					 5,6,7,
					 9,10,11};
	cout << "\n\nmat4:\n\n" << Creyon::;
	cin.get();
}