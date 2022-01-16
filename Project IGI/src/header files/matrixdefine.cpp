#include "matrix.h"


//2x2
namespace Creyon {

    //Constructors
    //default constructor, creates a 2x2 null matrix
    matrix_2x2::matrix_2x2():m_a{ 0,0 },m_b{ 0,0 }
    {}

    //overloaded constructor, initialises 2x2 matrix with given vector values
    matrix_2x2::matrix_2x2(std::vector <float>& vec)
        : m_a{ vec[0], vec[2] }, m_b{ vec[1], vec[3] }
    {
        if (vec.size() != 4) {
            std::cout << "\nIncompatible vector size! Size:" << vec.size();
            exit(EXIT_FAILURE);
        }
    }

    //overloaded constructor, initialises 2x2 matrix with given values
    matrix_2x2::matrix_2x2(float a0, float b0, float a1, float b1)
        :m_a{a0, a1}, m_b{b0, b1}
    {}

    //Methods
    matrix_2x2 matrix_2x2::transpose() {
        
        //changes rows to columns and columns to rows
        std::swap(m_a[1], m_b[0]);
        return *this;
    }

    //Overloaded Operators    
    //adds two 2x2 matrices elementwise
    matrix_2x2 matrix_2x2::operator+(const matrix_2x2& mat)const {
        
        return matrix_2x2(m_a[0] + mat.m_a[0], m_b[0] + mat.m_b[0],
                          m_a[1] + mat.m_a[1], m_b[1] + mat.m_b[1]);
    }

    //subtracts two 2x2 matrices elementwise
    matrix_2x2 matrix_2x2::operator-(const matrix_2x2& mat)const {

        return matrix_2x2(m_a[0] - mat.m_a[0], m_b[0] - mat.m_b[0],
                          m_a[1] - mat.m_a[1], m_b[1] - mat.m_b[1]);
        
    }

    //multiplies two 2x2 matrices
    matrix_2x2 matrix_2x2::operator*(const matrix_2x2& mat)const {
        std::vector <float> vec;
        
        for (int i = 0; i < 2; ++i) { //i represents row number
            vec.push_back(m_a[i] * mat.m_a[0] + m_b[i] * mat.m_a[1]); //row*column1
            vec.push_back(m_a[i] * mat.m_b[0] + m_b[i] * mat.m_b[1]); //row*column2
        }
        
        return matrix_2x2(vec);
    }

    //scalar multiplication of a 2x2 matrix
    matrix_2x2 matrix_2x2::operator*(float f)const {
        
        return matrix_2x2(m_a[0] * f, m_b[0] * f,
                          m_a[1] * f, m_b[1] * f);
    }

    //scalar division of a 2x2 matrix
    matrix_2x2 matrix_2x2::operator/(float f)const {
        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }

        return matrix_2x2(m_a[0] / f, m_b[0] / f,
                          m_a[1] / f, m_b[1] / f);
        
    }

    //Friend functions
    matrix_2x2 operator*(float f, matrix_2x2& mat) {
        //reverses scalar multiplication of form f*mat to mat*f
        return mat * f;
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_2x2& mat) {
        
        for (int i = 0; i < 2; ++i) {
            os << mat.m_a[i] << " " << mat.m_b[i] << "\n";
        }
        
        return os;
    }

    float det(const matrix_2x2& mat) {
        
        //returns determinant of a 2x2 matrix
        return mat.m_a[0] * mat.m_b[1] - mat.m_a[1] * mat.m_b[0];
    }

}





//3x3
namespace Creyon {
    //Constructors
    
    //default constructor, creates a 3x3 null matrix
    matrix_3x3::matrix_3x3() :m_a{ 0,0,0 }, m_b{ 0,0,0 }, m_c{ 0,0,0 }
    {}

    //overloaded constructor, initialises 3x3 matrix with given vector values
    matrix_3x3::matrix_3x3(std::vector <float>& vec)
      : m_a{ vec[0], vec[3], vec[6] },
        m_b{ vec[1], vec[4], vec[7] },
        m_c{ vec[2], vec[5], vec[8] }
    {
        if (vec.size() != 9) {
            std::cout << "\nIncompatible vector size! Size:" << vec.size();
            exit(EXIT_FAILURE);
        }
    }

