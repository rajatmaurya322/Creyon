#include "matrix2x2.h"

namespace Creyon {
    
    matrix_2x2::matrix_2x2() :m_elems{ 1.0f,0.0f, 0.0f,1.0f }
    {}
    
    matrix_2x2::matrix_2x2(float a0, float b0, float a1, float b1)
        : m_elems{ a0,b0, 
                   a1,b1 }
    {}

    matrix_2x2::matrix_2x2(const float *p_array)
        :m_elems{p_array[0], p_array[1], 
                 p_array[2], p_array[3]}
    {}

    matrix_2x2::matrix_2x2(const matrix_2x2& mat2) {
        *this = mat2;
    }

	matrix_2x2 matrix_2x2::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[2]);
        return *this;
    }
    
    matrix_2x2 matrix_2x2::operator+(const matrix_2x2& mat)const {
        
        return matrix_2x2(m_elems[0] + mat.m_elems[0], m_elems[1] + mat.m_elems[1],
                          m_elems[2] + mat.m_elems[2], m_elems[3] + mat.m_elems[3]);
    }

    matrix_2x2 matrix_2x2::operator-(const matrix_2x2& mat)const {

        return matrix_2x2(m_elems[0] - mat.m_elems[0], m_elems[1] - mat.m_elems[1],
                          m_elems[2] - mat.m_elems[2], m_elems[3] - mat.m_elems[3]);
        
    }

    matrix_2x2 matrix_2x2::operator*(const matrix_2x2& mat)const {
        matrix_2x2 a;

        a.m_elems[0] = m_elems[0] * mat.m_elems[0] + m_elems[1] * mat.m_elems[2];
        a.m_elems[1] = m_elems[0] * mat.m_elems[1] + m_elems[1] * mat.m_elems[3];

        a.m_elems[2] = m_elems[2] * mat.m_elems[0] + m_elems[3] * mat.m_elems[2];
        a.m_elems[3] = m_elems[2] * mat.m_elems[1] + m_elems[3] * mat.m_elems[3];

        return a;
    }

    matrix_2x2 matrix_2x2::operator*(float f)const {
        //Multiply each element by f
        return matrix_2x2(m_elems[0] * f, m_elems[1] * f,
                          m_elems[2] * f, m_elems[3] * f);
    }

    matrix_2x2 matrix_2x2::operator/(float f)const {
        
		if (f == 0) {   //Can't divide by 0
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return matrix_2x2(m_elems[0] / f, m_elems[1] / f,
                          m_elems[2] / f, m_elems[3] / f);
    }

    matrix_2x2 operator*(float f, matrix_2x2& mat) {
        //Calls above overloaded * operator
        return mat * f;
    }

    std::ostream& operator<<(std::ostream& os, const matrix_2x2& mat) {
        
        for (int i = 0; i < 4; i+=2) { //Prints row-wise elements
            os << mat.m_elems[i] << " " << mat.m_elems[i+1] << "\n";
        }
        
        return os;
    }

    float det(const matrix_2x2& mat) {
        //returns determinant of a 2x2 matrix
        return mat.m_elems[0] * mat.m_elems[3] - mat.m_elems[1] * mat.m_elems[2];
    }
}