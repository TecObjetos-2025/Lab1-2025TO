#ifndef SUMA_H
#define SUMA_H

#include "Operacion.h"

class Suma : public Operacion
{
public:
    double ejecutar(double numero1, double numero2) override;
};

#endif // SUMA_H