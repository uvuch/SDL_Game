//
//  sdl_game_object.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#include "sdl_game_object.h"
#include "texture_manager.h"
#include "game.h"

SdlGameObject::SdlGameObject(const LoaderParams* pParams) :
    GameObject(pParams),
    m_position(pParams->getX(), pParams->getY()),
    m_velocity(0, 0),
    m_acceleration(0, 0)
{
        m_width = pParams->getWidth();
        m_height = pParams->getHeight();
        m_textureID = pParams->getTextureID();
        
        m_currentRow = 1;
        m_currentFrame = 1;
};


void SdlGameObject::draw() {
    TheTextureManager::Instance()->drawFrame(m_textureID,
                                             (int) m_position.getX(),
                                             (int) m_position.getY(),
                                             m_width, m_height,
                                             m_currentRow, m_currentFrame,
                                             TheGame::Instance()->getRenderer());
}

void SdlGameObject::update() {
    m_velocity += m_acceleration;
    m_position += m_velocity;
}
