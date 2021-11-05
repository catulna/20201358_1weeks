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
  SDLGameObject::update(); //조심하기. 
  m_currentFrame = ((SDL_GetTicks() / 100) % 6); //움직임
  //m_x -= 1;
}

void Player::clean() {}