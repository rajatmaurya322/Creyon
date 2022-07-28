#pragma once

//Class for representing the application entry point

#include "CreyonEng.h"

namespace Creyon {

	class EngineApp
	{	
		public:
		EngineApp();

		void Run(CreyonWindow& windowInstance);

	};

}