#include "quaternion.h"

namespace Creyon {

	quaternion::quaternion():m_w{0.0f}, m_x{0.0f}, m_y{0.0}, m_z{0.0f}
	{}

	quaternion::quaternion(const float w, const float x, const float y, const float z):m_w{w}, m_x{x}, m_y{y}, m_z{z}
	{}

	quaternion quaternion::operator+(const quaternion& quat)const {
		//Adds respective components
		return quaternion(m_w + quat.m_w, m_x + quat.m_x, m_y + quat.m_y, m_z + quat.m_z);
	}

	quaternion quaternion::operator-(const quaternion& quat)const {
		//Subtracts respective components
		return quaternion(m_w - quat.m_w, m_x - quat.m_x, m_y - quat.m_y, m_z - quat.m_z);
	}

	quaternion quaternion::operator*(const quaternion& quat)const {
		//Quaternion multiplication
		return quaternion(m_w * quat.m_w -  m_x * quat.m_x -  m_y * quat.m_y -  m_z * quat.m_z,
						  m_w * quat.m_x +  quat.m_w * m_x +  m_y * quat.m_z -  quat.m_y * m_z,
						  m_w * quat.m_y +  quat.m_w * m_y +  m_z * quat.m_x -  quat.m_z * m_x, 
						  m_w * quat.m_z +  quat.m_w * m_z +  m_x * quat.m_y -  quat.m_x * m_y );
	}

	quaternion quaternion::operator*(const float& s)const {
		//scalar multiplication
		return quaternion(m_w * s, m_x * s, m_y * s, m_z * s);
	}

	quaternion quaternion::operator/(const float& s)const {
		if (s == 0) { //Can't divide by 0
			std::cout << "Quaternion division by 0 error";
			exit(EXIT_FAILURE);
		}
		else {
			//scalar division
			return quaternion(m_w / s, m_x / s, m_y / s, m_z / s);
		}
	}

	quaternion quaternion::operator-()const {
		return quaternion(-m_w, -m_x, -m_y, -m_z);
	}

	std::ostream& operator<<(std::ostream& os, const quaternion& quat) {
		//prints respective components
		os << "\nw:" << quat.m_w << "\tx:" << quat.m_x << "\ty:" << quat.m_y << "\tz:" << quat.m_z;
		return os;
	}
	
	//Non-member functions
	
	float sq_magn(const quaternion& q) {
		//Square of magnitude: w^2 + x^2+ y^2 + z^2 
		return q.m_w * q.m_w + q.m_x * q.m_x + q.m_y * q.m_y + q.m_z * q.m_z;
	}

	float magn(const quaternion& q) {
		//Magnitude: sqrt(w^2 + x^2+ y^2 + z^2)
		return sqrt(sq_magn(q));
	}

	void normalize(quaternion& q) {
		q = q / magn(q);
	}

	quaternion inverse(const quaternion& q) {
		//Quaternion Inverse: conjugate(q) / |q|^2
		return quaternion(q.m_w, -q.m_x, -q.m_y, -q.m_z) / sq_magn(q);
	}

	quaternion slerp(const quaternion& start, const quaternion& end, const float t) {
		
		//calculates cosine of angle between quaternions
		float cosOmega = start.m_w * end.m_w + start.m_x * end.m_x + start.m_y * end.m_y + start.m_z * end.m_z;

		//For negative dot product, negate the end quaternion to take shorter arc
		quaternion neg_end = end;
		if (cosOmega < 0.0f) {
			neg_end = -end;
			cosOmega = -cosOmega;
		}

		float k1, k2;
		
		//Check if quaternions are close together and use linear interpolation instead
		if (cosOmega > 0.9999f) {
			k1 = 1.0f - t;
			k2 = t;
		}
		//Otherwise use Slerp
		else {
			float sinOmega = sqrtf(1.0f - cosOmega * cosOmega);
			
			float Omega = atan2(sinOmega, cosOmega);

			float oneOversinOmega = 1.0f / sinOmega;

			k1 = sinf((1.0f - t) * Omega) * oneOversinOmega;
			k2 = sinf(t * Omega) * oneOversinOmega;
		}

		return start * k1 + neg_end * k2;
	}
}