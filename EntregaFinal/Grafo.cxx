#include "Grafo.h"
#include <stack>
using namespace std;
Grafo::Grafo(){
  
}

std::vector<Vertice> Grafo::getVertices()
{
    return vertices;
}

std::list<std::list<Arista>> Grafo::getConexiones()
{
    return conexiones;
}

void Grafo::setVertices(std::vector<Vertice> vertices)
{
    this->vertices = vertices;
}

void Grafo::setConexiones(std::list<std::list<Arista>> conexiones)
{
    this->conexiones = conexiones;
}

bool Grafo::esVacio()
{
    return vertices.empty() && conexiones.empty();
}

int Grafo::cantidadVertices()
{
    return vertices.size();
}

int Grafo::cantidadAristas()
{
    int contador = 0;
    for (const auto& lista : conexiones)
    {
        contador += lista.size();
    }
    return contador;
}

void Grafo::limpiarGrafo() {
    vertices.clear();
    conexiones.clear();
}

bool Grafo::insertarVertice(Vertice** vertice)
{
    if (!estaVertice(**vertice))
    {
        vertices.push_back(**vertice);
        std::list<Arista> aux;
        conexiones.push_back(aux);
        return true;
    }
    return false;
}

bool Grafo::insertarVertice(Puntointeres dato)
{
    Vertice* ver = new Vertice(dato);
    bool resultado = insertarVertice(&ver);
    if (!resultado)
    {
        delete ver;
    }
    return resultado;
}


bool Grafo::estaVertice(Vertice& vertice)
{
    for (auto& v : vertices)
    {
        if (*vertice.getDato() == *v.getDato())
            return true;
    }
    return false;
}

bool Grafo::estaVertice(Puntointeres dato)
{
    for (auto& v : vertices)
    {
        if (dato == *v.getDato())
        {
            return true;
        }
    }
    return false;
}

int Grafo::insertarArista(Puntointeres ver_org, Puntointeres ver_des, float peso)
{
    if (!estaVertice(ver_org))
    {
        return 1;
    }
    else if (!estaVertice(ver_des))
    {
        return 2;
    }
    else
    {
        int indice = obtenerIndice(ver_org);
        std::list<Arista>* conex = obtenerConexionesVertice(indice);
        Vertice* verDes = buscarVertice(ver_des);
        if (!insertarConexion(conex, verDes, peso))
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
}

std::list<Arista>* Grafo::obtenerConexionesVertice(int indice)
{
    int cont = 0;
    for (auto& lista : conexiones)
    {
        if (cont == indice)
        {
            return &lista;
        }
        cont++;
    }
    return nullptr;
}

int Grafo::obtenerIndice(Puntointeres& punto) {
    int indice = 0;
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        if (*it->getDato() == punto) {
            return indice;
        }
        ++indice;
    }
    return -1;
}


Vertice* Grafo::buscarVertice(Puntointeres ver_des)
{
    for (auto& v : vertices)
    {
        if (*v.getDato() == ver_des)
        {
            return &v;
        }
    }
    return nullptr;
}

bool Grafo::insertarConexion(std::list<Arista>* conex, Vertice* verDes, float peso)
{
    for (auto& arista : *conex)
    {
        if (arista.getSucesor() == verDes)
        {
            return false;
        }
    }
    Arista aris(verDes, peso);
    conex->push_back(aris);
    conex->sort();
    return true;
}

Arista* Grafo::buscarArista(Puntointeres ver_org, Puntointeres ver_des)
{
    int indice = obtenerIndice(ver_org);
    std::list<Arista>* conex = obtenerConexionesVertice(indice);
    for (auto& arista : *conex)
    {
        if (*arista.getSucesor()->getDato() == ver_des)
        {
            return &arista;
        }
    }
    return nullptr;
}

bool Grafo::verticeVisitado(std::list<Vertice*> lista, Puntointeres dato)
{
    for (auto& v : lista)
    {
        if (*v->getDato() == dato)
        {
            return true;
        }
    }
    return false;
}

