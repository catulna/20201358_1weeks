#pragma once

#include <math.h>

class Vecter2D {
  public: 
    Vecter2D(float x, float y) : m_x(x), m_y(y) {}
    float getX() { return m_x; }
    float getY() { return m_y; }
    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

    float length() { return sqrt(m_x*m_x + m_y*m_y); }

    Vecter2D operator+(const Vecter2D& v2) const;
    Vecter2D operator-(const Vecter2D& v2) const;
    Vecter2D operator*(float scalar);
    Vecter2D operator/(float scalar);

    Vecter2D& operator*=(float scalar);
    Vecter2D& operator/=(float scalar);

    void normalize();

    friend Vecter2D& operator+=(Vecter2D& v1, const Vecter2D& v2);
    friend Vecter2D& operator-=(Vecter2D& v1, const Vecter2D& v2);

  private:
    float m_x;
    float m_y;
};