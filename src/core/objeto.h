#ifndef OBJETO_H
#define OBJETO_H

typedef struct {
    float x, y;
} Vertice;

typedef struct {
    int inicio, fim;
} Aresta;

typedef struct {
    int numVertices;
    int numArestas;
    Vertice* vertices;
    Aresta* arestas;
} Objeto;

Objeto* carregarObjeto(const char* nomeArquivo);
void desalocarObjeto(Objeto* obj);
void imprimirObjeto(const Objeto* obj);

#endif