Vertice* Grafo::ObtenerVertice(int indice)
{
    if (indice >= 0 && indice < vertices.size())
    {
        auto it = vertices.begin();
        std::advance(it, indice);
        return &(*it);
    }
    else
    {
        return nullptr;
    }
}
std::pair<float, std::pair<Puntointeres*, Puntointeres*>> Grafo::obtenerComponentesMasAlejados() {
    // Verificar si el grafo está vacío
    if (vertices.empty()) {
        return std::make_pair(0.0, std::make_pair(nullptr, nullptr));
    }

    // Inicializar la distancia máxima como infinito
    float distanciaMaxima = std::numeric_limits<float>::infinity();

    // Variables para almacenar los componentes más alejados
    Puntointeres* componenteA = nullptr;
    Puntointeres* componenteB = nullptr;

    // Recorrer todos los pares de vértices
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        for (auto jt = std::next(it); jt != vertices.end(); ++jt) {
            // Obtener los índices de los vértices
            int indiceOrigen = obtenerIndice(*it->getDato());
            int indiceDestino = obtenerIndice(*jt->getDato());

            // Si alguno de los índices no es válido, continuar al siguiente par de vértices
            if (indiceOrigen == -1 || indiceDestino == -1) {
                continue;
            }

            // Realizar el cálculo de la distancia entre los vértices
            float distancia = calcularDistancia(*it->getDato(), *jt->getDato());

            // Verificar si se encontró una distancia máxima más grande que la actual
            if (distancia > distanciaMaxima) {
                distanciaMaxima = distancia;
                componenteA = it->getDato();
                componenteB = jt->getDato();
            }
        }
    }

    // Retornar la distancia máxima y los componentes más alejados
    return std::make_pair(distanciaMaxima, std::make_pair(componenteA, componenteB));
}
// Dentro de la clase Grafo

float Grafo::calcularDistancia(Puntointeres& puntoA, Puntointeres& puntoB) {
    // Realizar una búsqueda en anchura (BFS) para encontrar la distancia entre los puntos A y B
    std::queue<int> cola;
    std::vector<bool> visitados(vertices.size(), false);
    std::vector<int> distancias(vertices.size(), 0);

    // Encontrar el índice del punto A y B en el vector de vértices
    int indiceA = obtenerIndice(puntoA);
    int indiceB = obtenerIndice(puntoB);

    cola.push(indiceA);
    visitados[indiceA] = true;

    while (!cola.empty()) {
        int indiceActual = cola.front();
        cola.pop();

        // Verificar si se llegó al punto B
        if (indiceActual == indiceB) {
            return distancias[indiceActual];
        }

        // Recorrer las conexiones del vértice actual
        std::list<Arista>* conexiones = obtenerConexionesVertice(indiceActual);
        if (conexiones != nullptr) {
            for (Arista& arista : *conexiones) {
                int indiceDestino = obtenerIndice(*arista.getSucesor()->getDato());

                if (!visitados[indiceDestino]) {
                    cola.push(indiceDestino);
                    visitados[indiceDestino] = true;
                    distancias[indiceDestino] = distancias[indiceActual] + 1;
                }
            }
        }
    }

    // Si no se encontró una ruta entre los puntos A y B, se devuelve un valor negativo o infinito
    return -1.0;
}
std::vector<Puntointeres*> Grafo::ruta_mas_larga() {
    std::vector<bool> visitados(vertices.size(), false);
    std::vector<Puntointeres*> rutaActual, rutaMasLarga;

    for (int i = 0; i < vertices.size(); ++i) {
        DFS(i, rutaActual, rutaMasLarga, visitados);
    }
    return rutaMasLarga;
}

void Grafo::DFS(int indice, std::vector<Puntointeres*>& rutaActual, std::vector<Puntointeres*>& rutaMasLarga,
                std::vector<bool>& visitados) {
    visitados[indice] = true;
    rutaActual.push_back(vertices[indice].getDato());

    if (rutaActual.size() > rutaMasLarga.size()) {
        rutaMasLarga = rutaActual;
    }

    std::list<Arista>* conexiones = obtenerConexionesVertice(indice);
    if (conexiones != nullptr) {
        for (Arista& arista : *conexiones) {
            int indiceDestino = obtenerIndice(*arista.getSucesor()->getDato());

            if (!visitados[indiceDestino]) {
                DFS(indiceDestino, rutaActual, rutaMasLarga, visitados);
            }
        }
    }

    visitados[indice] = false;
    rutaActual.pop_back();
}

float Grafo::calcularDistanciaEntrePuntos(Puntointeres& puntoA, Puntointeres& puntoB) {
    // Calcular la distancia euclidiana entre los puntos A y B
    float deltaX = puntoB.ObtenerX() - puntoA.ObtenerX();
    float deltaY = puntoB.ObtenerY() - puntoA.ObtenerY();
    float distancia = std::sqrt(deltaX * deltaX + deltaY * deltaY);
    return distancia;
}


std::pair<float, std::pair<Vertice, Vertice>> Grafo::componenetes_mas_alejados_Dijkstra() {
    pair<float,pair<Vertice, Vertice>> max_distanciasDijkstra,distanciasDijkstra_Aux;
    max_distanciasDijkstra.first = 0;
    vector<Vertice>* predecesor = new vector<Vertice>(vertices.size());
    vector<Puntointeres*> rutaMasLarga;
    for (int i = 0; i < vertices.size(); ++i) {
      vector< float >* distDijk = new vector<float>(vertices.size(), 999999);
      recorridoDijkstra( distDijk, predecesor, i);
      distanciasDijkstra_Aux=obtenerComponentesMasAlejadosDijskstra(distDijk);
      if(distanciasDijkstra_Aux.first > max_distanciasDijkstra.first){
        max_distanciasDijkstra = distanciasDijkstra_Aux;
      }
    }
    return max_distanciasDijkstra;
}


