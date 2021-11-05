#include "Game.h"

Game* g_game = 0;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
 /* g_game = new Game();
  g_game->init("Game Class", 100, 100, 640, 480, 0);
  while(g_game->running())
  {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10);
  }
  g_game->clean();
  return 0;*/

  if(TheGame::Instance()->init("Chapter1", 100, 100, 640, 480, false))
  { 
    
    Uint32 frameStart, frameTime;
    while(TheGame::Instance()->running())
      {
        frameStart = SDL_GetTicks();
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime < DELAY_TIME)
          {
            SDL_Delay((int)(DELAY_TIME - frameTime));
          }
      }
    /*while (TheGame::Instance()->running()) {
      TheGame::Instance()->handleEvents();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(10);
    }
  }
  else 
  {
    std::cout << "game init fail" << SDL_GetError() <<"\n";
    return -1;*/
  }

 


  TheGame::Instance()->clean();
  return 0;
}
