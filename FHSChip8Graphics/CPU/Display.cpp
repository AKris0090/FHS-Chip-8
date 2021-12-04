#include "Display.h"
#include "SDL.h"
#include <cstdio>

#define SDL_MAIN_HANDLED

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

void Display::initDisplay() {
	// Startup the SDL Window

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
    }

    SDL_Window* window = SDL_CreateWindow("FHS Chip-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
}