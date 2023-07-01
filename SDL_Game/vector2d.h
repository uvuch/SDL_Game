//
//  vector2d.hpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/18/23.
//

#ifndef vector2d_h
#define vector2d_h

#include <math.h> // provides "sqrt" function

class Vector2D {
public:
    Vector2D(float x, float y): m_x(x), m_y(y) {}
    
    float getX() { return m_x; }
    float getY() { return m_y; }
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }
    
    float length() { return sqrt(m_x * m_x + m_y + m_y); }
        
    Vector2D operator+(const Vector2D& v2);
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);
    
    Vector2D operator-(const Vector2D& v2);
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2);
    
    Vector2D operator*(float scalar);
    friend Vector2D& operator*=(Vector2D& v, float scalar);
    
    Vector2D operator/(float scalar);
    friend Vector2D& operator/=(Vector2D& v, float scalar);
    
    void normalize();
    
private:
    
    float m_x, m_y;
};


#endif /* vector2d_h */
