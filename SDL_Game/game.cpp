//
//  game.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/13/23.
//

#include "game.h"


bool Game::init(const char *title, int xpos, int ypos, int height, int width, bool fullscreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;
    
    int flags = 0;
    if (fullscreen) flags = flags | SDL_WINDOW_FULLSCREEN;

    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if (m_pWindow) m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    
    if (!m_pWindow || !m_pRenderer) {
        clean();
        return false;
    }
    
    SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 255, 255); // RGBA
    if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
        return false;
    
    m_bRunning = true;

    return true;
}

void Game::clean() {
    if (m_pRenderer) SDL_DestroyRenderer(m_pRenderer);
    if (m_pWindow) SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    while( SDL_PollEvent( &event ) )
        switch (event.type) {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
}

void Game::update() {
    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);
    TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
    TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
    SDL_RenderPresent(m_pRenderer);
}
