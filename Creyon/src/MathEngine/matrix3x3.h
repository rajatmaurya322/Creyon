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
    
    class matrix_3x3 {
    
    public:  //All data members begin with m_ prefix
     
        float m_elems[9];     //3x3 matrix elements;

		//creates a 3X3 identity matrix
        matrix_3x3();

        //creates 3x3 matrix with given values
        matrix_3x3(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2);

        //Creates 3x3 matrix with given array
		matrix_3x3(const float *p_array);

		//Copy Constructor
        matrix_3x3(const matrix_3x3& mat3);
        
		//transposes the original 3x3 matrix; row-column interchange
		matrix_3x3 transpose();

		//adds two 3x3 matrices
        matrix_3x3 operator+(const matrix_3x3& mat)const;
        
		//subtracts two 3x3 matrices
        matrix_3x3 operator-(const matrix_3x3& mat)const;
        
		//multiplies of two 3x3 matrices
        matrix_3x3 operator*(const matrix_3x3& mat)const;
        
		//scalar multiplication of 3x3 matrix: mat*f
        matrix_3x3 operator*(float f)const;
        
		//scalar division of 3x3 matrix: mat/f
        matrix_3x3 operator/(float f)const;
		
        //Scalar multiplication of 3x3 matrix: f * mat
        friend matrix_3x3 operator*(float f, matrix_3x3& mat);
        
        //Prints 3x3 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const matrix_3x3& mat);
    };

    //Non member functions

	//Returns determinant of 3x3 matrix
    float det(const matrix_3x3& mat);
}