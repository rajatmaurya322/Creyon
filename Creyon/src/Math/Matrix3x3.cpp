#include "matrix3x3.h"

namespace Creyon {

    Mat33::Mat33() 
		:m_array{ 1.0f, 0.0f, 0.0f, 
				  0.0f, 1.0f, 0.0f,
				  0.0f, 0.0f, 1.0f }
    {}

	Mat33::Mat33(float array0, float array1, float array2,
				 float array3, float array4, float array5,
				 float array6, float array7, float array8)
		: m_array{ array0, array1, array2,
				   array3, array4, array5,
				   array6, array7, array8 }
	{}
    
    Mat33::Mat33(const Mat33& mat3) {
        *this = mat3;
    }

    Mat33 Mat33::transpose() {
        std::swap(m_array[1], m_array[3]);
        std::swap(m_array[2], m_array[6]);
        std::swap(m_array[5], m_array[7]);
        return *this;
    }

    Mat33 Mat33::operator+(const Mat33& mat)const {
		Mat33 addition;
		for (int i = 0; i < 9; ++i) {
			addition[i] = m_array[i] + mat[i];
		}
		return addition;
    }

    Mat33 Mat33::operator-(const Mat33& mat)const {
		Mat33 subtraction;
		for (int i = 0; i < 9; ++i) {
			subtraction[i] = m_array[i] - mat[i];
		}
		return subtraction;
    }

    Mat33 Mat33::operator*(const Mat33& mat)const {
        Mat33 product;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				float sum = 0;
				for (int k = 0; k < 3; ++k) {
					sum += m_array[3 * i + k] * mat[3 * k + j];
				}
				product[i] = sum;
			}
		}
		return product;
    }

    Mat33 Mat33::operator*(float f)const {
		Mat33 scalarProduct;
		for (int i = 0; i < 9; ++i) {
			scalarProduct[i] = m_array[i] * f;
		}
		return scalarProduct;
	}

    Mat33 Mat33::operator/(float f)const {
		if (f == 0.0f) {
			throw f;
		}

		Mat33 scalarDivision;
		for (int i = 0; i < 9; ++i) {
			scalarDivision[i] = m_array[i] / f;
		}
		return scalarDivision;
    }

    Mat33 operator*(float f, Mat33& mat) {
        return mat * f;
    }

    std::ostream& operator<<(std::ostream& os, const Mat33& mat) {
        for (int i = 0; i < 9; i += 3) {
            os << mat.m_array[i] << " " << mat.m_array[i + 1] << " " << mat.m_array[i + 2] << "\n";
        }
        return os;
    }
	
    float determinant(const Mat33& mat) {
		float minor1 = differenceOfProduct(mat[4], mat[8], mat[5], mat[7]);
		float minor2 = differenceOfProduct(mat[3], mat[8], mat[6], mat[5]);
		float minor3 = differenceOfProduct(mat[3], mat[7], mat[6], mat[4]);
		
		return mat[0] * minor1 - mat[1] * minor2 + mat[2] * minor3;
    }
}