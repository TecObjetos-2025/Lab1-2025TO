#ifndef DIVISION_H
#define DIVISION_H

#include "Operacion.h"

class Division : public Operacion
{
public:
    double ejecutar(double numero1, double numero2) override;
};

#endif