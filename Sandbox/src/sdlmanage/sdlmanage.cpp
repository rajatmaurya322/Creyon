#include "sdlmanage.h"
#include "glad/glad.h"
#include <iostream>

namespace Creyon {

	cwindow::cwindow():window{nullptr}, context{nullptr}
	{}

	cwindow::cwindow(const char* title, int width, int height){
		//Use opengl version 4.3 for now and set to core profile
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		
		if (window == nullptr) {
			std::cout << "Failed to create window!\nSDL error: " << SDL_GetError() << "\n";
			exit(EXIT_FAILURE);
		}
		else {
			context = SDL_GL_CreateContext(window);
			
			if (context == nullptr) {
				std::cout << "Failed to create context!\nSDL error: " << SDL_GetError() << "\n";
				exit(EXIT_FAILURE);
			}
			else {
				//Make the new window context current
				SDL_GL_MakeCurrent(window, context);
			}
		}
	}

	void cwindow::cdestroy() {
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
		context = nullptr;
		window = nullptr;
	}

	bool cInit() {
		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cout << "Failed to initialize SDL!\nSDL error: " << SDL_GetError() << "\n";
			return false;
		}
		else {
			return true;
		}
	}

	bool cSetup() {
		//Setup Glad and Swap interval for current context which is the newly created window
		if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}
		else if (SDL_GL_SetSwapInterval(1) < 0)
		{
			printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else {
			return true;
		}
	}

	void cProcessinput(bool& quit) {
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
}