#include "Curiosity.h"
#include <iostream>
# include <string>
#include <queue>
#include <vector>
#include <list>
#include <cmath>
using namespace std;
Curiosity::Curiosity(){
   x=0;
  y=0;
}

void Curiosity:: eliminarMovimientos(){
  lista_Movimientos.clear();
}
void Curiosity:: eliminarAnalisis(){
  lista_Analisis.clear();
}
void Curiosity:: eliminarPuntos(){
  lista_puntos.clear();
}
void Curiosity:: eliminarOrden(){
  orden_comandos.clear();
}

void Curiosity::Agregar_Movimiento(std::string linea_movimiento) {

  std::vector<std::string> elementos;
  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  Movimiento mov;


    while (posFound >= 0) {
        posFound = linea_movimiento.find(' ', posInit);
        splitted = linea_movimiento.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        elementos.push_back(splitted);
    }
  std::cout<<elementos[0]<<endl;
  std::cout<<elementos[1]<<endl;
  std::cout<<elementos[2]<<endl;
  std::cout<<elementos[3]<<endl;
  float aux=std::stof(elementos[2]);
  mov.fijarTipo(elementos[1]);
  mov.fijarMagnitud(aux );
  mov.fijarUnidad(elementos[3]);


  lista_Movimientos.push_back(mov);
  orden_comandos.push_back(0);
  std::cout<<"Movimiento agregado"<<endl;
}
void Curiosity::Agregar_Analisis(std::string linea_analisis) {

  std::vector<std::string> elementos;
  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  Analisis anl_aux;


    while (posFound >= 0) {
        posFound = linea_analisis.find(' ', posInit);
        splitted = linea_analisis.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        elementos.push_back(splitted);
    }
  std::cout<<elementos[0]<<endl;
  std::cout<<elementos[1]<<endl;
  std::cout<<elementos[2]<<endl;
  std::cout<<elementos[3]<<endl;

  anl_aux.fijarTipo(elementos[1]);
  anl_aux.fijarObjeto(elementos[2]);
  anl_aux.fijarComentario(elementos[3]);
  lista_Analisis.push_back(anl_aux);
  orden_comandos.push_back(1);
  std::cout<<"Analisis agregado"<<endl;
}
void Curiosity::Agregar_Puntointeres(std::string linea_puntointeres) {
  std::vector<std::string> elementos;
  int posInit = 0;
  int posFound = 0;
  std::string splitted;
  Puntointeres punt_aux;


    while (posFound >= 0) {
        posFound = linea_puntointeres.find(' ', posInit);
        splitted = linea_puntointeres.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        elementos.push_back(splitted);
    }
  std::cout<<elementos[0]<<endl;
  std::cout<<elementos[1]<<endl;
  std::cout<<elementos[2]<<endl;
  std::cout<<elementos[3]<<endl;
  std::cout<<elementos[4]<<endl;
  std::cout<<elementos[5]<<endl;
  punt_aux.fijarTipo(elementos[1]);
  punt_aux.fijarTamano(std::stof(elementos[2]));
  punt_aux.fijarUnidad(elementos[3]);
punt_aux.fijarCoordenadas(std::stof(elementos[4]),std::stof(elementos[5]));
  lista_puntos.push_back(punt_aux);
  std::cout<<"Punto agregado"<<endl;

}

std::list<Movimiento> Curiosity::ObtenerListaMovimientos() {
  return(lista_Movimientos);
}
std::list<Analisis> Curiosity::ObtenerListaAnalisis() {
  return( lista_Analisis );

}

