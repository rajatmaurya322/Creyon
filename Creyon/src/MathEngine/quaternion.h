#pragma once

#include <iostream>
#include <cmath>

//Namespace is Creyon
namespace Creyon {
	
	class Quaternion{
	public: //All data members begin with m_ prefix

		float m_w, m_x, m_y, m_z; // represents quaternion form: W + Xi + Yj + Zk
		
		//Creates a null quaternion
		Quaternion();

		//Creates a quaternion based on given values
		Quaternion(const float w, const float x, const float y , const float z);

		//Adds two quaternions
		Quaternion operator+(const Quaternion& quat)const;
		
		//Subtracts two quaternions
		Quaternion operator-(const Quaternion& quat)const;

		//Multiplies two quaternions
		Quaternion operator*(const Quaternion& quat)const;

		//Multiplies quaternion by scalar: q * s form
		Quaternion operator*(const float& s)const;

		//Divides quaternion by scalar
		Quaternion operator/(const float& s)const;

		//unary - (negates all components)
		Quaternion operator-()const;

		//Prints quaternion directly with cout
		friend std::ostream& operator<<(std::ostream& os, const Quaternion& quat);
	};

	//Non member functions

	//Returns square of magnitude of quaternion
	float sq_magn(const Quaternion& q);

	//Returns magnitude of quaternion
	float magn(const Quaternion& q);

	//Normalize a quaternion
	void normalize(Quaternion& q);

	//Returns inverse of quaternion
	Quaternion inverse(const Quaternion& q);

	//interpolates two quaternions -aka- Slerp(Spherical Linear Interpolation)
	Quaternion slerp(const Quaternion& start, const Quaternion& end, const float t);
}
