#include "Nodo.h"

// Impl. constructor - operando
Nodo::Nodo(double valor) : valor_numerico(valor),
                           tipo(OPERANDO),
                           izquierda(nullptr),
                           derecha(nullptr) {}

// Impl. constructor - operando
Nodo::Nodo(char valor) : valor_operador(valor),
                         tipo(OPERADOR),
                         izquierda(nullptr),
                         derecha(nullptr) {}