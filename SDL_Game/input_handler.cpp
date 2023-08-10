//
//  input_handler.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 7/3/23.
//

#include <iostream>
#include "input_handler.h"
#include "game.h"


InputHandler* InputHandler::s_pInstance = nullptr;

InputHandler::InputHandler() {
    m_keystate = nullptr;

    m_mousePosition = new Vector2D(0, 0);
    
    for(int i = 0; i < 3; i++)
        m_mouseButtonStates.push_back(false);
}

void InputHandler::initialiseJoystick() {
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
    
    if (SDL_NumJoysticks() > 0) {
        for(int i = 0; i < SDL_NumJoysticks(); i++) {
            SDL_Joystick* joy = SDL_JoystickOpen(i);
            if (joy != nullptr) {
                m_joysticks.push_back(joy);
                std::pair<Vector2D*, Vector2D*> joystickStick = std::make_pair(new Vector2D(0,0), new Vector2D(0,0));
                
                std::vector<bool> tempButtons;
                for(int j = 0; j < SDL_JoystickNumButtons(joy); j++)
                    tempButtons.push_back(false);
                m_buttonStates.push_back(tempButtons);
                
                m_joystickValues.push_back(joystickStick);
            }
            else {
                std::cout << SDL_GetError();
            }
        }
        
        SDL_JoystickEventState(SDL_ENABLE);
        m_bJoysticksInitialised = true;
        
        std::cout << "Initialized " << m_joysticks.size() << " joystick(s)\n";
    }
    else
        m_bJoysticksInitialised = false;
}

int InputHandler::xvalue(int joy, int stick) {
    if (m_joystickValues.size() > 0) {
        if (stick == 1) {
            return m_joystickValues[joy].first->getX();
        }
        else if (stick == 2) {
            return m_joystickValues[joy].second->getX();
        }
    }
    
    return 0;
}

int InputHandler::yvalue(int joy, int stick) {
    if (m_joystickValues.size() > 0) {
        if (stick == 1) {
            return m_joystickValues[joy].first->getY();
        }
        else if (stick == 2) {
            return m_joystickValues[joy].second->getY();
        }
    }
    
    return 0;
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    if (m_keystate)
        return m_keystate[key];
    
    return false;
}

void InputHandler::update() {
    SDL_Event event;
    while( SDL_PollEvent( &event ) ) {
        m_keystate = SDL_GetKeyboardState(0);

        switch(event.type) {
            case SDL_QUIT:
                TheGame::Instance()->quite();
                break;
                
            case SDL_JOYAXISMOTION:
                onJoystickAxisMove(event);
                break;
                
            case SDL_JOYBUTTONDOWN:
                onJoystickButtonDown(event);
                break;
                
            case SDL_JOYBUTTONUP:
                onJoystickButtonUp(event);
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;
                
            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;
                
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
                
            case SDL_KEYDOWN:
                onKeyDown();
                break;
                
            case SDL_KEYUP:
                onKeyUp();
                break;
            
            default:
                break;
        }

    }
}

void InputHandler::onJoystickAxisMove(SDL_Event& event) {
    int whichOne = event.jaxis.which;
    if (event.jaxis.axis == 0) {
        if (event.jaxis.value > m_joystickDeadZone) {
            m_joystickValues[whichOne].first->setX(1);
        }
        else if (event.jaxis.value < -m_joystickDeadZone) {
            m_joystickValues[whichOne].first->setX(-1);
        }
        else {
            m_joystickValues[whichOne].first->setX(0);
        }
    }
    
    if (event.jaxis.axis == 1) {
        if (event.jaxis.value > m_joystickDeadZone) {
            m_joystickValues[whichOne].first->setY(1);
        }
        else if (event.jaxis.value < -m_joystickDeadZone) {
            m_joystickValues[whichOne].first->setY(-1);
        }
        else {
            m_joystickValues[whichOne].first->setY(0);
        }
    }
    
    if (event.jaxis.axis == 3) {
        if (event.jaxis.value > m_joystickDeadZone) {
            m_joystickValues[whichOne].second->setX(1);
        }
        else if (event.jaxis.value < -m_joystickDeadZone) {
            m_joystickValues[whichOne].second->setX(-1);
        }
        else {
            m_joystickValues[whichOne].second->setX(0);
        }
    }
    
    if (event.jaxis.axis == 4) {
        if (event.jaxis.value > m_joystickDeadZone) {
            m_joystickValues[whichOne].second->setY(1);
        }
        else if (event.jaxis.value < -m_joystickDeadZone) {
            m_joystickValues[whichOne].second->setY(-1);
        }
        else {
            m_joystickValues[whichOne].second->setY(0);
        }
    }
}

void InputHandler::onJoystickButtonDown(SDL_Event& event) {
    int whichOne = event.jaxis.which;
    m_buttonStates[whichOne][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event& event) {
    int whichOne = event.jaxis.which;
    m_buttonStates[whichOne][event.jbutton.button] = false;
}

void InputHandler::onMouseMove(SDL_Event& event) {
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonUp(SDL_Event& event){
    if (event.button.button == SDL_BUTTON_LEFT)
        m_mouseButtonStates[LEFT] = false;
    if (event.button.button == SDL_BUTTON_RIGHT)
        m_mouseButtonStates[RIGHT] = false;
    if (event.button.button == SDL_BUTTON_MIDDLE)
        m_mouseButtonStates[MIDDLE] = false;
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {
    if (event.button.button == SDL_BUTTON_LEFT)
        m_mouseButtonStates[LEFT] = true;
    if (event.button.button == SDL_BUTTON_RIGHT)
        m_mouseButtonStates[RIGHT] = true;
    if (event.button.button == SDL_BUTTON_MIDDLE)
        m_mouseButtonStates[MIDDLE] = true;
}

void InputHandler::clean() {
    if (m_bJoysticksInitialised) {
        for(int i = 0; i < SDL_NumJoysticks(); i++) {
            SDL_JoystickClose(m_joysticks[i]);
        }
    }
}
