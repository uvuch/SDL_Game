//
//  main.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/12/23.
//


#include "main.h"


int main(int argc, const char * argv[]) {
    g_game = new Game();
    if (!g_game->init("Chapter 1", 100, 100, 640, 480, false)) {
        std::cout << "Error: Initialization step failed." << std::endl;
        delete g_game;
        return -1;
    };
    
    while( g_game->running() ) {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    
    delete g_game;
    return 0;
}
