#include "Division.h"

#include <stdexcept> // std::runtime_error

double Division::ejecutar(double numero1, double numero2)
{
    if (numero2 == 0)
    {
        throw std::runtime_error("Error: No se puede dividir por cero");
    }
    return numero1 / numero2;
}