#include "Utility.h"

namespace Creyon {

	bool absCompare(float a, float b, float abs_epsilon) {
		//If absolute difference between a and b is less than or equal to epsilon value, they are said to be equal
		return std::fabs(a - b) <= abs_epsilon;
	}

	bool relCompare(float a, float b, float rel_epsilon) {
		//If difference between a and b is within epsilon percent of larger of a and b, they are said to be equal
		return ( std::fabs(a - b) <= std::fmax( std::fabs(a), std::fabs(b) ) * rel_epsilon );
	}

	float toRad(const float angleInDeg) {
		return angleInDeg * degtorad;
	}

	float toDeg(const float angleInRad) {
		return angleInRad * radtodeg;
	}

	//Searches for Root Directory(Engine.root file)
	std::filesystem::path searchRootDir() {
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

	float getTime(){
		return (float)glfwGetTime();
	}

}