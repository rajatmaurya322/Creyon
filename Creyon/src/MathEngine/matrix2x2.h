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

    public: //All data members begin with m_ prefix

        float m_elems[4];         //2x2 matrix elements
		
		//creates a 2x2 identity matrix
        matrix_2x2();

		//creates a 2x2 matrix with given values
        matrix_2x2(float a0, float b0, float a1, float b1);

		//Creates 2x2 matrix with given array
        matrix_2x2(const float *p_array);

		//Copy Constructor
        matrix_2x2(const matrix_2x2& mat2);

		//transposes the original 2x2 matrix; row-column interchange
        matrix_2x2 transpose();

		//adds two 2x2 matrices
        matrix_2x2 operator+(const matrix_2x2& mat)const;

		//subtracts two 2x2 matrices
        matrix_2x2 operator-(const matrix_2x2& mat)const;

		//multiplies two 2x2 matrices
        matrix_2x2 operator*(const matrix_2x2& mat)const;

		//scalar multiplication of 2x2 matrix: mat*f
        matrix_2x2 operator*(float f)const;

		//scalar division of 2x2 matrix: mat/f
        matrix_2x2 operator/(float f)const;
		
        //Scalar multiplication of 2x2 matrix: f * mat
        friend matrix_2x2 operator*(float f, matrix_2x2& mat);

        //Prints 2x2 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const matrix_2x2& mat);
    };

    //Non member functions

	//Returns determinant of 2x2 matrix
    float det(const matrix_2x2& mat);
}