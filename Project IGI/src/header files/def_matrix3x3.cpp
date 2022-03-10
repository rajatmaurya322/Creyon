#include "matrix3x3.h"

//3x3
namespace Creyon {
    //Constructors

    //default constructor, creates a 3x3 identity matrix
    matrix_3x3::matrix_3x3() :m_elements{ 1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f, 0.0f,0.0f,1.0f }
    {}

    //Overloaded constructor, initialises 3x3 matrix with given values
    matrix_3x3::matrix_3x3(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2)
        : m_elements{ a0,b0,c0,
                     a1,b1,c1,
                     a2,b2,c2 }
    {}

    //Methods

    matrix_3x3 matrix_3x3::transpose() {

        //changes rows to columns and columns to rows
        std::swap(m_elements[1], m_elements[3]);
        std::swap(m_elements[2], m_elements[6]);
        std::swap(m_elements[5], m_elements[7]);
        return *this;
    }

    //Overloaded Operators    

    //adds two 3x3 matrices elementwise
    matrix_3x3 matrix_3x3::operator+(const matrix_3x3& mat)const {

        return matrix_3x3(m_elements[0] + mat.m_elements[0], m_elements[1] + mat.m_elements[1], m_elements[2] + mat.m_elements[2],
            m_elements[3] + mat.m_elements[3], m_elements[4] + mat.m_elements[4], m_elements[5] + mat.m_elements[5],
            m_elements[6] + mat.m_elements[6], m_elements[7] + mat.m_elements[7], m_elements[8] + mat.m_elements[8]);
    }

    //subtracts two 3x3 matrices elementwise
    matrix_3x3 matrix_3x3::operator-(const matrix_3x3& mat)const {

        return matrix_3x3(m_elements[0] - mat.m_elements[0], m_elements[1] - mat.m_elements[1], m_elements[2] - mat.m_elements[2],
            m_elements[3] - mat.m_elements[3], m_elements[4] - mat.m_elements[4], m_elements[5] - mat.m_elements[5],
            m_elements[6] - mat.m_elements[6], m_elements[7] - mat.m_elements[7], m_elements[8] - mat.m_elements[8]);
    }

    //multiplies two 3x3 matrices
    matrix_3x3 matrix_3x3::operator*(const matrix_3x3& mat)const {

        float a[9];

        a[0] = m_elements[0] * mat.m_elements[0] + m_elements[1] * mat.m_elements[3] + m_elements[2] * mat.m_elements[6];
        a[1] = m_elements[0] * mat.m_elements[1] + m_elements[1] * mat.m_elements[4] + m_elements[2] * mat.m_elements[7];
        a[2] = m_elements[0] * mat.m_elements[2] + m_elements[1] * mat.m_elements[5] + m_elements[2] * mat.m_elements[8];

        a[3] = m_elements[3] * mat.m_elements[0] + m_elements[4] * mat.m_elements[3] + m_elements[5] * mat.m_elements[6];
        a[4] = m_elements[3] * mat.m_elements[1] + m_elements[4] * mat.m_elements[4] + m_elements[5] * mat.m_elements[7];
        a[5] = m_elements[3] * mat.m_elements[2] + m_elements[4] * mat.m_elements[5] + m_elements[5] * mat.m_elements[8];

        a[6] = m_elements[6] * mat.m_elements[0] + m_elements[7] * mat.m_elements[3] + m_elements[8] * mat.m_elements[6];
        a[7] = m_elements[6] * mat.m_elements[1] + m_elements[7] * mat.m_elements[4] + m_elements[8] * mat.m_elements[7];
        a[8] = m_elements[6] * mat.m_elements[2] + m_elements[7] * mat.m_elements[5] + m_elements[8] * mat.m_elements[8];

        return matrix_3x3(a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
    }

    //scalar multiplication of a 3x3 matrix
    matrix_3x3 matrix_3x3::operator*(float f)const {

        return matrix_3x3(m_elements[0] * f, m_elements[1] * f, m_elements[2] * f,
            m_elements[3] * f, m_elements[4] * f, m_elements[5] * f,
            m_elements[6] * f, m_elements[7] * f, m_elements[8] * f);
    }

    //scalar division of a 3x3 matrix
    matrix_3x3 matrix_3x3::operator/(float f)const {

        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return matrix_3x3(m_elements[0] / f, m_elements[1] / f, m_elements[2] / f,
            m_elements[3] / f, m_elements[4] / f, m_elements[5] / f,
            m_elements[6] / f, m_elements[7] / f, m_elements[8] / f);
    }

    //Friend functions
    matrix_3x3 operator*(float f, matrix_3x3& mat) {
        //reverses scalar multiplication of form f*mat to mat*f

        return mat * f; //calls above overloaded mat*f
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_3x3& mat) {

        for (int i = 0; i < 9; i += 3) { //i represents row number
            os << mat.m_elements[i] << " " << mat.m_elements[i + 1] << " " << mat.m_elements[i + 2] << "\n";
        }

        return os;
    }

    float det(const matrix_3x3& mat) {
        //returns determinant of a 3x3 matrix
        return mat.m_elements[0] * (mat.m_elements[4] * mat.m_elements[8] - mat.m_elements[5] * mat.m_elements[7])
            - mat.m_elements[1] * (mat.m_elements[3] * mat.m_elements[8] - mat.m_elements[6] * mat.m_elements[5])
            + mat.m_elements[2] * (mat.m_elements[3] * mat.m_elements[7] - mat.m_elements[6] * mat.m_elements[4]);
    }
}