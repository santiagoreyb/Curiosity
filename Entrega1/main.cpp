#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <list>
#include "Curiosity.h"
#include <cmath>
/*
  Compilar:
         g++ -std=c++11 main.cpp Analisis.cpp Movimiento.cpp Puntointeres.cpp Curiosity.cpp -o main
    Ejecutar:
        ./main
    prueba:
      cargar_comandos Comandos.txt
      cargar_comandos Comandos1.txt
      cargar_elementos Puntos.txt
      simular_comandos 0 0
*/
//Comandos.txt
using namespace std;
int cmdos(string cmdo);
vector<string> splitargms(string str);
void ayuda(std::string comando);
bool archvo_vacio(ifstream& n_archivo);
void cargar_comandos(string nombre_archivo, Curiosity &curiosity);
void cargar_puntos(string nombre_archivo, Curiosity &curiosity);
void guardar(string tipo_archivo, string nombre_archivo, Curiosity &curiosity);

int main() {

    string comand, linea_comando, nombre_archivo, tipo_comp, unidadMedida, tipo_archivo;
    Curiosity curiosity;
    vector<string> argmts;
    int opcion=1;
    float tamano, x, y;
    cout << "Ingrese el comando deseado" << endl;
    cout << "Ingrese | ayuda | para deplegar comandos" << endl;
    while(opcion!=0){
        cout<<"$";
        getline(cin, linea_comando);
        argmts = splitargms(linea_comando);
        comand = argmts[0];
        opcion = cmdos(comand);
        switch(opcion){
            case 0:{
                if(argmts.size()!=1){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                }
                break;
            }
            case 1:{
                if(argmts.size()!=2){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    nombre_archivo = argmts[1];
                    cargar_comandos(nombre_archivo, curiosity);
                }
                break;
            }
            case 2:{
                if(argmts.size()!=2){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                      cout<<"comando valido :)"<< endl;
                      nombre_archivo = argmts[1];
                      cargar_puntos( nombre_archivo, curiosity);
                }
                break;
            }

            case 3:{
                if(argmts.size()!=4){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                  cout<<"comando valido :)"<< endl;
                  curiosity.Agregar_Movimiento(linea_comando);
                }
                break;
            }
            case 4:{
                if(argmts.size()!=4){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    curiosity.Agregar_Analisis(linea_comando);
                }
                break;
            }
            case 5:{
                if(argmts.size()<6||argmts.size()>7){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    curiosity.Agregar_Puntointeres(linea_comando);
                }
                break;
            }
            case 6:{
                if(argmts.size()!=3){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    nombre_archivo = argmts[1];
                    tipo_archivo = argmts[2];
                    curiosity.guardar(nombre_archivo, tipo_archivo);
                }
                break;
            }
            case 7:{
                if(argmts.size()!=3){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                  cout<<"comando valido :)"<< endl;
                  x = stof(argmts[1]);
                  y = stof(argmts[2]);
                  curiosity.simular_comandos(x, y);
                }
                break;
            }
            case 8:{
                if(argmts.size()!=1){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                }
                break;
            }
            case 9:{
                if(argmts.size()!=5){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                }
                break;
            }
            case 10:{
                if(argmts.size()!=2){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                }
                break;
            }
            case 11:{
                if(argmts.size()!=1){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                }
                break;
            }
            case 13:
                cout<<"Ingrese un comando valido"<<endl;
                cout<<"Ingrese el comando ayuda para desplegar la lista de comandos"<<endl;
                break;
            case 14:{
                if(argmts.size()!=1 && argmts.size()!=2){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    if(argmts.size() == 2){
                        ayuda(argmts[1]);
                    }else{
                        ayuda("todos");
                    }
                }
                break;
            }
            default:
                cout<<"Ingrese un comando valido"<<endl;
                break;
        }
    }
    cout<<"Fin"<<endl;
}

