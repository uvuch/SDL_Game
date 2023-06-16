//
//  enemy.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#include "enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SdlGameObject(pParams) {
}

void Enemy::draw() {
    SdlGameObject::draw();
}

void Enemy::update() {
    m_x += 1;
    m_y += 1;
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Enemy::clean() {
}
