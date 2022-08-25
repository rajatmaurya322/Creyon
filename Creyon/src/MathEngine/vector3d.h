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

        //Default constructor
        vector3d() :m_x{ 0.0f }, m_y{ 0.0f }, m_z{ 0.0f }
        {}

        //Creates a vector based on given component values
        vector3d(float x, float y, float z) :m_x{ x }, m_y{ y }, m_z{ z }
        {}

        //Copy constructor
        vector3d(const vector3d& v) :m_x{ v.m_x }, m_y{ v.m_y }, m_z{ v.m_z }
        {}

        //Methods  
        //Overloaded Operators 
        vector3d operator+(const vector3d& v)const;   //Add two vectors(respective x,y,z components)
        vector3d operator-(const vector3d& v)const;   //Subtract two vectors(respective x,y,z components)
        float operator*(const vector3d& v)const;       //Dot product of two vectors
        
        //Overloaded * operator for vector-matrix multiplication; only v*mat form
        vector3d operator*(const Creyon::matrix_3x3 &mat)const;

        //unary minus, returns a vector with negated components
        vector3d operator-()const;
        vector3d operator*(float s)const;          //Scalar multiplication of vector with s : v*s form
        vector3d operator/(float s)const;          //Scalar division of vector with s : v/s

        //Overloaded relational operators
        bool operator==(const vector3d& v)const {
            return m_x == v.m_x && m_y == v.m_y && m_z == v.m_z;
        }

        bool operator!=(const vector3d& v)const {
            return m_x != v.m_x || m_y != v.m_y || m_z != v.m_z;
        }

        //Friend Functions
        //Same Scalar multiplication of vector with s: s*v form
        friend vector3d operator*(float s, const vector3d& v);

        //overloaded << for directly printing vector with cout
        friend std::ostream& operator<<(std::ostream& os, const vector3d& v);
    };

    //NON-MEMBER Functions
    //Returns square of the magnitude of the vector
    float sq_magn(const vector3d& v);

    //Returns magnitude of the vector
    float magn(const vector3d& v);

    //Cross product of two vectors(represented by %)
    vector3d cross(const vector3d& a, const vector3d& b);

}