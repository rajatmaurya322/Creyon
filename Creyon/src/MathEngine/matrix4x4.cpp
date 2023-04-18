#include "matrix4x4.h"

namespace Creyon {
    
    Mat44::Mat44() 
		:m_elems{ 1.0f,		0.0f,	0.0f,	0.0f, 
				  0.0f,		1.0f,	0.0f,	0.0f, 
				  0.0f,		0.0f,	1.0f,	0.0f, 
				  0.0f,		0.0f,	0.0f,	1.0f }
    {}

    Mat44::Mat44(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3)
        : m_elems{a0,b0,c0,d0,
                  a1,b1,c1,d1,
                  a2,b2,c2,d2,
                  a3,b3,c3,d3}
    {}

    Mat44::Mat44(const Mat44& mat4) {
        *this = mat4;
    }
    
	Mat44 Mat44::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[4]);
        std::swap(m_elems[2], m_elems[8]);
        std::swap(m_elems[3], m_elems[12]);
        std::swap(m_elems[6], m_elems[9]);
        std::swap(m_elems[7], m_elems[13]);
        std::swap(m_elems[11], m_elems[14]);

        return *this;
    }

    Mat44 Mat44::operator+(const Mat44& mat)const {

        return Mat44(m_elems[0]  + mat[0],	m_elems[1]  + mat[1],	m_elems[2] + mat[2],	m_elems[3] + mat[3],
					 m_elems[4]  + mat[4],	m_elems[5]  + mat[5],	m_elems[6] + mat[6],	m_elems[7] + mat[7],
					 m_elems[8]  + mat[8],	m_elems[9]  + mat[9],	m_elems[10]+ mat[10],	m_elems[11]+ mat[11],
					 m_elems[12] + mat[12],	m_elems[13] + mat[13],	m_elems[14]+ mat[14],	m_elems[15]+ mat[15]);
    }

    Mat44 Mat44::operator-(const Mat44& mat)const {

        return Mat44(m_elems[0] - mat[0],	m_elems[1] - mat[1],	m_elems[2] - mat[2],	m_elems[3] - mat[3],
					 m_elems[4] - mat[4],	m_elems[5] - mat[5],	m_elems[6] - mat[6],	m_elems[7] - mat[7],
					 m_elems[8] - mat[8],	m_elems[9] - mat[9],	m_elems[10]- mat[10],	m_elems[11]- mat[11],
					 m_elems[12] -mat[12],	m_elems[13]- mat[13],	m_elems[14]- mat[14],	m_elems[15]- mat[15]);
    }

    Mat44 Mat44::operator*(const Mat44& mat)const {
		Mat44 result;
		
		//Matrix multiplication
		for (int i = 0; i < 16; i+=4) {  //i represents row's first element
			result[i] =   m_elems[i] * mat[0] + m_elems[i + 1] * mat[4] + m_elems[i + 2] * mat[8] + m_elems[i + 3] * mat[12];
			result[i+1] = m_elems[i] * mat[1] + m_elems[i + 1] * mat[5] + m_elems[i + 2] * mat[9] + m_elems[i + 3] * mat[13];
			result[i+2] = m_elems[i] * mat[2] + m_elems[i + 1] * mat[6] + m_elems[i + 2] * mat[10]+ m_elems[i + 3] * mat[14];
			result[i+3] = m_elems[i] * mat[3] + m_elems[i + 1] * mat[7] + m_elems[i + 2] * mat[11]+ m_elems[i + 3] * mat[15];
		}
		return result;
    }

    Mat44 Mat44::operator*(float f)const {
		//Multiply each element by f
        return Mat44(m_elems[0] * f, m_elems[1] * f, m_elems[2] * f, m_elems[3] * f,
                     m_elems[4] * f, m_elems[5] * f, m_elems[6] * f, m_elems[7] * f,
                     m_elems[8] * f, m_elems[9] * f, m_elems[10]* f, m_elems[11]* f,
                     m_elems[12]* f, m_elems[13]* f, m_elems[14]* f, m_elems[15]* f);
    }

    Mat44 Mat44::operator/(float f)const {

        if (f == 0) {  //Can't divide by 0
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
		else{
			return Mat44(m_elems[0] / f, m_elems[1] / f, m_elems[2] / f, m_elems[3] / f,
						 m_elems[4] / f, m_elems[5] / f, m_elems[6] / f, m_elems[7] / f,
						 m_elems[8] / f, m_elems[9] / f, m_elems[10]/ f, m_elems[11]/ f,
						 m_elems[12]/ f, m_elems[13]/ f, m_elems[14]/ f, m_elems[15]/ f);
		}
    }

    Mat44 operator*(float f, Mat44& mat) {
        return mat * f; //calls above overloaded mat*f
    }

    std::ostream& operator<<(std::ostream& os, const Mat44& mat) {
        for (int i = 0; i < 16; i += 4) { //Prints elements row-wise
            os << mat.m_elems[i] << " " << mat.m_elems[i + 1] << " " << mat.m_elems[i + 2] << " " << mat.m_elems[i + 3] << "\n";
        }

        return os;
    }


    /*Warning: Only change this determinant if you know what this code is doing;
    You can literally make a mess of the matrix determinant by doing one silly mistake. */

    float det(const Mat44& mat) {
        //returns determinant of 4x4  matrix
        return mat[0] * (mat[5] * (mat[10] *mat[15] - mat[14] * mat[11]) - mat[6] * (mat[9] * mat[15] - mat[13] * mat[11]) + mat[7] * (mat[9] * mat[14] - mat[13] * mat[10]))
             - mat[1] * (mat[4] * (mat[10] *mat[15] - mat[14] * mat[11]) - mat[6] * (mat[8] * mat[15] - mat[12] * mat[11]) + mat[7] * (mat[8] * mat[14] - mat[12] * mat[10]))
             + mat[2] * (mat[4] * (mat[9] * mat[15] - mat[13] * mat[11]) - mat[5] * (mat[8] * mat[15] - mat[12] * mat[11]) + mat[7] * (mat[8] * mat[13] - mat[12] * mat[9]))
             - mat[3] * (mat[4] * (mat[9] * mat[14] - mat[13] * mat[10]) - mat[5] * (mat[8] * mat[14] - mat[12] * mat[10]) + mat[6] * (mat[8] * mat[13] - mat[12] * mat[9]));
    }
}