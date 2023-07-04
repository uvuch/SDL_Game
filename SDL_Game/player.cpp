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
    m_velocity.setX(0);
    m_velocity.setY(0);
    
    handleInput();
    
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
    SdlGameObject::update();
}

void Player::clean() {
}

void Player::handleInput() {
    if (TheInputHandler::Instance()->joystickInitialised()) {
        if (TheInputHandler::Instance()->xvalue(0, 1) != 0) {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
        }
        
        if (TheInputHandler::Instance()->yvalue(0, 1) != 0) {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 1));
        }
        
        if (TheInputHandler::Instance()->xvalue(0, 2) != 0) {
            m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 2));
        }
        
        if (TheInputHandler::Instance()->yvalue(0, 2) != 0) {
            m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
        }
    }
}
