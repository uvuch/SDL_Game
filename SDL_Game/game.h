//
//  game.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/13/23.
//

#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Game {
public:
    Game() {
        m_pWindow = nullptr;
        m_pRenderer = nullptr;
        m_bRunning = false;
    }

    ~Game() { clean(); }
    
    bool init(const char *title, int xpos, int ypos, int height, int width, bool fuulscreen);
    
    bool running() { return m_bRunning; }
    
    void render();
    void update();
    void handleEvents();
    void clean();
    
private:
    bool m_bRunning;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    SDL_Texture* m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;
};


#endif /* defined(__Game__) */
