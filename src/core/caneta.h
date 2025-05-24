#ifndef CANETA_H
#define CANETA_H

#include "objeto.h"
#include <SDL2/SDL.h>

void desenharLinha(SDL_Renderer* renderer, float x1, float y1, float x2, float y2);
void desenharObjeto(const Objeto* obj, SDL_Renderer* renderer, float deslx, float desly, float escalax, float escalay);

#endif