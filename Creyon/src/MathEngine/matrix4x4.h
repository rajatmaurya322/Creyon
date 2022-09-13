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

    class matrix_4x4 {

    public:		//All data members begin with m_ prefix

        float m_elems[16];     //4x4 matrix elements;

		//creates a 4x4 identity matrix
        matrix_4x4();

        //creates a 4x4 matrix with given values
        matrix_4x4(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3);

		//creates a 4x4 matrix with given array
        matrix_4x4(const float *p_array);

		//Copy constructor
        matrix_4x4(const matrix_4x4& mat4);
        
		//transposes the original 4x4 matrix; row-column interchange
		matrix_4x4 transpose();

		//adds two 4x4 matrices
        matrix_4x4 operator+(const matrix_4x4& mat)const;

		//subtracts two 4x4 matrices
        matrix_4x4 operator-(const matrix_4x4& mat)const;

		//multiplies two 4x4 matrices
        matrix_4x4 operator*(const matrix_4x4& mat)const;

		//scalar multiplication of 4x4 matrix: mat*f
        matrix_4x4 operator*(float f)const;

		//scalar division of 4x4 matrix: mat/f
        matrix_4x4 operator/(float f)const;
		
        //scalar multiplication of 4x4 matrix: f * mat
        friend matrix_4x4 operator*(float f, matrix_4x4& mat);

		//Prints 4x4 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const matrix_4x4& mat);
    };

    //Non member functions

	//Returns determinant of 4x4 matrix
    float det(const matrix_4x4& mat);
}