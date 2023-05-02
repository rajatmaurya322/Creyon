#include "matrix2x2.h"

namespace Creyon {
    
    Mat22::Mat22() :m_elems{ 1.0f,0.0f, 0.0f,1.0f }
    {}
    
    Mat22::Mat22(float a0, float b0, float a1, float b1)
        : m_elems{ a0,b0, 
                   a1,b1 }
    {}

    Mat22::Mat22(const Mat22& mat2) {
        *this = mat2;
    }

	Mat22 Mat22::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[2]);
        return *this;
    }
    
    Mat22 Mat22::operator+(const Mat22& mat)const {
        
        return Mat22(m_elems[0] + mat.m_elems[0], m_elems[1] + mat.m_elems[1],
                          m_elems[2] + mat.m_elems[2], m_elems[3] + mat.m_elems[3]);
    }

    Mat22 Mat22::operator-(const Mat22& mat)const {

        return Mat22(m_elems[0] - mat.m_elems[0], m_elems[1] - mat.m_elems[1],
                          m_elems[2] - mat.m_elems[2], m_elems[3] - mat.m_elems[3]);
        
    }

    Mat22 Mat22::operator*(const Mat22& mat)const {
        Mat22 a;

        a.m_elems[0] = m_elems[0] * mat.m_elems[0] + m_elems[1] * mat.m_elems[2];
        a.m_elems[1] = m_elems[0] * mat.m_elems[1] + m_elems[1] * mat.m_elems[3];

        a.m_elems[2] = m_elems[2] * mat.m_elems[0] + m_elems[3] * mat.m_elems[2];
        a.m_elems[3] = m_elems[2] * mat.m_elems[1] + m_elems[3] * mat.m_elems[3];

        return a;
    }

    Mat22 Mat22::operator*(float f)const {
        //Multiply each element by f
        return Mat22(m_elems[0] * f, m_elems[1] * f,
                          m_elems[2] * f, m_elems[3] * f);
    }

    Mat22 Mat22::operator/(float f)const {
        
		if (f == 0) {   //Can't divide by 0
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return Mat22(m_elems[0] / f, m_elems[1] / f,
                          m_elems[2] / f, m_elems[3] / f);
    }

    Mat22 operator*(float f, Mat22& mat) {
        //Calls above overloaded * operator
        return mat * f;
    }

    std::ostream& operator<<(std::ostream& os, const Mat22& mat) {
        
        for (int i = 0; i < 4; i+=2) { //Prints row-wise elements
            os << mat.m_elems[i] << " " << mat.m_elems[i+1] << "\n";
        }
        
        return os;
    }

    float det(const Mat22& mat) {
        //returns determinant of a 2x2 matrix
        return mat.m_elems[0] * mat.m_elems[3] - mat.m_elems[1] * mat.m_elems[2];
    }
}