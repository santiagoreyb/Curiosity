#ifndef _PUNTOINITERES__H__
#define _PUNTOINITERES__H__
#include <string>
#include <vector>
class Puntointeres
{
protected:
std:: string tipo;
float tamano;
std::string unidad;
float x;
float y;

public:
Puntointeres();
~Puntointeres();
std:: string ObtenerTipo();
std::string ObtenerUnidad();

std::string ObtenerComentario();
int ObtenerTamano();
std::vector<float> ObtenerCoordenas();
void fijarTipo(std:: string);
void  fijarTamano(float);
void fijarUnidad(std::string);
void fijarCoordenadas(float, float);
float ObtenerX();
float ObtenerY();
};

#include "Puntointeres.hxx"
#endif