    //Overloaded constructor, initialises 2x2 matrix with given values
    matrix_3x3::matrix_3x3(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2)
        :m_a{a0, a1, a2} , m_b{b0, b1, b2}, m_c{c0, c1, c2}
    {}

    //Methods
    
    matrix_3x3 matrix_3x3::transpose() {
        
        //changes rows to columns and columns to rows
        std::swap(m_a[1], m_b[0]);
        std::swap(m_a[2], m_c[0]);
        std::swap(m_b[2], m_c[1]);
        return *this;
    }

    //Overloaded Operators    
    
    //adds two 3x3 matrices elementwise
    matrix_3x3 matrix_3x3::operator+(const matrix_3x3& mat)const {
        
        return matrix_3x3(m_a[0] + mat.m_a[0], m_b[0] + mat.m_b[0], m_c[0] + mat.m_c[0],
                          m_a[1] + mat.m_a[1], m_b[1] + mat.m_b[1], m_c[1] + mat.m_c[1],
                          m_a[2] + mat.m_a[2], m_b[2] + mat.m_b[2], m_c[2] + mat.m_c[2] );
    }

    //subtracts two 3x3 matrices elementwise
    matrix_3x3 matrix_3x3::operator-(const matrix_3x3& mat)const {
        
        return matrix_3x3(m_a[0] - mat.m_a[0], m_b[0] - mat.m_b[0], m_c[0] - mat.m_c[0],
                          m_a[1] - mat.m_a[1], m_b[1] - mat.m_b[1], m_c[1] - mat.m_c[1],
                          m_a[2] - mat.m_a[2], m_b[2] - mat.m_b[2], m_c[2] - mat.m_c[2]);
    }

    //multiplies two 3x3 matrices
    matrix_3x3 matrix_3x3::operator*(const matrix_3x3& mat)const {
        
        std::vector <float> vec;
        
        for (int i = 0; i < 3; ++i) { //i represents row number
            vec.push_back(m_a[i] * mat.m_a[0] + m_b[i] * mat.m_a[1] + m_c[i] * mat.m_a[2]); //row*column1 
            vec.push_back(m_a[i] * mat.m_b[0] + m_b[i] * mat.m_b[1] + m_c[i] * mat.m_b[2]); //row*column2
            vec.push_back(m_a[i] * mat.m_c[0] + m_b[i] * mat.m_c[1] + m_c[i] * mat.m_c[2]); //row*column3
        }
        
        return matrix_3x3(vec);
    }

    //scalar multiplication of a 3x3 matrix
    matrix_3x3 matrix_3x3::operator*(float f)const {
        
        return matrix_3x3(m_a[0] * f, m_b[0] * f, m_c[0] * f,
                          m_a[1] * f, m_b[1] * f, m_c[1] * f,
                          m_a[2] * f, m_b[2] * f, m_c[2] * f) ;
    }

    //scalar division of a 3x3 matrix
    matrix_3x3 matrix_3x3::operator/(float f)const {
        
        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        return matrix_3x3(m_a[0] / f, m_b[0] / f, m_c[0] / f,
                          m_a[1] / f, m_b[1] / f, m_c[1] / f,
                          m_a[2] / f, m_b[2] / f, m_c[2] / f);
    }

    //Friend functions
    matrix_3x3 operator*(float f, matrix_3x3& mat) {
        //reverses scalar multiplication of form f*mat to mat*f
        
        return mat * f; //calls above overloaded mat*f
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_3x3& mat) {
        
        for (int i = 0; i < 3; ++i) { //i represents row number
            os << mat.m_a[i] << " " << mat.m_b[i] << " " << mat.m_c[i] << "\n";
        }
        
        return os;
    }

    float det(const matrix_3x3& mat) {
        //returns determinant of a 3x3 matrix
        return mat.m_a[0] * (mat.m_b[1] * mat.m_c[2] - mat.m_b[2] * mat.m_c[1]) 
            - mat.m_b[0] * (mat.m_a[1] * mat.m_c[2] - mat.m_a[2] * mat.m_c[1]) 
            + mat.m_c[0] * (mat.m_a[1] * mat.m_b[2] - mat.m_a[2] * mat.m_b[1]);
    }
}


