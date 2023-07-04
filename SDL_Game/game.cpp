//
//  game.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/13/23.
//

#include <SDL2/SDL.h>
#include "game.h"
#include "texture_manager.h"
#include "player.h"
#include "enemy.h"

Game* Game::s_pInstance = nullptr;

Game* Game::Instance() {
    if (!s_pInstance) s_pInstance = new Game();
    
    return s_pInstance;
}

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

    LoaderParams *params = new LoaderParams(100, 100, 128, 82, "animate");
    m_gameObjects.push_back(new Player(params));
    
    params->update(300, 300, 128, 82, "animate");
    m_gameObjects.push_back(new Enemy(params));
    
    delete params;
    
    TheInputHandler::Instance()->initialiseJoystick();
    
    return true;
}

void Game::clean() {
    /*
     I think objects need to be deleted with "delete" cause they had been created with "new".
    while(SdlGameObject *obj = (SdlGameObject*) m_gameObjects.back()) {
        m_gameObjects.pop_back();
        delete obj;
    }
     */

    InputHandler::Instance()->clean();
        
    if (m_pRenderer) SDL_DestroyRenderer(m_pRenderer);
    if (m_pWindow) SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::handleEvents() {
    TheInputHandler::Instance()->update();
}

void Game::update() {
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++ ) {
        m_gameObjects[i]->update();
    }
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);
    
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++ ) {
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(m_pRenderer);
}

