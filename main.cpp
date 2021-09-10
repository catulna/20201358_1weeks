#include <SDL.h>
#include <stdio.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[])
{
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow("Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 240, SDL_WINDOW_SHOWN);
    //사이즈 변경. 640, 480 -> 320, 240

    if(g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }
  else
  {
    return 1;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 0, 103, 163, 255); 
  //RGB값 변경. 0, 0, 0 검정색 -> 181, 227, 216 민트색 ->  0, 103, 163 파랑색
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);

  SDL_Delay(5000);
  SDL_Quit();
 
  return 0;
}