//4x4
namespace Creyon {
    //Constructors
    
    //default constructor, creates a 4x4 null matrix
    matrix_4x4::matrix_4x4() :m_a{ 0,0,0,0 }, m_b{ 0,0,0,0 }, m_c{ 0,0,0,0 }, m_d{ 0,0,0,0 }
    {}

    //overloaded constructor, initialises 4x4 matrix with given vector values
    matrix_4x4::matrix_4x4(std::vector <float>& vec)
        : m_a{ vec[0], vec[4], vec[8], vec[12] },
        m_b{ vec[1], vec[5], vec[9], vec[13] },
        m_c{ vec[2], vec[6], vec[10], vec[14] },
        m_d{ vec[3], vec[7], vec[11], vec[15] }
    {
        if (vec.size() != 16) {
            std::cout << "\nIncompatible vector size! Size:" << vec.size();
            exit(EXIT_FAILURE);
        }
    }

    //overloaded constructor, initialises 4x4 matrix with given values
    matrix_4x4::matrix_4x4(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3)
        :m_a{a0, a1, a2, a3}, m_b{b0, b1, b2, b3}, m_c{c0, c1, c2, c3}, m_d{d0, d1, d2, d3}
    {}

    //Methods
    matrix_4x4 matrix_4x4::transpose() {
        //changes rows to columns and columns to rows
        std::swap(m_a[1], m_b[0]);
        std::swap(m_a[2], m_c[0]);
        std::swap(m_a[3], m_d[0]);
        std::swap(m_b[2], m_c[1]);
        std::swap(m_b[3], m_d[1]);
        std::swap(m_c[3], m_d[2]);
        
        return *this;
    }

    //Overloaded Operators    
    
    //adds two 4x4 matrices elementwise
    matrix_4x4 matrix_4x4::operator+(const matrix_4x4& mat)const {
    
        return matrix_4x4(m_a[0] + mat.m_a[0], m_b[0] + mat.m_b[0], m_c[0] + mat.m_c[0], m_d[0] + mat.m_d[0],
                          m_a[1] + mat.m_a[1], m_b[1] + mat.m_b[1], m_c[1] + mat.m_c[1], m_d[1] + mat.m_d[1], 
                          m_a[2] + mat.m_a[2], m_b[2] + mat.m_b[2], m_c[2] + mat.m_c[2], m_d[2] + mat.m_d[2], 
                          m_a[3] + mat.m_a[3], m_b[3] + mat.m_b[3], m_c[3] + mat.m_c[3], m_d[3] + mat.m_d[3] );
    }

    //subtracts two 4x4 matrices elementwise
    matrix_4x4 matrix_4x4::operator-(const matrix_4x4& mat)const {
        
        return matrix_4x4(m_a[0] - mat.m_a[0], m_b[0] - mat.m_b[0], m_c[0] - mat.m_c[0], m_d[0] - mat.m_d[0],
                          m_a[1] - mat.m_a[1], m_b[1] - mat.m_b[1], m_c[1] - mat.m_c[1], m_d[1] - mat.m_d[1],
                          m_a[2] - mat.m_a[2], m_b[2] - mat.m_b[2], m_c[2] - mat.m_c[2], m_d[2] - mat.m_d[2],
                          m_a[3] - mat.m_a[3], m_b[3] - mat.m_b[3], m_c[3] - mat.m_c[3], m_d[3] - mat.m_d[3] );
    }

    //multiplies two 4x4 matrices
    matrix_4x4 matrix_4x4::operator*(const matrix_4x4& mat)const {
        
        std::vector <float> vec;
        
        for (int i = 0; i < 4; ++i) { //i represents row number
            vec.push_back(m_a[i] * mat.m_a[0] + m_b[i] * mat.m_a[1] + m_c[i] * mat.m_a[2] + m_d[i] * mat.m_a[3]); //row*column1 
            vec.push_back(m_a[i] * mat.m_b[0] + m_b[i] * mat.m_b[1] + m_c[i] * mat.m_b[2] + m_d[i] * mat.m_b[3]); //row*column2
            vec.push_back(m_a[i] * mat.m_c[0] + m_b[i] * mat.m_c[1] + m_c[i] * mat.m_c[2] + m_d[i] * mat.m_c[3]); //row*column3
            vec.push_back(m_a[i] * mat.m_d[0] + m_b[i] * mat.m_d[1] + m_c[i] * mat.m_d[2] + m_d[i] * mat.m_d[3]); //row*column4
        }
        
        return matrix_4x4(vec);
    }

