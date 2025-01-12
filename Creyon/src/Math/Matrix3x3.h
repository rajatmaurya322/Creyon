#pragma once

#include <iostream>
#include "Utility/Utility.h"

//row major ordering is used

namespace Creyon {
    
    class Mat33 {
	private:
		float m_array[3][3];

    public:
     
		//creates a 3x3 identity matrix
        Mat33();

		//copy constructor
        Mat33(const Mat33& mat3);
        
		//transpose the matrix
		Mat33 transpose();

		//adds two matrices
        Mat33 operator+(const Mat33& mat)const;
        
		//subtracts two matrices
        Mat33 operator-(const Mat33& mat)const;
        
		//multiplies two matrices
        Mat33 operator*(const Mat33& mat)const;
        
		//scalar multiplication of 3x3 matrix: mat*f
        Mat33 operator*(float f)const;
        
		//scalar division of 3x3 matrix: mat/f
        Mat33 operator/(float f)const;

		float& operator()(int i, int j) {
			return m_array[i][j];
		}

		float operator()(int i, int j)const {
			return m_array[i][j];
		}

		const float* operator&()const {
			return m_array[0];
		}
		
        //scalar multiplication of 3x3 matrix: f * mat
        friend Mat33 operator*(float f, Mat33& mat);
        
        //prints 3x3 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat33& mat);
    };

    float determinant(const Mat33& mat);
}