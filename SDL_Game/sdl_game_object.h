//
//  sdl_game_object.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#ifndef sdl_game_object_h
#define sdl_game_object_h

#include "game_object.h"
#include "loader_params.h"
#include "vector2d.h"
#include <SDL2/SDL.h>

class SdlGameObject: public GameObject {
public:
    SdlGameObject(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    
protected:
    std::string m_textureID;
    
    int m_currentFrame;
    int m_currentRow;
    
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    
    int m_width, m_height;
};


#endif /* sdl_game_object_h */
