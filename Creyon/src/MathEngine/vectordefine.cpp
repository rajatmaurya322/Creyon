#include "vector3d.h"
#include "vector4d.h"
#include "vector2d.h"

//Vector3d functionalities
namespace Creyon {

    //Overloaded operators
    vector3d vector3d::operator+(const vector3d& v)const {
        
        return vector3d(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);  //addition of two vectors
    }

    vector3d vector3d::operator-(const vector3d& v)const {
        
        return vector3d(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);  //subtraction of two vectors
    }

    float vector3d::operator*(const vector3d& v)const {
        
        return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;    //dot product of two vectors
    }

    //Negates the components of the given vector and returns the new vector
    vector3d vector3d::operator-()const {
        
        return vector3d(-m_x, -m_y, -m_z);
    }

    //Multiplies all components by s
    vector3d vector3d::operator*(float s)const {
        
        return vector3d(m_x * s, m_y * s, m_z * s);
    }

    //Scalar division of vector by s, divides x,y,z components by s
    vector3d vector3d::operator/(float s)const {
        if (s == 0) {
            std::cout << "Vector division by 0 error";
            exit(EXIT_FAILURE);
        }
        else {
            return vector3d(m_x / s, m_y / s, m_z / s);
        }
    }

    //Performs vector-matrix multiplication
    vector3d vector3d::operator*(const Creyon::matrix_3x3 &mat)const{
        
        return vector3d(m_x * mat.m_elems[0] + m_y * mat.m_elems[3] + m_z * mat.m_elems[6],
                        m_x * mat.m_elems[1] + m_y * mat.m_elems[4] + m_z * mat.m_elems[7],
                        m_x * mat.m_elems[2] + m_y * mat.m_elems[5] + m_z * mat.m_elems[8]);
    }

    //Friend Functions

    //Same Scalar multiplication of vector with s: s*v form
    vector3d operator*(float s, const vector3d& v) {
        return v * s;   //calls above overloaded operator *
    }

    //Overloaded << operator to directly print the vector with cout 
    std::ostream& operator<<(std::ostream& os, const vector3d& v) {
        os << "X:" << v.m_x << " Y:" << v.m_y << " Z:" << v.m_z << "\n";
        return os;
    }

    float sq_magn(const vector3d& v) {
        return v.m_x * v.m_x + v.m_y * v.m_y + v.m_z * v.m_z;
    }

    float magn(const vector3d& v) {
        return sqrt(sq_magn(v));
    }

    //Cross product of two vectors
    vector3d cross(const vector3d& v1, const vector3d& v2) {  //Cross product of two vectors
        return vector3d(v1.m_y * v2.m_z - v1.m_z * v2.m_y, v1.m_z * v2.m_x - v1.m_x * v2.m_z, v1.m_x * v2.m_y - v1.m_y * v2.m_x);
    }
}

//Vector4d functionalities
namespace Creyon {

    //Overloaded operators
    //Vector matrix multiplication; v*mat form
    vector4d vector4d::operator*(const Creyon::matrix_4x4& mat) {
        return vector4d(m_x * mat.m_elems[0] + m_y * mat.m_elems[4] + m_z * mat.m_elems[8] + m_w * mat.m_elems[12],
                        m_x * mat.m_elems[1] + m_y * mat.m_elems[5] + m_z * mat.m_elems[9] + m_w * mat.m_elems[13],
                        m_x * mat.m_elems[2] + m_y * mat.m_elems[6] + m_z * mat.m_elems[10]+ m_w * mat.m_elems[14],
                        m_x * mat.m_elems[3] + m_y * mat.m_elems[7] + m_z * mat.m_elems[11]+ m_w * mat.m_elems[15]);
    }

    //overloaded << operator to display vector directly with cout
    std::ostream& operator<<(std::ostream& os, const vector4d& vec) {
        os << "X:" << vec.m_x << "\nY:" << vec.m_y << "\nZ:" << vec.m_z << "\nW:" << vec.m_w;
        return os;
    }
}

//Vector2d functionalities
namespace Creyon {
    //Overloaded operators
    //overloaded << operator to display vector directly with cout
    std::ostream& operator<<(std::ostream& os, const vector2d& vec) {
        os << "X:" << vec.m_x << "\nY:" << vec.m_y;
        return os;
    }
}