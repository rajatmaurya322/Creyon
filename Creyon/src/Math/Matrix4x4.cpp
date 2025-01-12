#include "matrix4x4.h"

namespace Creyon {
    
    Mat44::Mat44() 
		:m_array{ {1.0f, 0.0f, 0.0f, 0.0f},
				  {0.0f, 1.0f, 0.0f, 0.0f},
				  {0.0f, 0.0f, 1.0f, 0.0f},
				  {0.0f, 0.0f, 0.0f, 1.0f} }
    {}

    Mat44::Mat44(const Mat44& mat4) {
        *this = mat4;
    }
    
	Mat44 Mat44::transpose() {
        std::swap(m_array[0][1], m_array[1][0]);
        std::swap(m_array[0][2], m_array[2][0]);
        std::swap(m_array[0][3], m_array[3][0]);
        std::swap(m_array[1][2], m_array[2][1]);
        std::swap(m_array[1][3], m_array[3][1]);
        std::swap(m_array[2][3], m_array[3][2]);

        return *this;
    }

    Mat44 Mat44::operator+(const Mat44& mat)const {
		 Mat44 addition;
		 for (int i = 0; i < 4; ++i) {
			 for (int j = 0; j < 4; ++j) {
				addition(i,j) = m_array[i][j] + mat(i,j);
			 }
		 }
		 return addition;
    }

    Mat44 Mat44::operator-(const Mat44& mat)const {
		Mat44 subtraction;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				subtraction(i,j) = m_array[i][j] - mat(i,j);
			}
		}
		return subtraction;
	}

    Mat44 Mat44::operator*(const Mat44& mat)const {
		Mat44 product;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				float sum = 0;
				for (int k = 0; k < 4; ++k) {
					sum += m_array[i][k] * mat(k,j);
				}
				product(i,j) = sum;
			}
		}
		return product;
    }

    Mat44 Mat44::operator*(float f)const {
		Mat44 scalarProduct;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				scalarProduct(i,j) = m_array[i][j] * f;
			}
		}
		return scalarProduct;
    }

    Mat44 Mat44::operator/(float f)const {
		if (f == 0.0f) {
			throw f;
		}

		Mat44 scalarDivision;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				scalarDivision(i,j) = m_array[i][j] / f;
			}
		}
		return scalarDivision;
    }

    Mat44 operator*(float f, Mat44& mat) {
        return mat * f;
    }

    std::ostream& operator<<(std::ostream& os, const Mat44& mat) {
		for (int i = 0; i < 4; ++i) {
			os << "| ";
			for (int j = 0; j < 4; ++j) {
				os << mat(i,j) << ", ";
			}
			os << " |\n";
		}

        return os;
    }

    float determinant(const Mat44& mat) {
		float minor1 = differenceOfProduct(mat(2,2), mat(3,3), mat(3,2), mat(2,3));
		float minor2 = differenceOfProduct(mat(2,1), mat(3,3), mat(3,1), mat(2,3));
		float minor3 = differenceOfProduct(mat(2,1), mat(3,2), mat(3,1), mat(2,2));
		float minor4 = differenceOfProduct(mat(2,0), mat(3,3), mat(3,0), mat(2,3));
		float minor5 = differenceOfProduct(mat(2,0), mat(3,2), mat(3,0), mat(2,2));
		float minor6 = differenceOfProduct(mat(2,0), mat(3,1), mat(3,0), mat(2,1));

		float value1 = mat(0,0) * (mat(1,1) * minor1 - mat(1,2) * minor2 + mat(1,3) * minor3);
		float value2 = mat(0,1) * (mat(1,0) * minor1 - mat(1,2) * minor4 + mat(1,3) * minor5);
		float value3 = mat(0,2) * (mat(1,0) * minor2 - mat(1,1) * minor4 + mat(1,3) * minor6);
		float value4 = mat(0,3) * (mat(1,0) * minor3 - mat(1,1) * minor5 + mat(1,2) * minor6);
		
		return value1 - value2 + value3 - value4;
    }
}