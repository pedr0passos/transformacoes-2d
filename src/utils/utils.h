#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
#include "objeto.h"

void escutarTeclado(SDL_Event *event, float *deslx, float *desly, float *escalax, float *escalay);
void escutarMouse(SDL_Event *event, Objeto* obj, float *deslx, float *desly, float *escalax, float *escalay);

#endif