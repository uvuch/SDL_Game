//
//  input_handler.h
//  SDL_Game
//
//  Created by Serge Muzyka on 7/3/23.
//

#ifndef input_handler_h
#define input_handler_h

#include <SDL2/SDL.h>
#include <vector>
#include "vector2d.h"

enum mouse_buttons {
    LEFT   = 0,
    MIDDLE = 1,
    RIGHT  = 2
};

class InputHandler {
    const int m_joystickDeadZone = 10000;

public:
    static InputHandler* Instance() {
        if (s_pInstance == nullptr)
            s_pInstance = new InputHandler();
        
        return s_pInstance;
    }
    
    void initialiseJoystick();
    bool joystickInitialised() { return m_bJoysticksInitialised; }
    
    int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);
    
    bool isKeyDown(SDL_Scancode key);
    bool getButtonState(int joy, int buttonNumber) { return m_buttonStates[joy][buttonNumber]; }
    bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; }
    Vector2D* getMousePosition() { return m_mousePosition; }
    
    void update();
    void clean();
    
private:
    InputHandler();
    ~InputHandler() {}
    
    void onKeyUp() {}
    void onKeyDown() {}
    
    void onMouseMove(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    
    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);
    
    static InputHandler* s_pInstance;
    bool m_bJoysticksInitialised;

    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<std::vector<bool>> m_buttonStates;
    std::vector<bool> m_mouseButtonStates;
    const Uint8* m_keystate;
    
    Vector2D* m_mousePosition;
};

typedef InputHandler TheInputHandler;

#endif /* input_handler_h */
