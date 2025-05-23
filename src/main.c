#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "objeto.h"

int SDL_main(int argc, char* argv[]) {
    Objeto* obj = carregarObjeto("src/objs/obj1.txt");
    imprimirObjeto(obj);
    desalocarObjeto(obj);
}