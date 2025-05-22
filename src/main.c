#include <stdio.h>
#include <stdlib.h>
#include "objeto.h"

int main(void) {
    Objeto* obj = carregarObjeto("objs/obj1.txt");
    imprimirObjeto(obj);
    desalocarObjeto(obj);
}