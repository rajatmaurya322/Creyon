#pragma once

//Class for representing the application entry point

#include "CreyonEng.h"

namespace Creyon {

	class EngineApp
	{	
		private:
			CreyonWindow windowInstance;
		public:
		EngineApp();

		void Run();

	};

}