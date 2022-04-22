#include "matrix3x3.h"

//3x3
namespace Creyon {
    //Constructors

    //default constructor, creates a 3x3 identity matrix
    matrix_3x3::matrix_3x3() :m_elems{ 1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f, 0.0f,0.0f,1.0f }
    {}

    //Overloaded constructor, initialises 3x3 matrix with given values
    matrix_3x3::matrix_3x3(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2)
        : m_elems{ a0,b0,c0,
                   a1,b1,c1,
                   a2,b2,c2}
    {}

    matrix_3x3::matrix_3x3(const float *p_array)
        : m_elems{p_array[0],  p_array[1],  p_array[2],
                  p_array[3],  p_array[4],  p_array[5],
                  p_array[6],  p_array[7],  p_array[8]}
    {}
    
    matrix_3x3::matrix_3x3(const matrix_3x3& mat3) {
        *this = mat3;
    }
    //Methods

    matrix_3x3 matrix_3x3::transpose() {

        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[3]);
        std::swap(m_elems[2], m_elems[6]);
        std::swap(m_elems[5], m_elems[7]);
        return *this;
    }

    //Overloaded Operators    

    //adds two 3x3 matrices elementwise
    matrix_3x3 matrix_3x3::operator+(const matrix_3x3& mat)const {

        return matrix_3x3(m_elems[0] + mat.m_elems[0], m_elems[1] + mat.m_elems[1], m_elems[2] + mat.m_elems[2],
                          m_elems[3] + mat.m_elems[3], m_elems[4] + mat.m_elems[4], m_elems[5] + mat.m_elems[5],
                          m_elems[6] + mat.m_elems[6], m_elems[7] + mat.m_elems[7], m_elems[8] + mat.m_elems[8]);
    }

    //subtracts two 3x3 matrices elementwise
    matrix_3x3 matrix_3x3::operator-(const matrix_3x3& mat)const {

        return matrix_3x3(m_elems[0] - mat.m_elems[0], m_elems[1] - mat.m_elems[1], m_elems[2] - mat.m_elems[2],
                          m_elems[3] - mat.m_elems[3], m_elems[4] - mat.m_elems[4], m_elems[5] - mat.m_elems[5],
                          m_elems[6] - mat.m_elems[6], m_elems[7] - mat.m_elems[7], m_elems[8] - mat.m_elems[8]);
    }

    //multiplies two 3x3 matrices
    matrix_3x3 matrix_3x3::operator*(const matrix_3x3& mat)const {

        matrix_3x3 a;

        a.m_elems[0] = m_elems[0] * mat.m_elems[0] + m_elems[1] * mat.m_elems[3] + m_elems[2] * mat.m_elems[6];
        a.m_elems[1] = m_elems[0] * mat.m_elems[1] + m_elems[1] * mat.m_elems[4] + m_elems[2] * mat.m_elems[7];
        a.m_elems[2] = m_elems[0] * mat.m_elems[2] + m_elems[1] * mat.m_elems[5] + m_elems[2] * mat.m_elems[8];

        a.m_elems[3] = m_elems[3] * mat.m_elems[0] + m_elems[4] * mat.m_elems[3] + m_elems[5] * mat.m_elems[6];
        a.m_elems[4] = m_elems[3] * mat.m_elems[1] + m_elems[4] * mat.m_elems[4] + m_elems[5] * mat.m_elems[7];
        a.m_elems[5] = m_elems[3] * mat.m_elems[2] + m_elems[4] * mat.m_elems[5] + m_elems[5] * mat.m_elems[8];

        a.m_elems[6] = m_elems[6] * mat.m_elems[0] + m_elems[7] * mat.m_elems[3] + m_elems[8] * mat.m_elems[6];
        a.m_elems[7] = m_elems[6] * mat.m_elems[1] + m_elems[7] * mat.m_elems[4] + m_elems[8] * mat.m_elems[7];
        a.m_elems[8] = m_elems[6] * mat.m_elems[2] + m_elems[7] * mat.m_elems[5] + m_elems[8] * mat.m_elems[8];

        return a;
    }

    //scalar multiplication of a 3x3 matrix
    matrix_3x3 matrix_3x3::operator*(float f)const {

        return matrix_3x3(m_elems[0] * f, m_elems[1] * f, m_elems[2] * f,
                          m_elems[3] * f, m_elems[4] * f, m_elems[5] * f,
                          m_elems[6] * f, m_elems[7] * f, m_elems[8] * f);
    }

    //scalar division of a 3x3 matrix
    matrix_3x3 matrix_3x3::operator/(float f)const {

        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return matrix_3x3(m_elems[0] / f, m_elems[1] / f, m_elems[2] / f,
                          m_elems[3] / f, m_elems[4] / f, m_elems[5] / f,
                          m_elems[6] / f, m_elems[7] / f, m_elems[8] / f);
    }

    //Friend functions
    matrix_3x3 operator*(float f, matrix_3x3& mat) {
        //reverses scalar multiplication of form f*mat to mat*f

        return mat * f; //calls above overloaded mat*f
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_3x3& mat) {

        for (int i = 0; i < 9; i += 3) { //i represents row number
            os << mat.m_elems[i] << " " << mat.m_elems[i + 1] << " " << mat.m_elems[i + 2] << "\n";
        }

        return os;
    }

    float det(const matrix_3x3& mat) {
        //returns determinant of a 3x3 matrix
        return mat.m_elems[0] * (mat.m_elems[4] * mat.m_elems[8] - mat.m_elems[5] * mat.m_elems[7])
            - mat.m_elems[1] * (mat.m_elems[3] * mat.m_elems[8] - mat.m_elems[6] * mat.m_elems[5])
            + mat.m_elems[2] * (mat.m_elems[3] * mat.m_elems[7] - mat.m_elems[6] * mat.m_elems[4]);
    }
}