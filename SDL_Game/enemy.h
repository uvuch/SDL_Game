//
//  enemy.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#ifndef enemy_h
#define enemy_h

#include "sdl_game_object.h"

class Enemy: public SdlGameObject {
public:
    Enemy(const LoaderParams* pParams);
    
    void draw();
    void update();
    void clean();
};

#endif /* enemy_h */
