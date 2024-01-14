#ifndef __GRAFO__H__
#define __GRAFO__H__

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <limits>
#include "Vertice.h"
#include "Arista.h"
#include <algorithm>
#include "Puntointeres.h"
#include <queue>
#include <list>
#include <cmath>
#include <functional>

class Grafo
{
private:
    std::list<std::list<Arista>> conexiones;
    std::vector<Vertice> vertices;

public:
    Grafo();
    void limpiarGrafo();
    std::vector<Vertice> getVertices();
    std::list<std::list<Arista>> getConexiones();
    void setVertices(std::vector<Vertice> vertices);
    void setConexiones(std::list<std::list<Arista>> conexiones);
    bool esVacio();
    int cantidadVertices();
    int cantidadAristas();
    bool insertarVertice(Vertice** vertice);
    bool insertarVertice(Puntointeres dato);
    bool estaVertice(Vertice& vertice);
    bool estaVertice(Puntointeres dato);
    int insertarArista(Puntointeres ver_orig, Puntointeres ver_dest, float peso);
    std::list<Arista>* obtenerConexionesVertice(int indice);
    int obtenerIndice(Puntointeres& punto);
    Vertice* buscarVertice(Puntointeres vert_val);
    bool insertarConexion(std::list<Arista>* conex, Vertice* ver_dest, float peso);
    Arista* buscarArista(Puntointeres ver_orig, Puntointeres ver_dest);
    bool verticeVisitado(std::list<Vertice*> lista, Puntointeres dato);
    Vertice* ObtenerVertice(int indice);
    std::vector<float> obtenerDistanciasMasLargas();
    std::pair<float, std::pair<Puntointeres*, Puntointeres*>> obtenerComponentesMasAlejados();
    float calcularDistancia(Puntointeres& puntoA, Puntointeres& puntoB);
    std::vector<Puntointeres*> ruta_mas_larga();
    void dfs_ruta_mas_larga(Puntointeres& punto, std::vector<Puntointeres*>& rutaActual, std::vector<bool>& visitados);
  void DFS(int indice, std::vector<Puntointeres*>& rutaActual, std::vector<Puntointeres*>& rutaMasLarga,
                std::vector<bool>& visitados);
    float calcularDistanciaEntrePuntos(Puntointeres& puntoA, Puntointeres& puntoB);
    std::pair<float, std::pair<Vertice, Vertice>> componenetes_mas_alejados_Dijkstra();
    void recorridoDijkstra(std::vector<float>* distancias, std::vector<Vertice >* prede, int indice);
    Vertice min_distancia(std::list<Vertice>* todosLosVertices, std::vector<float> distancias);
    std::pair<float, std::pair<Vertice, Vertice>>obtenerComponentesMasAlejadosDijskstra(std::vector<float>* distancias);
    std::vector<Puntointeres*> ruta_componentes_mas_alejados(Vertice orig, Vertice dest);
};
    

#endif
