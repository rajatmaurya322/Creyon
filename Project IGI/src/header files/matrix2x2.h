#pragma once

#include <iostream>
#include <vector>

//Namespace is Creyon

//Matrix general notations(row_major ordering is used):

/*  Rows   a   b   c    ---Columns
    Row 0 |0   1   2|
    Row 1 |3   4   5|
    Row 2 |6   7   8| so element[0] is same as a0 and element[5] is same as c1 */


namespace Creyon {

    class matrix_2x2 {

    public:                             //All data members begin with m_ prefix

        float m_elements[4];         //2x2 matrix elements

        //Constructors
        matrix_2x2();   //creates a 2x2 identity matrix

        matrix_2x2(float a0, float b0, float a1, float b1); //creates a 2x2 matrix with given values

        //Methods
        matrix_2x2 transpose();  //transposes the original 2x2 matrix; row-column interchange

        //Overloaded Operators
        matrix_2x2 operator+(const matrix_2x2& mat)const;    //adds two 2x2 matrices

        matrix_2x2 operator-(const matrix_2x2& mat)const;    //subtracts two 2x2 matrices

        matrix_2x2 operator*(const matrix_2x2& mat)const;    //multiplication of two 2x2 matrices

        matrix_2x2 operator*(float f)const;           //scalar multiplication of 2x2 matrix: mat*f

        matrix_2x2 operator/(float f)const;           //scalar division of 2x2 matrix: mat/f

        //Friend functions
        //same scalar multiplication: f * mat
        friend matrix_2x2 operator*(float f, matrix_2x2& mat);

        //overloaded friend operator << for printing matrix directly with cout object
        friend std::ostream& operator<<(std::ostream& os, const matrix_2x2& mat);
    };

    //Non-member functions
    float det(const matrix_2x2& mat);
}