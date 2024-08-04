#include "SDL_error.h"
#include "SDL_events.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "SDL_image.h"
#include "SDL_keyboard.h"
#include "SDL_keycode.h"
#include "SDL_main.h"
#include "SDL_render.h"
#include "SDL_timer.h"
#include "window.h"
#include "object.h"
#include "font.h"

#define CACTI_NUM 5

SDL_Rect font_rect = {0,0,64*3,64*5};

//TODO: Make init()
int running = 1;
float ticksperframe = 1000.0f/60.0f;

int gameOver = 0;

Object* cacti[CACTI_NUM];

void CactusUpdate(Object** cacti);
void renderCacti(Window* win, Object** cacti);
void checkForCollisions(PhysicsObject* player, Object** _cacti, int* _gameOver);

int num = 0;

SDL_Rect rect = {0, 0, 450, 50};

int main()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL failed to init. Error: %s", SDL_GetError());
    }

    Window* win = createWindow("Game", 1280, 520);
    PhysicsObject* player = createPhysicsObject(20, 20, createTexture(win, "dino.png"), 1.0);

    SDL_Texture* tex = createTexture(win, "gameover.png");

    for(int i = 0; i < CACTI_NUM; i++)
    {
        cacti[i] = createObject(500+(i*400), 400, createTexture(win, "cactus.png"));
    }

    SDL_Event e;
    gameOver = 0;
    while(running)
    {
        int startticks = SDL_GetTicks();
        if(!gameOver)
        {
            PhysicsUpdate(player);
            CactusUpdate(cacti);
        }
        checkForCollisions(player, cacti, &gameOver);
        while(SDL_PollEvent(&e))
        {
            checkForCollisions(player, cacti, &gameOver);
            switch(e.type)
            {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_1:
                            num = 1;
                            break;
                        case SDLK_2:
                            num = 2;
                            break;
                        case SDLK_3:
                            num = 3;
                            break;
                        case SDLK_4:
                            num = 4;
                            break;
                        case SDLK_5:
                            num = 5;
                            break;
                        case SDLK_6:
                            num = 6;
                            break;
                        case SDLK_7:
                            num = 7;
                            break;
                        case SDLK_SPACE:
                            player->isJumping = 1;
                            break;
                        case SDLK_ESCAPE:
                            if(gameOver)
                            {
                                running = 0;
                            }
                            break;
                        case SDLK_r:
                            if(gameOver)
                            {
                                for(int i = 0; i < CACTI_NUM; i++)
                                {
                                    cacti[i] = createObject(500+(i*400), 400, createTexture(win, "cactus.png"));
                                }
                                player = createPhysicsObject(20, 20, createTexture(win, "dino.png"), 1.0);
                                gameOver = 0;

                            }
                        break;
                    }
            }
        }
        

        Font* font0 = createFont(num, "number.png", win);

        SDL_RenderClear(win->rend);
        SDL_RenderCopy(win->rend, player->tex, NULL, &player->postion);
        SDL_RenderCopy(win->rend, font0->tex, &font0->src_rect, &font_rect);
        renderCacti(win, cacti);
        if(gameOver)
        {
            SDL_RenderCopy(win->rend, tex, NULL, NULL);
        }
        SDL_RenderPresent(win->rend);
        int frameticks = SDL_GetTicks() - startticks;
        if(frameticks < ticksperframe)
        {
            SDL_Delay(ticksperframe - frameticks);
        }
    }

    printf("Hello, world!");
    SDL_Quit();
    return 0;
}

void CactusUpdate(Object** _cacti)
{
    for(int i = 0; i < CACTI_NUM; i++)
    {
        _cacti[i]->position.x -= 5;
        if(_cacti[i]->position.x < -30)
        {
            _cacti[i]->position.x = 2200;
        }
    }
}

void renderCacti(Window* win, Object** _cacti)
{
    for(int i = 0; i < CACTI_NUM; i++)
    {
        SDL_RenderCopy(win->rend, _cacti[i]->tex, NULL, &_cacti[i]->position);
    }
}

void checkForCollisions(PhysicsObject* player, Object** _cacti, int* _gameOver)
{
    for(int i = 0; i < CACTI_NUM; i++)
    {
        if(_cacti[i]->position.y - (player->postion.y + 65) <= 0 && (_cacti[i]->position.x - (player->postion.x + 64) <= 0) && (_cacti[i]->position.x+34 - (player->postion.x > 0)))
        {
            *_gameOver = 1;
        }
    }
}
