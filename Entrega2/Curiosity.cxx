#include "Curiosity.h"
#include <iostream>
#include <fstream>
#include <string>
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

bool Curiosity::Agregar_Movimiento(std::string linea_movimiento, bool cargar) {

    std::vector<std::string> elementos;
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    Movimiento mov;
    bool error = false;

    while (posFound >= 0) {
        posFound = linea_movimiento.find(' ', posInit);
        splitted = linea_movimiento.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        elementos.push_back(splitted);
    }
    float mag = 0;
    try {
        mag = std::stof(elementos[1]);
        // La conversión fue exitosa, "elementos[1]" es un float
    } catch (const std::exception& e) {
        error = true;
        // La conversión falló, "elementos[1]" no es un float
    }
    if(elementos[0] != "avanzar" && elementos[0] != "girar") error = true;
    if(elementos[0] == "avanzar" && elementos[2] != "cm" && elementos[2] != "dm" && elementos[2] != "m" && elementos[2] != "km") error = true;
    if(elementos[0] == "girar" && elementos[2] != "grd" && elementos[2] != "rad") error = true;
    if (error == true && cargar == false){
        cout << "La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad)."<<endl;
      return false;
    }else{
        mov.fijarTipo(elementos[0]);
        mov.fijarMagnitud(mag);
        mov.fijarUnidad(elementos[2]);
        lista_Movimientos.push_back(mov);
        orden_comandos.push_back(0);
        return true;
    }

}

bool Curiosity::Agregar_Analisis(std::string linea_analisis, bool cargar) {
    bool comentario=false;
    bool error = false;
    std::vector<std::string> elementos;
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    Analisis anl_aux;

    for(int i=0;i<3;i++){
        if(i<2){
            posFound = linea_analisis.find(' ', posInit);
            splitted = linea_analisis.substr(posInit, posFound - posInit);
            posInit = posFound + 1;
            elementos.push_back(splitted);
        }else{
            posInit = 0;
            bool isFound = linea_analisis.find("’") != std::string::npos;
            if (isFound){
                posInit = linea_analisis.find("’");
                posFound = linea_analisis.find("’", posInit);
                splitted = linea_analisis.substr(posInit, posFound - posInit-1);
                elementos.push_back(splitted);
                comentario=true;
            }
        }
    }
    if (elementos[0] != "fotografiar" && elementos[0] != "composicion" && elementos[0] != "perforar") error = true;
    if(elementos[1] != "roca" && elementos[1] != "crater" && elementos[1] != "monticulo" && elementos[1] != "duna") error = true;
    if (error == true && cargar == false){
        std::cout << "La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario)." << std::endl;
      return false;
    }else{
        if(comentario==true){
            anl_aux.fijarTipo(elementos[0]);
            anl_aux.fijarObjeto(elementos[1]);
            anl_aux.fijarComentario(elementos[2]);
        }else{
            anl_aux.fijarTipo(elementos[0]);
            anl_aux.fijarObjeto(elementos[1]);
        }
        lista_Analisis.push_back(anl_aux);
        orden_comandos.push_back(1);
        return true;
    }
}



bool Curiosity::Agregar_Puntointeres(std::string linea_puntointeres, bool cargar) {

    std::vector<std::string> elementos;
    bool error = false;
    int posInit = 0;
    int posFound = 0;
    float tam = 0;
    float coordX = 0;
    float coordY = 0;
    std::string splitted;
    Puntointeres punt_aux;
    while (posFound >= 0) {
        posFound = linea_puntointeres.find(' ', posInit);
        splitted = linea_puntointeres.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        elementos.push_back(splitted);
    }
    if(elementos[0] != "roca" && elementos[0] != "crater" && elementos[0] != "monticulo" && elementos[0] != "duna") error = true;
    if(elementos[2] != "cm" && elementos[2] != "dm" && elementos[2] != "m" && elementos[2] != "km") error = true;
    try {
        tam = std::stof(elementos[1]);
        coordX = std::stof(elementos[3]);
        coordY = std::stof(elementos[4]);
        // La conversión fue exitosa,
    } catch (const std::exception& e) {
        error = true;
        // La conversión falló,
    }
    if(error == true && cargar == false){
        cout << "La información del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)." << endl;
      return false;
    }else{
        punt_aux.fijarTipo(elementos[0]);
        punt_aux.fijarTamano(tam);
        punt_aux.fijarUnidad(elementos[2]);
        punt_aux.fijarCoordenadas(coordX, coordY);
        lista_puntos.push_back(punt_aux);
        return true;
    }

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
            archivo << it->ObtenerTipo() << " " << it->ObtenerObjeto() << " " << it->ObtenerComentario() << "\n";
            it++;
          }else if(comando == 0){
            archivo <<itm->ObtenerTipo() << " " << itm->ObtenerMagnitud() << " " << itm->ObtenerUnidad() << "\n";
            itm++;
          }
        }
    } else if (tipo_archivo == "elementos") {
        for (Puntointeres elemento : lista_puntos) { // recorre la lista de elementos
            archivo << elemento.ObtenerTipo() << " " << elemento.ObtenerTamano() << " " << elemento.ObtenerUnidad()
          << " " << elemento.ObtenerX() << " " << elemento.ObtenerY() << endl;
        }
    } else {
        cout << "La información requerida no está almacenada en memoria." << endl;
        return;
    }
    if (!archivo) {
        cout << "Error guardando en " << nombre_archivo << "." << endl;
        return;
    }
    archivo.close();
    cout << "La información ha sido guardada en " << nombre_archivo << "." << endl;

}

