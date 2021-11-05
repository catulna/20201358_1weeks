#include "Vecter2D.h"

Vecter2D Vecter2D::operator+(const Vecter2D& v2) const
{
  return Vecter2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vecter2D Vecter2D::operator-(const Vecter2D& v2) const
{
  return Vecter2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vecter2D Vecter2D::operator*(float scalar)
{
  return Vecter2D(m_x * scalar, m_y * scalar);
}

Vecter2D Vecter2D::operator/(float scalar)
{
  return Vecter2D(m_x / scalar, m_y / scalar);
}

Vecter2D& Vecter2D::operator*=(float scalar)
{
  m_x *= scalar;
  m_y *= scalar;
  return *this;
}

Vecter2D& Vecter2D::operator/=(float scalar)
{
  m_x *= scalar;
  m_y *= scalar;
  return *this;
}

void Vecter2D::normalize()
{
  float len = length(); //헷갈려서 l >> len이라고 했습니다
  if(len > 0)
  {
    (*this) *= 1 / len;
  }
}

Vecter2D& operator+=(Vecter2D& v1, const Vecter2D& v2)
{
  v1.m_x += v2.m_x;
  v1.m_y += v2.m_y;
  return v1;
}

Vecter2D& operator-=(Vecter2D& v1, const Vecter2D& v2)
{
  v1.m_x -= v2.m_x;
  v1.m_y -= v2.m_y;
  return v1;
}



