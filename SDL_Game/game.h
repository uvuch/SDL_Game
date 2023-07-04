//
//  game.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/13/23.
//

#ifndef __Game__
#define __Game__

#include <vector>
#include "game_object.h"
#include "input_handler.h"

class Game {
public:
    static Game* Instance();
    ~Game() { clean(); }
    
    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    
    bool init(const char *title, int xpos, int ypos, int height, int width, bool fuulscreen);
    
    bool running() { return m_bRunning; }
    
    void render();
    void update();
    void handleEvents();
    void clean();
    void quite() { m_bRunning = false; }
    
private:
    Game() {};
    
    static Game* s_pInstance;
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    bool m_bRunning;
    int m_currentFrame;
    
    std::vector<GameObject*> m_gameObjects;
};

typedef Game TheGame;

#endif /* defined(__Game__) */
