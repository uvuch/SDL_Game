//
//  main.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/12/23.
//


#include <iostream>
#include <SDL2/SDL.h>

bool g_bRunning = false;

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
SDL_RendererInfo rendererInfo;

int main(int argc, const char * argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "ERROR: SDL Library Initialization failed\n";
        return -1;
    }
    
    g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!g_pWindow) {
        std::cout << "ERROR: Cannot create window\n";
        SDL_Quit();
        return -1;
    }
    
    std::cout << "Window has been created successfully\n";
    g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    if (!g_pRenderer) {
        std::cout << "ERROR: Cannot create renderer\n";
        SDL_DestroyWindow(g_pWindow);
        SDL_Quit();
        return -1;
    }
    std::cout << "Renderer has been created successfully\n";
    
    SDL_GetRendererInfo(g_pRenderer, &rendererInfo);
    std::cout << "Renderer: " << rendererInfo.name << "\n";
    
    int res = SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, 50); // RGBA
    std::cout << "SetRenderDrawColor: " << res << "\n";
    
    res = SDL_RenderClear(g_pRenderer);
    std::cout << "SDL_RenderClear: " << res << "\n";
    
    SDL_RenderPresent(g_pRenderer);

    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    
    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
    return 0;
}
