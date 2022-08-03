#pragma once



#include "CreyonEng.h"

namespace Creyon {

	//Class for representing the application entry point
	class EngineApp
	{	
		private:
			CreyonWindow windowInstance;
		public:
		EngineApp();

		void Run();

	};

}