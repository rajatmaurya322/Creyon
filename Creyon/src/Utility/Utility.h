#pragma once

#include <cmath>
#include <filesystem>

namespace Creyon {

		const float pi =  3.141592653589793f;

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