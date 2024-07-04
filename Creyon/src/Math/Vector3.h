#pragma once

#include <iostream>
#include <cmath>
#include "matrix3x3.h"

//row vectors are used
namespace Creyon {

    class Vector3{
	public:
        float m_x, m_y, m_z;

        //creates a null vector
        Vector3() :m_x{ 0.0f }, m_y{ 0.0f }, m_z{ 0.0f }
        {}

        Vector3(float x, float y, float z) :m_x{ x }, m_y{ y }, m_z{ z }
        {}

        //copy constructor
        Vector3(const Vector3& v) :m_x{ v.m_x }, m_y{ v.m_y }, m_z{ v.m_z }
        {}

		//adds two vectors
        Vector3 operator+(const Vector3& v)const;
		
		//subtracts two vectors
        Vector3 operator-(const Vector3& v)const;
		
		//dot product of two vectors
        float operator*(const Vector3& v)const;
        
        //vector-matrix multiplication, only v*mat form
        Vector3 operator*(const Creyon::Mat33 &mat)const;

        //returns negated vector
        Vector3 operator-()const;
		
		//scalar multiplication of vector with s : v*s form
        Vector3 operator*(float s)const;
		
		//scalar division of vector with s : v / s
        Vector3 operator/(float s)const;

		//checks if two vectors are equal
        bool operator==(const Vector3& v)const {
            return m_x == v.m_x && m_y == v.m_y && m_z == v.m_z;
        }

		//checks if two vectors are not equal
        bool operator!=(const Vector3& v)const {
            return m_x != v.m_x || m_y != v.m_y || m_z != v.m_z;
        }
        
		//scalar multiplication of vector with s: s*v form
        friend Vector3 operator*(float s, const Vector3& v);

        //print vector directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
    };
	
    float magnitudeSquared(const Vector3& v);

	Vector3 normalize(const Vector3& v);

    Vector3 cross(const Vector3& a, const Vector3& b);

}