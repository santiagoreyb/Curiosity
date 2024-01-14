#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <list>
#include "Curiosity.h"
#include "ArbolQuad.h"
#include "Grafo.h"
#include "Puntointeres.h"
#include <cmath>
/*
  Compilar:
         g++ -std=c++11 main.cpp Analisis.cxx Movimiento.cxx Puntointeres.cxx Curiosity.cxx ArbolQuad.cxx NodoQuad.cxx Grafo.cxx Arista.cxx Vertice.cxx -o main
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
    Curiosity curiosity = Curiosity();
    ArbolQuad arbol = ArbolQuad();
    Grafo grafo = Grafo();
    vector<string> argmts;
    int opcion=1;
    float tamano, x, y, coeficiente;
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
                  linea_comando = argmts[1] + " " + argmts[2] + " " + argmts[3];
                  curiosity.Agregar_Movimiento(linea_comando, false);
                }
                break;
            }
            case 4:{
                if(argmts.size()!=3 && argmts.size()!=4){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    linea_comando = argmts[1] + " " + argmts[2] + " " + argmts[3];
                    curiosity.Agregar_Analisis(linea_comando, false);
                }
                break;
            }
            case 5:{
                if(argmts.size()!=6){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    linea_comando = argmts[1] + " " + argmts[2] + " " + argmts[3] + " " + argmts[4] + " " + argmts[5];
                    curiosity.Agregar_Puntointeres(linea_comando, false);
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
                  try {
                      x = stof(argmts[1]);
                      y = stof(argmts[2]);
                      curiosity.simular_comandos(x, y);
                      // La conversión fue exitosa,
                  } catch (const std::exception& e) {
                      cout<<"valores ingresados incorrectamente."<< endl;
                      // La conversión falló,
                  }
                  
                }
                break;
            }
            case 8:{
                if(argmts.size()!=1){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    curiosity.ubicar_elementos(arbol);
                }
                break;
            }
            case 9:{
                if(argmts.size()!=5){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                  try {
                      curiosity.en_cuadrante(stof(argmts[1]), stof(argmts[2]), stof(argmts[3]), stof(argmts[4]), arbol);
                      // La conversión fue exitosa,
                  } catch (const std::exception& e) {
                      cout<<"valores ingresados incorrectamente."<< endl;
                      // La conversión falló,
                  }
                    
                }
                break;
            }
            case 10:{
                if(argmts.size()!=2){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                  cout<<"comando valido :)"<< endl;
                  try {
                    curiosity.crear_mapa(grafo, stof(argmts[1]));
                      // La conversión fue exitosa,
                  } catch (const std::exception& e) {
                      cout<<"valores ingresados incorrectamente."<< endl;
                      // La conversión falló,
                  }
                  
                }
                break;
            }
            case 11:{
                if(argmts.size()!=1){
                    cout<<"Ingreso de parametros erroneo"<< endl;
                }else{
                    cout<<"comando valido :)"<< endl;
                    curiosity.comando_ruta_mas_larga2(grafo);
                    
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
        cout<<'\t' <<"- $cargar_comandos  (Fomato: $cargar_comandos nombre_archivo) Carga los comandos de movimiento y analisis al vehiculo curiosity desde el archivo indicado en el comando" <<endl;
    }else if(comando == "cargar_elementos"){
        cout<<'\t' <<"- $cargar_elementos  (Fomato: $cargar_comandos nombre_archivo) Carga en memoria los puntos de interes con sus coordenadas al vahiculo curiosity desde el archivo indicado en el comando"<<endl;
    }else if(comando == "agregar_movimiento"){
        cout<<'\t' <<"- $agregar_movimiento (Fomato: $agregar_movimiento tipo_mov magnitud unidad_med) Agrega a la lista de movimientos del curiosity el movimiento con el tipo de movimiento (avanzar, girar) con los valores ingresados (unidades de medida validas: cm,dm,m y km)"<<endl;
    }else if(comando == "agregar_analisis"){
        cout<<'\t' <<"- $agregar_analisis  (Fomato: $agregar_analisis tipo_analisis objeto comentario)Agrega a la lista de analisis del curiosity un analisis con el tipo de analisis (fotografiar, composicion y perforar) con su respectivo objeto (objetos validos:roca, crater, monticulo y duna) y un comentario opcional."<<endl;
    }else if(comando == "agregar_elemento"){
        cout<<'\t' <<"- $agregar_elemento   (Formato: $agregar_elemento tipo_comp tamaño unidad_med coordX coordY) Agrega a la lista de puntos de interes un elemento (tipo puede ser:roca, crater, monticulo y duna) con sus respectivas coordenadas en el plano."<<endl;
    }else if(comando == "guardar"){
        cout<<'\t' <<"- $guardar  (Fomato: guardar $tipo_de_archivo nombre_de_archivo) Escribe un archivo del tipo inicado(comandos o elementos), es decir, un archivo con los comandos del curiosity(movmimientos y analisis) o un archivo de elementos con los puntos de interes"<<endl;
    }else if(comando == "simular_comandos"){
        cout<<'\t' <<"- $simular_comandos   (Formato: $simular_comandos coordX coordY) Dada una virtual posicion del curiosity ingresada por el comando, se calcula la posicion del vehiculo si se realizaran los comandos de desplazamiento que tiene en memoria, por lo tanto es neceserio que ya se hayan cargado."<<endl;
    }else if(comando == "ubicar_elementos"){
        cout<<'\t' <<"- $ubicar_elementos   (Fomato: $ubicar_elementos) Ubica jerarquicamente los puntos de interes de acuaerdo a sus coordenadas en un arbol Quad"<<endl;
    }else if(comando == "en_cuadrante"){
        cout<<'\t' <<"- $en_cuadrante    (Formato: $en_cuadrante coordX1 coordX2 coordY1 coordY2) Utiliza el arbol Quad poblado con el comando ubicar_elementos y busca aquellos puntos de interes que se encuentren dentro del cuadrante especificado por los argumentos del comando. Tener en cuenta que CoordX1 debe ser mayor que CoordX2 y CoordY1 mayor a CoordY2"<<endl;
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
        cout<<'\t' <<"- $agregar_movimiento (Fomato: $agregar_movimiento tipo_mov magnitud unidad_med)"<<endl;
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
    }else{
        cout<<'\t' << " Comando " << comando << " no conocido :("<<endl;
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
        archivo_lectura.close();
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
                if(curiosity.Agregar_Movimiento(linea_archivo, true)){;
                n_comandos++;
                                                                     }
            }
        }else if(comando[0] == "fotografiar"||comando[0] == "composicion"|| comando[0] == "perforar"){
            // obtener en string los analisis
            if(curiosity.Agregar_Analisis(linea_archivo, true)){;
            n_comandos++;
                                                               }
        }else{
            cout<<"Error en la lectura del comando: "<< linea_archivo<<" No se puede cargar"<<endl;
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
        cout << endl << nombre_archivo << "Esta vacio, no contiene ningun punto" << endl;
        return;
    }
    curiosity.eliminarPuntos();
    cout<<"sobreescitro"<<endl;
    while(getline (archivo_lectura, linea_archivo)){
        if(curiosity.Agregar_Puntointeres(linea_archivo, true)){;
        n_puntos++;
                                                               }
      else{
            cout<<"Error en la lectura del comando: "<< linea_archivo<<" No se puede cargar"<<endl;
        }
    }
    archivo_lectura.close();
    cout << endl << n_puntos << " elementos cargados correctamente desde " << nombre_archivo << endl;
}
