//
//  TextureManager.h
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#ifndef TextureManager_h
#define TextureManager_h

#include <iostream>
#include <map>
#include <SDL2/SDL.h>


class TextureManager {
    
    bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    std::map<std::string, SDL_Texture*> m_textureMap;
    
};

#endif /* TextureManager_h */
