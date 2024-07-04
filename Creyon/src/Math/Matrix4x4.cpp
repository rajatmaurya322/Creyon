#include "matrix4x4.h"

namespace Creyon {
    
    Mat44::Mat44() 
		:m_array{ 1.0f,		0.0f,	0.0f,	0.0f, 
				  0.0f,		1.0f,	0.0f,	0.0f, 
				  0.0f,		0.0f,	1.0f,	0.0f, 
				  0.0f,		0.0f,	0.0f,	1.0f }
    {}

	Mat44::Mat44(float array0, float array1, float array2, float array3,
				 float array4, float array5, float array6, float array7,
				 float array8, float array9, float array10, float array11,
				 float array12, float array13, float array14, float array15)
        :m_array{array0, array1, array2, array3,
				 array4, array5, array6, array7,
				 array8, array9, array10, array11,
				 array12, array13, array14, array15 }
    {}

    Mat44::Mat44(const Mat44& mat4) {
        *this = mat4;
    }
    
	Mat44 Mat44::transpose() {
        std::swap(m_array[1], m_array[4]);
        std::swap(m_array[2], m_array[8]);
        std::swap(m_array[3], m_array[12]);
        std::swap(m_array[6], m_array[9]);
        std::swap(m_array[7], m_array[13]);
        std::swap(m_array[11],m_array[14]);

        return *this;
    }

    Mat44 Mat44::operator+(const Mat44& mat)const {
		 Mat44 addition;
		 for (int i = 0; i < 16; ++i) {
			 addition[i] = m_array[i] + mat[i];
		 }
		 return addition;
    }

    Mat44 Mat44::operator-(const Mat44& mat)const {
		Mat44 subtraction;
		for (int i = 0; i < 16; ++i) {
			subtraction[i] = m_array[i] + mat[i];
		}
		return subtraction;
	}

    Mat44 Mat44::operator*(const Mat44& mat)const {
		Mat44 product;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				float sum = 0;
				for (int k = 0; k < 4; ++k) {
					sum += m_array[4 * i + k] * mat[4 * k + j];
				}
				product[4 * i + j] = sum;
			}
		}
		return product;
    }

    Mat44 Mat44::operator*(float f)const {
		Mat44 scalarProduct;
		for (int i = 0; i < 16; ++i) {
			scalarProduct[i] = m_array[i] * f;
		}
		return scalarProduct;
    }

    Mat44 Mat44::operator/(float f)const {
		if (f == 0.0f) {
			throw f;
		}

		Mat44 scalarDivision;
		for (int i = 0; i < 16; ++i) {
			scalarDivision[i] = m_array[i] / f;
		}
		return scalarDivision;
    }

    Mat44 operator*(float f, Mat44& mat) {
        return mat * f;
    }

    std::ostream& operator<<(std::ostream& os, const Mat44& mat) {
        for (int i = 0; i < 16; i += 4) {
            os << mat.m_array[i] << " " << mat.m_array[i + 1] << " " 
			   << mat.m_array[i + 2] << " " << mat.m_array[i + 3] << "\n";
        }

        return os;
    }

    float determinant(const Mat44& mat) {
		float minor1 = differenceOfProduct(mat[10], mat[15], mat[14], mat[11]);
		float minor2 = differenceOfProduct(mat[9], mat[15], mat[13], mat[11]);
		float minor3 = differenceOfProduct(mat[9], mat[14], mat[13], mat[10]);
		float minor4 = differenceOfProduct(mat[8], mat[15], mat[12], mat[11]);
		float minor5 = differenceOfProduct(mat[8], mat[14], mat[12], mat[10]);
		float minor6 = differenceOfProduct(mat[8], mat[13], mat[12], mat[9]);

		float value1 = mat[0] * (mat[5] * minor1 - mat[6] * minor2 + mat[7] * minor3);
		float value2 = mat[1] * (mat[4] * minor1 - mat[6] * minor4 + mat[7] * minor5);
		float value3 = mat[2] * (mat[4] * minor2 - mat[5] * minor4 + mat[7] * minor6);
		float value4 = mat[3] * (mat[4] * minor3 - mat[5] * minor5 + mat[6] * minor6);
		
		return value1 - value2 + value3 - value4;
    }
}