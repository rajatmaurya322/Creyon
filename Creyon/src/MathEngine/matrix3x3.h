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
    
    class Mat33 {
    
    public:  //All data members begin with m_ prefix
     
        float m_elems[9];     //3x3 matrix elements;

		//creates a 3X3 identity matrix
        Mat33();

        //creates 3x3 matrix with given values
        Mat33(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2);

        //Creates 3x3 matrix with given array
		Mat33(const float *p_array);

		//Copy Constructor
        Mat33(const Mat33& mat3);
        
		//transposes the original 3x3 matrix; row-column interchange
		Mat33 transpose();

		//adds two 3x3 matrices
        Mat33 operator+(const Mat33& mat)const;
        
		//subtracts two 3x3 matrices
        Mat33 operator-(const Mat33& mat)const;
        
		//multiplies of two 3x3 matrices
        Mat33 operator*(const Mat33& mat)const;
        
		//scalar multiplication of 3x3 matrix: mat*f
        Mat33 operator*(float f)const;
        
		//scalar division of 3x3 matrix: mat/f
        Mat33 operator/(float f)const;
		
        //Scalar multiplication of 3x3 matrix: f * mat
        friend Mat33 operator*(float f, Mat33& mat);
        
        //Prints 3x3 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat33& mat);
    };

    //Non member functions

	//Returns determinant of 3x3 matrix
    float det(const Mat33& mat);
}