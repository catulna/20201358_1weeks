#include "Game.h"
#include "SDL_image.h"



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
        SDL_SetRenderDrawColor(m_pRenderer, 0, 128, 0, 255);
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

  /*SDL_Surface* pTempSurFace = IMG_Load("Assets/animate-alpha.png"); 

  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurFace);
  SDL_FreeSurface(pTempSurFace);

  
  m_sourceRectangle.x = 0;
  m_sourceRectangle.y = 0;

  m_destinationRectangle.w = m_sourceRectangle.w = 128;
  m_destinationRectangle.h = m_sourceRectangle.h = 82;



  m_destinationRectangle.x = 100;
  m_destinationRectangle.y = 100;*/

  //m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);

  if( !TextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
  {
    return false;
  }
  
  m_go.load(100, 100, 128, 82, "animate");
  m_player.load(300, 300, 128, 82, "animate");

  m_bRunning =  true;
  return true;
}


void Game::render()
{
  SDL_RenderClear(m_pRenderer);
  //SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  //SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 45, 0, SDL_FLIP_HORIZONTAL); //반대로
  //SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 30, 0, SDL_FLIP_VERTICAL); //뒤집기
  //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
  //m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
  //m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

  //TextureManager::Instance()->draw("animate", 0, 50, 128, 82, m_pRenderer);
  //TextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

  m_go.draw(m_pRenderer);
  m_player.draw(m_pRenderer);

  SDL_RenderPresent(m_pRenderer);
  
}

void Game::update()
{
  m_currentFrame = ((SDL_GetTicks() / 100) % 6); 

  m_go.update();
  m_player.update();
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
