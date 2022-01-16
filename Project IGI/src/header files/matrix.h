#pragma once

#include <iostream>
#include <vector>

//Namespace is Creyon

//Matrix representation general scheme:

/*         a   b   c    ---Columns
    Row 0 |1   2   3|
    Row 1 |4   5   6|
    Row 2 |7   8   9|     */


namespace Creyon {

    class matrix_2x2 {
    
    public:                             //All data members begin with m_ prefix
        
        float m_a[2], m_b[2];         //2x2 matrix; a,b represent columns

        //Constructors
        
        matrix_2x2();                          //creates a 2X2 null matrix
        
        matrix_2x2(std::vector <float>& vec);  //creates a 2x2 matrix initialised with values in vector

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

    
    
    class matrix_3x3 {
    
    public:                             //All data members begin with m_ prefix
     
        float m_a[3], m_b[3], m_c[3];     //3x3 matrix; a,b,c represent columns

        //Constructors
        matrix_3x3();                        //creates a 3X3 null matrix
        
        matrix_3x3(std::vector<float>& vec); //creates a 3x3 matrix initialised with values in vector


        //overloaded constructor, initialises 3x3 matrix with given values
        matrix_3x3(float a0, float b0, float c0, float a1, float b1, float c1, float a2, float b2, float c2);

        //Methods
        matrix_3x3 transpose();  //transposes the 3x3 matrix; row-column interchange

        //Overloaded Operators
        matrix_3x3 operator+(const matrix_3x3& mat)const;    //adds two 3x3 matrices
        
        matrix_3x3 operator-(const matrix_3x3& mat)const;    //subtracts two 3x3 matrices
        
        matrix_3x3 operator*(const matrix_3x3& mat)const;    //multiplication of two 3x3 matrices
        
        matrix_3x3 operator*(float f)const;           //scalar multiplication of matrix: mat*f
        
        matrix_3x3 operator/(float f)const;           //scalar division of 3x3 matrix: mat/f

        //Friend functions
        //same scalar multiplication: f * mat
        friend matrix_3x3 operator*(float f, matrix_3x3& mat);
        
        //overloaded friend operator << for printing matrix directly with cout object
        friend std::ostream& operator<<(std::ostream& os, const matrix_3x3& mat);
    };

    //Non member functions
    float det(const matrix_3x3& mat);

    
    
    
    class matrix_4x4 {
    
    public:                             //All data members begin with m_ prefix
        
        float m_a[4], m_b[4], m_c[4], m_d[4];     //4x4 matrix; a,b,c,d represent columns

        //Constructors
        matrix_4x4();                        //creates a 3X3 null matrix
        
        matrix_4x4(std::vector<float>& vec); //creates a 3x3 matrix initialised with values in vector


        //overloaded constructor, initialises 4x4 matrix with given values
        matrix_4x4(float a0, float b0, float c0, float d0, float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float a3, float b3, float c3, float d3);

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