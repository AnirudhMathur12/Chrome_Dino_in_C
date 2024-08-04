#ifndef WINDOW_H
#define WINDOW_H
#include "SDL_render.h"
#include "SDL_shape.h"
#include "object.h"

typedef struct Window
{
    SDL_Window* win;
    SDL_Renderer* rend;
} Window;

Window* createWindow(char* title, int w, int h);
void renderPhysObj(Window* win, PhysicsObject* obj);
SDL_Texture* createTexture(Window* win, char path[]);
#endif
