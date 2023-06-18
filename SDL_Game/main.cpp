//
//  main.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/12/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include "vector_2d.h"


int main(int argc, const char * argv[]) {
    std::cout << "game init attempt...\n";
    
    if (!TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false)) {
        std::cout << "Error: Initialization step failed - " << SDL_GetError() << std::endl;
        return -1;
    };
    
    Vector2D v1 = Vector2D(1,1);
    Vector2D v2 = Vector2D(2,2);
    std::cout << "V1(" << v1.getX() << ", " << v1.getY() << ")\n";
    std::cout << "V2(" << v2.getX() << ", " << v2.getY() << ")\n";
    
    Vector2D v3 = v1 + v2;
    std::cout << "V3(" << v3.getX() << ", " << v3.getY() << ")\n";
    
    v1 += v3;
    std::cout << "V1(" << v1.getX() << ", " << v1.getY() << ")\n";
    
    Vector2D v4 = v3 * 10;
    std::cout << "V4(" << v4.getX() << ", " << v4.getY() << ")\n";
    
    v1 *= 100;
    std::cout << "V1(" << v1.getX() << ", " << v1.getY() << ")\n";
    
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
