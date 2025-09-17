#ifndef OPERACION_H
#define OPERACION_H

class Operacion
{
public:
    virtual ~Operacion() = default;

    virtual double ejecutar(double numero1, double numero2) = 0;
};

#endif