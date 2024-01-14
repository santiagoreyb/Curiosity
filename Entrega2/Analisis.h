#ifndef _ANALISIS__H__
#define _ANALISIS__H__
#include <string>
class Analisis
{
protected:
std::string tipo;
std::string objeto ;
std::string comentario;

public:
Analisis();
~Analisis();
std::string ObtenerTipo();
std::string ObtenerObjeto();
std::string ObtenerComentario();
void fijarTipo(std::string);
void fijarObjeto(std::string);
void fijarComentario(std::string);
  
};


#endif