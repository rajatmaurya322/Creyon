#pragma once

#include <cmath>
#include <filesystem>

namespace Creyon {

		const float pi =  3.141592653589793f;
		const float halfPi = 1.570796326794896f;
		const float quarterPi = 0.785398163397448f;
		const float	degreeToRadian = 0.0174532925199f;
		const float radianToDegree = 57.295779513082f;

		bool absoluteCompare(float a, float b, float epsilon);

		bool relativeCompare(float a, float b, float epsilon);

		//Reference: https://pharr.org/matt/blog/2019/11/03/difference-of-floats
		
		//Calculates a * b - c * d and avoids catastrophic cancellation
		float differenceOfProduct(float a, float b, float c, float d);

		float toRadian(const float degreeAngle);

		float toDegree(const float radianAngle);

		//root directory contains Engine.root file
		std::filesystem::path searchRootDirectory();
}