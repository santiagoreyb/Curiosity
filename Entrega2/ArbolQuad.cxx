#include "ArbolQuad.h"
#include <iostream>

ArbolQuad::ArbolQuad() {
  this->raiz = NULL;
}

ArbolQuad::ArbolQuad(Puntointeres val) {
  this->raiz = new NodoQuad(val);
}

ArbolQuad::~ArbolQuad() {
  delete this->raiz;
}

Puntointeres ArbolQuad::datoRaiz() {
  return this->raiz->obtenerDato();
}

NodoQuad* ArbolQuad::obtenerRaiz() {
  return this->raiz;
}

void ArbolQuad::fijarRaiz(NodoQuad* n_raiz) {
  this->raiz = n_raiz;
}

bool ArbolQuad::esVacio() {
  return (this->raiz == NULL);
}

bool ArbolQuad::insertar(Puntointeres punto) {
    if (raiz == NULL) {
        raiz = new NodoQuad(punto);
        return true;
    }
    return raiz->insertar(punto);
}

void ArbolQuad::buscarEnCuadrante(NodoQuad* nodo_actual, float x1, float y1, float x2, float y2, std::vector<Puntointeres>& elementos_encontrados) {
    if (nodo_actual == NULL) {
        return;
    }
    Puntointeres punto_actual = nodo_actual->obtenerDato();
    if (punto_actual.ObtenerX() >= x1 && punto_actual.ObtenerX() <= x2 &&
        punto_actual.ObtenerY() >= y1 && punto_actual.ObtenerY() <= y2) {
        elementos_encontrados.push_back(punto_actual);
    }
    buscarEnCuadrante(nodo_actual->obtenerHijoSupIzq(), x1, y1, x2, y2, elementos_encontrados);
    buscarEnCuadrante(nodo_actual->obtenerHijoSupDer(), x1, y1, x2, y2, elementos_encontrados);
    buscarEnCuadrante(nodo_actual->obtenerHijoInfIzq(), x1, y1, x2, y2, elementos_encontrados);
    buscarEnCuadrante(nodo_actual->obtenerHijoInfDer(), x1, y1, x2, y2, elementos_encontrados);
}

void ArbolQuad::imprimirNodos(NodoQuad* nodo_actual) {
    if (nodo_actual != NULL) {
        // Imprimir el nodo actual
        std::cout << "Nodo: (" << nodo_actual->obtenerDato().ObtenerX() << ", " << nodo_actual->obtenerDato().ObtenerY() << ")" << std::endl;

        // Llamada recursiva para recorrer los hijos
        imprimirNodos(nodo_actual->obtenerHijoSupIzq());
        imprimirNodos(nodo_actual->obtenerHijoSupDer());
        imprimirNodos(nodo_actual->obtenerHijoInfIzq());
        imprimirNodos(nodo_actual->obtenerHijoInfDer());
    }
}

