//
//  game_object.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#ifndef game_object_h
#define game_object_h

#include "loader_params.h"

class GameObject {
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
    
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {};
};


#endif /* game_object_h */
