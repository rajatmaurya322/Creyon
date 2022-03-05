#pragma once

#include <iostream>
#include "matrix.h"

//Namespace is Creyon

namespace Creyon {

 //All vectors are treated as row vectors(or row major) and so vectors are pre-multiplied before in matrix transformation
    
    class vector4d {
    public:     //All data members have m_ prefix
        float m_x, m_y, m_z, m_w;

        //Constructors

        //Default constructor, makes a null vector with w=1
        vector4d() :m_x{ 0.0f }, m_y{ 0.0f }, m_z{ 0.0f }, m_w{ 1.0 }
        {}

        //Creates 4d vector based on given component values
        vector4d(float x, float y, float z, float w) :m_x{ x }, m_y{ y }, m_z{ z }, m_w{ w }
        {}

        //Copy constructor
        vector4d(const vector4d& vec) :m_x{ vec.m_x }, m_y{ vec.m_y }, m_z{ vec.m_z }, m_w{ vec.m_w }
        {}

        //Overloaded Operators
        //Overloaded multiplication operator * for vector-matrix multiplication; only v*mat form
        vector4d operator*(const Creyon::matrix_4x4& mat);

        //overloaded << operator to display vector directly with cout
        friend std::ostream& operator<<(std::ostream& os, const vector4d& vec);
    };
}