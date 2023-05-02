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

    class Mat22 {

    public: //All data members begin with m_ prefix

        float m_elems[4];         //2x2 matrix elements
		
		//creates a 2x2 identity matrix
        Mat22();

		//creates a 2x2 matrix with given values
        Mat22(float a0, float b0, float a1, float b1);

		//Copy Constructor
        Mat22(const Mat22& mat2);

		//transposes the original 2x2 matrix; row-column interchange
        Mat22 transpose();

		//adds two 2x2 matrices
        Mat22 operator+(const Mat22& mat)const;

		//subtracts two 2x2 matrices
        Mat22 operator-(const Mat22& mat)const;

		//multiplies two 2x2 matrices
        Mat22 operator*(const Mat22& mat)const;

		//scalar multiplication of 2x2 matrix: mat*f
        Mat22 operator*(float f)const;

		//scalar division of 2x2 matrix: mat/f
        Mat22 operator/(float f)const;
		
        //Scalar multiplication of 2x2 matrix: f * mat
        friend Mat22 operator*(float f, Mat22& mat);

        //Prints 2x2 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat22& mat);
    };

    //Non member functions

	//Returns determinant of 2x2 matrix
    float det(const Mat22& mat);
}