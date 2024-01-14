#include <iostream>
#include <string>
#include <vector>

/*
  Compilar:
         g++ -std=c++11 main.cpp -o main
    Ejecutar:
        ./main
*/
using namespace std;
int cmdos(string cmdo);
vector<string> splitargms(string str);
void ayuda();

int main() {

  string comand, linea_comando;
  vector<string> argmts;
  int opcion;
  cout << "Ingrese el comando deseado" << endl;
  cout << "Ingrese | ayuda | para deplegar comandos" << endl;
  while(opcion!=0){
    cout<<"$";
    
    getline(cin, linea_comando);
    argmts = splitargms(linea_comando);
        comand = argmts[0];
        opcion = cmdos(comand);
    
    switch(opcion){
      case 0:
      if(argmts.size()!=1){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
      
    case 1:
      if(argmts.size()!=2){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 2:
      if(argmts.size()!=2){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 3:
    if(argmts.size()!=4){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 4:
      if(argmts.size()!=4){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 5:
      if(argmts.size()!=6){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 6:
      if(argmts.size()!=3){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 7:
      if(argmts.size()!=3){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 8:
      if(argmts.size()!=1){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 9:
      if(argmts.size()!=5){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 10:
      if(argmts.size()!=2){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;
    case 11:
      if(argmts.size()!=1){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        }
    break;

    case 13:
      cout<<"Ingrese un comando valido"<<endl;
      cout<<"Ingrese el comando ayuda para desplegar la lista de comandos"<<endl;
    break;
    case 14:
      if(argmts.size()!=1){
        cout<<"Ingreso de parametros erroneo"<< endl;
      }
      else{
      cout<<"comando valido :)"<< endl;
        ayuda();
        }
      
      break;
      
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
  }
  if(cmdo=="cargar_elementos"){
    return 2;
  }
  if(cmdo=="agregar_movimiento"){
    return 3;
  }
  if(cmdo=="agregar_analisis"){
    return 4;
  }
  if(cmdo=="agregar_elemento"){
    return 5;
  }
  if(cmdo=="guardar"){
    return 6;
  }
  if(cmdo=="simular_comandos"){
    return 7;
  }
  if(cmdo=="ubicar_elementos"){
    return 8;
  }
  if(cmdo=="en_cuadrante"){
    return 9;
  }
  if(cmdo=="crear_mapa"){
    return 10;
  }
  if(cmdo=="ruta_mas_larga"){
    return 11;
  }
  if(cmdo=="salir"){
    return 0;
  }
  if(cmdo=="ayuda"){
    return 14;
  }
  else{
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
void ayuda(){
  cout<<"Lista de comandos: "<<endl;
  cout<<"cargar_comandos   " <<endl;
  cout<<"cargar_elementos  "<<endl;
  cout<<"agregar_movimiento (Fomato: agregar_analisis tipo_analisis objeto comentario)"<<endl;
  cout<<"agregar_analisis  (Fomato: agregar_analisis tipo_analisis objeto comentario)"<<endl;
  cout<<"agregar_elemento   (Formato: agregar_elemento tipo_comp tamaño unidad_med coordX coordY)"<<endl;
  cout<<"guardar  (Fomato: guardar tipo_de_archivo nombre_de_archivo)"<<endl;
  cout<<"simular_comandos   (Formato: simular_comandos coordX coordY) "<<endl;
  cout<<"ubicar_elementos"<<endl;
  cout<<"en_cuadrante    (Formato: en_cuadrante coordX1 coordX2 coordY1 coordY2)"<<endl;
  cout<<"crear_mapa   (Formato: crear_mapa coeficiente_conectividad)"<<endl;
  cout<<"ruta_mas_larga"<<endl;
  cout<<"salir"<<endl;
  cout<<"ayuda"<<endl;
}

