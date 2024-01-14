#ifndef _MOVIMIENTO__H__
#define _MOVIMIENTO__H__
#include <string>
class Movimiento
{
protected:
std::string tipo;
float magnitud;
std::string unidad;

public:
Movimiento();
~Movimiento();
std::string ObtenerTipo();
float ObtenerMagnitud();
std::string ObtenerUnidad();
void fijarTipo(std::string);
void fijarMagnitud(float);
void fijarUnidad(std::string);


};


#endif
