//
//  player.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#include "player.h"

Player::Player(const LoaderParams* pParams) : SdlGameObject(pParams) {
}

void Player::draw() {
    SdlGameObject::draw();
}

void Player::update() {
    m_x -= 1;
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
    
}

void Player::clean() {
}
