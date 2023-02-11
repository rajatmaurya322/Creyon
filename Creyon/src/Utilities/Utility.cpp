#include "Utility.h"

namespace Creyon {

	Utility::Utility()
	:pi{3.141592653589793f},
	 pi_u2{ 1.570796326794896f },
	 pi_u4{ 0.785398163397448f },
	 degtorad{ 0.0174532925199f},
	 radtodeg{ 57.295779513082f },
	 EngineRootPath{searchRootDir()},
	 CreyonSrcPath{ EngineRootPath / "Creyon\\src" }
	{}

	Utility& Utility::instance() {
		static Utility* instance = new Utility();
		return *instance;
	}

	bool Utility::absCompare(float a, float b, float abs_epsilon) {
		//If absolute difference between a and b is less than or equal to epsilon value, they are said to be equal
		return std::fabs(a - b) <= abs_epsilon;
	}

	bool Utility::relCompare(float a, float b, float rel_epsilon) {
		//If difference between a and b is within epsilon percent of larger of a and b, they are said to be equal
		return ( std::fabs(a - b) <= std::fmax( std::fabs(a), std::fabs(b) ) * rel_epsilon );
	}

	float Utility::toRad(const float angleInDeg) {
		return angleInDeg * degtorad;
	}

	float Utility::toDeg(const float angleInRad) {
		return angleInRad * radtodeg;
	}

	//Searches for Root Directory(Engine.root file)
	std::filesystem::path Utility::searchRootDir() {
		//Get working directory
		std::filesystem::path currpath = std::filesystem::current_path();
		
		while (true) {
			if (std::filesystem::exists(currpath / "Engine.root")) {
				break;
			}
			else {
				//Sets path to the Parent Directory
				currpath = currpath.parent_path();
			}
		}
		return currpath;
	}

	float Utility::getTime() {
		return (float)glfwGetTime();
	}

}