#include "matrix4x4.h"

//4x4
namespace Creyon {
    //Constructors
    //default constructor, creates a 4x4 identity matrix
    matrix_4x4::matrix_4x4() 
		:m_elems{ 1.0f,		0.0f,	0.0f,	0.0f, 
				  0.0f,		1.0f,	0.0f,	0.0f, 
				  0.0f,		0.0f,	1.0f,	0.0f, 
				  0.0f,		0.0f,	0.0f,	1.0f }
    {}

    //overloaded constructor, initialises 4x4 matrix with given values
    matrix_4x4::matrix_4x4(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3)
        : m_elems{a0,b0,c0,d0,
                  a1,b1,c1,d1,
                  a2,b2,c2,d2,
                  a3,b3,c3,d3}
    {}

    matrix_4x4::matrix_4x4(const float* p_array)
        :m_elems{p_array[0],  p_array[1],  p_array[2],  p_array[3],
                 p_array[4],  p_array[5],  p_array[6],  p_array[7],
                 p_array[8],  p_array[9],  p_array[10], p_array[11],
                 p_array[12], p_array[13], p_array[14], p_array[15]}
    {}

    matrix_4x4::matrix_4x4(const matrix_4x4& mat4) {
        *this = mat4;
    }

    //Methods
    matrix_4x4 matrix_4x4::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[4]);
        std::swap(m_elems[2], m_elems[8]);
        std::swap(m_elems[3], m_elems[12]);
        std::swap(m_elems[6], m_elems[9]);
        std::swap(m_elems[7], m_elems[13]);
        std::swap(m_elems[11], m_elems[14]);

        return *this;
    }

    //Overloaded Operators    

    //adds two 4x4 matrices elementwise
    matrix_4x4 matrix_4x4::operator+(const matrix_4x4& mat)const {

        return matrix_4x4(m_elems[0]  + mat.m_elems[0],     m_elems[1]  + mat.m_elems[1],  m_elems[2] + mat.m_elems[2],   m_elems[3] + mat.m_elems[3],
                          m_elems[4]  + mat.m_elems[4],     m_elems[5]  + mat.m_elems[5],  m_elems[6] + mat.m_elems[6],   m_elems[7] + mat.m_elems[7],
                          m_elems[8]  + mat.m_elems[8],     m_elems[9]  + mat.m_elems[9],  m_elems[10] + mat.m_elems[10], m_elems[11] + mat.m_elems[11],
                          m_elems[12] + mat.m_elems[12],    m_elems[13] + mat.m_elems[13], m_elems[14] + mat.m_elems[14], m_elems[15] + mat.m_elems[15]);
    }

    //subtracts two 4x4 matrices elementwise
    matrix_4x4 matrix_4x4::operator-(const matrix_4x4& mat)const {

        return matrix_4x4(m_elems[0] - mat.m_elems[0], m_elems[1] - mat.m_elems[1], m_elems[2] - mat.m_elems[2], m_elems[3] - mat.m_elems[3],
                          m_elems[4] - mat.m_elems[4], m_elems[5] - mat.m_elems[5], m_elems[6] - mat.m_elems[6], m_elems[7] - mat.m_elems[7],
                          m_elems[8] - mat.m_elems[8], m_elems[9] - mat.m_elems[9], m_elems[10] - mat.m_elems[10], m_elems[11] - mat.m_elems[11],
                          m_elems[12] - mat.m_elems[12], m_elems[13] - mat.m_elems[13], m_elems[14] - mat.m_elems[14], m_elems[15] - mat.m_elems[15]);
    }

    //multiplies two 4x4 matrices
    matrix_4x4 matrix_4x4::operator*(const matrix_4x4& mat)const {
		matrix_4x4 result;
		for (int i = 0; i < 16; i+=4) {  //i represents row's first element
			result.m_elems[i] = m_elems[i] * mat.m_elems[0] + m_elems[i + 1] * mat.m_elems[4] + m_elems[i + 2] * mat.m_elems[8] + m_elems[i + 3] * mat.m_elems[12];
			result.m_elems[i+1] = m_elems[i] * mat.m_elems[1] + m_elems[i + 1] * mat.m_elems[5] + m_elems[i + 2] * mat.m_elems[9] + m_elems[i + 3] * mat.m_elems[13];
			result.m_elems[i+2] = m_elems[i] * mat.m_elems[2] + m_elems[i + 1] * mat.m_elems[6] + m_elems[i + 2] * mat.m_elems[10] + m_elems[i + 3] * mat.m_elems[14];
			result.m_elems[i+3] = m_elems[i] * mat.m_elems[3] + m_elems[i + 1] * mat.m_elems[7] + m_elems[i + 2] * mat.m_elems[11] + m_elems[i + 3] * mat.m_elems[15];
		}
		return result;
    }

    //scalar multiplication of a 4x4 matrix
    matrix_4x4 matrix_4x4::operator*(float f)const {

        return matrix_4x4(m_elems[0] * f, m_elems[1] * f, m_elems[2] * f, m_elems[3] * f,
                          m_elems[4] * f, m_elems[5] * f, m_elems[6] * f, m_elems[7] * f,
                          m_elems[8] * f, m_elems[9] * f, m_elems[10]* f, m_elems[11]* f,
                          m_elems[12]* f, m_elems[13]* f, m_elems[14]* f, m_elems[15]* f);
    }

    //scalar division of a 4x4 matrix
    matrix_4x4 matrix_4x4::operator/(float f)const {

        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }

        return matrix_4x4(m_elems[0] / f, m_elems[1] / f, m_elems[2] / f, m_elems[3] / f,
                          m_elems[4] / f, m_elems[5] / f, m_elems[6] / f, m_elems[7] / f,
                          m_elems[8] / f, m_elems[9] / f, m_elems[10]/ f, m_elems[11]/ f,
                          m_elems[12]/ f, m_elems[13]/ f, m_elems[14]/ f, m_elems[15]/ f);
    }

    //Friend functions
    matrix_4x4 operator*(float f, matrix_4x4& mat) {
        //reverses scalar multiplication of form f*mat to mat*f

        return mat * f; //calls above overloaded mat*f
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_4x4& mat) {

        for (int i = 0; i < 16; i += 4) { //i represents row number
            os << mat.m_elems[i] << " " << mat.m_elems[i + 1] << " " << mat.m_elems[i + 2] << " " << mat.m_elems[i + 3] << "\n";
        }

        return os;
    }


    /*Warning: Only change this determinant if you know what this code is doing;
    You can literally make a mess of the matrix determinant by doing one silly mistake. */

    float det(const matrix_4x4& mat) {
        //returns determinant of 4x4  matrix
        return mat.m_elems[0] * (mat.m_elems[5] * (mat.m_elems[10] * mat.m_elems[15] - mat.m_elems[14] * mat.m_elems[11]) - mat.m_elems[6] * (mat.m_elems[9] * mat.m_elems[15] - mat.m_elems[13] * mat.m_elems[11]) + mat.m_elems[7] * (mat.m_elems[9] * mat.m_elems[14] - mat.m_elems[13] * mat.m_elems[10]))
            - mat.m_elems[1] * (mat.m_elems[4] * (mat.m_elems[10] * mat.m_elems[15] - mat.m_elems[14] * mat.m_elems[11]) - mat.m_elems[6] * (mat.m_elems[8] * mat.m_elems[15] - mat.m_elems[12] * mat.m_elems[11]) + mat.m_elems[7] * (mat.m_elems[8] * mat.m_elems[14] - mat.m_elems[12] * mat.m_elems[10]))
            + mat.m_elems[2] * (mat.m_elems[4] * (mat.m_elems[9] * mat.m_elems[15] - mat.m_elems[13] * mat.m_elems[11]) - mat.m_elems[5] * (mat.m_elems[8] * mat.m_elems[15] - mat.m_elems[12] * mat.m_elems[11]) + mat.m_elems[7] * (mat.m_elems[8] * mat.m_elems[13] - mat.m_elems[12] * mat.m_elems[9]))
            - mat.m_elems[3] * (mat.m_elems[4] * (mat.m_elems[9] * mat.m_elems[14] - mat.m_elems[13] * mat.m_elems[10]) - mat.m_elems[5] * (mat.m_elems[8] * mat.m_elems[14] - mat.m_elems[12] * mat.m_elems[10]) + mat.m_elems[6] * (mat.m_elems[8] * mat.m_elems[13] - mat.m_elems[12] * mat.m_elems[9]));
    }
}