#pragma once

#include <cmath>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <filesystem>

//Contains Constants and Functions which can be used anywhere 
namespace Creyon {

		const float pi = 3.141592653589793f;
		const float pi_u2 = 1.570796326794896f;
		const float pi_u4 = 0.785398163397448f;
		const float	degtorad = 0.0174532925199f;
		const float radtodeg = 57.295779513082f;

		//Absolute epsilon comparison
		bool absCompare(float a, float b, float abs_epsilon);

		//Relative epsilon comparison
		bool relCompare(float a, float b, float rel_epsilon);

		//Converts from degree to radian angles
		float toRad(const float angleInDeg);

		//Converts from radian to degree angles
		float toDeg(const float angleInRad);

		//Search root directory
		std::filesystem::path searchRootDir();
		
		const std::filesystem::path EngineRootPath{ searchRootDir() };
		const std::filesystem::path CreyonSrcPath{ EngineRootPath / "Creyon\\src" };

		//Returns elapsed Time from glfw initialisation
		float getTime();
}