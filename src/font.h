#ifndef FONT
#define FONT

#include "SDL_rect.h"
#include "window.h"
#include <SDL2/SDL.h>

typedef struct Font
{
    SDL_Texture* tex;
    SDL_Rect src_rect;
} Font;

Font* createFont(int num, const char* path, Window* win);

#endif // !FONT
