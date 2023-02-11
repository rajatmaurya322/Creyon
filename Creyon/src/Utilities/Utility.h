#pragma once

#include <cmath>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <filesystem>

//Contains Constants and Functions which can be used anywhere 
namespace Creyon {

	//Singleton class for accessing Utility functions and constants
	class Utility {
	private:
		Utility();

	public:
		const float pi, pi_u2, pi_u4, degtorad, radtodeg;
		const std::filesystem::path EngineRootPath, CreyonSrcPath;

		//Returns single instance of the Utility class
		static Utility& instance();
		
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

		//Returns elapsed Time from glfw initialisation
		float getTime();
		
	};
}