    //scalar multiplication of a 4x4 matrix
    matrix_4x4 matrix_4x4::operator*(float f)const {
        
        return matrix_4x4(m_a[0] * f, m_b[0] * f, m_c[0] * f, m_d[0] * f,
                          m_a[1] * f, m_b[1] * f, m_c[1] * f, m_d[1] * f,
                          m_a[2] * f, m_b[2] * f, m_c[2] * f, m_d[2] * f,
                          m_a[3] * f, m_b[3] * f, m_c[3] * f, m_d[3] * f );
    }

    //scalar division of a 4x4 matrix
    matrix_4x4 matrix_4x4::operator/(float f)const {
        
        if (f == 0) {
            std::cout << "Matrix division by zero!";
            exit(EXIT_FAILURE);
        }
        
        return matrix_4x4(m_a[0] / f, m_b[0] / f, m_c[0] / f, m_d[0] / f,
                          m_a[1] / f, m_b[1] / f, m_c[1] / f, m_d[1] / f,
                          m_a[2] / f, m_b[2] / f, m_c[2] / f, m_d[2] / f,
                          m_a[3] / f, m_b[3] / f, m_c[3] / f, m_d[3] / f);
    }

    //Friend functions
    matrix_4x4 operator*(float f, matrix_4x4& mat) {
        //reverses scalar multiplication of form f*mat to mat*f
        
        return mat * f; //calls above overloaded mat*f
    }

    //Overloaded friend operator << for printing matrix directly with cout object
    std::ostream& operator<<(std::ostream& os, const matrix_4x4& mat) {
        
        for (int i = 0; i < 4; ++i) { //i represents row number
            os << mat.m_a[i] << " " << mat.m_b[i] << " " << mat.m_c[i] << " " << mat.m_d[i] << "\n";
        }
        
        return os;
    }

    
    /*Warning: Only change this determinant if you know what this code is doing;
    You can literally make a mess of the matrix determinant by doing one silly mistake. */
    
    float det(const matrix_4x4& mat) {
        //returns determinant of 4x4  matrix
        return mat.m_a[0] * (mat.m_b[1] * (mat.m_c[2] * mat.m_d[3] - mat.m_c[3] * mat.m_d[2]) - mat.m_c[1] * (mat.m_b[2] * mat.m_d[3] - mat.m_b[3] * mat.m_d[2]) + mat.m_d[1] * (mat.m_b[2] * mat.m_c[3] - mat.m_b[3] * mat.m_c[2]))
            - mat.m_b[0] * (mat.m_a[1] * (mat.m_c[2] * mat.m_d[3] - mat.m_c[3] * mat.m_d[2]) - mat.m_c[1] * (mat.m_a[2] * mat.m_d[3] - mat.m_a[3] * mat.m_d[2]) + mat.m_d[1] * (mat.m_a[2] * mat.m_c[3] - mat.m_a[3] * mat.m_c[2]))
            + mat.m_c[0] * (mat.m_a[1] * (mat.m_b[2] * mat.m_d[3] - mat.m_b[3] * mat.m_d[2]) - mat.m_b[1] * (mat.m_a[2] * mat.m_d[3] - mat.m_a[3] * mat.m_d[2]) + mat.m_d[1] * (mat.m_a[2] * mat.m_b[3] - mat.m_a[3] * mat.m_b[2]))
            - mat.m_d[0] * (mat.m_a[1] * (mat.m_b[2] * mat.m_c[3] - mat.m_b[3] * mat.m_c[2]) - mat.m_b[1] * (mat.m_a[2] * mat.m_c[3] - mat.m_a[3] * mat.m_c[2]) + mat.m_c[1] * (mat.m_a[2] * mat.m_b[3] - mat.m_a[3] * mat.m_b[2]));
    }
}