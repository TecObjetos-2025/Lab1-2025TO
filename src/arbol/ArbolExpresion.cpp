#include "ArbolExpresion.h"
#include "../utilidades/Utilidades.h"
#include "Nodo.h"
#include <stack>
#include <stdexcept>
#include <cctype>
#include <iostream>

// Constructor
ArbolExpresion::ArbolExpresion() : raiz(nullptr) {}

// Destructor
ArbolExpresion::~ArbolExpresion()
{
    liberarArbol(raiz);
}

// Destruir cada nodo del arbol (memory free)
void ArbolExpresion::liberarArbol(Nodo *nodo)
{
    if (nodo)
    {
        liberarArbol(nodo->izquierda);
        liberarArbol(nodo->derecha);
        delete nodo;
    }
}

// Construir el arbol
// Inspirado en https://stackoverflow.com/questions/19895308/converting-from-reverse-polish-notationrpn-into-a-tree-form
void ArbolExpresion::construirArbol(const std::vector<std::string> &tokens)
{
    std::stack<Nodo *> pila;

    for (const auto &token : tokens)
    {
        if (!Utilidades::esOperador(token[0]))
        {
            pila.push(new Nodo(std::stod(token)));
        }
        else
        {
            if (pila.size() < 2)
            {
                throw std::invalid_argument("Expresion no esta bien formada");
            }
            Nodo *nodo_operador = new Nodo(token[0]);
            nodo_operador->derecha = pila.top();
            pila.pop();
            nodo_operador->izquierda = pila.top();
            pila.pop();

            pila.push(nodo_operador);
        }
    }

    if (pila.size() != 1)
    {
        throw std::invalid_argument("Expresion no esta bien formada");
    }
    raiz = pila.top();
}

double ArbolExpresion::evaluar(Nodo *nodo)
{
    if (!nodo)
    {
        throw std::invalid_argument("Ops! El arbol de expresion esta vacio");
    }

    if (nodo->tipo == OPERANDO)
    {
        return nodo->valor_numerico;
    }

    double valor_izquierdo = evaluar(nodo->izquierda);
    double valor_derecha = evaluar(nodo->derecha);

    switch (nodo->valor_operador)
    {
        {
        case '+':
            return valor_izquierdo + valor_derecha;
        case '-':
            return valor_izquierdo - valor_derecha;
        case '*':
            return valor_izquierdo * valor_derecha;
        case '/':
            if (valor_derecha == 0)
            {
                throw std::runtime_error("Error: Division por cero");
            }
            return valor_izquierdo / valor_derecha;
        default:
            throw std::invalid_argument("Error: El Operador no es valido");
        }
    }
}

double ArbolExpresion::evaluar()
{
    return evaluar(raiz);
}

// RECORRIDOS
// Izq | Raiz | Derecha
void ArbolExpresion::inorden(Nodo *nodo)
{
    if (nodo)
    {
        inorden(nodo->izquierda);
        if (nodo->tipo == OPERANDO)
        {
            std::cout << nodo->valor_numerico << " ";
        }
        else
        {
            std::cout << nodo->valor_operador << " ";
        }
        inorden(nodo->derecha);
    }
    // SINO es NULLPTR
}

// Raiz | Izq | Derecha
void ArbolExpresion::preorden(Nodo *nodo)
{
    if (nodo)
    {
        if (nodo->tipo == OPERANDO)
        {
            std::cout << nodo->valor_numerico << " ";
        }
        else
        {
            std::cout << nodo->valor_operador << " ";
        }
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
    // SINO es NULLPTR
}

// Izq | Derecha | Raiz
void ArbolExpresion::postorden(Nodo *nodo)
{
    if (nodo)
    {
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
        if (nodo->tipo == OPERANDO)
        {
            std::cout << nodo->valor_numerico << " ";
        }
        else
        {
            std::cout << nodo->valor_operador << " ";
        }
    }
    // SINO es NULLPTR
}

// Interfaz publica para recorridos
void ArbolExpresion::recorrerInorden()
{
    inorden(raiz);
    std::cout << std::endl;
}

void ArbolExpresion::recorrerPreorden()
{
    preorden(raiz);
    std::cout << std::endl;
}

void ArbolExpresion::recorrerPostorden()
{
    postorden(raiz);
    std::cout << std::endl;
}