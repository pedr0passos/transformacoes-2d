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

// Funções para manipulação de objetos
Objeto* carregarObjeto(const char* nomeArquivo);

void desalocarObjeto(Objeto* obj);
void imprimirObjeto(const Objeto* obj);
void moverObjeto(Objeto* obj, float deslx, float desly);
void escalonarObjeto(Objeto* obj, float escalax, float escalay);
void rotacionarObjeto(Objeto* obj, float theta);

#endif
