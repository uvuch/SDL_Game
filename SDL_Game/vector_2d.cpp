//
//  vector_2d.cpp
//  SDL_Game
//
//  Created by Serge Muzyka on 6/18/23.
//

#include "vector_2d.h"


Vector2D Vector2D::operator+(const Vector2D& v2) {
    return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
    v1.m_x += v2.m_x;
    v1.m_y += v2.m_y;
    
    return v1;
}

Vector2D Vector2D::operator-(const Vector2D& v2) {
    return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D& operator-=(Vector2D& v1, const Vector2D& v2) {
    v1.m_x -= v2.m_x;
    v1.m_y -= v2.m_y;
    
    return v1;
}

Vector2D Vector2D::operator*(float scalar) {
    return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D& operator*=(Vector2D& v, float scalar) {
    v.m_x *= scalar;
    v.m_y *= scalar;
    
    return v;
}

Vector2D Vector2D::operator/(float scalar) {
    return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D& operator/=(Vector2D& v, float scalar) {
    v.m_x /= scalar;
    v.m_y /= scalar;
    
    return v;
}
