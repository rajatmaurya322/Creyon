#include "CreyonEng.h"
#include "SDL2/SDL.h"
#include "glad/glad.h"

int main(int argc, char *argv[]) {

    SDL_Window* window = nullptr;
    SDL_Surface* screensurface = nullptr;


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Failed to initialize SDL!\nSDL error: " << SDL_GetError() << "\n";
    }
    else {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        window = SDL_CreateWindow("opengl window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            cout << "Failed to create window!\nSDL error: " << SDL_GetError() << "\n";
        }
        else {
            SDL_GLContext context = SDL_GL_CreateContext(window);
            if (context == nullptr) {
                cout << "Failed to create window!\nSDL error: " << SDL_GetError() << "\n";
            }
            else {
                if (!gladLoadGLLoader(SDL_GL_GetProcAddress))
                {
                    std::cout << "Failed to initialize GLAD" << std::endl;
                    return -1;
                }
                else {
                    if (SDL_GL_SetSwapInterval(1) < 0)
                    {
                        printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
                    }
                    glViewport(0, 0, 640, 480);

                    bool quit = false;
                    SDL_Event e;
                    while (!quit) {
                        while (SDL_PollEvent(&e) != 0) {
                            if (e.type == SDL_QUIT) {
                                quit = true;
                            }
                        }

                        glClearColor(1.0, 0.0, 0.0, 1.0);
                        glClear(GL_COLOR_BUFFER_BIT);

                        SDL_GL_SwapWindow(window);

                    }
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                }
            }
        }
    }
    return 0;
}