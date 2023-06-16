//
//  main.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/12/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"


int main(int argc, const char * argv[]) {
    std::cout << "game init attempt...\n";
    
    if (!TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false)) {
        std::cout << "Error: Initialization step failed - " << SDL_GetError() << std::endl;
        return -1;
    };
    
    std::cout << "game init success!\n";
    while( TheGame::Instance()->running() ) { 
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
        
        SDL_Delay(10);
    }
    
    std::cout << "game closing...\n";
    TheGame::Instance()->clean();

    return 0;
}
