#pragma once

#include <iostream>
#include <cmath>

//Namespace is Creyon
namespace Creyon {
	
	class quaternion
	{
	public: //All data members begin with m_ prefix

		float m_w, m_x, m_y, m_z; // represents quaternion form: W + Xi + Yj + Zk
		
		//Creates a null quaternion
		quaternion();

		//Creates a quaternion based on given values
		quaternion(const float w, const float x, const float y , const float z);

		//Adds two quaternions
		quaternion operator+(const quaternion& quat)const;
		
		//Subtracts two quaternions
		quaternion operator-(const quaternion& quat)const;

		//Multiplies two quaternions
		quaternion operator*(const quaternion& quat)const;

		//Multiplies quaternion by scalar: q * s form
		quaternion operator*(const float& s)const;

		//Divides quaternion by scalar
		quaternion operator/(const float& s)const;

		//unary - (negates all components)
		quaternion operator-()const;

		//Prints quaternion directly with cout
		friend std::ostream& operator<<(std::ostream& os, const quaternion& quat);
	};

	//Non member functions

	//Returns square of magnitude of quaternion
	float sq_magn(const quaternion& q);

	//Returns magnitude of quaternion
	float magn(const quaternion& q);

	//Normalize a quaternion
	void normalize(quaternion& q);

	//Returns inverse of quaternion
	quaternion inverse(const quaternion& q);

	//interpolates two quaternions -aka- Slerp(Spherical Linear Interpolation)
	quaternion slerp(const quaternion& start, const quaternion& end, const float t);
}
