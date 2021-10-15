#ifndef _Game_
#define _Game_

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>

class Game{
  public: 
    Game() {}
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();

  private:
    //TextureManager m_textureManager;
    int m_currentFrame;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    //SDL_Texture* m_pTexture;
    //SDL_Rect m_sourceRectangle;
    //SDL_Rect m_destinationRectangle;
    bool m_bRunning;

    //GameObject m_go;
    //Player m_player;

    std::vector<GameObject*> m_gameobjects;
};

#endif