#include "object.h"
#include "SDL_render.h"
#include <stdlib.h>

float accn = 0.1f;

PhysicsObject* createPhysicsObject(int x, int y, SDL_Texture* tex, float weight)
{
    int mult = 16*4;
    PhysicsObject* temp = malloc(sizeof(PhysicsObject));
    temp->tex = tex;
    temp->postion.x = x; 
    temp->postion.y = y;
    temp->postion.w = mult; 
    temp->postion.h = mult; 
    temp->weight = weight;
    temp->velocity = 1.0f;
    temp->isJumping = 0;
    return temp;
}

void PhysicsUpdate(PhysicsObject *obj)
{
    if(obj->postion.y >= 400)
    {
        accn = 0.0f;
        obj->velocity = 0;
        obj->postion.y = 400;
        if(obj->isJumping)
        {
            obj->velocity = -18.0f;
            obj->isJumping = 0;
        }
    }
    else 
    {
        accn = 0.98f;
    }
    obj->velocity += accn;
    obj->postion.y += obj->velocity;
}

Object* createObject(int x, int y, SDL_Texture* tex)
{
    int mult = 16*4;
    Object* obj = malloc(sizeof(Object));

    obj->tex = tex;
    obj->position.x = x;
    obj->position.y = y;
    obj->position.w = mult;
    obj->position.h = mult;


    return obj;
}
