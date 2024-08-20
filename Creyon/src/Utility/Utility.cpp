#include "Utility.h"

namespace Creyon {

	bool absoluteCompare(float a, float b, float epsilon) {
		return std::fabs(a - b) <= epsilon;
	}

	bool relativeCompare(float a, float b, float epsilon) {
		return std::fabs(a - b) <= std::fmax( std::fabs(a), std::fabs(b) ) * epsilon ;
	}

	float differenceOfProduct(float a, float b, float c, float d) {
		float cd = c * d;
		float err = std::fma(-c, d, cd);
		float diffOfProducts = std::fma(a, b, -cd);
		return diffOfProducts + err;
	}

	float toRadian(const float degreeAngle) {
		const float	degreeToRadian = 0.0174532925199f;
		return degreeAngle * degreeToRadian;
	}

	float toDegree(const float radianAngle) {
		const float radianToDegree = 57.295779513082f;
		return radianAngle * radianToDegree;
	}

	std::filesystem::path searchRootDirectory() {
		std::filesystem::path currentDirectory = std::filesystem::current_path();
	
		//search for Engine.root file and return the path
		while (true) {
			if (std::filesystem::exists(currentDirectory / "Engine.root")) {
				break;
			}
			currentDirectory = currentDirectory.parent_path();
		}
		return currentDirectory;
	}

}