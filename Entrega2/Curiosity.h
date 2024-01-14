#ifndef _CURIOSITY__H_
#define _CURIOSITY__H_
#include <string>
#include <iostream>
#include "Puntointeres.h"
#include "Analisis.h"
#include "Movimiento.h"
#include "ArbolQuad.h"
#include <queue>
#include <vector>
#include <list>


class Curiosity
{
protected:
float x;
float y;
std::list<Analisis> lista_Analisis;
std::list<Movimiento> lista_Movimientos;
std::list<Puntointeres> lista_puntos;
std::list<int> orden_comandos;

public:
Curiosity();
std::vector<float> ObtenerCoord();
std::list<Movimiento> ObtenerListaMovimientos();
std::list<int> ObtenerOrdenComandos();
std::list<Analisis> ObtenerListaAnalisis();
std::list<Puntointeres> ObtenerListaPuntos();
bool Agregar_Movimiento(std::string, bool);
bool Agregar_Analisis(std::string, bool);
bool Agregar_Puntointeres(std::string, bool);
void fijarCoordenadas(float, float);
void eliminarMovimientos();
void eliminarAnalisis();
void eliminarPuntos();
void eliminarOrden();
void simular_comandos(float coordX, float coordY);
void guardar(std::string tipo_archivo, std::string nombre_archivo);
void ubicar_elementos(ArbolQuad& arbol);
void en_cuadrante(float coordX1, float coordX2, float coordY1, float coordY2, ArbolQuad& arbol);
};

#endif
