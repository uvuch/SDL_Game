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
    handleInput();
    
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
    SdlGameObject::update();
}

void Enemy::clean() {
}

void Enemy::handleInput() {
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    m_velocity = (*vec - m_position) / 100;
}
