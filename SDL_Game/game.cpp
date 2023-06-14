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
    
    //SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
    SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
    m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    
    //SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
    m_destinationRectangle.x = m_sourceRectangle.x = 0;
    m_destinationRectangle.y = m_sourceRectangle.y = 0;
    m_destinationRectangle.w = m_sourceRectangle.w = 128;
    m_destinationRectangle.h = m_sourceRectangle.h = 82;
    
    
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
    //m_sourceRectangle.x = (m_sourceRectangle.x + 128) % 768;
    m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100) % 6);
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);
    //SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
    SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, NULL, SDL_FLIP_HORIZONTAL);
    SDL_RenderPresent(m_pRenderer);
}
