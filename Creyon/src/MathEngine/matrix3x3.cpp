#include "matrix3x3.h"

namespace Creyon {

    Mat33::Mat33() :m_elems{ 1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f, 0.0f,0.0f,1.0f }
    {}

    Mat33::Mat33(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2)
        : m_elems{ a0,b0,c0,
                   a1,b1,c1,
                   a2,b2,c2}
    {}
    
    Mat33::Mat33(const Mat33& mat3) {
        *this = mat3;
    }

    Mat33 Mat33::transpose() {

        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[3]);
        std::swap(m_elems[2], m_elems[6]);
        std::swap(m_elems[5], m_elems[7]);
        return *this;
    }

    Mat33 Mat33::operator+(const Mat33& mat)const {

        return Mat33(m_elems[0] + mat[0], m_elems[1] + mat[1], m_elems[2] + mat[2],
					 m_elems[3] + mat[3], m_elems[4] + mat[4], m_elems[5] + mat[5],
					 m_elems[6] + mat[6], m_elems[7] + mat[7], m_elems[8] + mat[8]);
    }

    Mat33 Mat33::operator-(const Mat33& mat)const {

        return Mat33(m_elems[0] - mat[0], m_elems[1] - mat[1], m_elems[2] - mat[2],
					 m_elems[3] - mat[3], m_elems[4] - mat[4], m_elems[5] - mat[5],
					 m_elems[6] - mat[6], m_elems[7] - mat[7], m_elems[8] - mat[8]);
    }

    Mat33 Mat33::operator*(const Mat33& mat)const {
        Mat33 a;
		
		//Matrix multiplication
		for (int i = 0; i < 9; i+=3) { //i represents row's first element
			a[i] =	 m_elems[i] * mat[0] + m_elems[i + 1] * mat[3] + m_elems[i + 2] * mat[6];
			a[i+1] = m_elems[i] * mat[1] + m_elems[i + 1] * mat[4] + m_elems[i + 2] * mat[7];
			a[i+2] = m_elems[i] * mat[2] + m_elems[i + 1] * mat[5] + m_elems[i + 2] * mat[8];
		}

		return a;
    }

    Mat33 Mat33::operator*(float f)const {
		//Multiply each element by f
        return Mat33(m_elems[0] * f, m_elems[1] * f, m_elems[2] * f,
					 m_elems[3] * f, m_elems[4] * f, m_elems[5] * f,
					 m_elems[6] * f, m_elems[7] * f, m_elems[8] * f);
    }

    Mat33 Mat33::operator/(float f)const {

        if (f == 0) { //Can't divide by zero
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return Mat33(m_elems[0] / f, m_elems[1] / f, m_elems[2] / f,
					 m_elems[3] / f, m_elems[4] / f, m_elems[5] / f,
					 m_elems[6] / f, m_elems[7] / f, m_elems[8] / f);
    }

    Mat33 operator*(float f, Mat33& mat) {
        return mat * f; //calls above overloaded mat*f
    }

    std::ostream& operator<<(std::ostream& os, const Mat33& mat) {

        for (int i = 0; i < 9; i += 3) { //Print row-wise elements
            os << mat.m_elems[i] << " " << mat.m_elems[i + 1] << " " << mat.m_elems[i + 2] << "\n";
        }

        return os;
    }
	
    float det(const Mat33& mat) {
        //returns determinant of a 3x3 matrix
        return mat[0] * (mat[4] * mat[8] - mat[5] * mat[7])
            - mat[1] * (mat[3] * mat[8] - mat[6] * mat[5])
            + mat[2] * (mat[3] * mat[7] - mat[6] * mat[4]);
    }
}