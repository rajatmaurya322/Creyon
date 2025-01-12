#include "matrix3x3.h"

namespace Creyon {

    Mat33::Mat33() 
		:m_array{ {1.0f, 0.0f, 0.0f},
				  {0.0f, 1.0f, 0.0f},
				  {0.0f, 0.0f, 1.0f} }
    {}
    
    Mat33::Mat33(const Mat33& mat3) {
        *this = mat3;
    }

    Mat33 Mat33::transpose() {
        std::swap(m_array[0][1], m_array[1][0]);
        std::swap(m_array[0][2], m_array[2][0]);
        std::swap(m_array[1][2], m_array[2][1]);
        return *this;
    }

    Mat33 Mat33::operator+(const Mat33& mat)const {
		Mat33 addition;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				addition(i,j) = m_array[i][j] + mat(i,j);
			}
		}
		return addition;
    }

    Mat33 Mat33::operator-(const Mat33& mat)const {
		Mat33 subtraction;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; j++) {
				subtraction(i,j) = m_array[i][j] - mat(i,j);
			}
		}
		return subtraction;
    }

    Mat33 Mat33::operator*(const Mat33& mat)const {
        Mat33 product;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				float sum = 0;
				for (int k = 0; k < 3; ++k) {
					sum += m_array[i][k] * mat(k,j);
				}
				product(i,j) = sum;
			}
		}
		return product;
    }

    Mat33 Mat33::operator*(float f)const {
		Mat33 scalarProduct;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				scalarProduct(i,j) = m_array[i][j] * f;
			}
		}
		return scalarProduct;
	}

    Mat33 Mat33::operator/(float f)const {
		if (f == 0.0f) {
			throw f;
		}

		Mat33 scalarDivision;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				scalarDivision(i,j) = m_array[i][j] / f;
			}
		}
		return scalarDivision;
    }

    Mat33 operator*(float f, Mat33& mat) {
        return mat * f;
    }

    std::ostream& operator<<(std::ostream& os, const Mat33& mat) {
        for (int i = 0; i < 3; ++i) {
			os << "| ";
			for (int j = 0; j < 3; ++j) {
				os<< mat(i,j) << ", ";
			}
			os << " |\n";
        }
        return os;
    }
	
    float determinant(const Mat33& mat) {
		float minor1 = differenceOfProduct(mat(1,1), mat(2,2), mat(1,2), mat(2,1));
		float minor2 = differenceOfProduct(mat(1,0), mat(2,2), mat(2,0), mat(1,2));
		float minor3 = differenceOfProduct(mat(1,0), mat(2,1), mat(2,0), mat(1,1));
		
		return mat(0,0) * minor1 - mat(0,1) * minor2 + mat(0,2) * minor3;
    }
}