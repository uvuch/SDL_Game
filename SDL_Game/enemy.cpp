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
    //m_position.setX(m_position.getX() + 1);
    //m_position.setY(m_position.getY() + 1);
    //m_velocity.setX(0);
    //m_velocity.setY(0);
    
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
