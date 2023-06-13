//
//  main.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/12/23.
//


#include <iostream>
#include <SDL2/SDL.h>

bool g_bRunning = false;

SDL_Window* g_pWindow = nullptr;
SDL_Renderer* g_pRenderer = nullptr;

bool init(const char *title, int xpos, int ypos, int height, int width, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if (!g_pWindow) {
        SDL_Quit();
        return false;
    }
    
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    if (!g_pRenderer) {
        SDL_DestroyWindow(g_pWindow);
        SDL_Quit();
        return false;
    }
    
    return true;
}

void handleEvents() {
    SDL_Event e;
    while( SDL_PollEvent( &e ) )
        if( e.type == SDL_QUIT ) g_bRunning = false;
}

void update() {
    
}

void render() {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 50); // RGBA
    SDL_RenderClear(g_pRenderer);
    SDL_RenderPresent(g_pRenderer);
}


int main(int argc, const char * argv[]) {
    if (!init("Chapter 1: Setting up SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN)) {
        std::cout << "ERROR: Initialization step failed\n";
        return -1;
    }

    g_bRunning = true;
    while( g_bRunning ) {
        handleEvents();
        update();
        render();
    }
    
    SDL_Quit();
    return 0;
}