void Curiosity::simular_comandos(float coordX, float coordY){

    if (lista_Movimientos.empty()) {
        std::cout << "La información requerida no está almacenada en memoria.\n";
        return;
    }
    float auxX, auxY,auxAngulo,AnguloActual=0,  PosX, PosY;
    auxX =1;
    auxY =0;
    PosX=coordX;
    PosY=coordY;
    std::list<Movimiento>::iterator cMov=lista_Movimientos.begin();
    for(; cMov!=lista_Movimientos.end();cMov++){
        //cout<<"unidad:"<<cMov->ObtenerUnidad()<<endl;
        if(cMov->ObtenerTipo() == "avanzar" ){
            if(cMov->ObtenerUnidad() == "m"){
                //cout << "av m"<<endl;
                PosX=PosX + auxX*(cMov->ObtenerMagnitud());
                PosY=PosY + auxY*(cMov->ObtenerMagnitud());
            }else if(cMov->ObtenerUnidad() == "dm"){
              //cout << "av cm"<<endl;
              PosX=PosX + (auxX*(cMov->ObtenerMagnitud())/10);
              PosY=PosY + (auxY*(cMov->ObtenerMagnitud())/10);
            }else if(cMov->ObtenerUnidad() == "cm"){
              //cout << "av dm"<<endl;
              PosX=PosX + (auxX*(cMov->ObtenerMagnitud())/100);
              PosY=PosY + (auxY*(cMov->ObtenerMagnitud())/100);
            }else if(cMov->ObtenerUnidad() == "cm"){
              //cout << "av km"<<endl;
              PosX=PosX + (auxX*(cMov->ObtenerMagnitud())*1000);
              PosY=PosY + (auxY*(cMov->ObtenerMagnitud())*1000);
            }
        }else if(cMov->ObtenerTipo() == "girar"){
            auxAngulo=cMov->ObtenerMagnitud();
            if(cMov->ObtenerUnidad() == "grd"){
                auxAngulo=auxAngulo*(3.14159265 / 180);
                AnguloActual=AnguloActual+auxAngulo;
                //cout << "angulo: "<<AnguloActual<<endl;
                auxX=cos(AnguloActual);
                auxY=sin(AnguloActual);
            }else if(cMov->ObtenerUnidad() == "rad"){
                AnguloActual=AnguloActual+auxAngulo;
                //cout << "angulo: "<<AnguloActual<<endl;
                auxX=cos(AnguloActual);
                auxY=sin(AnguloActual);
            }
        }
            
        
    }
    //cout<<"1"<<endl;
    cout << "La simulación de los comandos, a partir de la posición (" << coordX << "," << coordY << "), deja al robot en la nueva posición (" << PosX << "," << PosY << ").\n";
    cout << "Unidades en metros.\n";

}

void Curiosity::ubicar_elementos(ArbolQuad& arbol) {
    if (lista_puntos.empty()) {
        std::cout << "La información requerida no está almacenada en memoria.\n";
        return;
    }
    bool problemas_procesamiento = false;
    for (std::list<Puntointeres>::iterator it = lista_puntos.begin(); it != lista_puntos.end(); ++it) {
        bool resultado = arbol.insertar(*it);
        if (!resultado) {
            std::cerr << "Error al procesar el elemento (" << it->ObtenerTipo() << ", " << it->ObtenerX() << ", " << it->ObtenerY() << ")\n";
            problemas_procesamiento = true;
        }
    }
    if (problemas_procesamiento) {
        std::cout << "Algunos elementos no pudieron procesarse adecuadamente.\n";
    }else {
        std::cout << "Los elementos han sido procesados exitosamente.\n";
    }
}


void Curiosity::en_cuadrante(float coordX1, float coordX2, float coordY1, float coordY2, ArbolQuad& arbol) {
    if (coordX1 >= coordX2 || coordY1 >= coordY2) {
        std::cout << "La información del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)\n";
        return;
    }
    if (arbol.esVacio()) {
        std::cout << "Los elementos no han sido ubicados todavía (con el comando ubicar_elementos)\n";
        return;
    }
    std::vector<Puntointeres> elementos_encontrados;
    arbol.buscarEnCuadrante(arbol.obtenerRaiz(), coordX1, coordY1, coordX2, coordY2, elementos_encontrados);
    if (elementos_encontrados.empty()) {
        std::cout << "No se encontraron elementos dentro del cuadrante especificado\n";
    }
    else {
        std::cout << "Los elementos ubicados en el cuadrante solicitado son:\n";
        for (std::vector<Puntointeres>::iterator it = elementos_encontrados.begin(); it != elementos_encontrados.end(); ++it) {
            std::cout << "- " << it->ObtenerTipo() << " (" << it->ObtenerX() << ", " << it->ObtenerY() << ")\n";
        }
    }
}

