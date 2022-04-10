#pragma once

#include <iostream>
#include <vector>

//Namespace is Creyon

//Matrix general notations(row_major ordering is used):

/*         a    b   c    d    ---Columns
    Row 0 |0    1   2    3| Given  inside are indices of each element
    Row 1 |4    5   6    7|
    Row 2 |8    9   10  11|
    Row 3 |12   13  14  15|

    so element[0] is same as a0(column a and row 0) and element[6] is same as c1(Column c and row 1) 
*/


namespace Creyon {

    class matrix_4x4 {

    public:                             //All data members begin with m_ prefix

        float m_elems[16];     //4x4 matrix elements;

        //Constructors
        matrix_4x4();                        //creates a 4x4 identity matrix

        //overloaded constructor, initialises 4x4 matrix with given values
        matrix_4x4(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3);

        matrix_4x4(const float *p_array);

        matrix_4x4(const matrix_4x4& mat4);
        
        //overloaded constructor
        //Methods
        matrix_4x4 transpose();  //transposes the 3x3 matrix; row-column interchange

        //Overloaded Operators
        matrix_4x4 operator+(const matrix_4x4& mat)const;    //adds two 3x3 matrices

        matrix_4x4 operator-(const matrix_4x4& mat)const;    //subtracts two 3x3 matrices

        matrix_4x4 operator*(const matrix_4x4& mat)const;    //multiplication of two 3x3 matrices

        matrix_4x4 operator*(float f)const;           //scalar multiplication of matrix: mat*f

        matrix_4x4 operator/(float f)const;           //scalar division of 3x3 matrix: mat/f

        //Friend functions
        //same scalar multiplication: f * mat
        friend matrix_4x4 operator*(float f, matrix_4x4& mat);

        //overloaded friend operator << for printing matrix directly with cout object
        friend std::ostream& operator<<(std::ostream& os, const matrix_4x4& mat);
    };

    //NON-MEMBER FUNCTIONS
    float det(const matrix_4x4& mat);
}