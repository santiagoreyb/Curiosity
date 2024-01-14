#include "NodoQuad.h"
#include <iostream>
#include <stack>
#include <queue>

NodoQuad::NodoQuad() {
  this->hijoSupIzq = NULL;
  this->hijoSupDer = NULL;
  this->hijoInfIzq = NULL;
  this->hijoInfDer = NULL;
}

NodoQuad::NodoQuad(Puntointeres val) {
  this->dato = val;
  this->hijoSupIzq = NULL;
  this->hijoSupDer = NULL;
  this->hijoInfIzq = NULL;
  this->hijoInfDer = NULL;
}

NodoQuad::~NodoQuad() {
  delete this->hijoSupIzq;
  delete this->hijoSupDer;
  delete this->hijoInfIzq;
  delete this->hijoInfDer;
}

Puntointeres NodoQuad::obtenerDato() {
  return this->dato;
}

void NodoQuad::fijarDato(Puntointeres val) {
  this->dato = val;
}

NodoQuad* NodoQuad::obtenerHijoSupIzq() {
  return this->hijoSupIzq;
}

NodoQuad* NodoQuad::obtenerHijoSupDer() {
  return this->hijoSupDer;
}

NodoQuad* NodoQuad::obtenerHijoInfIzq() {
  return this->hijoInfIzq;
}

NodoQuad* NodoQuad::obtenerHijoInfDer() {
  return this->hijoInfDer;
}

void NodoQuad::fijarHijoSupIzq(NodoQuad* sizq) {
  this->hijoSupIzq = sizq;
}

void NodoQuad::fijarHijoSupDer(NodoQuad* sder) {
  this->hijoSupDer = sder;
}

void NodoQuad::fijarHijoInfIzq(NodoQuad* iizq) {
  this->hijoInfIzq = iizq;
}

void NodoQuad::fijarHijoInfDer(NodoQuad* ider) {
  this->hijoInfDer = ider;
}

bool NodoQuad::esHoja() {
     return (this->hijoSupIzq == NULL &&
             this->hijoSupDer == NULL &&
             this->hijoInfIzq == NULL &&
             this->hijoInfDer == NULL);
}

bool NodoQuad::insertar(Puntointeres punto) {
    if (punto.ObtenerX() == dato.ObtenerX() && punto.ObtenerY() == dato.ObtenerY()) {
        return false;  // El punto ya existe en el arbol
    }
    if (punto.ObtenerX() <= dato.ObtenerX() && punto.ObtenerY() <= dato.ObtenerY()) {
        if (hijoInfIzq == NULL) {
            hijoInfIzq = new NodoQuad(punto);
            return true;
        } else {
            return hijoInfIzq->insertar(punto);
        }
    }
    if (punto.ObtenerX() > dato.ObtenerX() && punto.ObtenerY() <= dato.ObtenerY()) {
        if (hijoInfDer == NULL) {
            hijoInfDer = new NodoQuad(punto);
            return true;
        } else {
            return hijoInfDer->insertar(punto);
        }
    }
    if (punto.ObtenerX() <= dato.ObtenerX() && punto.ObtenerY() > dato.ObtenerY()) {
        if (hijoSupIzq == NULL) {
            hijoSupIzq = new NodoQuad(punto);
            return true;
        } else {
            return hijoSupIzq->insertar(punto);
        }
    }
    if (punto.ObtenerX() > dato.ObtenerX() && punto.ObtenerY() > dato.ObtenerY()) {
        if (hijoSupDer == NULL) {
            hijoSupDer = new NodoQuad(punto);
            return true;
        } else {
            return hijoSupDer->insertar(punto);
        }
    }
    return false;

}
