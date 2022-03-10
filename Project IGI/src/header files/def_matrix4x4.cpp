#include "matrix4x4.h"

//4x4
namespace Creyon {
    //Constructors

    //default constructor, creates a 4x4 identity matrix
    matrix_4x4::matrix_4x4() :m_elements{ 1.0f,0.0f,0.0f,0.0f, 0.0f,1.0f,0.0f,0.0f, 0.0f,0.0f,1.0f,0.0f, 0.0f,0.0f,0.0f,1.0f }
    {}

    //overloaded constructor, initialises 4x4 matrix with given values
    matrix_4x4::matrix_4x4(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3)
        : m_elements{ a0,b0,c0,d0,
                    a1,b1,c1,d1,
                    a2,b2,c2,d2,
                    a3,b3,c3,d3 }
    {}

    //Methods
    matrix_4x4 matrix_4x4::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_elements[1], m_elements[4]);
        std::swap(m_elements[2], m_elements[8]);
        std::swap(m_elements[3], m_elements[12]);
        std::swap(m_elements[6], m_elements[9]);
        std::swap(m_elements[7], m_elements[13]);
        std::swap(m_elements[11], m_elements[14]);

        return *this;
    }

    //Overloaded Operators    

    //adds two 4x4 matrices elementwise
    matrix_4x4 matrix_4x4::operator+(const matrix_4x4& mat)const {

        return matrix_4x4(m_elements[0] + mat.m_elements[0], m_elements[1] + mat.m_elements[1], m_elements[2] + mat.m_elements[2], m_elements[3] + mat.m_elements[3],
            m_elements[4] + mat.m_elements[4], m_elements[5] + mat.m_elements[5], m_elements[6] + mat.m_elements[6], m_elements[7] + mat.m_elements[7],
            m_elements[8] + mat.m_elements[8], m_elements[9] + mat.m_elements[9], m_elements[10] + mat.m_elements[10], m_elements[11] + mat.m_elements[11],
            m_elements[12] + mat.m_elements[12], m_elements[13] + mat.m_elements[13], m_elements[14] + mat.m_elements[14], m_elements[15] + mat.m_elements[15]);
    }

    //subtracts two 4x4 matrices elementwise
    matrix_4x4 matrix_4x4::operator-(const matrix_4x4& mat)const {

        return matrix_4x4(m_elements[0] - mat.m_elements[0], m_elements[1] - mat.m_elements[1], m_elements[2] - mat.m_elements[2], m_elements[3] - mat.m_elements[3],
            m_elements[4] - mat.m_elements[4], m_elements[5] - mat.m_elements[5], m_elements[6] - mat.m_elements[6], m_elements[7] - mat.m_elements[7],
            m_elements[8] - mat.m_elements[8], m_elements[9] - mat.m_elements[9], m_elements[10] - mat.m_elements[10], m_elements[11] - mat.m_elements[11],
            m_elements[12] - mat.m_elements[12], m_elements[13] - mat.m_elements[13], m_elements[14] - mat.m_elements[14], m_elements[15] - mat.m_elements[15]);
    }

    //multiplies two 4x4 matrices
    matrix_4x4 matrix_4x4::operator*(const matrix_4x4& mat)const {
        float a[16];

        a[0] = m_elements[0] * mat.m_elements[0] + m_elements[1] * mat.m_elements[4] + m_elements[2] * mat.m_elements[8] + m_elements[3] * m_elements[12];
        a[1] = m_elements[0] * mat.m_elements[1] + m_elements[1] * mat.m_elements[5] + m_elements[2] * mat.m_elements[9] + m_elements[3] * m_elements[13];
        a[2] = m_elements[0] * mat.m_elements[2] + m_elements[1] * mat.m_elements[6] + m_elements[2] * mat.m_elements[10] + m_elements[3] * m_elements[14];
        a[3] = m_elements[0] * mat.m_elements[3] + m_elements[1] * mat.m_elements[7] + m_elements[2] * mat.m_elements[11] + m_elements[3] * m_elements[15];

        a[4] = m_elements[4] * mat.m_elements[0] + m_elements[5] * mat.m_elements[4] + m_elements[6] * mat.m_elements[8] + m_elements[7] * m_elements[12];
        a[5] = m_elements[4] * mat.m_elements[1] + m_elements[5] * mat.m_elements[5] + m_elements[6] * mat.m_elements[9] + m_elements[7] * m_elements[13];
        a[6] = m_elements[4] * mat.m_elements[2] + m_elements[5] * mat.m_elements[6] + m_elements[6] * mat.m_elements[10] + m_elements[7] * m_elements[14];
        a[7] = m_elements[4] * mat.m_elements[3] + m_elements[5] * mat.m_elements[7] + m_elements[6] * mat.m_elements[11] + m_elements[7] * m_elements[15];

        a[8] = m_elements[8] * mat.m_elements[0] + m_elements[9] * mat.m_elements[4] + m_elements[10] * mat.m_elements[8] + m_elements[11] * m_elements[12];
        a[9] = m_elements[8] * mat.m_elements[1] + m_elements[9] * mat.m_elements[5] + m_elements[10] * mat.m_elements[9] + m_elements[11] * m_elements[13];
        a[10] = m_elements[8] * mat.m_elements[2] + m_elements[9] * mat.m_elements[6] + m_elements[10] * mat.m_elements[10] + m_elements[11] * m_elements[14];
        a[11] = m_elements[8] * mat.m_elements[3] + m_elements[9] * mat.m_elements[7] + m_elements[10] * mat.m_elements[11] + m_elements[11] * m_elements[15];

        a[12] = m_elements[12] * mat.m_elements[0] + m_elements[13] * mat.m_elements[4] + m_elements[14] * mat.m_elements[8] + m_elements[15] * m_elements[12];
        a[13] = m_elements[12] * mat.m_elements[1] + m_elements[13] * mat.m_elements[5] + m_elements[14] * mat.m_elements[9] + m_elements[15] * m_elements[13];
        a[14] = m_elements[12] * mat.m_elements[2] + m_elements[13] * mat.m_elements[6] + m_elements[14] * mat.m_elements[10] + m_elements[15] * m_elements[14];
        a[15] = m_elements[12] * mat.m_elements[3] + m_elements[13] * mat.m_elements[7] + m_elements[14] * mat.m_elements[11] + m_elements[15] * m_elements[15];

        return matrix_4x4(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]);
    }

    //scalar multiplication of a 4x4 matrix
    matrix_4x4 matrix_4x4::operator*(float f)const {

        return matrix_4x4(m_elements[0] * f, m_elements[1] * f, m_elements[2] * f, m_elements[3] * f,
            m_elements[4] * f, m_elements[5] * f, m_elements[6] * f, m_elements[7] * f,
            m_elements[8] * f, m_elements[9] * f, m_elements[10] * f, m_elements[11] * f,
            m_elements[12] * f, m_elements[13] * f, m_elements[14] * f, m_elements[15] * f);
    }

    //scalar division of a 4x4 matrix
    matrix_4x4 matrix_4x4::operator/(float f)const {

        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }

        return matrix_4x4(m_elements[0] / f, m_elements[1] / f, m_elements[2] / f, m_elements[3] / f,
            m_elements[4] / f, m_elements[5] / f, m_elements[6] / f, m_elements[7] / f,
            m_elements[8] / f, m_elements[9] / f, m_elements[10] / f, m_elements[11] / f,
            m_elements[12] / f, m_elements[13] / f, m_elements[14] / f, m_elements[15] / f);
    }

    //Friend functions
    matrix_4x4 operator*(float f, matrix_4x4& mat) {
        //reverses scalar multiplication of form f*mat to mat*f

        return mat * f; //calls above overloaded mat*f
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_4x4& mat) {

        for (int i = 0; i < 16; i += 4) { //i represents row number
            os << mat.m_elements[i] << " " << mat.m_elements[i + 1] << " " << mat.m_elements[i + 2] << " " << mat.m_elements[i + 3] << "\n";
        }

        return os;
    }


    /*Warning: Only change this determinant if you know what this code is doing;
    You can literally make a mess of the matrix determinant by doing one silly mistake. */

    float det(const matrix_4x4& mat) {
        //returns determinant of 4x4  matrix
        return mat.m_elements[0] * (mat.m_elements[5] * (mat.m_elements[10] * mat.m_elements[15] - mat.m_elements[14] * mat.m_elements[11]) - mat.m_elements[6] * (mat.m_elements[9] * mat.m_elements[15] - mat.m_elements[13] * mat.m_elements[11]) + mat.m_elements[7] * (mat.m_elements[9] * mat.m_elements[14] - mat.m_elements[13] * mat.m_elements[10]))
            - mat.m_elements[1] * (mat.m_elements[4] * (mat.m_elements[10] * mat.m_elements[15] - mat.m_elements[14] * mat.m_elements[11]) - mat.m_elements[6] * (mat.m_elements[8] * mat.m_elements[15] - mat.m_elements[12] * mat.m_elements[11]) + mat.m_elements[7] * (mat.m_elements[8] * mat.m_elements[14] - mat.m_elements[12] * mat.m_elements[10]))
            + mat.m_elements[2] * (mat.m_elements[4] * (mat.m_elements[9] * mat.m_elements[15] - mat.m_elements[13] * mat.m_elements[11]) - mat.m_elements[5] * (mat.m_elements[8] * mat.m_elements[15] - mat.m_elements[12] * mat.m_elements[11]) + mat.m_elements[7] * (mat.m_elements[8] * mat.m_elements[13] - mat.m_elements[12] * mat.m_elements[9]))
            - mat.m_elements[3] * (mat.m_elements[4] * (mat.m_elements[9] * mat.m_elements[14] - mat.m_elements[13] * mat.m_elements[10]) - mat.m_elements[5] * (mat.m_elements[8] * mat.m_elements[14] - mat.m_elements[12] * mat.m_elements[10]) + mat.m_elements[6] * (mat.m_elements[8] * mat.m_elements[13] - mat.m_elements[12] * mat.m_elements[9]));
    }
}