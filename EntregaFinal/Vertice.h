#ifndef __VERTICE__H__
#define __VERTICE__H__

#include "Puntointeres.h"

class Vertice
{
protected:
    Puntointeres dato;

public:
    Vertice();
    Vertice(Puntointeres dato);
    Puntointeres* getDato();
    void setDato(Puntointeres dato);
    bool operator<(Vertice& ver);
};
#endif
