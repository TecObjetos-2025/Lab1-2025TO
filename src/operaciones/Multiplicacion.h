#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H

#include "Operacion.h"

class Multiplicacion : public Operacion
{
public:
    double ejecutar(double numero1, double numero2) override;
};

#endif