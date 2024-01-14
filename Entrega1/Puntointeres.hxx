# include   "Puntointeres.h"
#include<vector>
#include<cstring>

Puntointeres::Puntointeres(){
  tipo='f';
  unidad[0]='-';
  tamano=0;
  x=0;
  y=0;
}
Puntointeres::~Puntointeres(){

}
std:: string Puntointeres::ObtenerTipo() {
  return( tipo );
}


int Puntointeres::ObtenerTamano(){
  return(tamano);
}
std::string Puntointeres::ObtenerUnidad() {
  return( unidad );
}

float Puntointeres::ObtenerX(){
  return (x);
}
float Puntointeres::ObtenerY(){
  return (y);
}

void Puntointeres::fijarTipo(std:: string n_tipo) {
  this->tipo = n_tipo;
}


void Puntointeres::fijarCoordenadas(float m,float n) {
  this->x = m;
  this->y = n;
}
void  Puntointeres:: fijarTamano(float t){
  this->tamano=t;
}

void Puntointeres::fijarUnidad(std::string n_unidad) {
    this->unidad = n_unidad;
  
}
