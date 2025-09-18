#ifndef NODO_H
#define NODO_H

#include <string>

enum TipoNodo
{
    OPERADOR,
    OPERANDO
};

struct Nodo
{
    // Explanation -> https://www.geeksforgeeks.org/c/c-unions/
    union
    {
        double valor_numerico;
        char valor_operador;
    };
    TipoNodo tipo;
    Nodo *izquierda;
    Nodo *derecha;

    // Constructor - Operando
    Nodo(double valor);

    // Constructor - Operador
    Nodo(char valor);
};

#endif // NODO_H