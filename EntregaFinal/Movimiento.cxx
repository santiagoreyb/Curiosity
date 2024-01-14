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
  /*if(n_unidad.length()<=2){

    char* char_array = new char[2];
    strcpy(char_array, n_unidad.c_str());
  this->unidad[0]= char_array[0];
  this->unidad[1]= char_array[1];
    }
  else
    this->unidad[0] = '-';
  this->unidad[1] = '-';*/
}
