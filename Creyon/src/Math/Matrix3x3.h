#pragma once

#include <iostream>
#include "Utility/Utility.h"

//row major ordering is used

namespace Creyon {
    
    class Mat33 {
	private: 
		float m_array[9];
    
    public:
     
		//creates a 3x3 identity matrix
        Mat33();

        Mat33(float array0, float array1, float array2, 
			  float array3, float array4, float array5, 
			  float array6, float array7, float array8);

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

		//write access to a matrix element with []
		float& operator[](int i) {
			return m_array[i];
		}
		
		//read access to a matrix element with []
		float operator[](int i)const {
			return m_array[i];
		}

		const float* operator&()const {
			return m_array;
		}
		
        //scalar multiplication of 3x3 matrix: f * mat
        friend Mat33 operator*(float f, Mat33& mat);
        
        //prints 3x3 matrix directly with cout
        friend std::ostream& operator<<(std::ostream& os, const Mat33& mat);
    };

    float determinant(const Mat33& mat);
}