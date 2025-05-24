#include <stdio.h>
#include <stdlib.h>

#include "caneta.h"

#define WIDTH 800
#define HEIGHT 600

void desenharLinha(SDL_Renderer* renderer, float x1, float y1, float x2, float y2) {
    // Código padrão de "colaTrabalho.c"
    int xa, xb, ya, yb;
    xa = WIDTH * ((x1 + 1)/2);
    xb = WIDTH * ((x2 + 1)/2);
    ya = HEIGHT * ((-y1 + 1)/2);
    yb = HEIGHT * ((-y2 + 1)/2);
    SDL_RenderDrawLine(renderer, xa, ya, xb, yb);
}

void desenharObjeto(const Objeto* obj, SDL_Renderer* renderer, float deslx, float desly, float escalax, float escalay) {
    // Código adaptado de "colaTrabalho.c"
    
    // para cada aresta do objeto
    for(int i = 0; i < obj->numArestas; i++) {

        // pega os vertices da aresta
        int vi = obj->arestas[i].inicio;
        int vf = obj->arestas[i].fim;

        // coordenadas dos vertices
        float x1 = deslx + obj->vertices[vi].x * escalax;
        float y1 = desly + obj->vertices[vi].y * escalay;
        float x2 = deslx + obj->vertices[vf].x * escalax;
        float y2 = desly + obj->vertices[vf].y * escalay;

        desenharLinha(renderer, x1, y1, x2, y2);
    }
}