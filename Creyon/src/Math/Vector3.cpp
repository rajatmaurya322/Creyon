#include "Vector3.h"

namespace Creyon {

    Vector3 Vector3::operator+(const Vector3& v)const {
		return Vector3(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
    }
	
    Vector3 Vector3::operator-(const Vector3& v)const {
		return Vector3(m_x - v.m_x, m_y - v.m_y, m_z - v.m_z);
    }

    float Vector3::operator*(const Vector3& v)const {
		return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;
    }

    Vector3 Vector3::operator-()const {
		return Vector3(-m_x, -m_y, -m_z);
    }

    Vector3 Vector3::operator*(float s)const {
		return Vector3(m_x * s, m_y * s, m_z * s);
    }

    Vector3 Vector3::operator/(float s)const {
		if (s == 0.0f) {
			throw s;
		}
		return Vector3(m_x / s, m_y / s, m_z / s);
    }

    Vector3 Vector3::operator*(const Creyon::Mat33 &mat)const{
		return Vector3(m_x * mat[0] + m_y * mat[3] + m_z * mat[6],
						m_x * mat[1] + m_y * mat[4] + m_z * mat[7],
						m_x * mat[2] + m_y * mat[5] + m_z * mat[8]);
    }

    Vector3 operator*(float s, const Vector3& v) {
        return v * s;
    }
 
    std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        os << "x:" << v.m_x << " y:" << v.m_y << " z:" << v.m_z << "\n";
        return os;
    }

    float magnitudeSquared(const Vector3& v) {
        return v.m_x * v.m_x + v.m_y * v.m_y + v.m_z * v.m_z;
    }
	
	Vector3 normalize(const Vector3& v) {
		return v / sqrtf(magnitudeSquared(v));
	}

    Vector3 cross(const Vector3& a, const Vector3& b) {
		Vector3 crossProduct;
		crossProduct.m_x = differenceOfProduct(a.m_y, b.m_z, a.m_z, b.m_y);
		crossProduct.m_y = differenceOfProduct(a.m_z, b.m_x, a.m_x, b.m_z);
		crossProduct.m_z = differenceOfProduct(a.m_x, b.m_y, a.m_y, b.m_x);
		return crossProduct;
    }
}