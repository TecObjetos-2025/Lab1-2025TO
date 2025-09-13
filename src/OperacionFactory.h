#ifndef OPERACIONFACTORY_H
#define OPERACIONFACTORY_H

#include "Operacion.h"

class OperacionFactory
{
public:
    static Operacion *crearOperacion(char operador);
};

#endif // OPERACIONFACTORY_H