#pragma once

#include "SDL2/SDL.h"

namespace Creyon {

	//Class cwindow to facilitate easy creation of opengl windows by abstracting SDL2 functionalities
	
	class cwindow {
	public:

		SDL_Window* window;
		SDL_GLContext context;
		
		//Constructors
		
		//Default constructor
		cwindow();		//initializes window and context to nullptr

		//Creates a window with appropriate title and size
		cwindow(const char* title, int width, int height);
		
		void cdestroy();
	};

	bool cInit();
	bool cSetup();
	void cProcessinput(bool& quit);
}