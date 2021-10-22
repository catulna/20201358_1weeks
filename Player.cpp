#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
  
}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  m_currentFrame = ((SDL_GetTicks() / 100) % 6); //움직임
  m_x -= 1;
}

void Player::clean() {}