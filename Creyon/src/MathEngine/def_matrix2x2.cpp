#include "matrix2x2.h"

//2x2
namespace Creyon {

    //Constructors
    
    //default constructor, creates a 2x2 identity matrix
    matrix_2x2::matrix_2x2() :m_elems{ 1.0f,0.0f, 0.0f,1.0f }
    {}
    
    //overloaded constructor, initialises 2x2 matrix with given values
    matrix_2x2::matrix_2x2(float a0, float b0, float a1, float b1)
        : m_elems{ a0,b0, 
                   a1,b1 }
    {}

    //overloaded constructor, initialises 2x2 matrix with array values
    matrix_2x2::matrix_2x2(const float *p_array)
        :m_elems{p_array[0], p_array[1], 
                 p_array[2], p_array[3]}
    {}

    //Copy constructor
    matrix_2x2::matrix_2x2(const matrix_2x2& mat2) {
        *this = mat2;
    }


    //Methods
    matrix_2x2 matrix_2x2::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_elems[1], m_elems[2]);
        return *this;
    }

    //Overloaded Operators    
    //adds two 2x2 matrices elementwise
    matrix_2x2 matrix_2x2::operator+(const matrix_2x2& mat)const {
        
        return matrix_2x2(m_elems[0] + mat.m_elems[0], m_elems[1] + mat.m_elems[1],
                          m_elems[2] + mat.m_elems[2], m_elems[3] + mat.m_elems[3]);
    }

    //subtracts two 2x2 matrices elementwise
    matrix_2x2 matrix_2x2::operator-(const matrix_2x2& mat)const {

        return matrix_2x2(m_elems[0] - mat.m_elems[0], m_elems[1] - mat.m_elems[1],
                          m_elems[2] - mat.m_elems[2], m_elems[3] - mat.m_elems[3]);
        
    }

    //multiplies two 2x2 matrices
    matrix_2x2 matrix_2x2::operator*(const matrix_2x2& mat)const {
        matrix_2x2 a;

        a.m_elems[0] = m_elems[0] * mat.m_elems[0] + m_elems[1] * mat.m_elems[2];
        a.m_elems[1] = m_elems[0] * mat.m_elems[1] + m_elems[1] * mat.m_elems[3];

        a.m_elems[2] = m_elems[2] * mat.m_elems[0] + m_elems[3] * mat.m_elems[2];
        a.m_elems[3] = m_elems[2] * mat.m_elems[1] + m_elems[3] * mat.m_elems[3];

        return a;
    }

    //scalar multiplication of a 2x2 matrix
    matrix_2x2 matrix_2x2::operator*(float f)const {
        
        return matrix_2x2(m_elems[0] * f, m_elems[1] * f,
                          m_elems[2] * f, m_elems[3] * f);
    }

    //scalar division of a 2x2 matrix
    matrix_2x2 matrix_2x2::operator/(float f)const {
        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return matrix_2x2(m_elems[0] / f, m_elems[1] / f,
                          m_elems[2] / f, m_elems[3] / f);
        
    }

    //Friend functions
    matrix_2x2 operator*(float f, matrix_2x2& mat) {
        //reverses scalar multiplication of form f*mat to mat*f
        return mat * f;
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_2x2& mat) {
        
        for (int i = 0; i < 4; i+=2) {
            os << mat.m_elems[i] << " " << mat.m_elems[i+1] << "\n";
        }
        
        return os;
    }

    float det(const matrix_2x2& mat) {
        
        //returns determinant of a 2x2 matrix
        return mat.m_elems[0] * mat.m_elems[3] - mat.m_elems[1] * mat.m_elems[2];
    }
}