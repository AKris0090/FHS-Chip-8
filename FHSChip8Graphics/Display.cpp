#include "Display.h"
#include "SDL.h"
#include <cstdio>

#define SDL_MAIN_HANDLED

#define SCALE_FACTOR 20

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32
SDL_Window* window;
SDL_Renderer* renderer;



void Display::initDisplay() {

	// Startup the video feed
    SDL_Init(SDL_INIT_VIDEO);

    // Create the SDL Window and open
    window = SDL_CreateWindow("FHS Chip-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (SCREEN_WIDTH * SCALE_FACTOR), (SCREEN_HEIGHT * SCALE_FACTOR), 0);

    // Create the renderer for the window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Update the display and presaent it
    updateDisplay();
    SDL_RenderPresent(renderer);

    // Keep the window open until forcefully closed
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
    }
}

void Display::updateDisplay() {

    // Get surface off of the window
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    // Get pixels from the surface of the window
    Uint64* pixels = (Uint64*)surface->pixels;

    // Iterrate through the pixels change every other pixel to white
    int startX = 0;
    int startY = 0;

    int startPos = 0;
    for (int y = 0; y < 32; y++) {
        for (int x = startPos; x < 64; x += 2) {
            SDL_Rect rect;
            rect.x = x * SCALE_FACTOR;
            rect.y = y * SCALE_FACTOR;
            rect.w = SCALE_FACTOR;
            rect.h = SCALE_FACTOR;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
        }
        startPos = 1 - startPos;
    }

    // Update the window with the new graphic
    SDL_UpdateWindowSurface(window);
}