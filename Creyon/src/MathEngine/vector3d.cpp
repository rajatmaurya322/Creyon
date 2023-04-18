#include "vector3d.h"

//Namespace is Creyon
namespace Creyon {

    Vector3d Vector3d::operator+(const Vector3d& v)const {

        return Vector3d(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
    }
	
    Vector3d Vector3d::operator-(const Vector3d& v)const {
        
        return Vector3d(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
    }

    float Vector3d::operator*(const Vector3d& v)const {
        
        return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;
    }

    Vector3d Vector3d::operator-()const {
        
        return Vector3d(-m_x, -m_y, -m_z);
    }

    Vector3d Vector3d::operator*(float s)const {
		//Multiplies all components with s
        return Vector3d(m_x * s, m_y * s, m_z * s);
    }

    Vector3d Vector3d::operator/(float s)const {
        if (s == 0) {	//Can't divide by zero
            std::cout << "Vector division by 0 error";
            exit(EXIT_FAILURE);
        }
        else {
            return Vector3d(m_x / s, m_y / s, m_z / s);
        }
    }

    Vector3d Vector3d::operator*(const Creyon::Mat33 &mat)const{
        
        return Vector3d(m_x * mat[0] + m_y * mat[3] + m_z * mat[6],
                        m_x * mat[1] + m_y * mat[4] + m_z * mat[7],
                        m_x * mat[2] + m_y * mat[5] + m_z * mat[8]);
    }

    Vector3d operator*(float s, const Vector3d& v) {
        return v * s;   //calls above overloaded operator *
    }
 
    std::ostream& operator<<(std::ostream& os, const Vector3d& v) {
        os << "X:" << v.m_x << " Y:" << v.m_y << " Z:" << v.m_z << "\n";
        return os;
    }

    float sq_magn(const Vector3d& v) { //Square of magnitude: x^2 + y^2 + z^2 
        return v.m_x * v.m_x + v.m_y * v.m_y + v.m_z * v.m_z;
    }

    float magn(const Vector3d& v) {
        return sqrt(sq_magn(v));  // Vector magnitude = sqrt(x^2 + y^2 + z^2)
    }
	
	Vector3d normalize(const Vector3d& v) {
		//Returns a new normalized vector
		return v / magn(v);
	}

    Vector3d cross(const Vector3d& v1, const Vector3d& v2) {
        return Vector3d(v1.m_y * v2.m_z - v1.m_z * v2.m_y, v1.m_z * v2.m_x - v1.m_x * v2.m_z, v1.m_x * v2.m_y - v1.m_y * v2.m_x);
    }
}