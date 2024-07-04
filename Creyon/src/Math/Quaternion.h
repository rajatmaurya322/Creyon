#pragma once

#include <iostream>
#include <cmath>

namespace Creyon {
	
	class Quaternion{
	public:
		float m_w, m_x, m_y, m_z;
		
		//creates a null quaternion
		Quaternion();

		//creates a quaternion based on given values
		Quaternion(const float w, const float x, const float y , const float z);

		//adds two quaternions
		Quaternion operator+(const Quaternion& quat)const;
		
		//subtracts two quaternions
		Quaternion operator-(const Quaternion& quat)const;

		//multiply two quaternions
		Quaternion operator*(const Quaternion& quat)const;

		//multiply quaternion by scalar: q * s form
		Quaternion operator*(const float& s)const;

		//divide quaternion by scalar
		Quaternion operator/(const float& s)const;

		//returns negated quaternion
		Quaternion operator-()const;

		//prints quaternion directly with cout
		friend std::ostream& operator<<(std::ostream& os, const Quaternion& quat);
	};

	float magnitudeSquared(const Quaternion& q);

	void normalize(Quaternion& q);

	Quaternion inverse(const Quaternion& q);

	//quaternion interpolation - Spherical Linear Interpolation)
	Quaternion slerp(const Quaternion& start, const Quaternion& end, const float t);
}
