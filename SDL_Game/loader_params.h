//
//  loader_params.hpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/14/23.
//

#ifndef loader_params_h
#define loader_params_h

#include <iostream>

class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID) :
        m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID) {}
    
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    
    void update(int x, int y, int width, int height, const std::string textureID);
    
    std::string getTextureID() const { return m_textureID; }
    
private:
    int m_x, m_y;
    int m_width, m_height;
    std::string m_textureID;
};

#endif /* loader_params_h */
