#pragma once

#include <iostream>
#include "Utility/Utility.h"

// row major ordering is used

namespace Creyon {

    class Mat44 {
	private:
        float m_array[16];
    
	public:

		//creates a 4x4 identity matrix
        Mat44();

        Mat44(float array0, float array1, float array2, float array3, 
			  float array4, float array5, float array6, float array7, 
			  float array8, float array9, float array10, float array11, 
			  float array12, float array13, float array14, float array15);

		//Copy constructor
        Mat44(const Mat44& mat4);
        
		//transpose the matrix
		Mat44 transpose();

		//adds two matrices
        Mat44 operator+(const Mat44& mat)const;

		//subtracts two matrices
        Mat44 operator-(const Mat44& mat)const;

		//multiplies two matrices
        Mat44 operator*(const Mat44& mat)const;

		//scalar multiplication of 4x4 matrix: mat*f
        Mat44 operator*(float f)const;

		//scalar division of 4x4 matrix: mat/f
        Mat44 operator/(float f)const;

		//write access to a matrix element with []
		float& operator[](int i) {
			return m_array[i];
		}

		//read access to a matrix element with []
		float operator[](int i)const {
			return m_array[i];
		}

		const float* operator&()const{
			return m_array;
		}
		
        //scalar multiplication of 4x4 matrix: f * mat
		friend Mat44 operator*(float f, Mat44& mat);

		//prints 4x4 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat44& mat);
    };

    float determinant(const Mat44& mat);
}