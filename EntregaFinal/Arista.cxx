#include "Arista.h"

Arista::Arista()
{
    // Implementación del constructor sin argumentos
}

Arista::Arista(Vertice* verDes, float peso)
{
    this->peso = peso;
    sucesor = verDes;
}

float Arista::getPeso()
{
    return peso;
}

Vertice* Arista::getSucesor()
{
    return sucesor;
}

void Arista::setPeso(float peso)
{
    this->peso = peso;
}

void Arista::setSucesor(Vertice* sucesor)
{
    this->sucesor = sucesor;
}

bool Arista::operator<(Arista& ar)
{
    return *sucesor < *(ar.getSucesor());
}
