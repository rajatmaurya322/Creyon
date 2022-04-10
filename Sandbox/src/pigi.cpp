#include <iostream>
#include "CreyonEng.h"

using mat44 = Creyon::matrix_4x4;

int main() {
	using std::cout;
	using std::cin;
	using Creyon::matrix_3x3;
	using Creyon::matrix_2x2;
	using Creyon::vector3d;
	using Creyon::vector4d;

	vector4d vec4{1,0,0,1};
	vector4d z{ 0,0,1,1 };
	mat44 mat4{ Creyon::rotateZ(Creyon::pi) };
	z = z * mat4;
	cout << z; 
	
	cin.get();
}