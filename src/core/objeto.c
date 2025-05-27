#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "objeto.h"

Objeto* carregarObjeto(const char* nomeArquivo) {
    FILE* f = fopen(nomeArquivo, "r");
    
    if (!f) {
        perror("Erro ao abrir arquivo");
        return NULL;
    }

    Objeto* obj = malloc(sizeof(Objeto));
    if (!obj) {
        perror("Erro ao alocar memória para objeto");
        fclose(f);
        return NULL;
    }

    fscanf(f, "%d", &obj->numVertices);
    obj->vertices = malloc(obj->numVertices * sizeof(Vertice));

    for (int i = 0; i < obj->numVertices; i++) {
        fscanf(f, "%f %f", &obj->vertices[i].x, &obj->vertices[i].y);
    }

    fscanf(f, "%d", &obj->numArestas);
    obj->arestas = malloc(obj->numArestas * sizeof(Aresta));

    for (int i = 0; i < obj->numArestas; i++) {
        fscanf(f, "%d %d", &obj->arestas[i].inicio, &obj->arestas[i].fim);
    }

    fclose(f);
    return obj;
}

void imprimirObjeto(const Objeto* obj) {
    printf("Vertices (%d):\n", obj->numVertices);
    for (int i = 0; i < obj->numVertices; i++) {
        printf("  %d: (%.2f, %.2f)\n", i, obj->vertices[i].x, obj->vertices[i].y);
    }

    printf("Arestas (%d):\n", obj->numArestas);
    for (int i = 0; i < obj->numArestas; i++) {
        printf("  %d -> %d\n", obj->arestas[i].inicio, obj->arestas[i].fim);
    }
}

void desalocarObjeto(Objeto* obj) {
    if (!obj) return;
    free(obj->vertices);
    free(obj->arestas);
    free(obj);
}

// void moverObjeto(Objeto* obj, float deslx, float desly) {
//     for (int i = 0; i < obj->numVertices; i++) {
//         obj->vertices[i].x += deslx; 
//         obj->vertices[i].y += desly; 
//     }
// }

// void escalonarObjeto(Objeto* obj, float escalax, float escalay) {
//     for (int i = 0; i < obj->numVertices; i++) {
//         obj->vertices[i].x *= escalax; 
//         obj->vertices[i].y *= escalay; 
//     }
// }

void rotacionarObjeto(Objeto* obj, float theta) {
    float c = cosf(theta);
    float s = sinf(theta);
    for (int i = 0; i < obj->numVertices; i++) {
        float x = obj->vertices[i].x;
        float y = obj->vertices[i].y;
        // aplica a matriz de rotação
        obj->vertices[i].x = x * c - y * s;
        obj->vertices[i].y = x * s + y * c;
    }
}