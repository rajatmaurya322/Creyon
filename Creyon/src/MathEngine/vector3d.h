#pragma once

//Namespace is Creyon

#include <iostream>
#include <cmath>
#include "matrix3x3.h"

//Row vectors are used
namespace Creyon {

    class vector3d{
    public:		//All data members of a class have m_ prefix
        float m_x, m_y, m_z;

        //Default constructor, creates a null vector
        vector3d() :m_x{ 0.0f }, m_y{ 0.0f }, m_z{ 0.0f }
        {}

        //Creates a vector based on given components
        vector3d(float x, float y, float z) :m_x{ x }, m_y{ y }, m_z{ z }
        {}

        //Copy constructor
        vector3d(const vector3d& v) :m_x{ v.m_x }, m_y{ v.m_y }, m_z{ v.m_z }
        {}

		
		//Add two vectors(respective x,y,z components)
        vector3d operator+(const vector3d& v)const;
		
		//Subtract two vectors(respective x,y,z components)
        vector3d operator-(const vector3d& v)const;
		
		//Dot product of two vectors
        float operator*(const vector3d& v)const;
        
        //Vector-matrix multiplication; only v*mat form
        vector3d operator*(const Creyon::matrix_3x3 &mat)const;

        //unary minus, returns a vector with negated components
        vector3d operator-()const;
		
		//Scalar multiplication of vector with s : v*s form
        vector3d operator*(float s)const;
		
		// Scalar division of vector with s : v / s
        vector3d operator/(float s)const;

		//Checks if two vectors are equal
        bool operator==(const vector3d& v)const {
            return m_x == v.m_x && m_y == v.m_y && m_z == v.m_z;
        }

		//Checks if two vectors are not equal
        bool operator!=(const vector3d& v)const {
            return m_x != v.m_x || m_y != v.m_y || m_z != v.m_z;
        }
        
		//Scalar multiplication of vector with s: s*v form
        friend vector3d operator*(float s, const vector3d& v);

        //Prints vector directly with cout
        friend std::ostream& operator<<(std::ostream& os, const vector3d& v);
    };

    //Non member Functions
	
    //Returns square of the magnitude of the vector
    float sq_magn(const vector3d& v);

    //Returns magnitude of the vector
    float magn(const vector3d& v);

	//Normalize a vector
	vector3d normalize(const vector3d& v);

    //Cross product of two vectors
    vector3d cross(const vector3d& a, const vector3d& b);

}