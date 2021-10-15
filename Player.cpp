#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
  GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
  GameObject::draw(pRenderer);
}

void Player::update()
{
   m_currentFrame = ((SDL_GetTicks() / 100) % 6); //움직임
  m_x -= 1;
}