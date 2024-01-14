#include "Analisis.h"
# include <string>
Analisis::Analisis(){
  tipo='f';
  objeto="";
  comentario="";
}
//Destructor
Analisis::~Analisis(){}

std::string Analisis::ObtenerTipo() {
  return( tipo );
}

std::string Analisis::ObtenerObjeto() {
  return( objeto );
}

std::string Analisis::ObtenerComentario() {
  return( comentario );
}
void Analisis::fijarTipo(std::string n_tipo) {
  this->tipo = n_tipo;
}

void Analisis::fijarObjeto(std::string n_objeto) {
  this->objeto = n_objeto;
}
void Analisis::fijarComentario(std::string n_comentario) {
  this->comentario = n_comentario;
}