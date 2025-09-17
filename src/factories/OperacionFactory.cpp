#include "OperacionFactory.h"
#include "../operaciones/Suma.h"
#include "../operaciones/Resta.h"
#include "../operaciones/Multiplicacion.h"
#include "../operaciones/Division.h"
#include <stdexcept>

Operacion *OperacionFactory::crearOperacion(char operador)
{
    switch (operador)
    {
    case '+':
        return new Suma();
    case '-':
        return new Resta();
    case '*':
        return new Multiplicacion();
    case '/':
        return new Division();
    default:
        throw std::invalid_argument("Error: Operador no válido");
    }
}