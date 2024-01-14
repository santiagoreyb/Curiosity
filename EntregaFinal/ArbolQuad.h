#ifndef __ARBOLQUAD_H__
#define __ARBOLQUAD_H__

#include "NodoQuad.h"
#include <iostream>
#include <fstream>
#include <sstream>

class ArbolQuad {
  protected:
    NodoQuad* raiz;
  public:
    ArbolQuad();
    ArbolQuad(Puntointeres val);
    ~ArbolQuad();
    Puntointeres datoRaiz();
    NodoQuad* obtenerRaiz();
    void fijarRaiz(NodoQuad* n_raiz);
    bool esVacio();
    void buscarEnCuadrante(NodoQuad* nodo_actual, float x1, float y1, float x2, float y2, std::vector<Puntointeres>& elementos_encontrados);
    bool insertar(Puntointeres punto);
    void imprimirNodos(NodoQuad* nodo_actual);
};

#endif
