#ifndef OBJECT
#define OBJECT
#include "SDL_render.h"
#include <SDL.h>
#include <stdlib.h>

typedef struct PhysicsObject 
{
    float weight, velocity;
    SDL_Rect postion;
    SDL_Texture* tex;
    int isJumping;
} PhysicsObject;

typedef struct Object
{
    SDL_Rect position;
    SDL_Texture* tex;
} Object;

PhysicsObject* createPhysicsObject(int x, int y, SDL_Texture* tex, float weight);

Object* createObject(int x, int y, SDL_Texture* tex);

void PhysicsUpdate(PhysicsObject* obj);
void PhysicsObjectJump(PhysicsObject* obj);

#endif 
