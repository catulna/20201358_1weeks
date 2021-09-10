#include <SDL.h>
#include <stdio.h>

//창 크기 변경, 색상 변경

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

//함수 선언
bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
;
void render();

//메인
int main(int argc, char* args[])
{

  if(init("Breaking up SDL", 
          SDL_WINDOWPOS_CENTERED, 
          SDL_WINDOWPOS_CENTERED, 
          320, 240, //크기 변경. 640, 480 -> 320, 240
          SDL_WINDOW_SHOWN))
  {
    g_bRunning = true;
  }
  else
  {
    return 1;
  }

  while (g_bRunning)
  {
    render();
  }

  SDL_Quit();
 
  return 0;
}

//함수 정의
bool init(const char* title, int xpos, int ypos, int height, int width, int flags)
{
  
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if(g_pWindow != 0)
    {
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
    }
  }
  else
  {
    return false;
  }

  SDL_SetRenderDrawColor(g_pRenderer, 0, 103, 163, 255); 
  //RGB값 변경. 0, 0, 0 검정색 -> 181, 227, 216 민트색 ->  0, 103, 163 파랑색

  return true;
}

void render()
{
  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);
}