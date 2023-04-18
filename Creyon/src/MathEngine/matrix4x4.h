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

    class Mat44 {
	private:
        float m_elems[16];     //4x4 matrix elements;
    
	public:		//All data members begin with m_ prefix

		//creates a 4x4 identity matrix
        Mat44();

        //creates a 4x4 matrix with given values
        Mat44(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3);

		//Copy constructor
        Mat44(const Mat44& mat4);
        
		//transposes the original 4x4 matrix; row-column interchange
		Mat44 transpose();

		//adds two 4x4 matrices
        Mat44 operator+(const Mat44& mat)const;

		//subtracts two 4x4 matrices
        Mat44 operator-(const Mat44& mat)const;

		//multiplies two 4x4 matrices
        Mat44 operator*(const Mat44& mat)const;

		//scalar multiplication of 4x4 matrix: mat*f
        Mat44 operator*(float f)const;

		//scalar division of 4x4 matrix: mat/f
        Mat44 operator/(float f)const;

		//Read/Write access to a matrix element with []
		float& operator[](int i) {
			return m_elems[i];
		}

		//Read access to a matrix element with []
		float operator[](int i)const {
			return m_elems[i];
		}

		const float* operator&()const{
			return m_elems;
		}
		
        //scalar multiplication of 4x4 matrix: f * mat
        friend Mat44 operator*(float f, Mat44& mat);

		//Prints 4x4 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat44& mat);
    };

    //Non member functions

	//Returns determinant of 4x4 matrix
    float det(const Mat44& mat);
}