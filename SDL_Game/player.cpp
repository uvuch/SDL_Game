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
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
    m_acceleration.setX(0.05);
    SdlGameObject::update();
}

void Player::clean() {
}
