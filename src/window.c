#include "window.h"
#include "SDL_render.h"
#include <stdlib.h>
#include <SDL_image.h>

Window* createWindow(char* title, int w, int h)
{
    Window* _win = malloc(sizeof(Window));
    _win->win = SDL_CreateWindow(title, 20, 20, w, h, 0);
    _win->rend = SDL_CreateRenderer(_win->win, -1, SDL_RENDERER_ACCELERATED);
    return _win;
}

SDL_Texture* createTexture(Window* win, char path[])
{
    SDL_Texture* tex;
    tex = IMG_LoadTexture(win->rend, path);
    return tex;
}

void renderPhysObj(Window *win, PhysicsObject *obj)
{
    SDL_RenderCopy(win->rend, obj->tex, &obj->postion, &obj->postion);
}
