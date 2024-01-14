#ifndef __NODOQUAD_H__
#define __NODOQUAD_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include "Puntointeres.h"

class NodoQuad {
  protected:
    Puntointeres dato;
    NodoQuad* hijoSupIzq;
    NodoQuad* hijoSupDer;
    NodoQuad* hijoInfIzq;
    NodoQuad* hijoInfDer;
  public:
    NodoQuad();
    NodoQuad(Puntointeres val);
    ~NodoQuad();
    Puntointeres obtenerDato();
    void fijarDato(Puntointeres val);
    NodoQuad* obtenerHijoSupIzq();
    NodoQuad* obtenerHijoSupDer();
    NodoQuad* obtenerHijoInfIzq();
    NodoQuad* obtenerHijoInfDer();
    void fijarHijoSupIzq(NodoQuad* sizq);
    void fijarHijoSupDer(NodoQuad* sder);
    void fijarHijoInfIzq(NodoQuad* iizq);
    void fijarHijoInfDer(NodoQuad* ider);
    bool esHoja();
    bool insertar(Puntointeres punto);
};

#endif
