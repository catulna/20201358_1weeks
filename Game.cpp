#include "Game.h"

//위치 변경
//배경 투명화가 된 이미지를 제작 후 출력해봤는데 투명화가 되지 않아서 찾아봤지만 어떻게 수정해야하는 지를 모르겠습니다...



bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(m_pWindow != 0)
    {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0)
      {
        SDL_SetRenderDrawColor(m_pRenderer, 74, 168, 216, 255);
      }
      else 
      {
        return false; 
      }
    }
    else 
    {
      return false;
    }
  }
  else{
    return false;
  }

  SDL_Surface* pTempSurFace = SDL_LoadBMP("Assets/Test.bmp");

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurFace);
  SDL_FreeSurface(pTempSurFace);

  SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);

  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;


// 위치 변경
  m_destinationRectangle.x = 265; m_sourceRectangle.x = 0;
  m_destinationRectangle.y = 195; m_sourceRectangle.y = 0;

  
  m_bRunning =  true;
  return true;
}


void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}

void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
