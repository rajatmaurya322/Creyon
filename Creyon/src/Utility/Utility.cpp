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
		return degreeAngle * degreeToRadian;
	}

	float toDegree(const float radianAngle) {
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