#pragma once

#include <iostream>

//Namespace is Creyon

//Row vectors are used
namespace Creyon {

	class vector2d {
	public:		//All data members have m_ prefix
		float m_x, m_y;

		//Default constructor, creates null vector
		vector2d():m_x{ 0.0f } , m_y{ 0.0f }
		{}

		//Creates a vector based on given components
		vector2d(float x, float y):m_x{x} , m_y{y}
		{}

		//Prints vector directly with cout
		friend std::ostream& operator<<(std::ostream& os, const vector2d& vec);
	};
}