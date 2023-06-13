//
//  main.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/13/23.
//

#ifndef main_h
#define main_h

#include <iostream>
#include <SDL2/SDL.h>

bool g_bRunning = false;

SDL_Window* g_pWindow = nullptr;
SDL_Renderer* g_pRenderer = nullptr;

bool init(const char *title, int xpos, int ypos, int height, int width, int flags);
void handleEvents();
void handleEvents();
void update();
void render();
void clean();

#endif /* main_h */
