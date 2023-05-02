#pragma once

//Namespace is Creyon

#include <iostream>
#include <cmath>
#include "matrix3x3.h"

//Row vectors are used
namespace Creyon {

    class Vector3d{
    public:		//All data members of a class have m_ prefix
        float m_x, m_y, m_z;

        //Default constructor, creates a null vector
        Vector3d() :m_x{ 0.0f }, m_y{ 0.0f }, m_z{ 0.0f }
        {}

        //Creates a vector based on given components
        Vector3d(float x, float y, float z) :m_x{ x }, m_y{ y }, m_z{ z }
        {}

        //Copy constructor
        Vector3d(const Vector3d& v) :m_x{ v.m_x }, m_y{ v.m_y }, m_z{ v.m_z }
        {}

		
		//Add two vectors(respective x,y,z components)
        Vector3d operator+(const Vector3d& v)const;
		
		//Subtract two vectors(respective x,y,z components)
        Vector3d operator-(const Vector3d& v)const;
		
		//Dot product of two vectors
        float operator*(const Vector3d& v)const;
        
        //Vector-matrix multiplication; only v*mat form
        Vector3d operator*(const Creyon::Mat33 &mat)const;

        //unary minus, returns a vector with negated components
        Vector3d operator-()const;
		
		//Scalar multiplication of vector with s : v*s form
        Vector3d operator*(float s)const;
		
		// Scalar division of vector with s : v / s
        Vector3d operator/(float s)const;

		//Checks if two vectors are equal
        bool operator==(const Vector3d& v)const {
            return m_x == v.m_x && m_y == v.m_y && m_z == v.m_z;
        }

		//Checks if two vectors are not equal
        bool operator!=(const Vector3d& v)const {
            return m_x != v.m_x || m_y != v.m_y || m_z != v.m_z;
        }
        
		//Scalar multiplication of vector with s: s*v form
        friend Vector3d operator*(float s, const Vector3d& v);

        //Prints vector directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Vector3d& v);
    };

    //Non member Functions
	
    //Returns square of the magnitude of the vector
    float sq_magn(const Vector3d& v);

	//Normalize a vector
	Vector3d normalize(const Vector3d& v);

    //Cross product of two vectors
    Vector3d cross(const Vector3d& a, const Vector3d& b);

}