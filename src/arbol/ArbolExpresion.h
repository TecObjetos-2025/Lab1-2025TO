#ifndef ARBOLEXPRESION_H
#define ARBOLEXPRESION_H

#include "Nodo.h"
#include <vector>
#include <string>

class ArbolExpresion
{
private:
    Nodo *raiz;

    // Recorridos
    void inorden(Nodo *nodo);
    void preorden(Nodo *nodo);
    void postorden(Nodo *nodo);

    // Evaluacion recursiva
    double evaluar(Nodo *nodo);

public:
    // Constructor y Destructor
    ArbolExpresion();
    ~ArbolExpresion();

    // Metodo para construir arbol desde expresion tokenizada
    void construirArbol(const std::vector<std::string> &tokens);

    // Interfaz para recorridos
    void recorrerInorden();
    void recorrerPreorden();
    void recorrerPostorden();

    double evaluar();

    // Gestion de nodos (punteros). Avoid Memory Leak!!
    void liberarArbol(Nodo *nodo);
};

#endif // ARBOLEXPRESION_H