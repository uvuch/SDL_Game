//
//  player.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#ifndef player_h
#define player_h

#include "sdl_game_object.h"

class Player: public SdlGameObject {
public:
    Player(const LoaderParams* pParams);

    void draw();
    void update();
    void clean();
};

#endif /* player_h */
