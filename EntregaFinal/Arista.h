#ifndef __ARISTA__H__
#define __ARISTA__H__

#include "Vertice.h"

class Arista
{
protected:
    float peso;
    Vertice* sucesor;

public:
    Arista();
    Arista(Vertice* verDes, float peso);
    float getPeso() ;
    Vertice* getSucesor();
    void setPeso(float peso);
    void setSucesor(Vertice* sucesor);
    bool operator<(Arista& ar);
};

#endif
