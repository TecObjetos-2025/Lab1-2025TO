#include "ArbolExpresion.h"
#include "Nodo.h"
#include <stack>
#include <stdexcept>
#include <cctype>

// Constructor
ArbolExpresion::ArbolExpresion() : raiz(nullptr) {}

// Destructor
ArbolExpresion::ArbolExpresion()
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

// Funciones auxiliares
bool esOperador(const std::string &token)
{
    return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

// Construir el arbol
// Inspirado en https://stackoverflow.com/questions/19895308/converting-from-reverse-polish-notationrpn-into-a-tree-form
void ArbolExpresion::construirArbol(const std::vector<std::string> &tokens)
{
    std::stack<Nodo *> pila;

    for (const auto &token : tokens)
    {
        if (!esOperador(token))
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
            return valor_izquierdo + valor_derecha;
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