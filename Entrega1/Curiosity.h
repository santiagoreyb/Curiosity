#ifndef _CURIOSITY__H_
#define _CURIOSITY__H_
#include <string>
#include <iostream>
#include "Puntointeres.h"
#include "Analisis.h"
#include "Movimiento.h"
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
void Agregar_Movimiento(std::string);
void Agregar_Analisis(std::string);
void Agregar_Puntointeres(std::string);
void fijarCoordenadas(float, float);
void eliminarMovimientos();
void eliminarAnalisis();
void eliminarPuntos();
void eliminarOrden();
void simular_comandos(float coordX, float coordY);
void simular_comandos1(float coordX, float coordY);
void guardar(std::string tipo_archivo, std::string nombre_archivo);
};

#include "Curiosity.hxx"
#endif