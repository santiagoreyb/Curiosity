#include "Vertice.h"

Vertice::Vertice()
{
    // Implementación del constructor sin argumentos
}

Vertice::Vertice(Puntointeres dato)
{
    this->dato = dato;
}

Puntointeres* Vertice::getDato()
{
    return &dato;
}

void Vertice::setDato(Puntointeres dato)
{
    this->dato = dato;
}

bool Vertice::operator<(Vertice& ver)
{
    Puntointeres* otroDato = ver.getDato();
    if (dato.ObtenerX() < otroDato->ObtenerX())
    {
        return true;
    }
    else if (dato.ObtenerX() > otroDato->ObtenerX())
    {
        return false;
    }
    else
    {
        return dato.ObtenerY() < otroDato->ObtenerY();
    }
}




