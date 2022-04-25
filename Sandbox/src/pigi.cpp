#include "CreyonEng.h"
#include "SDL2/SDL.h"
#include "glad/glad.h"

int main(int argc, char *argv[]) {

		Creyon::cInit();
		
		Creyon::cwindow sandboxwin{ "Opengl test", 640, 480 };
		
		if(Creyon::cSetup()){
			
			glViewport(0, 0, 640, 480);
			bool quit = false;
			while (!quit) {
				
				Creyon::cProcessinput(quit);

				glClearColor(0.0, 1.0, 0.0, 1.0);
				glClear(GL_COLOR_BUFFER_BIT);

				SDL_GL_SwapWindow(sandboxwin.window);
			}

			sandboxwin.cdestroy();

			SDL_Quit();
		}
	return 0;
}