std::list<Puntointeres> Curiosity::ObtenerListaPuntos() {
    return( lista_puntos);
}
std::list<int> Curiosity::ObtenerOrdenComandos() {
    return(orden_comandos);
}
void Curiosity::simular_comandos(float coordX, float coordY) {
    // Verificar si hay información almacenada en memoria para simular comandos
    if (lista_Movimientos.empty()) {
        std::cout << "(No hay información) La información requerida no está almacenada en memoria.\n";
        return;
    }
    cout << "hello1";
    // Simular comandos de movimiento
    float nuevoX = coordX, nuevoY = coordY, angulo_actual = 0;
    for (Movimiento comando : lista_Movimientos) {
        if (comando.ObtenerTipo() == "avanzar" && comando.ObtenerUnidad() == "cm") {
          cout << "hola1";
            nuevoY += std::cos(angulo_actual) * comando.ObtenerMagnitud();
            nuevoX += std::sin(angulo_actual) * comando.ObtenerMagnitud();

        } else if (comando.ObtenerTipo() == "girar") {
            cout << "hola2";
            angulo_actual -= 3.1416/2;
        } else if (comando.ObtenerTipo() == "avanzar" && comando.ObtenerUnidad() == "m"){
            cout << "hola3";
            nuevoY += std::cos(angulo_actual) * comando.ObtenerMagnitud() * 100;
            nuevoX += std::sin(angulo_actual) * comando.ObtenerMagnitud() * 100;
        }
        cout << "ho";
    }

    // Mostrar resultado exitoso con la nueva posición
    std::cout << "(Resultado exitoso) La simulación de los comandos, a partir de la posición (" << coordX << "," << coordY << "), deja al robot en la nueva posición (" << nuevoX << "," << nuevoY << ").\n";
}
void Curiosity::guardar(std::string tipo_archivo, std::string nombre_archivo) {
    // Crear un objeto de flujo de salida de archivo
    std::ofstream archivo(nombre_archivo);

    // Verificar si se pudo abrir el archivo correctamente
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo " << nombre_archivo << std::endl;
        return;
    }
    std::list<Analisis>::iterator it = lista_Analisis.begin();
    std::list<Movimiento>::iterator itm = lista_Movimientos.begin();
  //1=analisis, 0=movimiento
    if (tipo_archivo == "comandos") {
        for (int comando : orden_comandos) {
          if(comando == 1){
            archivo << "1 " << it->ObtenerTipo() << " " << it->ObtenerObjeto() << " " << it->ObtenerComentario() << "\n";
            it++;
          }else if(comando == 0){
            archivo << "0 " <<itm->ObtenerTipo() << " " << itm->ObtenerMagnitud() << " " << itm->ObtenerUnidad() << "\n";
            itm++;
          }
        }
    } else if (tipo_archivo == "elementos") {
        cout << lista_puntos.empty();
        for (Puntointeres elemento : lista_puntos) { // recorre la lista de elementos
            archivo << elemento.ObtenerTipo() << " " << elemento.ObtenerTamano() << " " << elemento.ObtenerUnidad()
          << " " << elemento.ObtenerX() << " " << elemento.ObtenerY() << endl;
        }
    } else {
        cout << "(No hay información) La información requerida no está almacenada en memoria." << endl;
        return;
    }

    if (!archivo) {
        cout << "(Problemas en archivo) Error guardando en " << nombre_archivo << "." << endl;
        return;
    }

    archivo.close();
    cout << "(Escritura exitosa) La información ha sido guardada en " << nombre_archivo << "." << endl;
}

void Curiosity::simular_comandos1(float coordX, float coordY){
  if (lista_Movimientos.empty()) {
        std::cout << "(No hay información) La información requerida no está almacenada en memoria.\n";
        return;
    }
  float auxX, auxY,auxAngulo,AnguloAnterior, Angulogiro, PosX, PosY;
  int cont=0;
  auxX =0;
  auxY =1;
  PosX=coordX;
  PosY=coordY;
  AnguloAnterior=0;
    std::list<Movimiento>::iterator cMov=lista_Movimientos.begin();
  for(; cMov!=lista_Movimientos.end();cMov++){
    cout<<"unidad:"<<cMov->ObtenerUnidad()<<endl;
    if(cMov->ObtenerTipo() == "avanzar" && cMov->ObtenerUnidad() == "m"){
      if(cMov->ObtenerUnidad() == "m"){
      cout << "av m"<<endl;
      PosX=PosX + auxX*(cMov->ObtenerMagnitud());
      PosY=PosY + auxY*(cMov->ObtenerMagnitud());
        }
    }

     else if(cMov->ObtenerTipo() == "avanzar" && cMov->ObtenerUnidad() == "cm"){
      cout << "av cm"<<endl;
      PosX=PosX + (auxX*(cMov->ObtenerMagnitud())/100);
      PosY=PosY + (auxY*(cMov->ObtenerMagnitud())/100);
    }

    else if(cMov->ObtenerTipo() == "girar"){
      cout << "gi"<<endl;
      auxAngulo=cMov->ObtenerMagnitud();
      if(cont==0){
      auxAngulo=auxAngulo+90;
        cont++;
        }
      AnguloAnterior=AnguloAnterior+auxAngulo;
      cout << "angulo: "<<AnguloAnterior<<endl;
      Angulogiro=AnguloAnterior*(3.14159265 / 180);

      auxX=cos(Angulogiro);
      auxY=sin(Angulogiro);

    }
    else{
      cout<<"movimiento no valido"<<endl;
    }

    cout<<"1"<<endl;
    }
  std::cout << "(Resultado exitoso) La simulación de los comandos, a partir de la posición (" << coordX << "," << coordY << "), deja al robot en la nueva posición (" << PosX << "," << PosY << ").\n";
  std::cout << "Unidades en metros.\n";

}
