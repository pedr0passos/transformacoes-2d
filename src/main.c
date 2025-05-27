#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "objeto.h"
#include "caneta.h"
#include "utils.h"

#define WIDTH 800
#define HEIGHT 600

int SDL_main(int argc, char* argv[]) {
    Objeto* obj = carregarObjeto("src/objs/obj5.txt");
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_Window *window = SDL_CreateWindow(
        "Transformações 2D", 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        WIDTH, HEIGHT, 
        SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_OPENGL
    );

    if(!window){
        printf("Erro de janela.\nSDL error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    SDL_MaximizeWindow(window);

    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // parametros de escala iniciais
    float deslx = 0.1f, desly = 0.1f;
    float escalax = 0.5f, escalay = 0.5f;

    while (1) {
        
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                break;
            }
            escutarTeclado(&event, &deslx, &desly, &escalax, &escalay);
            escutarMouse(&event, obj, &deslx, &desly, &escalax, &escalay);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        desenharObjeto(obj, renderer, deslx, desly, escalax, escalay);
        SDL_RenderPresent(renderer);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    desalocarObjeto(obj);

    return EXIT_SUCCESS;
}