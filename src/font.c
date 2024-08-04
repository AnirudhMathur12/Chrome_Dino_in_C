#include "font.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "window.h"
#include <stdlib.h>

Font* createFont(int num, const char* path, Window* win)
{
    Font* font = malloc(sizeof(Font));
    font->tex = IMG_LoadTexture(win->rend, path);
    font->src_rect.h = 5;
    font->src_rect.w = 3;
    font->src_rect.x = 3*num;
    font->src_rect.y = 0;

    return font;
}
