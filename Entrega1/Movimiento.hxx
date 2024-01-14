#include "Movimiento.h"
#include <string>
#include <cstring>


Movimiento::Movimiento(){
  tipo="avanzar";
  magnitud=0;
  unidad="-";
}
Movimiento::~Movimiento(){}
std::string Movimiento::ObtenerTipo() {
  return( tipo );
}

float Movimiento::ObtenerMagnitud() {
  return( magnitud );
}

std::string Movimiento::ObtenerUnidad() {
  return( unidad );
}
void Movimiento::fijarTipo(std:: string n_tipo) {
  this->tipo = n_tipo;
}

void Movimiento::fijarMagnitud(float n_magnitud) {
  this->magnitud = n_magnitud;
}
void Movimiento::fijarUnidad(std::string n_unidad) {
    this->unidad = n_unidad;
}
