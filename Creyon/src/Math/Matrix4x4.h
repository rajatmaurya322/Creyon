#pragma once

#include <iostream>
#include "Utility/Utility.h"

// row major ordering is used

namespace Creyon {

    class Mat44 {
	private:
        float m_array[4][4];

    public:

		//creates a 4x4 identity matrix
        Mat44();

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

		float& operator()(int i, int j) {
			return m_array[i][j];
		}

		float operator()(int i, int j)const {
			return m_array[i][j];
		}

		const float* operator&()const{
			return m_array[0];
		}
		
        //scalar multiplication of 4x4 matrix: f * mat
		friend Mat44 operator*(float f, Mat44& mat);

		//prints 4x4 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat44& mat);
    };

    float determinant(const Mat44& mat);
}