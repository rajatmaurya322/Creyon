#include <iostream>

#include "matrix.h"
#include "vector3d.h"
#include "linearTransform.h"
#include "Constants/constants.h"

int main() {
	using std::cout;
	using std::cin;
	
	using Creyon::matrix_4x4;
	using Creyon::matrix_3x3;
	using Creyon::matrix_2x2;
	using Creyon::vector3d;
	
	vector3d vec{ 1,0,0 };

	cout << "Z axis :" << vec;
	
	Creyon_linearTransform::rotateaboutYaxis(vec, Creyon::pi);
	
	cout << "\n\nScaled vector:" << vec;
	cin.get();
}