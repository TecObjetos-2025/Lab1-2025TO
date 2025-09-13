#ifndef RESTA_H
#define RESTA_H

#include "Operacion.h"

class Resta : public Operacion
{
public:
    double ejecutar(double numero1, double numero2) override;
};

#endif // RESTA_H