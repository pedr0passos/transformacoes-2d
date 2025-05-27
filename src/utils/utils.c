#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "objeto.h"

void escutarTeclado(SDL_Event *event, float *deslx, float *desly, float *escalax, float *escalay) {
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
            // transformações
            case SDLK_ESCAPE:
                printf("ESC pressed, exiting...\n");
                exit(EXIT_SUCCESS);
                break;
            case SDLK_w:
                printf("Tecla: W pressionada\n");
                *desly += 0.1f; 
                break;
            case SDLK_a:
                printf("Tecla: A pressionada\n");
                *deslx += -0.1f; 
                break;
            case SDLK_s:
                printf("Tecla: S pressionada\n");
                *desly += -0.1f; 
                break;
            case SDLK_d:
                printf("Tecla: D pressionada\n");
                *deslx += 0.1f; 
                break;
            // escalas
            case SDLK_UP:
                printf("Tecla: UP pressionada\n");
                *escalay += 0.1f; 
                break;
            case SDLK_DOWN:
                printf("Tecla: DOWN pressionada\n");
                *escalay += -0.1f; 
                break;
            case SDLK_LEFT:
                printf("Tecla: LEFT pressionada\n");
                *escalax += -0.1f; 
                break;
            case SDLK_RIGHT:
                printf("Tecla: RIGHT pressionada\n");
                *escalax += 0.1f; 
                break;
            default:
                printf("Other key pressed: %s\n", SDL_GetKeyName(event->key.keysym.sym));
        }
    }
}

void escutarMouse(SDL_Event *event, Objeto* obj, float *deslx, float *desly, float *escalax, float *escalay) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        float angulo = 0.3f; 
        switch (event->button.button) {
            case SDL_BUTTON_LEFT:
                rotacionarObjeto(obj, angulo); 
                break;
            case SDL_BUTTON_RIGHT:
                rotacionarObjeto(obj, -angulo); 
                break;
            default:
                printf("Other mouse button pressed\n");
        }
    }
}