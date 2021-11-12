#include "Enemy.h"
#include "InputHandler.h"
#include <iostream>

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
  
}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  handleInput();
  SDLGameObject::update(); 
  m_currentFrame = ((SDL_GetTicks() / 100) % 6); //움직임
  //m_acceleration.setX(1);
  
  //m_x += 1;
  //m_y += 1;
}

void Enemy::handleInput()
{
  if(TheInputHandler::Instance()->getMouseButtonState(LEFT))
  {
    std::cout << "shoot \n";
  }

  Vecter2D* vec = TheInputHandler::Instance()->getMousePosition();
  m_velocity = (*vec - m_position) / 100;
}

void Enemy::clean() {}