Vertice Grafo::min_distancia(list<Vertice>* todosLosVertices, vector<float> distancias)
{
    typename list<Vertice >::iterator it=todosLosVertices->begin();
    typename list<Vertice>::iterator itAux=todosLosVertices->begin();
    int menor = numeric_limits<int>::max();
    for(; it!=todosLosVertices->end(); it++)
    {
        int indice=obtenerIndice(*it->getDato());
        if(distancias.at(indice)<menor)
        {
            itAux=it;
            menor=distancias.at(indice);
        }
    }
    todosLosVertices->erase(itAux);
    return (*itAux);
}

void Grafo::recorridoDijkstra(std::vector<float>* distancias, std::vector<Vertice>* prede, int indice)
{
    

    
    distancias->at(indice) = 0;
    prede->at(indice) = *ObtenerVertice(indice);
        
  
    //                       S=conjunto de vertices visitados ES LA LISTA QUE SE PASA COMO PAREMETRO(Prede)
    list<Vertice > Q(vertices.begin(), vertices.end());
  //Copia de la lista de vertices para llevar el recuento de los vertices que falta por visitar (Q)
    //list<Vertice<T> > Q = vertices;
    while(!Q.empty())
    {
        Vertice minimo = min_distancia(&Q, *distancias);///Dado Q y dist se obtiene el vertice que tiene la menor distancia
        
        //cout << minimo.getDato()<< " "<<endl;
 
        
        int indice = obtenerIndice(*minimo.getDato());
        list<Arista >* aristas = obtenerConexionesVertice(indice);
        
        typename list<Arista >::iterator it=aristas->begin();  
        for(; it!=aristas->end(); it++)
        {
            int indice2 = obtenerIndice(*it->getSucesor()->getDato());
            int posibleMinimo = (distancias->at(indice) + it->getPeso());
            
            if(distancias->at(indice2) > posibleMinimo)
            {
                distancias->at(indice2) = posibleMinimo;
                prede->at(indice2) = minimo;
                
                //cout << *prede->at(indice2).getDato()<< "  es el dato"<<endl;
                //cout<<"el predecesor "<<*minimo.getDato()<<" con ubicacion "<<*myItList->getDato()<<endl;

            }
        }
        //cout<<"tamano de prede "<<prede->size()<<endl;
    }
   
}




std::pair<float, std::pair<Vertice, Vertice>> Grafo::obtenerComponentesMasAlejadosDijskstra(vector<float>* distancias){
    float distanciaMaxima=0;
    int iAux;
    Vertice orig, dest;
      for(int i=0;i<vertices.size();i++){
        if(distancias->at(i)==0){
           orig = *ObtenerVertice(i);
        }
        if(distancias->at(i)>distanciaMaxima &&distancias->at(i)!=999999){
            distanciaMaxima = distancias->at(i);
            iAux = i;
        }
        
      }
    dest = *ObtenerVertice(iAux);



  return std::make_pair(distanciaMaxima, std::make_pair(orig, dest));
} 


std::vector<Puntointeres*> Grafo::ruta_componentes_mas_alejados(Vertice orig, Vertice dest){
  vector<Puntointeres*> ruta;
  int indice_orig = obtenerIndice(*orig.getDato());
  int indice = obtenerIndice(*dest.getDato());
  
  
  vector<Vertice>* predecesor = new vector<Vertice>(vertices.size());
  
  vector< float >* distDijk = new vector<float>(vertices.size(), 999999);
      recorridoDijkstra( distDijk, predecesor, indice_orig);
  
  Vertice predAux;
  Puntointeres* PuntoAux;
  bool recorrido_completo = false;
  
  std::stack<Puntointeres*> pilaAux;
  pilaAux.push(dest.getDato());
    while(recorrido_completo==false){
        predAux = predecesor->at(indice);
      
        
        
        indice = obtenerIndice(*predAux.getDato());
        
        pilaAux.push(ObtenerVertice(indice)->getDato());
        
        
        if(indice_orig == obtenerIndice(*predAux.getDato())){
          
          recorrido_completo=true;
        }
    }
  int n = pilaAux.size();
  
  for(int i=0;i<n;i++){
    PuntoAux = pilaAux.top();
    
    ruta.push_back(PuntoAux);
    
    pilaAux.pop();
   
  }
  
 return ruta; 
}