int cmdos(string cmdo){

    if(cmdo=="cargar_comandos"){
        return 1;
      }else if(cmdo=="cargar_elementos"){
        return 2;
      }else if(cmdo=="agregar_movimiento"){
        return 3;
      }else if(cmdo=="agregar_analisis"){
        return 4;
      }else if(cmdo=="agregar_elemento"){
        return 5;
      }else if(cmdo=="guardar"){
        return 6;
      }else if(cmdo=="simular_comandos"){
        return 7;
      }else if(cmdo=="ubicar_elementos"){
        return 8;
      }else if(cmdo=="en_cuadrante"){
        return 9;
      }else if(cmdo=="crear_mapa"){
        return 10;
      }else if(cmdo=="ruta_mas_larga"){
        return 11;
      }else if(cmdo=="salir"){
        return 0;
      }else if(cmdo=="ayuda"){
        return 14;
      }else{
        return 13;
      }
}
vector<string> splitargms(string str){

    vector<string> comand_argms;
    int posInit = 0;
    int posFound = 0;
    string splitted;
    while (posFound >= 0) {
        posFound = str.find(' ', posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        comand_argms.push_back(splitted);
    }
    return comand_argms;
}

void ayuda(std::string comando){

    if(comando == "cargar_comandos" ){
        cout<<'\t' <<"- $cargar_comandos  (Fomato: $cargar_comandos nombre_archivo)" <<endl;
    }else if(comando == "cargar_elementos"){
        cout<<'\t' <<"- $cargar_elementos  (Fomato: $cargar_comandos nombre_archivo)"<<endl;
    }else if(comando == "agregar_movimiento"){
        cout<<'\t' <<"- $agregar_movimiento (Fomato: $agregar_analisis tipo_analisis objeto comentario)"<<endl;
    }else if(comando == "agregar_analisis"){
        cout<<'\t' <<"- $agregar_analisis  (Fomato: $agregar_analisis tipo_analisis objeto comentario)"<<endl;
    }else if(comando == "agregar_elemento"){
        cout<<'\t' <<"- $agregar_elemento   (Formato: $agregar_elemento tipo_comp tamaño unidad_med coordX coordY)"<<endl;
    }else if(comando == "guardar"){
        cout<<'\t' <<"- $guardar  (Fomato: guardar $tipo_de_archivo nombre_de_archivo)"<<endl;
    }else if(comando == "simular_comandos"){
        cout<<'\t' <<"- $simular_comandos   (Formato: $simular_comandos coordX coordY) "<<endl;
    }else if(comando == "ubicar_elementos"){
        cout<<'\t' <<"- $ubicar_elementos   (Fomato: $ubicar_elementos)"<<endl;
    }else if(comando == "en_cuadrante"){
        cout<<'\t' <<"- $en_cuadrante    (Formato: $en_cuadrante coordX1 coordX2 coordY1 coordY2)"<<endl;
    }else if(comando == "crear_mapa"){
        cout<<'\t' <<"- $crear_mapa   (Formato: $crear_mapa coeficiente_conectividad)"<<endl;
    }else if(comando == "ruta_mas_larga"){
        cout<<'\t' <<"- $ruta_mas_larga   (Fomato: $ruta_mas_larga)"<<endl;
    }else if(comando == "salir"){
        cout<<'\t' <<"- $salir    (Fomato: $salir)"<<endl;
    }else if(comando == "ayuda"){
        cout<<'\t' << "- $ayuda    (Fomato: $ayuda nombre_comando)"<<endl;
    }else if(comando == "todos"){
        cout<<'\t' << "Para mayor facilidad escribe ($ayuda nombre_comando)"<<endl;
        cout<<'\t' << "Por ejemplo: $ayuda cargar_elementos" << endl <<endl;
        cout<<'\t' << "Lista de comandos: "<<endl;

        cout<<'\t' << "- $cargar_comandos  (Fomato: $cargar_comandos nombre_archivo)" <<endl;
        cout<<'\t' << "- $cargar_elementos  (Fomato: $cargar_comandos nombre_archivo)"<<endl;
        cout<<'\t' << "- $agregar_movimiento (Fomato: $agregar_analisis tipo_analisis objeto comentario)"<<endl;
        cout<<'\t' << "- $agregar_analisis  (Fomato: $agregar_analisis tipo_analisis objeto comentario)"<<endl;
        cout<<'\t' << "- $agregar_elemento   (Formato: $agregar_elemento tipo_comp tamaño unidad_med coordX coordY)"<<endl;
        cout<<'\t' << "- $guardar  (Fomato: $guardar tipo_de_archivo nombre_de_archivo)"<<endl;
        cout<<'\t' << "- $simular_comandos   (Formato: $simular_comandos coordX coordY) "<<endl;
        cout<<'\t' << "- $ubicar_elementos   (Fomato: $ubicar_elementos)"<<endl;
        cout<<'\t' << "- $en_cuadrante    (Formato: $en_cuadrante coordX1 coordX2 coordY1 coordY2)"<<endl;
        cout<<'\t' << "- $crear_mapa   (Formato: $crear_mapa coeficiente_conectividad)"<<endl;
        cout<<'\t' << "- $ruta_mas_larga   (Fomato: $ruta_mas_larga)"<<endl;
        cout<<'\t' << "- $salir    (Fomato: $salir)"<<endl;
        cout<<'\t' << "- $ayuda    (Fomato: $ayuda nombre_comando)"<<endl;
    }
}

bool archvo_vacio(ifstream& n_archivo){
    return n_archivo.peek() == ifstream::traits_type::eof();
}

void cargar_comandos(string nombre_archivo, Curiosity &curiosity){

    unsigned int  n_comandos=0, pos, lineas=0;

    std:: string linea_archivo, com_movimiento, com_analisis;

    cout << endl << "cargando archivo:  " << nombre_archivo << endl;
    ifstream archivo_lectura(nombre_archivo);

    // Verificar si el archivo existe
    if (!archivo_lectura) {
        cout << endl << nombre_archivo << " no se encuentra o no puede leerse" << endl;
        return;
    }
    // Verificar si el archivo esta vacio
    if (archvo_vacio(archivo_lectura)){
        cout << endl << nombre_archivo << " no contiene comandos." << endl;
        return;
    }
    curiosity.eliminarMovimientos();
    curiosity.eliminarAnalisis();
    curiosity.eliminarOrden();
    cout<<"sobreescitro"<<endl;
    while(getline (archivo_lectura, linea_archivo)){
        vector<string> comando=splitargms(linea_archivo);
        lineas++;
        if (comando[0] == "avanzar"||comando[0] == "girar"){
            if(comando[2]=="cm"||comando[2]=="m"||comando[2]=="dm"||comando[2]=="km"||comando[2]=="grd"||comando[2]=="rad"){
                // obtener en string los movimientos
                curiosity.Agregar_Movimiento(linea_archivo);
                n_comandos++;
            }
        }else if(comando[0] == "fotografiar"||comando[0] == "composicion"|| comando[0] == "perforar"){
            // obtener en string los analisis
            curiosity.Agregar_Analisis(linea_archivo);
            n_comandos++;
        }else{
            cout<<"Error en la lectura del archivo. No se puede cargar"<<endl;
            curiosity.eliminarMovimientos();
            curiosity.eliminarAnalisis();
            archivo_lectura.close();
            return;
        }
    }
    archivo_lectura.close();

    cout << endl << "Se han cargado " << n_comandos << " comandos" << " de " <<lineas<<" lineas de archivo"<<endl;
}

void cargar_puntos(string nombre_archivo, Curiosity &curiosity){

    unsigned int n_puntos=0, pos;
    std:: string linea_archivo, linea_elemento;
    cout << endl << "cargando archivo:  " << nombre_archivo << endl;
    ifstream archivo_lectura(nombre_archivo);

    // Verificar si el archivo existe
    if (!archivo_lectura) {
        cout << endl << nombre_archivo << "No se encuentra o no puede leerse" << endl;
        return;
    }
    // Verificar si el archivo esta vacio
    if (archvo_vacio(archivo_lectura)){
        cout << endl << nombre_archivo << "Esta vacio, no contiene ningun comando" << endl;
        return;
    }
    curiosity.eliminarPuntos();
    cout<<"sobreescitro"<<endl;
    while(getline (archivo_lectura, linea_archivo)){
        curiosity.Agregar_Puntointeres(linea_archivo);
        n_puntos++;
    }
    archivo_lectura.close();
    cout << endl << "Se han cargado " << n_puntos << " Puntos de interes" << endl;
}




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

void Curiosity::Agregar_Movimiento(std::string linea_movimiento, bool cargar) {

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
    }else{
        mov.fijarTipo(elementos[0]);
        mov.fijarMagnitud(mag);
        mov.fijarUnidad(elementos[2]);
        lista_Movimientos.push_back(mov);
        orden_comandos.push_back(0);
        if(cargar == false)
            cout << "El comando de movimiento ha sido agregado exitosamente." << endl;
    }

}
void Curiosity::Agregar_Analisis(std::string linea_analisis) {

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
            bool isFound = linea_analisis.find("’") != string::npos;
            if (isFound){
                posInit = linea_analisis.find("’");
                posFound = linea_analisis.find("’", posInit);
                splitted = linea_analisis.substr(posInit, posFound - posInit);
                elementos.push_back(splitted);
                comentario=true;
            }
        }
    }
    if (elementos[0] != "fotografiar" || elementos[0] != "composicion" || elementos[0] != "perforar") error = true;
    if(elementos[1] != "roca" || elementos[1] != "crater" || elementos[1] != "monticulo" || elementos[1] != "duna") error = true;
    if (error == true){
        cout << "La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario)." << endl;
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
        cout << "El comando de análisis ha sido agregado exitosamente." << endl;
    }

}
void Curiosity::Agregar_Puntointeres(std::string linea_puntointeres) {

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
    if(elementos[0] != "roca" || elementos[0] != "crater" || elementos[0] != "monticulo" || elementos[0] != "duna") error = true;
    if(elementos[2] != "cm" || elementos[2] != "dm" || elementos[2] != "m" || elementos[2] != "km") error = true;
    try {
        tam = std::stof(elementos[1]);
        coordX = std::stof(elementos[3]);
        coordY = std::stof(elementos[4]);
        // La conversión fue exitosa,
    } catch (const std::exception& e) {
        error = true;
        // La conversión falló,
    }
    if(error == true){
        cout << "La información del elemento no corresponde a los datos esperados (tipo, tamaño, unidad, x, y)." << endl;
    }else{
        punt_aux.fijarTipo(elementos[0]);
        punt_aux.fijarTamano(tam);
        punt_aux.fijarUnidad(elementos[2]);
        punt_aux.fijarCoordenadas(coordX, coordY);
        lista_puntos.push_back(punt_aux);
        cout << "El elemento ha sido agregado exitosamente." << endl;
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
        }else{
            cout<<"Movimiento no valido"<<endl;
        }
    }
    //cout<<"1"<<endl;
    cout << "La simulación de los comandos, a partir de la posición (" << coordX << "," << coordY << "), deja al robot en la nueva posición (" << PosX << "," << PosY << ").\n";
    cout << "Unidades en metros.\n";

}
