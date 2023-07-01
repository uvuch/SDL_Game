//
//  loader_params.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#include "loader_params.h"

void LoaderParams::update(int x, int y, int width, int height, std::string textureID) {
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
}
