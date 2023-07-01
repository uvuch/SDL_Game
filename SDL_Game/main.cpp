//
//  main.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/12/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, const char * argv[]) {
    std::cout << "game init attempt...\n";
    
    if (!TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false)) {
        std::cout << "Error: Initialization step failed - " << SDL_GetError() << std::endl;
        return -1;
    };
    
    Uint32 frameStart, frameTime;
    
    std::cout << "game init success!\n";
    while( TheGame::Instance()->running() ) {
        frameStart = SDL_GetTicks();
        
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME)
            SDL_Delay((int) (DELAY_TIME - frameTime));
    }
    
    std::cout << "game closing...\n";
    TheGame::Instance()->clean();

    return 0;
}
