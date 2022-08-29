#include "vector3d.h"

//Namespace is Creyon
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