#pragma once

#include <iostream>
#include <vector>

//Namespace is Creyon

/*Matrix General notations(row_major ordering is used) :
 If values are given as [a,b,c,d,e,f,g,h,i], matrix created :
		|a,	b,	c|
		|d,	e,	f|
		|g,	h,	i|
 */

namespace Creyon {

    class matrix_2x2 {

    public:                             //All data members begin with m_ prefix

        float m_elems[4];         //2x2 matrix elements

        //Constructors
        matrix_2x2();   //creates a 2x2 identity matrix

        matrix_2x2(float a0, float b0, float a1, float b1); //creates a 2x2 matrix with given values

        matrix_2x2(const float *p_array); //Creates 2x2 matrix with given array

        matrix_2x2(const matrix_2x2& mat2);

        //Methods
        matrix_2x2 transpose();  //transposes the original 2x2 matrix; row-column interchange

        //Overloaded Operators
        matrix_2x2 operator+(const matrix_2x2& mat)const;    //adds two 2x2 matrices

        matrix_2x2 operator-(const matrix_2x2& mat)const;    //subtracts two 2x2 matrices

        matrix_2x2 operator*(const matrix_2x2& mat)const;    //multiplication of two 2x2 matrices

        matrix_2x2 operator*(float f)const;           //scalar multiplication of 2x2 matrix: mat*f

        matrix_2x2 operator/(float f)const;           //scalar division of 2x2 matrix: mat/f

        //Friend functions
        //same scalar multiplication: f * mat
        friend matrix_2x2 operator*(float f, matrix_2x2& mat);

        //overloaded friend operator << for printing matrix directly with cout object
        friend std::ostream& operator<<(std::ostream& os, const matrix_2x2& mat);
    };

    //Non-member functions
    float det(const matrix_2x2& mat);
}